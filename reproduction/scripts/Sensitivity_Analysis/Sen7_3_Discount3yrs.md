Sensitivity analysis: 3% Discount Rate
================
16 October, 2024

    ## 
    ## > errors<-c(
    ## +   ERR_INCORRECT_SETTING_VARIABLE=-1,
    ## +   ERR_INCORRECT_VECTOR_SIZE=-2,
    ## +   ERR_INCORRECT_INPUT_VAR=-3,
    ## +   ERR_EVENT_STACK_FULL=-4,
    ## +   .... [TRUNCATED] 
    ## 
    ## > record_mode<-c(
    ## +   record_mode_none=0,
    ## +   record_mode_agent=1,
    ## +   record_mode_event=2,
    ## +   record_mode_some_event=3
    ## + )
    ## 
    ## > agent_creation_mode<-c(
    ## +   agent_creation_mode_one=0,
    ## +   agent_creation_mode_all=1,
    ## +   agent_creation_mode_pre=2
    ## + )
    ## 
    ## > medication_classes<-c(
    ## +   MED_CLASS_SABA=1,
    ## +   MED_CLASS_LABA=2,
    ## +   MED_CLASS_LAMA=4,
    ## +   MED_CLASS_ICS=8,
    ## +   MED_CLASS_MACRO=16
    ## + )
    ## 
    ## > events<-c(
    ## +     event_start=0,
    ## +     event_fixed=1,
    ## +     event_birthday=2,
    ## +     event_smoking_change=3,
    ## +     event_COPD=4,
    ## +     event_exacerbat .... [TRUNCATED]

``` r
# CHANGE: Add a timer (will see addition below to print time too)
# Start timer
start.time <- Sys.time()
```

``` r
# CHANGE: Add save paths (will see later, we also add lines to save to csv)
outputs <- "../../outputs/Sen7_3_Discount"
files <- list(
  s1 = "s1.csv",
  s2 = "s2.csv",
  s3 = "s3.csv",
  sall = "sall.csv",
  ceplane = "ceplane.csv",
  clinical = "clinicalresults.csv"
)

# Apply to each element in list to create path to file in outputs
paths <- lapply(files, function(filename) paste0(outputs, filename))
```

    ## Initializing the session

    ## [1] 0

**Global inputs:**

  - Medication adherence is 0.7
  - Smoking adherence is 0.7
  - Cost discounting: 0.015
  - QALY discounting: 0.015
  - Time horizon: 20
  - The WTP threshold for NMB is 50000

**Case detection inputs:**

  - Case detection occurs at 3 year intervals.
  - An outpatient diagnosis costs 61.18
  - The utility gain due to symptom relief from treatment is 0.0367

## S1 All patients scenario

All patients are eligible. The cost of case detection is:

| None | CDQ17 | FlowMeter | FlowMeter\_CDQ |
| ---: | ----: | --------: | -------------: |
|    0 | 11.56 |     30.46 |          42.01 |

#### S1NoCD: No Case detection

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S1NoCD2: No Case detection- Other time interval

    ## Initializing the session

    ## [1] 0

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S1A: CDQ ≥17 points

    ## Initializing the session

    ## [1] 0

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S1B: Screening Spirometry with BD

    ## Initializing the session

    ## [1] 0

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S1C: CDQ ≥17 points and Screening Spirometry with BD

    ## Initializing the session

    ## [1] 0

    ## [1] 0

    ## Terminating the session

    ## [1] 0

