Sensitivity analysis: 3% Discount Rate
================
16 September, 2024

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

| Scenario  | Agents | PatientYears |  CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |   Mild | Moderate | Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |  NoCOPD |  GOLD1 |  GOLD2 |   GOLD3 | GOLD4 |      Cost | CostpAgent |    QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |     ICER | IncrementalNMB |
| :-------- | -----: | -----------: | -------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | -----: | -------: | -----: | ---------: | -----: | ---------: | -------: | -----------: | ------: | -----: | -----: | ------: | ----: | --------: | ---------: | ------: | ---------: | -------: | ---------------: | --------------: | -------: | -------------: |
| S1NoCD    | 371579 |      6251100 | 706693.3 |         1907271 |     131040.9 |           133904 | 0.017 | 0.136 |    0.152 |       0.081 | 152231 |    28857 |  48565 |       4210 |  0.215 |      0.041 |    0.069 |        0.006 | 5270314 | 287267 | 304912 | 67938.0 | 12088 | 693416794 |   1866.136 | 4140081 |     11.142 | 555226.9 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCD2   | 371849 |      6258006 | 711427.5 |         1245925 |     134326.9 |           162900 | 0.021 | 0.138 |    0.153 |       0.081 | 153957 |    28983 |  48765 |       4194 |  0.216 |      0.041 |    0.069 |        0.006 | 5272466 | 288303 | 307998 | 68401.0 | 11986 | 697019850 |   1874.470 | 4144039 |     11.144 | 555346.2 |            0.000 |           0.000 |      NaN |          0.000 |
| S1NoCDAvg | 371714 |      6254553 | 709060.4 |         1576598 |     132683.9 |           148402 | 0.019 | 0.137 |    0.152 |       0.081 | 153094 |    28920 |  48665 |       4202 |  0.216 |      0.041 |    0.069 |        0.006 | 5271390 | 287785 | 306455 | 68169.5 | 12037 | 695218322 |   1870.304 | 4142060 |     11.143 | 555286.5 |            0.000 |           0.000 |      NaN |          0.000 |
| S1a       | 371902 |      6259940 | 715671.7 |         1860288 |     332259.1 |           133758 | 0.027 | 0.157 |    0.308 |       0.093 | 148736 |    27895 |  46953 |       4074 |  0.208 |      0.039 |    0.066 |        0.006 | 5270381 | 290230 | 309289 | 68990.0 | 12196 | 783941052 |   2107.924 | 4149002 |     11.156 | 555700.6 |          241.788 |           0.014 | 16895.73 |        473.742 |
| S1b       | 372140 |      6259675 | 712868.5 |         1884251 |     237934.2 |           133471 | 0.021 | 0.149 |    0.242 |       0.088 | 150400 |    28799 |  48224 |       4222 |  0.211 |      0.040 |    0.068 |        0.006 | 5272825 | 288870 | 308796 | 68640.0 | 11651 | 767647959 |   2062.793 | 4147250 |     11.144 | 555153.5 |          196.658 |           0.002 | 79752.62 |       \-73.365 |
| S1c       | 371919 |      6260241 | 706186.6 |         1892166 |     204936.3 |           134248 | 0.020 | 0.144 |    0.214 |       0.086 | 150938 |    28202 |  47543 |       4054 |  0.214 |      0.040 |    0.067 |        0.006 | 5279621 | 286590 | 304912 | 68525.0 | 11555 | 764610989 |   2055.854 | 4147446 |     11.151 | 555517.9 |          189.718 |           0.010 | 19731.63 |        291.028 |

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

| Scenario | Agents | PatientYears |  CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |   Mild | Moderate | Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |  NoCOPD |  GOLD1 |  GOLD2 | GOLD3 | GOLD4 |      Cost | CostpAgent |    QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |     ICER | IncrementalNMB |
| :------- | -----: | -----------: | -------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | -----: | -------: | -----: | ---------: | -----: | ---------: | -------: | -----------: | ------: | -----: | -----: | ----: | ----: | --------: | ---------: | ------: | ---------: | -------: | ---------------: | --------------: | -------: | -------------: |
| S2NoCD   | 219759 |      3629137 | 502614.4 |         1104519 |     96571.85 |            76657 | 0.017 | 0.142 |    0.159 |       0.088 | 114918 |    21470 |  35762 |       3125 |  0.229 |      0.043 |    0.071 |        0.006 | 2971512 | 185231 | 226774 | 55920 | 10059 | 516117722 |   2348.562 | 2397884 |     10.911 | 543222.7 |            0.000 |           0.000 |      NaN |          0.000 |
| S2a      | 221233 |      3655045 | 504163.3 |         1090071 |    187694.30 |            76886 | 0.023 | 0.161 |    0.273 |       0.100 | 111819 |    21267 |  35379 |       3000 |  0.222 |      0.042 |    0.070 |        0.006 | 2994733 | 187473 | 224775 | 56946 | 10292 | 562547217 |   2542.782 | 2417048 |     10.925 | 543724.8 |          194.219 |           0.014 | 13944.49 |        502.182 |

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

