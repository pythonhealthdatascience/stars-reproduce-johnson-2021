Sensitivity analysis: No Smoking Cessation
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
outputs <- "../../outputs/Sen1_No_Smoking_Cessation"
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
  - Smoking adherence is 0
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
| S1NoCD    | 74397625 |   1251888615 | 142400097 |       381936924 |     26358454 |         26783324 | 0.017 | 0.135 |    0.151 |       0.080 | 30847754 |  5758388 | 9691126 |     836590 |  0.217 |      0.040 |    0.068 |        0.006 | 1054688429 | 57727616 | 61505481 | 13799186 | 2398591 | 159124648209 |   2138.840 | 933200651 |     12.543 | 625032.2 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCD2   | 74394066 |   1251871999 | 142377758 |       249324170 |     26617487 |         32718146 | 0.021 | 0.135 |    0.151 |       0.080 | 30874590 |  5768744 | 9690479 |     835272 |  0.217 |      0.041 |    0.068 |        0.006 | 1054693564 | 57729618 | 61465178 | 13817742 | 2397911 | 159276748461 |   2140.987 | 933192471 |     12.544 | 625054.5 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCDAvg | 74395846 |   1251880307 | 142388928 |       315630547 |     26487970 |         29750735 | 0.019 | 0.135 |    0.151 |       0.080 | 30861172 |  5763566 | 9690802 |     835931 |  0.217 |      0.040 |    0.068 |        0.006 | 1054690996 | 57728617 | 61485330 | 13808464 | 2398251 | 159200698335 |   2139.914 | 933196561 |     12.544 | 625043.3 |            0.000 |           0.000 |      NaN |          0.000 |
| S1a       | 74394771 |   1252091491 | 142557438 |       372128624 |     66213412 |         26771781 | 0.026 | 0.159 |    0.310 |       0.094 | 29914376 |  5620783 | 9479364 |     819537 |  0.210 |      0.039 |    0.066 |        0.006 | 1054733720 | 57720098 | 61584515 | 13858892 | 2416178 | 180319782953 |   2423.823 | 934242431 |     12.558 | 625471.4 |          284.983 |           0.014 | 19674.89 |        439.247 |
| S1b       | 74384118 |   1251703447 | 142505867 |       376679454 |     47607164 |         26787921 | 0.022 | 0.148 |    0.240 |       0.088 | 30296542 |  5680532 | 9581587 |     826935 |  0.213 |      0.040 |    0.067 |        0.006 | 1054408482 | 57730018 | 61529087 | 13855676 | 2416625 | 174899343545 |   2351.300 | 933542720 |     12.550 | 625163.5 |          212.459 |           0.007 | 30896.97 |        131.360 |
| S1c       | 74390209 |   1251828104 | 142354152 |       378340031 |     41045426 |         26779722 | 0.020 | 0.144 |    0.214 |       0.085 | 30433623 |  5703967 | 9612703 |     829564 |  0.214 |      0.040 |    0.068 |        0.006 | 1054672194 | 57623840 | 61512975 | 13840093 | 2409156 | 176728465906 |   2375.695 | 933496178 |     12.549 | 625056.5 |          236.855 |           0.005 | 45347.36 |         24.301 |

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
| S2NoCD   | 44166055 |    729117912 | 100405688 |       221954036 |     19343537 |         15478949 | 0.017 | 0.141 |    0.159 |       0.087 | 22957271 |  4249333 | 7089574 |     607905 |  0.229 |      0.042 |    0.071 |        0.006 | 597585749 | 37297625 | 44999354 | 11122450 | 2059355 | 117144112006 |   2652.356 | 541887056 |     12.269 | 610813.2 |            0.000 |            0.00 |      NaN |          0.000 |
| S2a      | 44161595 |    729112649 | 100432995 |       217571137 |     37001975 |         15492083 | 0.023 | 0.157 |    0.269 |       0.097 | 22424977 |  4176799 | 6987343 |     599803 |  0.223 |      0.042 |    0.070 |        0.006 | 597552506 | 37218775 | 45066339 | 11152095 | 2067861 | 127021423440 |   2876.287 | 542294220 |     12.280 | 611112.2 |          223.931 |            0.01 | 21410.38 |        299.018 |

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