| Scenario  |   Agents | PatientYears |   CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |     Mild | Moderate |  Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |     NoCOPD |    GOLD1 |    GOLD2 |    GOLD3 |   GOLD4 |         Cost | CostpAgent |      QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |     ICER | IncrementalNMB |
| :-------- | -------: | -----------: | --------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | -------: | -------: | ------: | ---------: | -----: | ---------: | -------: | -----------: | ---------: | -------: | -------: | -------: | ------: | -----------: | ---------: | --------: | ---------: | -------: | ---------------: | --------------: | -------: | -------------: |
| S1NoCD    | 74388747 |   1251903576 | 142277086 |       381929878 |     26336153 |         26747209 | 0.017 | 0.135 |    0.151 |       0.080 | 30809289 |  5766720 | 9701609 |   839538.0 |  0.217 |      0.041 |    0.068 |        0.006 | 1054811684 | 57697202 | 61465410 | 13763906 | 2389153 | 138701936801 |   1864.555 | 829008490 |     11.144 | 555349.1 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCD2   | 74388425 |   1251968458 | 142302175 |       249329256 |     26636736 |         32661650 | 0.021 | 0.136 |    0.151 |       0.080 | 30801067 |  5759155 | 9700407 |   837363.0 |  0.216 |      0.040 |    0.068 |        0.006 | 1054852003 | 57672835 | 61488796 | 13791895 | 2388663 | 138942645767 |   1867.799 | 829048977 |     11.145 | 555375.5 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCDAvg | 74388586 |   1251936017 | 142289630 |       315629567 |     26486444 |         29704430 | 0.019 | 0.136 |    0.151 |       0.080 | 30805178 |  5762938 | 9701008 |   838450.5 |  0.216 |      0.041 |    0.068 |        0.006 | 1054831844 | 57685018 | 61477103 | 13777900 | 2388908 | 138822291284 |   1866.177 | 829028734 |     11.145 | 555362.3 |            0.000 |           0.000 |      NaN |          0.000 |
| S1a       | 74380275 |   1252107231 | 142568770 |       372100831 |     66270673 |         26745802 | 0.026 | 0.159 |    0.310 |       0.094 | 29815042 |  5625494 | 9500837 |   824680.0 |  0.209 |      0.039 |    0.067 |        0.006 | 1054730269 | 57758498 | 61574433 | 13835312 | 2423951 | 157886317266 |   2122.691 | 829882713 |     11.157 | 555742.1 |          258.135 |           0.013 | 19821.86 |        393.003 |
| S1b       | 74383024 |   1252030978 | 142410670 |       376764647 |     47607118 |         26748888 | 0.022 | 0.148 |    0.241 |       0.088 | 30192660 |  5683507 | 9596337 |   830158.0 |  0.212 |      0.040 |    0.067 |        0.006 | 1054810413 | 57710159 | 61499603 | 13827904 | 2405886 | 152914677120 |   2055.774 | 829494032 |     11.152 | 555527.1 |          191.219 |           0.007 | 25892.74 |        178.033 |
| S1c       | 74393892 |   1252166867 | 142379318 |       378416895 |     41063274 |         26758496 | 0.020 | 0.144 |    0.214 |       0.085 | 30350312 |  5702044 | 9621386 |   828456.0 |  0.213 |      0.040 |    0.068 |        0.006 | 1054965444 | 57726777 | 61483651 | 13803995 | 2400849 | 154475292879 |   2076.451 | 829462690 |     11.150 | 555403.9 |          211.896 |           0.005 | 39721.03 |         54.834 |

*Treatment rate:* SABA is expressed per all patient-years, LAMA,
LAMA/LABA, ICS/LAMA/LABA are per COPD patient-years *Exacerbations:*
Total exacerbations and rate per COPD patient-year: *GOLD Stage:*
Cumulative patient-years *Cost/QALY:* Total cost and QALYs *NMB:* Net
Monetary Benefit is calculated as QALY per patient-year \* Lamba - Cost
per patient-year

-----

## S2 Symptomatic patients scenario

Patients with symptoms at year 1 are eligible. The cost of case
detection is:

    ## Initializing the session

    ## [1] 0

| None | FlowMeter |
| ---: | --------: |
|    0 |     24.33 |

#### S2NoCD: No Case detection

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S2a: Screening Spirometry without BD

    ## Initializing the session

    ## [1] 0

    ## [1] 0

    ## Terminating the session

    ## [1] 0