| Scenario | Agents | PatientYears |  CopdPYs | NCaseDetections | DiagnosedPYs | OverdiagnosedPYs |  SABA |  LAMA | LAMALABA | ICSLAMALABA |  Mild | Moderate | Severe | VerySevere | MildPY | ModeratePY | SeverePY | VerySeverePY |  NoCOPD |  GOLD1 |  GOLD2 | GOLD3 | GOLD4 |      Cost | CostpAgent |    QALY | QALYpAgent |      NMB | IncrementalCosts | IncrementalQALY |     ICER | IncrementalNMB |
| :------- | -----: | -----------: | -------: | --------------: | -----------: | ---------------: | ----: | ----: | -------: | ----------: | ----: | -------: | -----: | ---------: | -----: | ---------: | -------: | -----------: | ------: | -----: | -----: | ----: | ----: | --------: | ---------: | ------: | ---------: | -------: | ---------------: | --------------: | -------: | -------------: |
| S3NoCD   | 172154 |      2596453 | 416267.8 |          799855 |     76852.85 |            57928 | 0.018 | 0.136 |    0.152 |       0.085 | 97495 |    17657 |  29861 |       2619 |  0.234 |      0.042 |    0.072 |        0.006 | 2071385 | 153396 | 185269 | 48874 |  8728 | 431630006 |   2507.232 | 1729527 |     10.046 | 499812.4 |            0.000 |           0.000 |      NaN |          0.000 |
| S3a      | 172660 |      2605291 | 417975.1 |          794584 |    109412.00 |            58149 | 0.021 | 0.142 |    0.202 |       0.091 | 97401 |    17791 |  29901 |       2514 |  0.233 |      0.043 |    0.072 |        0.006 | 2078316 | 153154 | 186348 | 48897 |  9539 | 460928261 |   2669.572 | 1735995 |     10.054 | 500051.1 |          162.340 |           0.008 | 20235.54 |        238.786 |
| S3b      | 172336 |      2597409 | 414801.3 |          776924 |    169415.85 |            58485 | 0.027 | 0.156 |    0.292 |       0.098 | 93305 |    17249 |  29154 |       2538 |  0.225 |      0.042 |    0.070 |        0.006 | 2073562 | 151906 | 185791 | 48390 |  8665 | 474129705 |   2751.194 | 1732272 |     10.052 | 499834.4 |          243.962 |           0.005 | 45851.89 |         22.071 |
| S3c      | 172314 |      2601178 | 413310.6 |          785238 |    140563.81 |            58308 | 0.024 | 0.152 |    0.253 |       0.097 | 94971 |    17967 |  29976 |       2568 |  0.230 |      0.043 |    0.073 |        0.006 | 2078632 | 152348 | 184613 | 47450 |  9041 | 467593586 |   2713.613 | 1734099 |     10.064 | 500466.4 |          206.382 |           0.017 | 11993.56 |        654.003 |
| S3d      | 172882 |      2607172 | 418585.2 |          790887 |    126089.76 |            58037 | 0.022 | 0.148 |    0.229 |       0.093 | 96041 |    18109 |  30257 |       2592 |  0.229 |      0.043 |    0.072 |        0.006 | 2079272 | 153348 | 187559 | 48917 |  8624 | 474794782 |   2746.352 | 1737496 |     10.050 | 499762.9 |          239.120 |           0.004 | 63036.94 |       \-49.453 |

*Treatment rate:* SABA is expressed per all patient-years, LAMA,
LAMA/LABA, ICS/LAMA/LABA are per COPD patient-years *Exacerbations:*
Total exacerbations and rate per COPD patient-year *GOLD Stage:*
Cumulative patient-years *Cost/QALY:* Total cost and QALYs *NMB:* Net
Monetary Benefit is calculated as QALY per patient-year \* Lamba - Cost
per patient-year

-----

## All Scenarios

*Ordered by descending Net Monetary Benefit*