| Scenario |   Agents | PatientYears |  CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |     Mild | Moderate |  Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |    NoCOPD |    GOLD1 |    GOLD2 |   GOLD3 |   GOLD4 |         Cost | CostpAgent |      QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |     ICER | IncrementalNMB |
| :------- | -------: | -----------: | -------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | -------: | -------: | ------: | ---------: | -----: | ---------: | -------: | -----------: | --------: | -------: | -------: | ------: | ------: | -----------: | ---------: | --------: | ---------: | -------: | ---------------: | --------------: | -------: | -------------: |
| S3NoCD   | 34500349 |    520094995 | 83461691 |       160143901 |     15618828 |         11654651 | 0.018 | 0.137 |    0.154 |       0.086 | 19547537 |  3636418 | 6069919 |     520617 |  0.234 |      0.044 |    0.073 |        0.006 | 414853261 | 30586952 | 37418093 | 9635730 | 1793033 |  99418734054 |   2881.673 | 387394495 |     11.229 | 558553.9 |            0.000 |           0.000 |      NaN |          0.000 |
| S3a      | 34498365 |    520044251 | 83543965 |       158570002 |     22025358 |         11641972 | 0.021 | 0.143 |    0.204 |       0.090 | 19349214 |  3610114 | 6036237 |     518479 |  0.232 |      0.043 |    0.072 |        0.006 | 414726752 | 30585780 | 37465015 | 9656171 | 1804975 | 105579216551 |   3060.412 | 387503366 |     11.233 | 558565.3 |          178.739 |           0.004 | 47016.76 |         11.341 |
| S3b      | 34505121 |    520325831 | 83596107 |       155591308 |     34370572 |         11646287 | 0.027 | 0.155 |    0.292 |       0.099 | 19045362 |  3554737 | 5952719 |     512271 |  0.228 |      0.043 |    0.071 |        0.006 | 414946581 | 30589147 | 37475808 | 9683238 | 1812590 | 109490006079 |   3173.152 | 387996999 |     11.245 | 559057.9 |          291.479 |           0.016 | 18322.35 |        503.940 |
| S3c      | 34505668 |    520264309 | 83596889 |       157131912 |     28149353 |         11644831 | 0.024 | 0.149 |    0.249 |       0.095 | 19179049 |  3582497 | 6000047 |     515697 |  0.229 |      0.043 |    0.072 |        0.006 | 414890025 | 30618993 | 37472630 | 9661994 | 1807193 | 107022937523 |   3101.605 | 387810723 |     11.239 | 558850.6 |          219.931 |           0.010 | 21287.01 |        296.654 |
| S3d      | 34507875 |    520253275 | 83509443 |       157815894 |     25352833 |         11646210 | 0.023 | 0.146 |    0.229 |       0.093 | 19265713 |  3593496 | 6016041 |     515763 |  0.231 |      0.043 |    0.072 |        0.006 | 414960418 | 30586470 | 37432733 | 9658194 | 1800918 | 107608997577 |   3118.390 | 387745308 |     11.236 | 558703.1 |          236.716 |           0.008 | 30673.67 |        149.146 |

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
| S3b      | 34505121 | 109490006079 |   3173.152 | 387996999 |     11.245 | 18322.35 |        503.940 |
| S1a      | 74394771 | 180319782953 |   2423.823 | 934242431 |     12.558 | 19674.89 |        439.247 |
| S2a      | 44161595 | 127021423440 |   2876.287 | 542294220 |     12.280 | 21410.38 |        299.018 |
| S3c      | 34505668 | 107022937523 |   3101.605 | 387810723 |     11.239 | 21287.01 |        296.654 |
| S3d      | 34507875 | 107608997577 |   3118.390 | 387745308 |     11.236 | 30673.67 |        149.146 |
| S1b      | 74384118 | 174899343545 |   2351.300 | 933542720 |     12.550 | 30896.97 |        131.360 |
| S1c      | 74390209 | 176728465906 |   2375.695 | 933496178 |     12.549 | 45347.36 |         24.301 |
| S3a      | 34498365 | 105579216551 |   3060.412 | 387503366 |     11.233 | 47016.76 |         11.341 |
| S1NoCD   | 74397625 | 159124648209 |   2138.840 | 933200651 |     12.543 |      NaN |          0.000 |
| S2NoCD   | 44166055 | 117144112006 |   2652.356 | 541887056 |     12.269 |      NaN |          0.000 |
| S3NoCD   | 34500349 |  99418734054 |   2881.673 | 387394495 |     11.229 |      NaN |          0.000 |

