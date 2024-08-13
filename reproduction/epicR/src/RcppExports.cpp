// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// mvrnormArma
arma::mat mvrnormArma(int n, arma::vec mu, arma::mat sigma);
RcppExport SEXP _epicR_mvrnormArma(SEXP nSEXP, SEXP muSEXP, SEXP sigmaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type mu(muSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type sigma(sigmaSEXP);
    rcpp_result_gen = Rcpp::wrap(mvrnormArma(n, mu, sigma));
    return rcpp_result_gen;
END_RCPP
}
// Cset_settings_var
int Cset_settings_var(std::string name, NumericVector value);
RcppExport SEXP _epicR_Cset_settings_var(SEXP nameSEXP, SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type value(valueSEXP);
    rcpp_result_gen = Rcpp::wrap(Cset_settings_var(name, value));
    return rcpp_result_gen;
END_RCPP
}
// Cget_settings
List Cget_settings();
RcppExport SEXP _epicR_Cget_settings() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_settings());
    return rcpp_result_gen;
END_RCPP
}
// Cget_runtime_stats
List Cget_runtime_stats();
RcppExport SEXP _epicR_Cget_runtime_stats() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_runtime_stats());
    return rcpp_result_gen;
END_RCPP
}
// Xrexp
NumericVector Xrexp(int n, double rate);
RcppExport SEXP _epicR_Xrexp(SEXP nSEXP, SEXP rateSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type rate(rateSEXP);
    rcpp_result_gen = Rcpp::wrap(Xrexp(n, rate));
    return rcpp_result_gen;
END_RCPP
}
// Cget_inputs
List Cget_inputs();
RcppExport SEXP _epicR_Cget_inputs() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_inputs());
    return rcpp_result_gen;
END_RCPP
}
// Cset_input_var
int Cset_input_var(std::string name, NumericVector value);
RcppExport SEXP _epicR_Cset_input_var(SEXP nameSEXP, SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type value(valueSEXP);
    rcpp_result_gen = Rcpp::wrap(Cset_input_var(name, value));
    return rcpp_result_gen;
END_RCPP
}
// get_sample_output
double get_sample_output(int year, int sex);
RcppExport SEXP _epicR_get_sample_output(SEXP yearSEXP, SEXP sexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type year(yearSEXP);
    Rcpp::traits::input_parameter< int >::type sex(sexSEXP);
    rcpp_result_gen = Rcpp::wrap(get_sample_output(year, sex));
    return rcpp_result_gen;
END_RCPP
}
// Cget_agent
List Cget_agent(long id);
RcppExport SEXP _epicR_Cget_agent(SEXP idSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< long >::type id(idSEXP);
    rcpp_result_gen = Rcpp::wrap(Cget_agent(id));
    return rcpp_result_gen;
END_RCPP
}
// Cget_smith
List Cget_smith();
RcppExport SEXP _epicR_Cget_smith() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_smith());
    return rcpp_result_gen;
END_RCPP
}
// Cget_output
List Cget_output();
RcppExport SEXP _epicR_Cget_output() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_output());
    return rcpp_result_gen;
END_RCPP
}
// Cget_output_ex
List Cget_output_ex();
RcppExport SEXP _epicR_Cget_output_ex() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_output_ex());
    return rcpp_result_gen;
END_RCPP
}
// Ccreate_agents
int Ccreate_agents();
RcppExport SEXP _epicR_Ccreate_agents() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Ccreate_agents());
    return rcpp_result_gen;
END_RCPP
}
// Cget_event
List Cget_event(int i);
RcppExport SEXP _epicR_Cget_event(SEXP iSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type i(iSEXP);
    rcpp_result_gen = Rcpp::wrap(Cget_event(i));
    return rcpp_result_gen;
END_RCPP
}
// Cget_n_events
int Cget_n_events();
RcppExport SEXP _epicR_Cget_n_events() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_n_events());
    return rcpp_result_gen;
END_RCPP
}
// Cget_agent_events
DataFrame Cget_agent_events(int id);
RcppExport SEXP _epicR_Cget_agent_events(SEXP idSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type id(idSEXP);
    rcpp_result_gen = Rcpp::wrap(Cget_agent_events(id));
    return rcpp_result_gen;
END_RCPP
}
// Cget_events_by_type
DataFrame Cget_events_by_type(int event_type);
RcppExport SEXP _epicR_Cget_events_by_type(SEXP event_typeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type event_type(event_typeSEXP);
    rcpp_result_gen = Rcpp::wrap(Cget_events_by_type(event_type));
    return rcpp_result_gen;
END_RCPP
}
// Cget_all_events
DataFrame Cget_all_events();
RcppExport SEXP _epicR_Cget_all_events() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_all_events());
    return rcpp_result_gen;
