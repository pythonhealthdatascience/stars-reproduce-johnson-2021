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

| Scenario  |   Agents | PatientYears |   CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |     Mild | Moderate |  Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |     NoCOPD |    GOLD1 |    GOLD2 |    GOLD3 |   GOLD4 |         Cost | CostpAgent |      QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |     ICER | IncrementalNMB |
| :-------- | -------: | -----------: | --------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | -------: | -------: | ------: | ---------: | -----: | ---------: | -------: | -----------: | ---------: | -------: | -------: | -------: | ------: | -----------: | ---------: | --------: | ---------: | -------: | ---------------: | --------------: | -------: | -------------: |
| S1NoCD2   | 74388747 |   1251903576 | 142277086 |       381929878 |     26336153 |         26747209 | 0.017 | 0.135 |    0.151 |       0.080 | 30809289 |  5766720 | 9701609 |   839538.0 |  0.217 |      0.041 |    0.068 |        0.006 | 1054811684 | 57697202 | 61465410 | 13763906 | 2389153 | 138701936801 |   1864.555 | 829008490 |     11.144 | 555349.1 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCD    | 74388425 |   1251968458 | 142302175 |       249329256 |     26636736 |         32661650 | 0.021 | 0.136 |    0.151 |       0.080 | 30801067 |  5759155 | 9700407 |   837363.0 |  0.216 |      0.040 |    0.068 |        0.006 | 1054852003 | 57672835 | 61488796 | 13791895 | 2388663 | 138942645767 |   1867.799 | 829048977 |     11.145 | 555375.5 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCDAvg | 74388586 |   1251936017 | 142289630 |       315629567 |     26486444 |         29704430 | 0.019 | 0.136 |    0.151 |       0.080 | 30805178 |  5762938 | 9701008 |   838450.5 |  0.216 |      0.041 |    0.068 |        0.006 | 1054831844 | 57685018 | 61477103 | 13777900 | 2388908 | 138822291284 |   1866.177 | 829028734 |     11.145 | 555362.3 |            0.000 |           0.000 |      NaN |          0.000 |
| S1a       | 74386318 |   1252092577 | 142511621 |       245523949 |     57058349 |         32655914 | 0.028 | 0.154 |    0.274 |       0.091 | 30028808 |  5656584 | 9558038 |   827432.0 |  0.211 |      0.040 |    0.067 |        0.006 | 1054768469 | 57752767 | 61521629 | 13851433 | 2413714 | 152526962185 |   2050.471 | 829711078 |     11.154 | 555653.6 |          182.671 |           0.009 | 19819.98 |        278.155 |
| S1b       | 74385413 |   1252007176 | 142455061 |       247448362 |     41936466 |         32651747 | 0.024 | 0.145 |    0.216 |       0.086 | 30368698 |  5706469 | 9627370 |   832514.0 |  0.213 |      0.040 |    0.068 |        0.006 | 1054746061 | 57768304 | 61498391 | 13812986 | 2404656 | 148706489801 |   1999.135 | 829367944 |     11.150 | 555481.1 |          131.336 |           0.005 | 27712.02 |        105.630 |
| S1c       | 74390720 |   1252048091 | 142295860 |       248074520 |     37009576 |         32668233 | 0.023 | 0.142 |    0.196 |       0.084 | 30456632 |  5715293 | 9646702 |   833108.0 |  0.214 |      0.040 |    0.068 |        0.006 | 1054933501 | 57690667 | 61453687 | 13794504 | 2396041 | 149630762735 |   2011.417 | 829312433 |     11.148 | 555391.7 |          143.618 |           0.003 | 44912.99 |         16.267 |

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
| S2NoCD   | 44157029 |    729047563 | 100380900 |       145000421 |     19524492 |         18863743 | 0.021 | 0.142 |    0.160 |       0.087 | 22925265 |  4254784 | 7099566 |     609563 |  0.228 |      0.042 |    0.071 |        0.006 | 597538799 | 37245010 | 45040554 | 11117169 | 2054803 | 102687192587 |   2325.500 | 481821543 |     10.912 | 543251.9 |            0.000 |           0.000 |      NaN |            0.0 |
| S2a      | 44154576 |    729145856 | 100448839 |       143361789 |     32595478 |         18878233 | 0.025 | 0.154 |    0.242 |       0.095 | 22519648 |  4200194 | 7025459 |     605531 |  0.224 |      0.042 |    0.070 |        0.006 | 597564735 | 37286040 | 45033303 | 11135908 | 2066352 | 108994087698 |   2468.466 | 482147541 |     10.920 | 543508.4 |          142.966 |           0.008 | 17894.65 |          256.5 |

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
| S3NoCD   | 34491937 |    520096794 | 83394436 |       104866546 |     15798844 |         14116443 | 0.022 | 0.137 |    0.154 |       0.086 | 19479590 |  3630576 | 6075819 |     523166 |  0.234 |      0.044 |    0.073 |        0.006 | 414917152 | 30599570 | 37365292 | 9614469 | 1790750 | 87288548274 |   2530.694 | 346433081 |     10.044 | 499663.6 |            0.000 |           0.000 |      NaN |          0.000 |
| S3a      | 34494037 |    520214111 | 83457293 |       104351592 |     20245608 |         14129448 | 0.024 | 0.142 |    0.189 |       0.089 | 19332282 |  3614629 | 6055063 |     518761 |  0.232 |      0.043 |    0.073 |        0.006 | 414968911 | 30599997 | 37426814 | 9615582 | 1787056 | 91012637190 |   2638.503 | 346595429 |     10.048 | 499760.5 |          107.809 |           0.004 | 26326.46 |         96.945 |
| S3b      | 34509196 |    520537138 | 83620081 |       103218767 |     29823148 |         14132996 | 0.029 | 0.152 |    0.258 |       0.096 | 19135380 |  3582069 | 6004729 |     516649 |  0.229 |      0.043 |    0.072 |        0.006 | 415119150 | 30640730 | 37483240 | 9661621 | 1802895 | 93844195380 |   2719.397 | 346989244 |     10.055 | 500029.6 |          188.702 |           0.011 | 17010.73 |        365.955 |
| S3c      | 34504471 |    520423616 | 83513343 |       103824096 |     24853847 |         14121585 | 0.026 | 0.146 |    0.223 |       0.093 | 19220385 |  3595075 | 6024956 |     518536 |  0.230 |      0.043 |    0.072 |        0.006 | 415113845 | 30619979 | 37421385 | 9639642 | 1802009 | 92029481714 |   2667.176 | 346825427 |     10.052 | 499913.2 |          136.481 |           0.008 | 17673.54 |        249.636 |
| S3d      | 34501231 |    520389346 | 83507084 |       104079260 |     22711874 |         14135933 | 0.025 | 0.144 |    0.207 |       0.091 | 19266710 |  3605577 | 6035420 |     519637 |  0.231 |      0.043 |    0.072 |        0.006 | 415086795 | 30631737 | 37413709 | 9638221 | 1794998 | 92355832428 |   2676.885 | 346759011 |     10.051 | 499854.5 |          146.191 |           0.007 | 21685.99 |        190.872 |

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
| S3b      | 34509196 |  93844195380 |   2719.397 | 346989244 |     10.055 | 17010.73 |        365.955 |
| S1a      | 74386318 | 152526962185 |   2050.471 | 829711078 |     11.154 | 19819.98 |        278.155 |
| S2a      | 44154576 | 108994087698 |   2468.466 | 482147541 |     10.920 | 17894.65 |        256.500 |
| S3c      | 34504471 |  92029481714 |   2667.176 | 346825427 |     10.052 | 17673.54 |        249.636 |
| S3d      | 34501231 |  92355832428 |   2676.885 | 346759011 |     10.051 | 21685.99 |        190.872 |
| S1b      | 74385413 | 148706489801 |   1999.135 | 829367944 |     11.150 | 27712.02 |        105.630 |
| S3a      | 34494037 |  91012637190 |   2638.503 | 346595429 |     10.048 | 26326.46 |         96.945 |
| S1c      | 74390720 | 149630762735 |   2011.417 | 829312433 |     11.148 | 44912.99 |         16.267 |
| S1NoCD   | 74388425 | 138942645767 |   1867.799 | 829048977 |     11.145 |      NaN |          0.000 |
| S2NoCD   | 44157029 | 102687192587 |   2325.500 | 481821543 |     10.912 |      NaN |          0.000 |
| S3NoCD   | 34491937 |  87288548274 |   2530.694 | 346433081 |     10.044 |      NaN |          0.000 |