| Scenario |   Agents | PatientYears |   CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |     Mild | Moderate |  Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |    NoCOPD |    GOLD1 |    GOLD2 |    GOLD3 |   GOLD4 |         Cost | CostpAgent |      QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |     ICER | IncrementalNMB |
| :------- | -------: | -----------: | --------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | -------: | -------: | ------: | ---------: | -----: | ---------: | -------: | -----------: | --------: | -------: | -------: | -------: | ------: | -----------: | ---------: | --------: | ---------: | -------: | ---------------: | --------------: | -------: | -------------: |
| S2NoCD   | 44156404 |    729084497 | 100330760 |       221928932 |     19330952 |         15481473 | 0.017 | 0.142 |    0.159 |       0.087 | 22917076 |  4253860 | 7098458 |     609501 |  0.228 |      0.042 |    0.071 |        0.006 | 597619551 | 37246010 | 44990133 | 11123560 | 2050468 | 102511836117 |   2321.562 | 481847558 |     10.912 | 543293.0 |            0.000 |            0.00 |      NaN |          0.000 |
| S2a      | 44164773 |    729329891 | 100492049 |       217625447 |     37010683 |         15485858 | 0.023 | 0.157 |    0.269 |       0.097 | 22383331 |  4181008 | 7006346 |     603148 |  0.223 |      0.042 |    0.070 |        0.006 | 597700094 | 37284225 | 45068617 | 11147317 | 2064302 | 111527223359 |   2525.253 | 482358789 |     10.922 | 543564.7 |          203.691 |            0.01 | 21423.74 |        271.695 |

*Treatment rate:* SABA is expressed per all patient-years, LAMA,
LAMA/LABA, ICS/LAMA/LABA are per COPD patient-years *Exacerbations:*
Total exacerbations and rate per COPD patient-year: *GOLD Stage:*
Cumulative patient-years *Cost/QALY:* Total cost and QALYs *NMB:* Net
Monetary Benefit is calculated as QALY per patient-year \* Lamba - Cost
per patient-year

-----

## S3 Smoking history scenario

Ever smokers ≥50 years of age are eligible. The cost of case detection
is:

    ## Initializing the session

    ## [1] 0

| None | CDQ195 | CDQ165 | FlowMeter | FlowMeter\_CDQ |
| ---: | -----: | -----: | --------: | -------------: |
|    0 |  11.56 |  11.56 |     24.33 |          42.01 |

#### S3NoCD: No Case detection

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S3a: CDQ ≥19.5 points

    ## Initializing the session

    ## [1] 0

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S3b: CDQ ≥16.5 points

    ## Initializing the session

    ## [1] 0

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S3c: Screening spirometry without BD

    ## Initializing the session

    ## [1] 0

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S3d: Screening Spirometry with BD + CDQ ≥17 points

    ## Initializing the session

    ## [1] 0

    ## [1] 0

    ## Terminating the session

    ## [1] 0

