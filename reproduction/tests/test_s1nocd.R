# This file runs one of the model scenarios and checks if you are getting
# consistent results with us. It has been modified to have a much shorter run
# time than in the reproduction.

# Run time: 18 seconds

# Load local package epicR
devtools::load_all("epicR")

# Clear environment as want to use library(epicR) below, which will use the
# devtools loaded library, but want to clear any other bits load_all() brought
# in and just work with that package from a "clean slate".
rm(list=ls())

# Import required packages
set.seed(333)
library(epicR)
library(tidyverse)
library(knitr)
library(kableExtra)

# Start timer
start.time <- Sys.time()

# Set model parameters
record_mode<-c(
  record_mode_none=0,
  record_mode_agent=1,
  record_mode_event=2,
  record_mode_some_event=3)

settings <- get_default_settings()
settings$record_mode <- record_mode["record_mode_none"]
settings$n_base_agents <- 50000
lambda=50000

init_session(settings = settings)
input <- init_input()

years_btw_case_detection=3
medication_utility=0.0367
med_adherence=0.7
smoking_adherence=0.7

other_years_btw_case_detection=5

costs <- data.frame(t(input$values$diagnosis$case_detection_methods[3,]))

CD_method = "None"
yrs_btw_CD = 3
min_age = 40
min_pack_years = 0
num_symptoms=0
med_adherence=0.7
smoking_adherence=0.7
time_horizon=20
medication_utility=0.0367 
discount_rate=0.015

# Process parameters to serve as model inputs
input$values$diagnosis$years_btw_case_detection <- yrs_btw_CD
input$values$diagnosis$min_cd_age <- min_age
input$values$diagnosis$min_cd_pack_years <- min_pack_years
input$values$diagnosis$min_cd_symptoms <- num_symptoms
input$values$medication$medication_adherence <- med_adherence
input$values$smoking$smoking_cessation_adherence <- smoking_adherence
input$values$global_parameters$time_horizon <- time_horizon
input$values$medication$medication_utility <-c(None=0,SABA=medication_utility, LABA=0,SABA_LABA=0, LAMA=medication_utility, LAMA_SABA=0,
                                               LAMA_LABA=medication_utility, LAMA_LAMA_SABA=0, ICS=0, ICS_SABA=0, ICS_LABA=0, ICS_LABA_SABA=0,
                                               ICS_LAMA=0, ICS_LAMA_SABA=0, ICS_LAMA_LABA=medication_utility, ICS_LAMA_LABA_SABA=0)
input$values$global_parameters$discount_cost <- discount_rate
input$values$global_parameters$discount_qaly <- discount_rate
input$values$cost$cost_case_detection <- input$values$diagnosis$case_detection_methods[3,CD_method]

input$values$diagnosis$logit_p_prevalent_diagnosis_by_sex <- cbind(male=c(intercept=1.0543, age=-0.0152, smoking=0.1068, fev1=-0.6146, cough=0.075, phlegm=0.283, wheeze=-0.0275, dyspnea=0.5414, case_detection=input$values$diagnosis$case_detection_methods[1,CD_method]),
                                                                   female=c(intercept=1.0543-0.1638, age=-0.0152, smoking=0.1068, fev1=-0.6146, cough=0.075, phlegm=0.283, wheeze=-0.0275,   dyspnea=0.5414, case_detection=input$values$diagnosis$case_detection_methods[1,CD_method]))

input$values$diagnosis$logit_p_diagnosis_by_sex <- cbind(male=c(intercept=-2, age=-0.0324, smoking=0.3711, fev1=-0.8032,
                                                                gpvisits=0.0087, cough=0.208, phlegm=0.4088, wheeze=0.0321, dyspnea=0.722,   case_detection=input$values$diagnosis$case_detection_methods[1,CD_method]), female=c(intercept=-2-0.4873, age=-0.0324, smoking=0.3711, fev1=-0.8032, gpvisits=0.0087, cough=0.208, phlegm=0.4088, wheeze=0.0321, dyspnea=0.722, case_detection=input$values$diagnosis$case_detection_methods[1,CD_method]))

input$values$diagnosis$logit_p_overdiagnosis_by_sex <- cbind(male=c(intercept=-5.2169, age=0.0025, smoking=0.6911, gpvisits=0.0075,
                                                                    cough=0.7264, phlegm=0.7956, wheeze=0.66, dyspnea=0.8798, case_detection=input$values$diagnosis$case_detection_methods[2,CD_method]),
                                                             female=c(intercept=-5.2169+0.2597, age=0.0025, smoking=0.6911, gpvisits=0.0075, cough=0.7264, phlegm=0.7956, wheeze=0.66,  dyspnea=0.8798, case_detection=input$values$diagnosis$case_detection_methods[2,CD_method]))

run(input = input$values)

inputs <- Cget_inputs()
output <- Cget_output()
output_ex <- Cget_output_ex()

copdPY <- output$cumul_time - output_ex$cumul_non_COPD_time
totalPY <- output$cumul_time

terminate_session()

# Run model
base <- data.frame(Scenario="S1NoCD",
                   Agents=output$n_cohort,
                   PatientYears=totalPY,
                   CopdPYs=copdPY,
                   NCaseDetections=output_ex$n_total_case_detection,
                   DiagnosedPYs=output$total_diagnosed_time,
                   OverdiagnosedPYs=sum(output_ex$n_Overdiagnosed_by_ctime_sex))

meds <- output_ex$medication_time_by_class[-5]
meds <- c(meds[1]/totalPY, meds[-1]/copdPY)
names(meds) <- c("SABA","LAMA","LAMALABA","ICSLAMALABA")
meds <- data.frame(t(meds))

exac <- output$total_exac
names(exac) <- c("Mild","Moderate","Severe","VerySevere")
exac <- data.frame(t(exac))

exacPY <- output$total_exac/copdPY
names(exacPY) <- c("MildPY","ModeratePY","SeverePY","VerySeverePY")
exacPY <- data.frame(t(exacPY))

gold<- colSums(output_ex$n_COPD_by_ctime_severity)
names(gold) <- c("NoCOPD","GOLD1","GOLD2","GOLD3","GOLD4")
gold <- data.frame(t(gold))

payoffs <- data.frame(Cost=output$total_cost, CostpAgent=output$total_cost/output$n_cohort,
                      QALY=output$total_qaly, QALYpAgent=output$total_qaly/output$n_cohort)
payoffs$NMB <- (payoffs$QALYpAgent)*lambda - (payoffs$CostpAgent)

s1NoCD <- cbind(base, meds, exac, exacPY, gold, payoffs)

# Import the expected results
exp_s1NoCD <- read.csv("tests/expected_results/s1nocd_50000.csv")

# End timer
end.time <- Sys.time()
time.taken <- end.time - start.time
time.taken

expect_equal(s1NoCD, exp_s1NoCD)