END_RCPP
}
// Cget_all_events_matrix
NumericMatrix Cget_all_events_matrix();
RcppExport SEXP _epicR_Cget_all_events_matrix() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_all_events_matrix());
    return rcpp_result_gen;
END_RCPP
}
// Callocate_resources
int Callocate_resources();
RcppExport SEXP _epicR_Callocate_resources() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Callocate_resources());
    return rcpp_result_gen;
END_RCPP
}
// Cget_pointers
List Cget_pointers();
RcppExport SEXP _epicR_Cget_pointers() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cget_pointers());
    return rcpp_result_gen;
END_RCPP
}
// Cdeallocate_resources
int Cdeallocate_resources();
RcppExport SEXP _epicR_Cdeallocate_resources() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cdeallocate_resources());
    return rcpp_result_gen;
END_RCPP
}
// Cdeallocate_resources2
int Cdeallocate_resources2();
RcppExport SEXP _epicR_Cdeallocate_resources2() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cdeallocate_resources2());
    return rcpp_result_gen;
END_RCPP
}
// Cinit_session
int Cinit_session();
RcppExport SEXP _epicR_Cinit_session() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(Cinit_session());
    return rcpp_result_gen;
END_RCPP
}
// Cmodel
int Cmodel(int max_n_agents);
RcppExport SEXP _epicR_Cmodel(SEXP max_n_agentsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type max_n_agents(max_n_agentsSEXP);
    rcpp_result_gen = Rcpp::wrap(Cmodel(max_n_agents));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_epicR_mvrnormArma", (DL_FUNC) &_epicR_mvrnormArma, 3},
    {"_epicR_Cset_settings_var", (DL_FUNC) &_epicR_Cset_settings_var, 2},
    {"_epicR_Cget_settings", (DL_FUNC) &_epicR_Cget_settings, 0},
    {"_epicR_Cget_runtime_stats", (DL_FUNC) &_epicR_Cget_runtime_stats, 0},
    {"_epicR_Xrexp", (DL_FUNC) &_epicR_Xrexp, 2},
    {"_epicR_Cget_inputs", (DL_FUNC) &_epicR_Cget_inputs, 0},
    {"_epicR_Cset_input_var", (DL_FUNC) &_epicR_Cset_input_var, 2},
    {"_epicR_get_sample_output", (DL_FUNC) &_epicR_get_sample_output, 2},
    {"_epicR_Cget_agent", (DL_FUNC) &_epicR_Cget_agent, 1},
    {"_epicR_Cget_smith", (DL_FUNC) &_epicR_Cget_smith, 0},
    {"_epicR_Cget_output", (DL_FUNC) &_epicR_Cget_output, 0},
    {"_epicR_Cget_output_ex", (DL_FUNC) &_epicR_Cget_output_ex, 0},
    {"_epicR_Ccreate_agents", (DL_FUNC) &_epicR_Ccreate_agents, 0},
    {"_epicR_Cget_event", (DL_FUNC) &_epicR_Cget_event, 1},
    {"_epicR_Cget_n_events", (DL_FUNC) &_epicR_Cget_n_events, 0},
    {"_epicR_Cget_agent_events", (DL_FUNC) &_epicR_Cget_agent_events, 1},
    {"_epicR_Cget_events_by_type", (DL_FUNC) &_epicR_Cget_events_by_type, 1},
    {"_epicR_Cget_all_events", (DL_FUNC) &_epicR_Cget_all_events, 0},
    {"_epicR_Cget_all_events_matrix", (DL_FUNC) &_epicR_Cget_all_events_matrix, 0},
    {"_epicR_Callocate_resources", (DL_FUNC) &_epicR_Callocate_resources, 0},
    {"_epicR_Cget_pointers", (DL_FUNC) &_epicR_Cget_pointers, 0},
    {"_epicR_Cdeallocate_resources", (DL_FUNC) &_epicR_Cdeallocate_resources, 0},
    {"_epicR_Cdeallocate_resources2", (DL_FUNC) &_epicR_Cdeallocate_resources2, 0},
    {"_epicR_Cinit_session", (DL_FUNC) &_epicR_Cinit_session, 0},
    {"_epicR_Cmodel", (DL_FUNC) &_epicR_Cmodel, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_epicR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}