| Scenario | Agents |      Cost | CostpAgent |    QALY | QALYpAgent |     ICER | IncrementalNMB |
| :------- | -----: | --------: | ---------: | ------: | ---------: | -------: | -------------: |
| S3c      | 172314 | 467593586 |   2713.613 | 1734099 |     10.064 | 11993.56 |        654.003 |
| S2a      | 221233 | 562547217 |   2542.782 | 2417048 |     10.925 | 13944.49 |        502.182 |
| S1a      | 371902 | 783941052 |   2107.924 | 4149002 |     11.156 | 16895.73 |        473.742 |
| S1c      | 371919 | 764610989 |   2055.854 | 4147446 |     11.151 | 19731.63 |        291.028 |
| S3a      | 172660 | 460928261 |   2669.572 | 1735995 |     10.054 | 20235.54 |        238.786 |
| S3b      | 172336 | 474129705 |   2751.194 | 1732272 |     10.052 | 45851.89 |         22.071 |
| S1NoCD   | 371579 | 693416794 |   1866.136 | 4140081 |     11.142 |      NaN |          0.000 |
| S2NoCD   | 219759 | 516117722 |   2348.562 | 2397884 |     10.911 |      NaN |          0.000 |
| S3NoCD   | 172154 | 431630006 |   2507.232 | 1729527 |     10.046 |      NaN |          0.000 |
| S3d      | 172882 | 474794782 |   2746.352 | 1737496 |     10.050 | 63036.94 |       \-49.453 |
| S1b      | 372140 | 767647959 |   2062.793 | 4147250 |     11.144 | 79752.62 |       \-73.365 |

-----

## Cost Effectiveness Plane

Adjusted to the total population

| Scenario  | Agents | PropAgents |      Cost | CostpAgent | CostpAgentExcluded | CostpAgentAll |    QALY | QALYpAgent | QALYpAgentExcluded | QALYpAgentAll | IncrementalCosts | IncrementalQALY |    ICERAdj |     ICER |        INMB |
| :-------- | -----: | ---------: | --------: | ---------: | -----------------: | ------------: | ------: | ---------: | -----------------: | ------------: | ---------------: | --------------: | ---------: | -------: | ----------: |
| S1NoCDAvg | 371714 |  1.0000000 | 695218322 |   1870.304 |              0.000 |      1870.304 | 4142060 |   11.14314 |            0.00000 |      11.14314 |          0.00000 |       0.0000000 |        NaN |      NaN |     0.00000 |
| S1a       | 371902 |  1.0000000 | 783941052 |   2107.924 |              0.000 |      2107.924 | 4149002 |   11.15617 |            0.00000 |      11.15617 |        237.61935 |       0.0130338 |   18230.98 | 16895.73 |   414.07181 |
| S1b       | 372140 |  1.0000000 | 767647959 |   2062.793 |              0.000 |      2062.793 | 4147250 |   11.14433 |            0.00000 |      11.14433 |        192.48908 |       0.0011891 |  161883.14 | 79752.62 | \-133.03598 |
| S1c       | 371919 |  1.0000000 | 764610989 |   2055.854 |              0.000 |      2055.854 | 4147446 |   11.15148 |            0.00000 |      11.15148 |        185.54915 |       0.0083381 |   22253.09 | 19731.63 |   231.35734 |
| S2NoCD    | 219759 |  0.5912045 | 516117722 |   2348.562 |           1178.642 |      1870.304 | 2397884 |   10.91142 |           11.47824 |      11.14314 |          0.00000 |       0.0000000 |        NaN |      NaN |     0.00000 |
| S2a       | 221233 |  0.5951699 | 562547217 |   2542.782 |           1178.642 |      1990.537 | 2417048 |   10.92535 |           11.47824 |      11.14918 |        120.23269 |       0.0060419 |   19899.90 | 13944.49 |   181.86099 |
| S3NoCD    | 172154 |  0.4631356 | 431630006 |   2507.232 |           1320.847 |      1870.304 | 1729527 |   10.04639 |           12.08926 |      11.14314 |          0.00000 |       0.0000000 |        NaN |      NaN |     0.00000 |
| S3a       | 172660 |  0.4644969 | 460928261 |   2669.572 |           1320.847 |      1947.326 | 1735995 |   10.05441 |           12.08926 |      11.14408 |         77.02133 |       0.0009455 |   81456.90 | 20235.54 |  \-29.74398 |
| S3b       | 172336 |  0.4636253 | 474129705 |   2751.194 |           1320.847 |      1983.992 | 1732272 |   10.05171 |           12.08926 |      11.14460 |        113.68769 |       0.0014665 |   77520.65 | 45851.89 |  \-40.36033 |
| S3c       | 172314 |  0.4635661 | 467593586 |   2713.613 |           1320.847 |      1966.487 | 1734099 |   10.06360 |           12.08926 |      11.15023 |         96.18213 |       0.0070976 |   13551.41 | 11993.56 |   258.69646 |
| S3d       | 172882 |  0.4650941 | 474794782 |   2746.352 |           1320.847 |      1983.841 | 1737496 |   10.05019 |           12.08926 |      11.14090 |        113.53675 |     \-0.0022367 | \-50760.81 | 63036.94 | \-225.37179 |

![](../../outputs/Sen7_3_Discount_CEplot-1.png)<!-- -->