-----

## Cost Effectiveness Plane

Adjusted to the total population

| Scenario  |   Agents | PropAgents |         Cost | CostpAgent | CostpAgentExcluded | CostpAgentAll |      QALY | QALYpAgent | QALYpAgentExcluded | QALYpAgentAll | IncrementalCosts | IncrementalQALY |  ICERAdj |     ICER |        INMB |
| :-------- | -------: | ---------: | -----------: | ---------: | -----------------: | ------------: | --------: | ---------: | -----------------: | ------------: | ---------------: | --------------: | -------: | -------: | ----------: |
| S1NoCDAvg | 74395846 |  1.0000000 | 159200698335 |   2139.914 |              0.000 |      2139.914 | 933196561 |   12.54367 |            0.00000 |      12.54367 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.0000000 |
| S1a       | 74394771 |  1.0000000 | 180319782953 |   2423.823 |              0.000 |      2423.823 | 934242431 |   12.55790 |            0.00000 |      12.55790 |        283.90952 |       0.0142395 | 19938.10 | 19674.89 | 428.0679251 |
| S1b       | 74384118 |  1.0000000 | 174899343545 |   2351.300 |              0.000 |      2351.300 | 933542720 |   12.55030 |            0.00000 |      12.55030 |        211.38573 |       0.0066313 | 31876.86 | 30896.97 | 120.1803646 |
| S1c       | 74390209 |  1.0000000 | 176728465906 |   2375.695 |              0.000 |      2375.695 | 933496178 |   12.54864 |            0.00000 |      12.54864 |        235.78142 |       0.0049781 | 47364.02 | 45347.36 |  13.1220799 |
| S2NoCD    | 44166055 |  0.5936629 | 117144112006 |   2652.356 |           1391.230 |      2139.914 | 541887056 |   12.26931 |           12.94450 |      12.54366 |          0.00000 |       0.0000000 |      NaN |      NaN | \-0.0042008 |
| S2a       | 44161595 |  0.5936030 | 127021423440 |   2876.287 |           1391.230 |      2272.764 | 542294220 |   12.27977 |           12.94450 |      12.54991 |        132.85038 |       0.0062490 | 21259.60 | 21410.38 | 179.5934649 |
| S3NoCD    | 34500349 |  0.4637403 |  99418734054 |   2881.673 |           1498.464 |      2139.914 | 387394495 |   11.22871 |           13.68079 |      12.54366 |          0.00000 |       0.0000000 |      NaN |      NaN | \-0.0042008 |
| S3a       | 34498365 |  0.4637136 | 105579216551 |   3060.412 |           1498.464 |      2222.761 | 387503366 |   11.23251 |           13.68079 |      12.54549 |         82.84677 |       0.0018282 | 45314.89 | 47016.76 |   8.5613330 |
| S3b       | 34505121 |  0.4638044 | 109490006079 |   3173.152 |           1498.464 |      2275.192 | 387996999 |   11.24462 |           13.68079 |      12.55089 |        135.27800 |       0.0072211 | 18733.72 | 18322.35 | 225.7726271 |
| S3c       | 34505668 |  0.4638118 | 107022937523 |   3101.605 |           1498.464 |      2242.019 | 387810723 |   11.23904 |           13.68079 |      12.54828 |        102.10561 |       0.0046167 | 22116.79 | 21287.02 | 128.7229448 |
| S3d       | 34507875 |  0.4638414 | 107608997577 |   3118.390 |           1498.464 |      2249.853 | 387745308 |   11.23643 |           13.68079 |      12.54700 |        109.93875 |       0.0033315 | 32999.56 | 30673.67 |  56.6331517 |

![](../../outputs/Sen1_No_Smoking_Cessation_CEplot-1.png)<!-- -->

## Clinical Results for all scenarios

Adjusted to the total population

