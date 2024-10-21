Sensitivity analysis: 0% Discount Rate
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
outputs <- "../../outputs/Sen6_0_Discount"
files <- list(
  s1 = "s1_5y.csv",
  s2 = "s2_5y.csv",
  s3 = "s3_5y.csv",
  sall = "sall_5y.csv",
  ceplane = "ceplane_5y.csv",
  clinical = "clinicalresults_5y.csv"
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

  - Case detection occurs at 5 year intervals.
  - An outpatient diagnosis costs 61.18
  - The utility gain due to symptom relief from treatment is 0.0367

## S1 All patients scenario

All patients are eligible. The cost of case detection is:

| None | CDQ17 | FlowMeter | FlowMeter\_CDQ |
| ---: | ----: | --------: | -------------: |
|    0 | 11.56 |     30.46 |          42.01 |

#### S1NoCD2: No Case detection- Other time interval

    ## [1] 0

    ## Terminating the session

    ## [1] 0

#### S1NoCD: No Case detection

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

| Scenario  |   Agents | PatientYears |   CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |     Mild | Moderate |  Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |     NoCOPD |    GOLD1 |    GOLD2 |    GOLD3 |   GOLD4 |         Cost | CostpAgent |       QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |     ICER | IncrementalNMB |
| :-------- | -------: | -----------: | --------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | -------: | -------: | ------: | ---------: | -----: | ---------: | -------: | -----------: | ---------: | -------: | -------: | -------: | ------: | -----------: | ---------: | ---------: | ---------: | -------: | ---------------: | --------------: | -------: | -------------: |
| S1NoCD2   | 74388747 |   1251903576 | 142277086 |       381929878 |     26336153 |         26747209 | 0.017 | 0.135 |    0.151 |       0.080 | 30809289 |  5766720 | 9701609 |   839538.0 |  0.217 |      0.041 |    0.068 |        0.006 | 1054811684 | 57697202 | 61465410 | 13763906 | 2389153 | 185724530860 |   2496.675 | 1059845409 |     14.247 | 709872.8 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCD    | 74388425 |   1251968458 | 142302175 |       249329256 |     26636736 |         32661650 | 0.021 | 0.136 |    0.151 |       0.080 | 30801067 |  5759155 | 9700407 |   837363.0 |  0.216 |      0.040 |    0.068 |        0.006 | 1054852003 | 57672835 | 61488796 | 13791895 | 2388663 | 186033235253 |   2500.836 | 1059900380 |     14.248 | 709908.6 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCDAvg | 74388586 |   1251936017 | 142289630 |       315629567 |     26486444 |         29704430 | 0.019 | 0.136 |    0.151 |       0.080 | 30805178 |  5762938 | 9701008 |   838450.5 |  0.216 |      0.041 |    0.068 |        0.006 | 1054831844 | 57685018 | 61477103 | 13777900 | 2388908 | 185878883057 |   2498.755 | 1059872895 |     14.248 | 709890.7 |            0.000 |           0.000 |      NaN |          0.000 |
| S1a       | 74386318 |   1252092577 | 142511621 |       245523949 |     57058349 |         32655914 | 0.028 | 0.154 |    0.274 |       0.091 | 30028808 |  5656584 | 9558038 |   827432.0 |  0.211 |      0.040 |    0.067 |        0.006 | 1054768469 | 57752767 | 61521629 | 13851433 | 2413714 | 203290806711 |   2732.906 | 1060803037 |     14.261 | 710303.5 |          232.070 |           0.013 | 18508.89 |        394.845 |
| S1b       | 74385413 |   1252007176 | 142455061 |       247448362 |     41936466 |         32651747 | 0.024 | 0.145 |    0.216 |       0.086 | 30368698 |  5706469 | 9627370 |   832514.0 |  0.213 |      0.040 |    0.068 |        0.006 | 1054746061 | 57768304 | 61498391 | 13812986 | 2404656 | 198298896720 |   2665.830 | 1060342609 |     14.255 | 710069.7 |          164.995 |           0.007 | 25298.01 |        161.107 |
| S1c       | 74390720 |   1252048091 | 142295860 |       248074520 |     37009576 |         32668233 | 0.023 | 0.142 |    0.196 |       0.084 | 30456632 |  5715293 | 9646702 |   833108.0 |  0.214 |      0.040 |    0.068 |        0.006 | 1054933501 | 57690667 | 61453687 | 13794504 | 2396041 | 199278771241 |   2678.812 | 1060261851 |     14.253 | 709951.6 |          177.976 |           0.004 | 40270.48 |         43.000 |

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

| Scenario |   Agents | PatientYears |   CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |     Mild | Moderate |  Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |    NoCOPD |    GOLD1 |    GOLD2 |    GOLD3 |   GOLD4 |         Cost | CostpAgent |      QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |  ICER | IncrementalNMB |
| :------- | -------: | -----------: | --------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | -------: | -------: | ------: | ---------: | -----: | ---------: | -------: | -----------: | --------: | -------: | -------: | -------: | ------: | -----------: | ---------: | --------: | ---------: | -------: | ---------------: | --------------: | ----: | -------------: |
| S2NoCD   | 44157029 |    729047563 | 100380900 |       145000421 |     19524492 |         18863743 | 0.021 | 0.142 |    0.160 |       0.087 | 22925265 |  4254784 | 7099566 |     609563 |  0.228 |      0.042 |    0.071 |        0.006 | 597538799 | 37245010 | 45040554 | 11117169 | 2054803 | 136358873737 |   3088.045 | 614694012 |     13.921 | 692943.9 |            0.000 |           0.000 |   NaN |          0.000 |
| S2a      | 44154576 |    729145856 | 100448839 |       143361789 |     32595478 |         18878233 | 0.025 | 0.154 |    0.242 |       0.095 | 22519648 |  4200194 | 7025459 |     605531 |  0.224 |      0.042 |    0.070 |        0.006 | 597564735 | 37286040 | 45033303 | 11135908 | 2066352 | 144286219339 |   3267.752 | 615140303 |     13.932 | 693308.2 |          179.708 |           0.011 | 16516 |        364.334 |

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
| S3NoCD   | 34491937 |    520096794 | 83394436 |       104866546 |     15798844 |         14116443 | 0.022 | 0.137 |    0.154 |       0.086 | 19479590 |  3630576 | 6075819 |     523166 |  0.234 |      0.044 |    0.073 |        0.006 | 414917152 | 30599570 | 37365292 | 9614469 | 1790750 | 115570166575 |   3350.643 | 436927836 |     12.668 | 630026.1 |            0.000 |           0.000 |      NaN |          0.000 |
| S3a      | 34494037 |    520214111 | 83457293 |       104351592 |     20245608 |         14129448 | 0.024 | 0.142 |    0.189 |       0.089 | 19332282 |  3614629 | 6055063 |     518761 |  0.232 |      0.043 |    0.073 |        0.006 | 414968911 | 30599997 | 37426814 | 9615582 | 1787056 | 120160874413 |   3483.526 | 437149998 |     12.673 | 630176.7 |          132.883 |           0.006 | 23438.76 |        150.586 |
| S3b      | 34509196 |    520537138 | 83620081 |       103218767 |     29823148 |         14132996 | 0.029 | 0.152 |    0.258 |       0.096 | 19135380 |  3582069 | 6004729 |     516649 |  0.229 |      0.043 |    0.072 |        0.006 | 415119150 | 30640730 | 37483240 | 9661621 | 1802895 | 123796077467 |   3587.336 | 437667749 |     12.683 | 630544.7 |          236.693 |           0.015 | 15669.18 |        518.589 |
| S3c      | 34504471 |    520423616 | 83513343 |       103824096 |     24853847 |         14121585 | 0.026 | 0.146 |    0.223 |       0.093 | 19220385 |  3595075 | 6024956 |     518536 |  0.230 |      0.043 |    0.072 |        0.006 | 415113845 | 30619979 | 37421385 | 9639642 | 1802009 | 121485915694 |   3520.875 | 437449142 |     12.678 | 630381.2 |          170.232 |           0.011 | 16202.08 |        355.107 |
| S3d      | 34501231 |    520389346 | 83507084 |       104079260 |     22711874 |         14135933 | 0.025 | 0.144 |    0.207 |       0.091 | 19266710 |  3605577 | 6035420 |     519637 |  0.231 |      0.043 |    0.072 |        0.006 | 415086795 | 30631737 | 37413709 | 9638221 | 1794998 | 121822210448 |   3530.953 | 437363185 |     12.677 | 630306.1 |          180.310 |           0.009 | 19586.22 |        279.987 |

*Treatment rate:* SABA is expressed per all patient-years, LAMA,
LAMA/LABA, ICS/LAMA/LABA are per COPD patient-years *Exacerbations:*
Total exacerbations and rate per COPD patient-year *GOLD Stage:*
Cumulative patient-years *Cost/QALY:* Total cost and QALYs *NMB:* Net
Monetary Benefit is calculated as QALY per patient-year \* Lamba - Cost
per patient-year

-----

## All Scenarios

*Ordered by descending Net Monetary Benefit*

| Scenario |   Agents |         Cost | CostpAgent |       QALY | QALYpAgent |     ICER | IncrementalNMB |
| :------- | -------: | -----------: | ---------: | ---------: | ---------: | -------: | -------------: |
| S3b      | 34509196 | 123796077467 |   3587.336 |  437667749 |     12.683 | 15669.18 |        518.589 |
| S1a      | 74386318 | 203290806711 |   2732.906 | 1060803037 |     14.261 | 18508.89 |        394.845 |
| S2a      | 44154576 | 144286219339 |   3267.752 |  615140303 |     13.932 | 16516.00 |        364.334 |
| S3c      | 34504471 | 121485915694 |   3520.875 |  437449142 |     12.678 | 16202.08 |        355.107 |
| S3d      | 34501231 | 121822210448 |   3530.953 |  437363185 |     12.677 | 19586.22 |        279.987 |
| S1b      | 74385413 | 198298896720 |   2665.830 | 1060342609 |     14.255 | 25298.01 |        161.107 |
| S3a      | 34494037 | 120160874413 |   3483.526 |  437149998 |     12.673 | 23438.76 |        150.586 |
| S1c      | 74390720 | 199278771241 |   2678.812 | 1060261851 |     14.253 | 40270.48 |         43.000 |
| S1NoCD   | 74388425 | 186033235253 |   2500.836 | 1059900380 |     14.248 |      NaN |          0.000 |
| S2NoCD   | 44157029 | 136358873737 |   3088.045 |  614694012 |     13.921 |      NaN |          0.000 |
| S3NoCD   | 34491937 | 115570166575 |   3350.643 |  436927836 |     12.668 |      NaN |          0.000 |

-----

## Cost Effectiveness Plane

Adjusted to the total population

| Scenario  |   Agents | PropAgents |         Cost | CostpAgent | CostpAgentExcluded | CostpAgentAll |       QALY | QALYpAgent | QALYpAgentExcluded | QALYpAgentAll | IncrementalCosts | IncrementalQALY |  ICERAdj |     ICER |      INMB |
| :-------- | -------: | ---------: | -----------: | ---------: | -----------------: | ------------: | ---------: | ---------: | -----------------: | ------------: | ---------------: | --------------: | -------: | -------: | --------: |
| S1NoCDAvg | 74388586 |  1.0000000 | 185878883057 |   2498.755 |              0.000 |      2498.755 | 1059872895 |   14.24779 |            0.00000 |      14.24779 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.00000 |
| S1a       | 74386318 |  1.0000000 | 203290806711 |   2732.906 |              0.000 |      2732.906 | 1060803037 |   14.26073 |            0.00000 |      14.26073 |        234.15046 |       0.0129386 | 18097.02 | 18508.89 | 412.78069 |
| S1b       | 74385413 |  1.0000000 | 198298896720 |   2665.830 |              0.000 |      2665.830 | 1060342609 |   14.25471 |            0.00000 |      14.25471 |        167.07499 |       0.0069224 | 24135.55 | 25298.01 | 179.04299 |
| S1c       | 74390720 |  1.0000000 | 199278771241 |   2678.812 |              0.000 |      2678.812 | 1060261851 |   14.25261 |            0.00000 |      14.25261 |        180.05681 |       0.0048198 | 37357.37 | 40270.48 |  60.93551 |
| S2NoCD    | 44157029 |  0.5935995 | 136358873737 |   3088.045 |           1638.024 |      2498.755 |  614694012 |   13.92064 |           14.72564 |      14.24779 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.00000 |
| S2a       | 44154576 |  0.5935665 | 144286219339 |   3267.752 |           1638.024 |      2605.376 |  615140303 |   13.93152 |           14.72564 |      14.25427 |        106.62071 |       0.0064850 | 16441.02 | 16516.00 | 217.63136 |
| S3NoCD    | 34491937 |  0.4636724 | 115570166575 |   3350.643 |           1762.271 |      2498.755 |  436927836 |   12.66754 |           15.61397 |      14.24779 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.00000 |
| S3a       | 34494037 |  0.4637007 | 120160874413 |   3483.526 |           1762.271 |      2560.418 |  437149998 |   12.67320 |           15.61397 |      14.25033 |         61.66278 |       0.0025457 | 24222.21 | 23438.76 |  65.62285 |
| S3b       | 34509196 |  0.4639044 | 123796077467 |   3587.336 |           1762.271 |      2608.927 |  437667749 |   12.68264 |           15.61397 |      14.25411 |        110.17142 |       0.0063240 | 17421.26 | 15669.18 | 206.02677 |
| S3c       | 34504471 |  0.4638409 | 121485915694 |   3520.875 |           1762.271 |      2577.983 |  437449142 |   12.67804 |           15.61397 |      14.25217 |         79.22803 |       0.0043770 | 18100.91 | 16202.08 | 139.62291 |
| S3d       | 34501231 |  0.4637974 | 121822210448 |   3530.953 |           1762.271 |      2582.581 |  437363185 |   12.67674 |           15.61397 |      14.25169 |         83.82557 |       0.0039016 | 21485.10 | 19586.22 | 111.25281 |

![](../../outputs/Sen6_0_Discount_CEplot_5y-1.png)<!-- -->

## Clinical Results for all scenarios

Adjusted to the total population

| Scenario  | PropAgents | ProppPatientYears | ProppCopdPYs |   SABAAll |   LAMAAll | LAMALABAAll | ICSLAMALABAAll | MildpAgentAll | ModeratepAgentAll | SeverepAgentAll | VerySeverepAgentAll | NoCOPDpPYAll | GOLD1pPYAll | GOLD2pPYAll | GOLD3pPYAll | GOLD4pPYAll | DiagnosedpPYAll |
| :-------- | ---------: | ----------------: | -----------: | --------: | --------: | ----------: | -------------: | ------------: | ----------------: | --------------: | ------------------: | -----------: | ----------: | ----------: | ----------: | ----------: | --------------: |
| S1NoCDAvg |  1.0000000 |         1.0000000 |    1.0000000 | 0.0190054 | 0.1355252 |   0.1513708 |      0.0796683 |     0.4141116 |         0.0774707 |       0.1304099 |           0.0112712 |    0.8425605 |   0.0460767 |   0.0491056 |   0.0110053 |   0.0019082 |       0.1861446 |
| S1a       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0277770 | 0.1541676 |   0.2735725 |      0.0911068 |     0.4036872 |         0.0760433 |       0.1284919 |           0.0111234 |    0.8424045 |   0.0461250 |   0.0491350 |   0.0110626 |   0.0019277 |       0.4003768 |
| S1b       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0240246 | 0.1449184 |   0.2159908 |      0.0856256 |     0.4082615 |         0.0767149 |       0.1294255 |           0.0111919 |    0.8424441 |   0.0461406 |   0.0491198 |   0.0110327 |   0.0019206 |       0.2943838 |
| S1c       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0229387 | 0.1419011 |   0.1959119 |      0.0838224 |     0.4094144 |         0.0768280 |       0.1296761 |           0.0111991 |    0.8425663 |   0.0460770 |   0.0490825 |   0.0110176 |   0.0019137 |       0.2600889 |
| S2NoCD    |  0.5935995 |         0.5823361 |    0.7054688 | 0.0190054 | 0.1355252 |   0.1513708 |      0.0796683 |     0.4141116 |         0.0774707 |       0.1304099 |           0.0112712 |    0.8425605 |   0.0460767 |   0.0491056 |   0.0110053 |   0.0019082 |       0.1861446 |
| S2a       |  0.5935665 |         0.5824146 |    0.7059463 | 0.0213966 | 0.1438505 |   0.2094804 |      0.0850851 |     0.4086675 |         0.0767385 |       0.1294165 |           0.0112173 |    0.8425126 |   0.0461064 |   0.0490974 |   0.0110198 |   0.0019173 |       0.2779271 |
| S3NoCD    |  0.4636724 |         0.4154340 |    0.5860893 | 0.0190054 | 0.1355252 |   0.1513708 |      0.0796683 |     0.4141116 |         0.0774707 |       0.1304099 |           0.0112712 |    0.8425605 |   0.0460767 |   0.0491056 |   0.0110053 |   0.0019082 |       0.1861446 |
| S3a       |  0.4637007 |         0.4155277 |    0.5865311 | 0.0197899 | 0.1383033 |   0.1717111 |      0.0814794 |     0.4121234 |         0.0772548 |       0.1301283 |           0.0112118 |    0.8425199 |   0.0460735 |   0.0491517 |   0.0110056 |   0.0019051 |       0.2173159 |
| S3b       |  0.4639044 |         0.4157857 |    0.5876752 | 0.0217416 | 0.1441790 |   0.2124183 |      0.0853294 |     0.4094186 |         0.0768062 |       0.1294332 |           0.0111818 |    0.8424143 |   0.0460965 |   0.0491883 |   0.0110409 |   0.0019176 |       0.2844185 |
| S3c       |  0.4638409 |         0.4156951 |    0.5869250 | 0.0206754 | 0.1410634 |   0.1917068 |      0.0833411 |     0.4105793 |         0.0769845 |       0.1297108 |           0.0112077 |    0.8424894 |   0.0460833 |   0.0491418 |   0.0110239 |   0.0019170 |       0.2496308 |
| S3d       |  0.4637974 |         0.4156677 |    0.5868810 | 0.0202585 | 0.1397122 |   0.1824904 |      0.0824625 |     0.4112144 |         0.0771280 |       0.1298555 |           0.0112228 |    0.8424917 |   0.0460937 |   0.0491366 |   0.0110229 |   0.0019114 |       0.2345851 |

## Time elapsed

Run time for this notebook:

``` r
end.time <- Sys.time()
time.taken <- end.time - start.time
time.taken
```

    ## Time difference of 1.163011 days