-----

## Cost Effectiveness Plane

Adjusted to the total population

| Scenario  |   Agents | PropAgents |         Cost | CostpAgent | CostpAgentExcluded | CostpAgentAll |      QALY | QALYpAgent | QALYpAgentExcluded | QALYpAgentAll | IncrementalCosts | IncrementalQALY |  ICERAdj |     ICER |      INMB |
| :-------- | -------: | ---------: | -----------: | ---------: | -----------------: | ------------: | --------: | ---------: | -----------------: | ------------: | ---------------: | --------------: | -------: | -------: | --------: |
| S1NoCDAvg | 74388586 |  1.0000000 | 138822291284 |   1866.177 |              0.000 |      1866.177 | 829028734 |   11.14457 |            0.00000 |      11.14457 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.00000 |
| S1a       | 74386318 |  1.0000000 | 152526962185 |   2050.471 |              0.000 |      2050.471 | 829711078 |   11.15408 |            0.00000 |      11.15408 |        184.29335 |       0.0095128 | 19373.25 | 19819.98 | 291.34545 |
| S1b       | 74385413 |  1.0000000 | 148706489801 |   1999.135 |              0.000 |      1999.135 | 829367944 |   11.14960 |            0.00000 |      11.14960 |        132.95779 |       0.0050356 | 26403.79 | 27712.02 | 118.82008 |
| S1c       | 74390720 |  1.0000000 | 149630762735 |   2011.417 |              0.000 |      2011.417 | 829312433 |   11.14806 |            0.00000 |      11.14806 |        145.23974 |       0.0034939 | 41569.07 | 44912.99 |  29.45715 |
| S2NoCD    | 44157029 |  0.5935995 | 102687192587 |   2325.500 |           1195.277 |      1866.177 | 481821543 |   10.91155 |           11.48493 |      11.14457 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.00000 |
| S2a       | 44154576 |  0.5935665 | 108994087698 |   2468.466 |           1195.277 |      1951.000 | 482147541 |   10.91954 |           11.48493 |      11.14933 |         84.82252 |       0.0047611 | 17815.76 | 17894.65 | 153.23220 |
| S3NoCD    | 34491937 |  0.4636724 |  87288548274 |   2530.694 |           1291.681 |      1866.177 | 346433081 |   10.04389 |           12.09614 |      11.14457 |          0.00000 |       0.0000000 |      NaN |      NaN |   0.00000 |
| S3a       | 34494037 |  0.4637007 |  91012637190 |   2638.503 |           1291.681 |      1916.203 | 346595429 |   10.04798 |           12.09614 |      11.14641 |         50.02617 |       0.0018410 | 27173.96 | 26326.46 |  42.02184 |
| S3b       | 34509196 |  0.4639044 |  93844195380 |   2719.397 |           1291.681 |      1954.005 | 346989244 |   10.05498 |           12.09614 |      11.14924 |         87.82737 |       0.0046700 | 18806.67 | 17010.73 | 145.67317 |
| S3c       | 34504471 |  0.4638409 |  92029481714 |   2667.176 |           1291.681 |      1929.692 | 346825427 |   10.05161 |           12.09614 |      11.14781 |         63.51436 |       0.0032361 | 19626.52 | 17673.54 |  98.29313 |
| S3d       | 34501231 |  0.4637974 |  92355832428 |   2676.885 |           1291.681 |      1934.135 | 346759011 |   10.05063 |           12.09614 |      11.14744 |         67.95773 |       0.0028702 | 23677.23 | 21685.99 |  75.55086 |

![](../../outputs/Sen7_3_Discount_CEplot_5y-1.png)<!-- -->

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

    ## Time difference of 1.276366 days
