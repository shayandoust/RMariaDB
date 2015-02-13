#ifndef __RMYSQL_MY_BINDING__
#define __RMYSQL_MY_BINDING__

#include <Rcpp.h>
#include <mysql.h>
#include <boost/noncopyable.hpp>
#include "MyTypes.h"
#include <ctime>

class MyRow : boost::noncopyable {
  MYSQL_STMT* pStatement_;

  int n_;
  std::vector<MYSQL_BIND> bindings_;

  std::vector<MyFieldType> types_;
  std::vector< std::vector<unsigned char>* > buffers_;
  std::vector<unsigned long> lengths_;
  std::vector<my_bool> nulls_, errors_;

public:
  MyRow(MYSQL_STMT* pStatement, std::vector<MyFieldType> types):
    pStatement_(pStatement),
    types_(types)
  {
    n_ = types_.size();

    bindings_.resize(n_);
    lengths_.resize(n_);
    nulls_.resize(n_);
    errors_.resize(n_);

    for (int i = 0; i < n_; ++i) {
      // http://dev.mysql.com/doc/refman/5.0/en/c-api-prepared-statement-type-codes.html
      switch(types_[i]) {
      case MY_INT32:
        bindings_[i].buffer_type = MYSQL_TYPE_LONG;
        buffers_.push_back(new std::vector<unsigned char>(4));
        break;
      case MY_INT64:
        bindings_[i].buffer_type = MYSQL_TYPE_LONGLONG;
        buffers_.push_back(new std::vector<unsigned char>(8));
        break;
      case MY_DBL:
        bindings_[i].buffer_type = MYSQL_TYPE_DOUBLE;
        buffers_.push_back(new std::vector<unsigned char>(8));
        break;
      case MY_DATE:
        bindings_[i].buffer_type = MYSQL_TYPE_DATE;
        buffers_.push_back(new std::vector<unsigned char>(sizeof(MYSQL_TIME)));
        break;
      case MY_DATE_TIME:
        bindings_[i].buffer_type = MYSQL_TYPE_TIME;
        buffers_.push_back(new std::vector<unsigned char>(sizeof(MYSQL_TIME)));
        break;
      case MY_TIME:
        bindings_[i].buffer_type = MYSQL_TYPE_DATETIME;
        buffers_.push_back(new std::vector<unsigned char>(sizeof(MYSQL_TIME)));
        break;
      case MY_STR:
      case MY_RAW:
        bindings_[i].buffer_type = MYSQL_TYPE_STRING;
        // buffers might be arbitrary length, so leave size and use
        // alternative strategy 0
        buffers_.push_back(new std::vector<unsigned char>);
        break;
      }

      bindings_[i].buffer = &buffers_[i][0];
      bindings_[i].buffer_length = buffers_[i]->size();
      bindings_[i].length = &lengths_[i];
      bindings_[i].is_null = &nulls_[i];
      bindings_[i].is_unsigned = true;
      bindings_[i].error = &errors_[i];
    }

    if (mysql_stmt_bind_result(pStatement, &bindings_[0]) != 0)
      Rcpp::stop("%s", mysql_stmt_error(pStatement));

  }

  // Value accessors -----------------------------------------------------------
  bool isNull(int j) {
    return nulls_[j] == 1;
  }

  int valueInt(int j) {
    return isNull(j) ? NA_INTEGER : *((int*) &buffers_[j][0]);
  }

  int valueInt64(int j) {
    return isNull(j) ? NA_INTEGER : *((long long int*) &buffers_[j][0]);
  }

  int valueDouble(int j) {
    return isNull(j) ? NA_REAL : *((double*) &buffers_[j][0]);
  }

  SEXP valueString(int j) {
    if (isNull(j))
      return NA_STRING;

    Rcpp::Rcout << j << " size: " << buffers_[j]->size() << "\n";
    fetchBuffer(j);
    Rcpp::Rcout << j << " size: " << buffers_[j]->size() << "\n";
    buffers_[j]->push_back('\0');  // ensure string is null terminated
    char* val = (char*) &buffers_[j][0];

    return Rf_mkCharCE(val, CE_UTF8);
  }

  SEXP valueRaw(int j) {
    if (isNull(j))
      return Rf_allocVector(RAWSXP, 0);

    fetchBuffer(j);
    SEXP bytes = Rf_allocVector(RAWSXP, lengths_[j]);
    memcpy(RAW(bytes), &buffers_[j][0], lengths_[j]);

    return bytes;
  }

  int valueDateTime(int j) {
    if (isNull(j))
      return NA_INTEGER;

    MYSQL_TIME* mytime = (MYSQL_TIME*) &buffers_[j][0];

    struct tm t = { 0 };
    t.tm_year = mytime->year;
    t.tm_mon = mytime->month;
    t.tm_mday = mytime->day;
    t.tm_hour = mytime->hour;
    t.tm_min = mytime->minute;
    t.tm_sec = mytime->second;

    return mktime(&t);
  }

  int valueTime(int j) {
    if (isNull(j))
      return NA_INTEGER;

    MYSQL_TIME* mytime = (MYSQL_TIME*) &buffers_[j][0];
    return mytime->hour * 3600 + mytime->minute * 60 + mytime->second;
  }

  void setListValue(SEXP x, int i, int j) {
    switch(types_[j]) {
    case MY_INT32:
      INTEGER(x)[i] = valueInt(j);
      break;
    case MY_INT64:
      INTEGER(x)[i] = valueInt64(j);
      break;
    case MY_DBL:
      REAL(x)[i] = valueDouble(j);
      break;
    case MY_STR:
      SET_STRING_ELT(x, i, valueString(j));
      break;
    case MY_DATE:
    case MY_DATE_TIME:
      INTEGER(x)[i] = valueDateTime(j);
      break;
    case MY_TIME:
      INTEGER(x)[i] = valueTime(j);
      break;
    case MY_RAW:
      SET_VECTOR_ELT(x, i, valueRaw(j));
      break;
    }
  }

private:
  void fetchBuffer(int j) {
    unsigned long length = lengths_[j];
    if (length == 0)
      return;

    Rcpp::Rcout << j << " size: " << buffers_[j]->size() << "\n";
    buffers_[j]->resize(length);
    Rcpp::Rcout << j << " size: " << buffers_[j]->size() << "\n";
    bindings_[j].buffer = &buffers_[j][0]; // might have moved
    bindings_[j].buffer_length = length;
    mysql_stmt_fetch_column(pStatement_, &bindings_[j], j, 0);

    // Reset buffer length to zero for next row
    bindings_[j].buffer_length = 0;
  }

};

#endif