## Clinical Results for all scenarios

Adjusted to the total population

| Scenario  | PropAgents | ProppPatientYears | ProppCopdPYs |   SABAAll |   LAMAAll | LAMALABAAll | ICSLAMALABAAll | MildpAgentAll | ModeratepAgentAll | SeverepAgentAll | VerySeverepAgentAll | NoCOPDpPYAll | GOLD1pPYAll | GOLD2pPYAll | GOLD3pPYAll | GOLD4pPYAll | DiagnosedpPYAll |
| :-------- | ---------: | ----------------: | -----------: | --------: | --------: | ----------: | -------------: | ------------: | ----------------: | --------------: | ------------------: | -----------: | ----------: | ----------: | ----------: | ----------: | --------------: |
| S1NoCDAvg |  1.0000000 |         1.0000000 |    1.0000000 | 0.0190669 | 0.1369635 |   0.1524877 |      0.0811388 |     0.4118597 |         0.0778018 |       0.1309205 |           0.0113044 |    0.8428084 |   0.0460121 |   0.0489971 |   0.0108992 |   0.0019245 |       0.1871263 |
| S1a       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0265445 | 0.1570223 |   0.3084907 |      0.0926510 |     0.3999333 |         0.0750063 |       0.1262510 |           0.0109545 |    0.8419219 |   0.0463631 |   0.0494077 |   0.0110209 |   0.0019483 |       0.4642618 |
| S1b       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0214586 | 0.1491594 |   0.2417213 |      0.0881407 |     0.4041490 |         0.0773875 |       0.1295856 |           0.0113452 |    0.8423480 |   0.0461478 |   0.0493310 |   0.0109654 |   0.0018613 |       0.3337701 |
| S1c       |  1.0000000 |         1.0000000 |    1.0000000 | 0.0203173 | 0.1442037 |   0.2142410 |      0.0858433 |     0.4058357 |         0.0758283 |       0.1278316 |           0.0109002 |    0.8433575 |   0.0457794 |   0.0487061 |   0.0109461 |   0.0018458 |       0.2902014 |
| S2NoCD    |  0.5912045 |         0.5802392 |    0.7088457 | 0.0190669 | 0.1369635 |   0.1524877 |      0.0811388 |     0.4118597 |         0.0778018 |       0.1309205 |           0.0113044 |    0.8428084 |   0.0460121 |   0.0489971 |   0.0108992 |   0.0019245 |       0.1871263 |
| S2a       |  0.5951699 |         0.5843814 |    0.7110301 | 0.0224588 | 0.1502763 |   0.2333607 |      0.0900274 |     0.4025264 |         0.0770612 |       0.1295535 |           0.0109400 |    0.8428925 |   0.0462087 |   0.0485518 |   0.0110439 |   0.0019587 |       0.3152558 |
| S3NoCD    |  0.4631356 |         0.4151300 |    0.5870696 | 0.0190669 | 0.1369635 |   0.1524877 |      0.0811388 |     0.4118597 |         0.0778018 |       0.1309205 |           0.0113044 |    0.8428084 |   0.0460121 |   0.0489971 |   0.0108992 |   0.0019245 |       0.1871263 |
| S3a       |  0.4644969 |         0.4165431 |    0.5894774 | 0.0201971 | 0.1407461 |   0.1823544 |      0.0846326 |     0.4112275 |         0.0780854 |       0.1308999 |           0.0110111 |    0.8426805 |   0.0459215 |   0.0491228 |   0.0108954 |   0.0020529 |       0.2325859 |
| S3b       |  0.4636253 |         0.4152828 |    0.5850013 | 0.0226724 | 0.1487887 |   0.2343546 |      0.0889405 |     0.4004511 |         0.0766765 |       0.1289724 |           0.0110826 |    0.8430228 |   0.0457682 |   0.0490755 |   0.0108210 |   0.0019143 |       0.3180639 |
| S3c       |  0.4635661 |         0.4158854 |    0.5828990 | 0.0212574 | 0.1466240 |   0.2115343 |      0.0882504 |     0.4049496 |         0.0786114 |       0.1311894 |           0.0111638 |    0.8433063 |   0.0458168 |   0.0488672 |   0.0106675 |   0.0019739 |       0.2777743 |
| S3d       |  0.4650941 |         0.4168438 |    0.5903378 | 0.0207322 | 0.1440997 |   0.1979824 |      0.0857580 |     0.4074024 |         0.0789072 |       0.1318013 |           0.0112162 |    0.8425703 |   0.0459414 |   0.0493065 |   0.0108970 |   0.0019063 |       0.2559428 |

## Time elapsed

Run time for this notebook:

``` r
end.time <- Sys.time()
time.taken <- end.time - start.time
time.taken
```

    ## Time difference of 8.582391 mins