| Scenario  | PropAgents | ProppPatientYears | ProppCopdPYs |   SABAAll |   LAMAAll | LAMALABAAll | ICSLAMALABAAll | MildpAgentAll | ModeratepAgentAll | SeverepAgentAll | VerySeverepAgentAll | NoCOPDpPYAll | GOLD1pPYAll | GOLD2pPYAll | GOLD3pPYAll | GOLD4pPYAll | DiagnosedpPYAll |
| :-------- | ---------: | ----------------: | -----------: | --------: | --------: | ----------: | -------------: | ------------: | ----------------: | --------------: | ------------------: | -----------: | ----------: | ----------: | ----------: | ----------: | --------------: |
| S1NoCDAvg |  1.0000000 |         1.0000000 |    1.0000000 | 0.0190473 | 0.1352836 |   0.1511410 |      0.0795532 |     0.4148239 |         0.0774716 |       0.1302600 |           0.0112363 |    0.8424855 |   0.0461135 |   0.0491144 |   0.0110302 |   0.0019157 |       0.1860255 |
| S1a       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0264236 | 0.1585082 |   0.3095994 |      0.0937869 |     0.4021032 |         0.0755535 |       0.1274198 |           0.0110161 |    0.8423775 |   0.0460989 |   0.0491853 |   0.0110686 |   0.0019297 |       0.4644683 |
| S1b       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0216557 | 0.1477093 |   0.2403393 |      0.0875356 |     0.4072985 |         0.0763675 |       0.1288123 |           0.0111171 |    0.8423788 |   0.0461212 |   0.0491563 |   0.0110695 |   0.0019307 |       0.3340716 |
| S1c       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0201669 | 0.1439219 |   0.2141501 |      0.0851948 |     0.4091079 |         0.0766763 |       0.1292200 |           0.0111515 |    0.8425056 |   0.0460318 |   0.0491385 |   0.0110559 |   0.0019245 |       0.2883332 |
| S2NoCD    |  0.5936629 |         0.5824182 |    0.7051510 | 0.0190473 | 0.1352836 |   0.1511410 |      0.0795532 |     0.4148239 |         0.0774716 |       0.1302600 |           0.0112363 |    0.8424855 |   0.0461135 |   0.0491144 |   0.0110302 |   0.0019157 |       0.1860255 |
| S2a       |  0.5936030 |         0.5824140 |    0.7053427 | 0.0224080 | 0.1461094 |   0.2285254 |      0.0866425 |     0.4076846 |         0.0764996 |       0.1288910 |           0.0111278 |    0.8424626 |   0.0460507 |   0.0491680 |   0.0110539 |   0.0019225 |       0.3100084 |
| S3NoCD    |  0.4637403 |         0.4154511 |    0.5861530 | 0.0190473 | 0.1352836 |   0.1511410 |      0.0795532 |     0.4148239 |         0.0774716 |       0.1302600 |           0.0112363 |    0.8424855 |   0.0461135 |   0.0491144 |   0.0110302 |   0.0019157 |       0.1860255 |
| S3a       |  0.4637136 |         0.4154105 |    0.5867308 | 0.0201580 | 0.1390265 |   0.1803887 |      0.0821315 |     0.4121656 |         0.0771195 |       0.1298097 |           0.0112077 |    0.8424199 |   0.0461141 |   0.0491532 |   0.0110467 |   0.0019253 |       0.2309121 |
| S3b       |  0.4638044 |         0.4156354 |    0.5870970 | 0.0227316 | 0.1462341 |   0.2324623 |      0.0869039 |     0.4080556 |         0.0763703 |       0.1286788 |           0.0111236 |    0.8423988 |   0.0461084 |   0.0491544 |   0.0110671 |   0.0019312 |       0.3175452 |
| S3c       |  0.4638118 |         0.4155863 |    0.5871025 | 0.0213685 | 0.1426453 |   0.2068680 |      0.0845367 |     0.4098505 |         0.0767430 |       0.1293143 |           0.0111696 |    0.8423966 |   0.0461341 |   0.0491535 |   0.0110504 |   0.0019269 |       0.2738525 |
| S3d       |  0.4638414 |         0.4155775 |    0.5864883 | 0.0207967 | 0.1410580 |   0.1950703 |      0.0834919 |     0.4110070 |         0.0768893 |       0.1295266 |           0.0111702 |    0.8424605 |   0.0461085 |   0.0491219 |   0.0110474 |   0.0019219 |       0.2543257 |

## Time elapsed

Run time for this notebook:

``` r
end.time <- Sys.time()
time.taken <- end.time - start.time
time.taken
```

    ## Time difference of 1.275262 days
