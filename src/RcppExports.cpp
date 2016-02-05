// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "RMySQL_types.h"
#include <Rcpp.h>

using namespace Rcpp;

// connection_create
XPtr<MyConnectionPtr> connection_create(Rcpp::Nullable < std::string > host, Rcpp::Nullable < std::string > user, Rcpp::Nullable < std::string > password, Rcpp::Nullable < std::string > db, unsigned int port, Rcpp::Nullable < std::string > unix_socket, unsigned long client_flag, Rcpp::Nullable < std::string > groups, Rcpp::Nullable < std::string > default_file);
RcppExport SEXP RMySQL_connection_create(SEXP hostSEXP, SEXP userSEXP, SEXP passwordSEXP, SEXP dbSEXP, SEXP portSEXP, SEXP unix_socketSEXP, SEXP client_flagSEXP, SEXP groupsSEXP, SEXP default_fileSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< Rcpp::Nullable < std::string > >::type host(hostSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable < std::string > >::type user(userSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable < std::string > >::type password(passwordSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable < std::string > >::type db(dbSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type port(portSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable < std::string > >::type unix_socket(unix_socketSEXP);
    Rcpp::traits::input_parameter< unsigned long >::type client_flag(client_flagSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable < std::string > >::type groups(groupsSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable < std::string > >::type default_file(default_fileSEXP);
    __result = Rcpp::wrap(connection_create(host, user, password, db, port, unix_socket, client_flag, groups, default_file));
    return __result;
END_RCPP
}
// connection_release
void connection_release(XPtr<MyConnectionPtr> con);
RcppExport SEXP RMySQL_connection_release(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyConnectionPtr> >::type con(conSEXP);
    connection_release(con);
    return R_NilValue;
END_RCPP
}
// connection_info
List connection_info(XPtr<MyConnectionPtr> con);
RcppExport SEXP RMySQL_connection_info(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyConnectionPtr> >::type con(conSEXP);
    __result = Rcpp::wrap(connection_info(con));
    return __result;
END_RCPP
}
// connection_valid
bool connection_valid(XPtr<MyConnectionPtr> con);
RcppExport SEXP RMySQL_connection_valid(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyConnectionPtr> >::type con(conSEXP);
    __result = Rcpp::wrap(connection_valid(con));
    return __result;
END_RCPP
}
// connection_quote_string
CharacterVector connection_quote_string(XPtr<MyConnectionPtr> con, CharacterVector input);
RcppExport SEXP RMySQL_connection_quote_string(SEXP conSEXP, SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyConnectionPtr> >::type con(conSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type input(inputSEXP);
    __result = Rcpp::wrap(connection_quote_string(con, input));
    return __result;
END_RCPP
}
// connection_exec
bool connection_exec(XPtr<MyConnectionPtr> con, std::string sql);
RcppExport SEXP RMySQL_connection_exec(SEXP conSEXP, SEXP sqlSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyConnectionPtr> >::type con(conSEXP);
    Rcpp::traits::input_parameter< std::string >::type sql(sqlSEXP);
    __result = Rcpp::wrap(connection_exec(con, sql));
    return __result;
END_RCPP
}
// result_create
XPtr<MyResult> result_create(XPtr<MyConnectionPtr> con, std::string sql);
RcppExport SEXP RMySQL_result_create(SEXP conSEXP, SEXP sqlSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyConnectionPtr> >::type con(conSEXP);
    Rcpp::traits::input_parameter< std::string >::type sql(sqlSEXP);
    __result = Rcpp::wrap(result_create(con, sql));
    return __result;
END_RCPP
}
// result_column_info
List result_column_info(XPtr<MyResult> rs);
RcppExport SEXP RMySQL_result_column_info(SEXP rsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyResult> >::type rs(rsSEXP);
    __result = Rcpp::wrap(result_column_info(rs));
    return __result;
END_RCPP
}
// result_fetch
List result_fetch(XPtr<MyResult> rs, int n);
RcppExport SEXP RMySQL_result_fetch(SEXP rsSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyResult> >::type rs(rsSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    __result = Rcpp::wrap(result_fetch(rs, n));
    return __result;
END_RCPP
}
// result_bind
void result_bind(XPtr<MyResult> rs, List params);
RcppExport SEXP RMySQL_result_bind(SEXP rsSEXP, SEXP paramsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyResult> >::type rs(rsSEXP);
    Rcpp::traits::input_parameter< List >::type params(paramsSEXP);
    result_bind(rs, params);
    return R_NilValue;
END_RCPP
}
// result_bind_rows
void result_bind_rows(XPtr<MyResult> rs, List params);
RcppExport SEXP RMySQL_result_bind_rows(SEXP rsSEXP, SEXP paramsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyResult> >::type rs(rsSEXP);
    Rcpp::traits::input_parameter< List >::type params(paramsSEXP);
    result_bind_rows(rs, params);
    return R_NilValue;
END_RCPP
}
// result_release
void result_release(XPtr<MyResult> rs);
RcppExport SEXP RMySQL_result_release(SEXP rsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyResult> >::type rs(rsSEXP);
    result_release(rs);
    return R_NilValue;
END_RCPP
}
// result_rows_affected
int result_rows_affected(XPtr<MyResult> rs);
RcppExport SEXP RMySQL_result_rows_affected(SEXP rsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyResult> >::type rs(rsSEXP);
    __result = Rcpp::wrap(result_rows_affected(rs));
    return __result;
END_RCPP
}
// result_rows_fetched
int result_rows_fetched(XPtr<MyResult> rs);
RcppExport SEXP RMySQL_result_rows_fetched(SEXP rsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyResult> >::type rs(rsSEXP);
    __result = Rcpp::wrap(result_rows_fetched(rs));
    return __result;
END_RCPP
}
// result_complete
bool result_complete(XPtr<MyResult> rs);
RcppExport SEXP RMySQL_result_complete(SEXP rsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyResult> >::type rs(rsSEXP);
    __result = Rcpp::wrap(result_complete(rs));
    return __result;
END_RCPP
}
// result_active
bool result_active(XPtr<MyResult> rs);
RcppExport SEXP RMySQL_result_active(SEXP rsSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtr<MyResult> >::type rs(rsSEXP);
    __result = Rcpp::wrap(result_active(rs));
    return __result;
END_RCPP
}
// version
IntegerVector version();
RcppExport SEXP RMySQL_version() {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    __result = Rcpp::wrap(version());
    return __result;
END_RCPP
}