| Scenario |   Agents | PatientYears |  CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |     Mild | Moderate |  Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |    NoCOPD |    GOLD1 |    GOLD2 |   GOLD3 |   GOLD4 |        Cost | CostpAgent |      QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |     ICER | IncrementalNMB |
| :------- | -------: | -----------: | -------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | -------: | -------: | ------: | ---------: | -----: | ---------: | -------: | -----------: | --------: | -------: | -------: | ------: | ------: | ----------: | ---------: | --------: | ---------: | -------: | ---------------: | --------------: | -------: | -------------: |
| S3NoCD   | 34500334 |    520264617 | 83469550 |       160191877 |     15617539 |         11630123 | 0.018 | 0.137 |    0.154 |       0.086 | 19525292 |  3631989 | 6073558 |     522424 |  0.234 |      0.044 |    0.073 |        0.006 | 415002016 | 30608834 | 37422882 | 9624470 | 1788687 | 87147515108 |   2525.990 | 346536202 |     10.044 | 499695.5 |            0.000 |           0.000 |      NaN |          0.000 |
| S3a      | 34507415 |    520428951 | 83482576 |       158676520 |     22030098 |         11639538 | 0.021 | 0.144 |    0.204 |       0.091 | 19287934 |  3609226 | 6045313 |     521405 |  0.231 |      0.043 |    0.072 |        0.006 | 415152628 | 30610103 | 37407716 | 9641236 | 1794702 | 92759974976 |   2688.117 | 346780020 |     10.049 | 499783.6 |          162.127 |           0.005 | 32396.01 |         88.100 |
| S3b      | 34499539 |    520396932 | 83618002 |       155590263 |     34428826 |         11625591 | 0.027 | 0.156 |    0.293 |       0.099 | 18988453 |  3564625 | 5980823 |     516662 |  0.227 |      0.043 |    0.072 |        0.006 | 414988556 | 30607762 | 37472866 | 9688489 | 1813970 | 96533122891 |   2798.099 | 346983955 |     10.058 | 500083.9 |          272.108 |           0.013 | 20598.68 |        388.391 |
| S3c      | 34496334 |    520227370 | 83568351 |       157099275 |     28171361 |         11622564 | 0.024 | 0.150 |    0.249 |       0.095 | 19145218 |  3585036 | 6010150 |     518449 |  0.229 |      0.043 |    0.072 |        0.006 | 414875686 | 30589301 | 37479876 | 9661353 | 1804425 | 94096368027 |   2727.721 | 346758704 |     10.052 | 499874.5 |          201.730 |           0.008 | 26492.17 |        179.005 |
| S3d      | 34507664 |    520495018 | 83555471 |       157877292 |     25364366 |         11630839 | 0.023 | 0.147 |    0.229 |       0.093 | 19209915 |  3595849 | 6028084 |     520340 |  0.230 |      0.043 |    0.072 |        0.006 | 415141325 | 30594930 | 37472224 | 9653084 | 1805226 | 94690116842 |   2744.031 | 346877136 |     10.052 | 499864.8 |          218.041 |           0.008 | 28147.56 |        169.277 |

*Treatment rate:* SABA is expressed per all patient-years, LAMA,
LAMA/LABA, ICS/LAMA/LABA are per COPD patient-years *Exacerbations:*
Total exacerbations and rate per COPD patient-year *GOLD Stage:*
Cumulative patient-years *Cost/QALY:* Total cost and QALYs *NMB:* Net
Monetary Benefit is calculated as QALY per patient-year \* Lamba - Cost
per patient-year

-----

## All Scenarios

*Ordered by descending Net Monetary Benefit*

| Scenario |   Agents |         Cost | CostpAgent |      QALY | QALYpAgent |     ICER | IncrementalNMB |
| :------- | -------: | -----------: | ---------: | --------: | ---------: | -------: | -------------: |
| S1a      | 74380275 | 157886317266 |   2122.691 | 829882713 |     11.157 | 19821.86 |        393.003 |
| S3b      | 34499539 |  96533122891 |   2798.099 | 346983955 |     10.058 | 20598.68 |        388.391 |
| S2a      | 44164773 | 111527223359 |   2525.253 | 482358789 |     10.922 | 21423.74 |        271.695 |
| S3c      | 34496334 |  94096368027 |   2727.721 | 346758704 |     10.052 | 26492.17 |        179.005 |
| S1b      | 74383024 | 152914677120 |   2055.774 | 829494032 |     11.152 | 25892.74 |        178.033 |
| S3d      | 34507664 |  94690116842 |   2744.031 | 346877136 |     10.052 | 28147.56 |        169.277 |
| S3a      | 34507415 |  92759974976 |   2688.117 | 346780020 |     10.049 | 32396.01 |         88.100 |
| S1c      | 74393892 | 154475292879 |   2076.451 | 829462690 |     11.150 | 39721.03 |         54.834 |
| S1NoCD   | 74388747 | 138701936801 |   1864.555 | 829008490 |     11.144 |      NaN |          0.000 |
| S2NoCD   | 44156404 | 102511836117 |   2321.562 | 481847558 |     10.912 |      NaN |          0.000 |
| S3NoCD   | 34500334 |  87147515108 |   2525.990 | 346536202 |     10.044 |      NaN |          0.000 |

-----

## Cost Effectiveness Plane

Adjusted to the total population

| Scenario  |   Agents | PropAgents |         Cost | CostpAgent | CostpAgentExcluded | CostpAgentAll |      QALY | QALYpAgent | QALYpAgentExcluded | QALYpAgentAll | IncrementalCosts | IncrementalQALY |  ICERAdj |     ICER |      INMB |
| :-------- | -------: | ---------: | -----------: | ---------: | -----------------: | ------------: | --------: | ---------: | -----------------: | ------------: | ---------------: | --------------: | -------: | -------: | --------: |
| S1NoCDAvg | 74388586 |  1.0000000 | 138822291284 |   1866.177 |              0.000 |      1866.177 | 829028734 |   11.14457 |            0.00000 |      11.14457 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.00000 |
| S1a       | 74380275 |  1.0000000 | 157886317266 |   2122.691 |              0.000 |      2122.691 | 829882713 |   11.15730 |            0.00000 |      11.15730 |        256.51338 |       0.0127265 | 20155.83 | 19821.86 | 379.81226 |
| S1b       | 74383024 |  1.0000000 | 152914677120 |   2055.774 |              0.000 |      2055.774 | 829494032 |   11.15166 |            0.00000 |      11.15166 |        189.59656 |       0.0070888 | 26746.02 | 25892.74 | 164.84224 |
| S1c       | 74393892 |  1.0000000 | 154475292879 |   2076.451 |              0.000 |      2076.451 | 829462690 |   11.14961 |            0.00000 |      11.14961 |        210.27398 |       0.0050384 | 41734.64 | 39721.03 |  41.64381 |
| S2NoCD    | 44156404 |  0.5935911 | 102511836117 |   2321.562 |           1201.053 |      1866.177 | 481847558 |   10.91229 |           11.48383 |      11.14457 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.00000 |
| S2a       | 44164773 |  0.5937036 | 111527223359 |   2525.253 |           1201.053 |      1987.235 | 482358789 |   10.92180 |           11.48383 |      11.15015 |        121.05803 |       0.0055805 | 21693.18 | 21423.74 | 157.96518 |
| S3NoCD    | 34500334 |  0.4637853 |  87147515108 |   2525.990 |           1295.489 |      1866.177 | 346536202 |   10.04443 |           12.09611 |      11.14457 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.00000 |
| S3a       | 34507415 |  0.4638805 |  92759974976 |   2688.117 |           1295.489 |      1941.502 | 346780020 |   10.04943 |           12.09611 |      11.14670 |         75.32455 |       0.0021262 | 35426.76 | 32396.01 |  30.98570 |
| S3b       | 34499539 |  0.4637746 |  96533122891 |   2798.099 |           1295.489 |      1992.361 | 346983955 |   10.05764 |           12.09611 |      11.15072 |        126.18384 |       0.0061484 | 20523.09 | 20598.68 | 181.23543 |
| S3c       | 34496334 |  0.4637315 |  94096368027 |   2727.721 |           1295.489 |      1959.660 | 346758704 |   10.05205 |           12.09611 |      11.14821 |         93.48255 |       0.0036415 | 25671.40 | 26492.17 |  88.59273 |
| S3d       | 34507664 |  0.4638839 |  94690116842 |   2744.031 |           1295.489 |      1967.444 | 346877136 |   10.05218 |           12.09611 |      11.14796 |        101.26696 |       0.0033912 | 29861.30 | 28147.56 |  68.29524 |

![](../../outputs/Sen7_3_Discount_CEplot-1.png)<!-- -->

## Clinical Results for all scenarios

Adjusted to the total population

| Scenario  | PropAgents | ProppPatientYears | ProppCopdPYs |   SABAAll |   LAMAAll | LAMALABAAll | ICSLAMALABAAll | MildpAgentAll | ModeratepAgentAll | SeverepAgentAll | VerySeverepAgentAll | NoCOPDpPYAll | GOLD1pPYAll | GOLD2pPYAll | GOLD3pPYAll | GOLD4pPYAll | DiagnosedpPYAll |
| :-------- | ---------: | ----------------: | -----------: | --------: | --------: | ----------: | -------------: | ------------: | ----------------: | --------------: | ------------------: | -----------: | ----------: | ----------: | ----------: | ----------: | --------------: |
| S1NoCDAvg |  1.0000000 |         1.0000000 |    1.0000000 | 0.0190054 | 0.1355252 |   0.1513708 |      0.0796683 |     0.4141116 |         0.0774707 |       0.1304099 |           0.0112712 |    0.8425605 |   0.0460767 |   0.0491056 |   0.0110053 |   0.0019082 |       0.1861446 |
| S1a       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0264033 | 0.1593018 |   0.3099946 |      0.0940914 |     0.4008461 |         0.0756315 |       0.1277333 |           0.0110873 |    0.8423642 |   0.0461290 |   0.0491766 |   0.0110496 |   0.0019359 |       0.4648330 |
| S1b       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0216398 | 0.1482342 |   0.2406521 |      0.0877947 |     0.4059079 |         0.0764087 |       0.1290125 |           0.0111606 |    0.8424795 |   0.0460932 |   0.0491199 |   0.0110444 |   0.0019216 |       0.3342946 |
| S1c       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0201517 | 0.1441110 |   0.2141912 |      0.0851720 |     0.4079678 |         0.0766467 |       0.1293303 |           0.0111361 |    0.8425119 |   0.0461015 |   0.0491018 |   0.0110241 |   0.0019174 |       0.2884076 |
| S2NoCD    |  0.5935911 |         0.5823656 |    0.7051165 | 0.0190054 | 0.1355252 |   0.1513708 |      0.0796683 |     0.4141116 |         0.0774707 |       0.1304099 |           0.0112712 |    0.8425605 |   0.0460767 |   0.0491056 |   0.0110053 |   0.0019082 |       0.1861446 |
| S2a       |  0.5937036 |         0.5825616 |    0.7062500 | 0.0223572 | 0.1465203 |   0.2287835 |      0.0867962 |     0.4069072 |         0.0764858 |       0.1291620 |           0.0111850 |    0.8424534 |   0.0460995 |   0.0491621 |   0.0110233 |   0.0019191 |       0.3102030 |
| S3NoCD    |  0.4637853 |         0.4155681 |    0.5866172 | 0.0190054 | 0.1355252 |   0.1513708 |      0.0796683 |     0.4141116 |         0.0774707 |       0.1304099 |           0.0112712 |    0.8425605 |   0.0460767 |   0.0491056 |   0.0110053 |   0.0019082 |       0.1861446 |
| S3a       |  0.4638805 |         0.4156993 |    0.5867088 | 0.0201156 | 0.1395918 |   0.1808230 |      0.0824771 |     0.4108939 |         0.0771596 |       0.1300215 |           0.0112568 |    0.8425660 |   0.0460728 |   0.0490892 |   0.0110179 |   0.0019129 |       0.2311946 |
| S3b       |  0.4637746 |         0.4156737 |    0.5876605 | 0.0227032 | 0.1471017 |   0.2332507 |      0.0873282 |     0.4068980 |         0.0765657 |       0.1291642 |           0.0111939 |    0.8424573 |   0.0460719 |   0.0491421 |   0.0110558 |   0.0019283 |       0.3181560 |
| S3c       |  0.4637315 |         0.4155383 |    0.5873116 | 0.0213262 | 0.1432680 |   0.2074859 |      0.0848645 |     0.4090175 |         0.0768424 |       0.1295624 |           0.0112182 |    0.8424856 |   0.0460621 |   0.0491521 |   0.0110349 |   0.0019208 |       0.2742435 |
| S3d       |  0.4638839 |         0.4157521 |    0.5872211 | 0.0207546 | 0.1415673 |   0.1954816 |      0.0837051 |     0.4098442 |         0.0769796 |       0.1297896 |           0.0112424 |    0.8425108 |   0.0460587 |   0.0491390 |   0.0110271 |   0.0019212 |       0.2545329 |

## Time elapsed

Run time for this notebook:

``` r
end.time <- Sys.time()
time.taken <- end.time - start.time
time.taken
```

    ## Time difference of 1.217285 days
