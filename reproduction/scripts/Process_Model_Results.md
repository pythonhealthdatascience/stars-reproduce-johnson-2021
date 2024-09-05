Process Model Results
================
05 September, 2024

This file processes the model results so they match up as closely as
possible to those in the publication.

``` r
library(dplyr)
```

## Define file paths and import files

``` r
paths <- list(
  # Model results
  sall_3y = "../outputs/sall.csv",
  sall_5y = "../outputs/sall_5y.csv",
  ceplane_3y = "../outputs/ceplane.csv",
  ceplane_5y = "../outputs/ceplane_5y.csv",

  # Original study results
  paper_tab3 = "../../original_study/tab3.csv",
  original_sall = "../../original_study/sall.csv",
  original_ceplane = "../../original_study/ceplane.csv",

  # Outputs from this .Rmd file
  tab3_compare = "../outputs/tab3_compare_to_original.csv"
)
```

``` r
sall_3y <- read.csv(paths$sall_3y) %>% mutate("Interval" = "3 years")
sall_5y <- read.csv(paths$sall_5y) %>% mutate("Interval" = "5 years")
ceplane_3y <- read.csv(paths$ceplane_3y) %>% mutate("Interval" = "3 years")
ceplane_5y <- read.csv(paths$ceplane_5y) %>% mutate("Interval" = "5 years")

paper_tab3 <- read.csv(paths$paper_tab3)
original_sall <- read.csv(paths$original_sall)
original_ceplane <- read.csv(paths$original_ceplane)
```

## Table 3

Preview the results.

``` r
rbind(ceplane_3y, ceplane_5y) %>%
  arrange(Scenario)
```

    ##     Scenario Agents PropAgents       Cost CostpAgent CostpAgentExcluded
    ## 1  S1NoCDAvg 743240  1.0000000 1599466443   2152.020              0.000
    ## 2  S1NoCDAvg 743240  1.0000000 1599466443   2152.020              0.000
    ## 3        S1a 743762  1.0000000 1807321435   2429.973              0.000
    ## 4        S1a 744354  1.0000000 1752926443   2354.963              0.000
    ## 5        S1b 744327  1.0000000 1760175403   2364.788              0.000
    ## 6        S1b 744122  1.0000000 1719863654   2311.266              0.000
    ## 7        S1c 744352  1.0000000 1784618220   2397.546              0.000
    ## 8        S1c 744408  1.0000000 1712210641   2300.097              0.000
    ## 9     S2NoCD 441551  0.5940894 1172222127   2654.783           1416.175
    ## 10    S2NoCD 441928  0.5945966 1179924911   2669.948           1392.382
    ## 11       S2a 441650  0.5942226 1270487699   2876.684           1416.175
    ## 12       S2a 441121  0.5935108 1240789795   2812.811           1392.382
    ## 13    S3NoCD 345450  0.4647893 1009751817   2923.004           1482.477
    ## 14    S3NoCD 344713  0.4637977  996287204   2890.193           1513.522
    ## 15       S3a 344340  0.4632958 1058616300   3074.334           1482.477
    ## 16       S3a 344831  0.4639565 1045268642   3031.249           1513.522
    ## 17       S3b 344561  0.4635932 1098068656   3186.863           1482.477
    ## 18       S3b 344259  0.4631869 1074556989   3121.362           1513.522
    ## 19       S3c 345148  0.4643830 1069636233   3099.065           1482.477
    ## 20       S3c 344359  0.4633214 1045425869   3035.860           1513.522
    ## 21       S3d 344912  0.4640654 1075013391   3116.776           1482.477
    ## 22       S3d 343958  0.4627819 1047428798   3045.223           1513.522
    ##    CostpAgentAll    QALY QALYpAgent QALYpAgentExcluded QALYpAgentAll
    ## 1       2152.020 9319095   12.53848            0.00000      12.53848
    ## 2       2152.020 9319095   12.53848            0.00000      12.53848
    ## 3       2429.973 9340234   12.55810            0.00000      12.55810
    ## 4       2354.963 9349016   12.55991            0.00000      12.55991
    ## 5       2364.788 9341640   12.55045            0.00000      12.55045
    ## 6       2311.266 9342006   12.55440            0.00000      12.55440
    ## 7       2397.546 9343139   12.55204            0.00000      12.55204
    ## 8       2300.097 9338065   12.54428            0.00000      12.54428
    ## 9       2152.019 5415116   12.26385           12.94041      12.53847
    ## 10      2152.019 5422979   12.27118           12.93050      12.53847
    ## 11      2284.043 5428810   12.29211           12.94041      12.55517
    ## 12      2235.422 5419996   12.28687           12.93050      12.54850
    ## 13      2152.019 3878935   11.22864           13.67596      12.53847
    ## 14      2152.019 3873367   11.23650           13.66464      12.53847
    ## 15      2219.978 3873043   11.24773           13.67596      12.55097
    ## 16      2217.681 3874091   11.23475           13.66464      12.53728
    ## 17      2272.619 3875123   11.24655           13.67596      12.54970
    ## 18      2258.252 3874191   11.25371           13.66464      12.54793
    ## 19      2233.193 3879671   11.24060           13.67596      12.54502
    ## 20      2218.854 3873257   11.24773           13.66464      12.54483
    ## 21      2240.899 3876329   11.23860           13.67596      12.54487
    ## 22      2222.365 3863483   11.23243           13.66464      12.53905
    ##    IncrementalCosts IncrementalQALY    ICERAdj       ICER        INMB Interval
    ## 1           0.00000     0.000000000         NA         NA    0.000000  3 years
    ## 2           0.00000     0.000000000         NA         NA    0.000000  5 years
    ## 3         277.95257     0.019613777  14171.293  13791.124  702.736263  3 years
    ## 4         202.94319     0.021425035   9472.245   9739.527  868.308574  5 years
    ## 5         212.76756     0.011970800  17773.880  17035.376  385.772440  3 years
    ## 6         159.24546     0.015920268  10002.688  10379.531  636.767913  5 years
    ## 7         245.52585     0.013562965  18102.668  17438.189  432.622386  3 years
    ## 8         148.07681     0.005802018  25521.605  27838.899  142.024090  5 years
    ## 9           0.00000     0.000000000         NA         NA   -0.420303  3 years
    ## 10          0.00000     0.000000000         NA         NA   -0.420303  5 years
    ## 11        132.02380     0.016700953   7905.166   7852.913  702.603532  3 years
    ## 12         83.40312     0.010026932   8317.911   9106.416  417.523169  5 years
    ## 13          0.00000     0.000000000         NA         NA   -0.420303  3 years
    ## 14          0.00000     0.000000000         NA         NA   -0.420303  5 years
    ## 15         67.95925     0.012496296   5438.352   7929.873  556.435226  3 years
    ## 16         65.66229    -0.001195652 -54917.558 -80779.766 -125.865199  5 years
    ## 17        120.60002     0.011228431  10740.594  14735.648  440.401243  3 years
    ## 18        106.23342     0.009456154  11234.316  13429.701  366.153959  5 years
    ## 19         81.17449     0.006546236  12400.176  14726.663  245.717029  3 years
    ## 20         66.83501     0.006360854  10507.238  12968.139  250.787397  5 years
    ## 21         88.87997     0.006392796  13903.144  19458.355  230.339544  3 years
    ## 22         70.34646     0.000581916 120887.662 -38068.150  -41.670964  5 years

Combine, organise and modify results as per paper.

``` r
ceplane <- rbind(ceplane_3y, ceplane_5y) %>%
  # Remove scenarios 2 and 3 with no case detection, and scenario 2b
  filter(!(Scenario %in% c("S2NoCD", "S3NoCD", "S2b"))) %>%
  # Remove S1NoCD from 5 years, then set interval of S1NoCD to NA
  filter(!(Scenario == "S1NoCD" & Interval == "5 years")) %>%
  mutate(Interval = ifelse(Scenario == "S1NoCD", NA, Interval)) %>%
  # Remove INMB for S1NoCD
  mutate(INMB = ifelse(Scenario!="S1NoCD", INMB, NA)) %>%
  # Get INMB ranking
  mutate(Ranking = min_rank(desc(INMB)))

ceplane
```

    ##     Scenario Agents PropAgents       Cost CostpAgent CostpAgentExcluded
    ## 1  S1NoCDAvg 743240  1.0000000 1599466443   2152.020              0.000
    ## 2        S1a 743762  1.0000000 1807321435   2429.973              0.000
    ## 3        S1b 744327  1.0000000 1760175403   2364.788              0.000
    ## 4        S1c 744352  1.0000000 1784618220   2397.546              0.000
    ## 5        S2a 441650  0.5942226 1270487699   2876.684           1416.175
    ## 6        S3a 344340  0.4632958 1058616300   3074.334           1482.477
    ## 7        S3b 344561  0.4635932 1098068656   3186.863           1482.477
    ## 8        S3c 345148  0.4643830 1069636233   3099.065           1482.477
    ## 9        S3d 344912  0.4640654 1075013391   3116.776           1482.477
    ## 10 S1NoCDAvg 743240  1.0000000 1599466443   2152.020              0.000
    ## 11       S1a 744354  1.0000000 1752926443   2354.963              0.000
    ## 12       S1b 744122  1.0000000 1719863654   2311.266              0.000
    ## 13       S1c 744408  1.0000000 1712210641   2300.097              0.000
    ## 14       S2a 441121  0.5935108 1240789795   2812.811           1392.382
    ## 15       S3a 344831  0.4639565 1045268642   3031.249           1513.522
    ## 16       S3b 344259  0.4631869 1074556989   3121.362           1513.522
    ## 17       S3c 344359  0.4633214 1045425869   3035.860           1513.522
    ## 18       S3d 343958  0.4627819 1047428798   3045.223           1513.522
    ##    CostpAgentAll    QALY QALYpAgent QALYpAgentExcluded QALYpAgentAll
    ## 1       2152.020 9319095   12.53848            0.00000      12.53848
    ## 2       2429.973 9340234   12.55810            0.00000      12.55810
    ## 3       2364.788 9341640   12.55045            0.00000      12.55045
    ## 4       2397.546 9343139   12.55204            0.00000      12.55204
    ## 5       2284.043 5428810   12.29211           12.94041      12.55517
    ## 6       2219.978 3873043   11.24773           13.67596      12.55097
    ## 7       2272.619 3875123   11.24655           13.67596      12.54970
    ## 8       2233.193 3879671   11.24060           13.67596      12.54502
    ## 9       2240.899 3876329   11.23860           13.67596      12.54487
    ## 10      2152.020 9319095   12.53848            0.00000      12.53848
    ## 11      2354.963 9349016   12.55991            0.00000      12.55991
    ## 12      2311.266 9342006   12.55440            0.00000      12.55440
    ## 13      2300.097 9338065   12.54428            0.00000      12.54428
    ## 14      2235.422 5419996   12.28687           12.93050      12.54850
    ## 15      2217.681 3874091   11.23475           13.66464      12.53728
    ## 16      2258.252 3874191   11.25371           13.66464      12.54793
    ## 17      2218.854 3873257   11.24773           13.66464      12.54483
    ## 18      2222.365 3863483   11.23243           13.66464      12.53905
    ##    IncrementalCosts IncrementalQALY    ICERAdj       ICER       INMB Interval
    ## 1           0.00000     0.000000000         NA         NA    0.00000  3 years
    ## 2         277.95257     0.019613777  14171.293  13791.124  702.73626  3 years
    ## 3         212.76756     0.011970800  17773.880  17035.376  385.77244  3 years
    ## 4         245.52585     0.013562965  18102.668  17438.189  432.62239  3 years
    ## 5         132.02380     0.016700953   7905.166   7852.913  702.60353  3 years
    ## 6          67.95925     0.012496296   5438.352   7929.873  556.43523  3 years
    ## 7         120.60002     0.011228431  10740.594  14735.648  440.40124  3 years
    ## 8          81.17449     0.006546236  12400.176  14726.663  245.71703  3 years
    ## 9          88.87997     0.006392796  13903.144  19458.355  230.33954  3 years
    ## 10          0.00000     0.000000000         NA         NA    0.00000  5 years
    ## 11        202.94319     0.021425035   9472.245   9739.527  868.30857  5 years
    ## 12        159.24546     0.015920268  10002.688  10379.531  636.76791  5 years
    ## 13        148.07681     0.005802018  25521.605  27838.899  142.02409  5 years
    ## 14         83.40312     0.010026932   8317.911   9106.416  417.52317  5 years
    ## 15         65.66229    -0.001195652 -54917.558 -80779.766 -125.86520  5 years
    ## 16        106.23342     0.009456154  11234.316  13429.701  366.15396  5 years
    ## 17         66.83501     0.006360854  10507.238  12968.139  250.78740  5 years
    ## 18         70.34646     0.000581916 120887.662 -38068.150  -41.67096  5 years
    ##    Ranking
    ## 1       15
    ## 2        2
    ## 3        9
    ## 4        7
    ## 5        3
    ## 6        5
    ## 7        6
    ## 8       12
    ## 9       13
    ## 10      15
    ## 11       1
    ## 12       4
    ## 13      14
    ## 14       8
    ## 15      18
    ## 16      10
    ## 17      11
    ## 18      17

Reformat to match paper.

``` r
ceplane_pretty <- ceplane %>%
  # Round columns
  mutate(CostpAgentAll = paste0("$", round(CostpAgentAll, 0))) %>%
  mutate(QALYpAgentAll = round(QALYpAgentAll, 3)) %>%
  mutate(ICER = round(ICER, 0)) %>%
  # Create INMB and rank column
  mutate(INMBRank = ifelse(
    Scenario!="S1NoCD",
    paste0(round(INMB, 0), "(", Ranking, ")"),
    NA)) %>%
  # Arrange and relabel the scenarios
  arrange(Scenario) %>%
  mutate(Scenario = recode(Scenario,
                           "S1NoCD" = "S0: No case detection",
                           "S1a" = "(S1a) CDQ ≥ 17 points",
                           "S1b" = "(S1b) Screening spirometry",
                           "S1c" = "(S1c) CDQ + screening spirometry",
                           "S2a" = "(S2a) Screening spirometry",
                           "S3a" = "(S3a) CDQ ≥ 19.5 points",
                           "S3b" = "(S3b) CDQ ≥ 16.5 points",
                           "S3c" = "(S3c) Screening spirometry",
                           "S3d" = "(S3d) CDQ + screening spirometry")) %>%
  # Select, reorder and relabel columns
  select(Scenario, Interval, CostpAgentAll, QALYpAgentAll, ICER, INMBRank) %>%
  rename("Testing interval" = Interval,
         "Costs ($/patient)" = CostpAgentAll,
         "QALYs (QALYs/patient)" = QALYpAgentAll,
         "ICER ($/QALY)" = ICER,
         "INMB (ranking)" = INMBRank)

# Preview dataframe
ceplane_pretty
```

    ##                            Scenario Testing interval Costs ($/patient)
    ## 1                         S1NoCDAvg          3 years             $2152
    ## 2                         S1NoCDAvg          5 years             $2152
    ## 3             (S1a) CDQ ≥ 17 points          3 years             $2430
    ## 4             (S1a) CDQ ≥ 17 points          5 years             $2355
    ## 5        (S1b) Screening spirometry          3 years             $2365
    ## 6        (S1b) Screening spirometry          5 years             $2311
    ## 7  (S1c) CDQ + screening spirometry          3 years             $2398
    ## 8  (S1c) CDQ + screening spirometry          5 years             $2300
    ## 9        (S2a) Screening spirometry          3 years             $2284
    ## 10       (S2a) Screening spirometry          5 years             $2235
    ## 11          (S3a) CDQ ≥ 19.5 points          3 years             $2220
    ## 12          (S3a) CDQ ≥ 19.5 points          5 years             $2218
    ## 13          (S3b) CDQ ≥ 16.5 points          3 years             $2273
    ## 14          (S3b) CDQ ≥ 16.5 points          5 years             $2258
    ## 15       (S3c) Screening spirometry          3 years             $2233
    ## 16       (S3c) Screening spirometry          5 years             $2219
    ## 17 (S3d) CDQ + screening spirometry          3 years             $2241
    ## 18 (S3d) CDQ + screening spirometry          5 years             $2222
    ##    QALYs (QALYs/patient) ICER ($/QALY) INMB (ranking)
    ## 1                 12.538            NA          0(15)
    ## 2                 12.538            NA          0(15)
    ## 3                 12.558         13791         703(2)
    ## 4                 12.560          9740         868(1)
    ## 5                 12.550         17035         386(9)
    ## 6                 12.554         10380         637(4)
    ## 7                 12.552         17438         433(7)
    ## 8                 12.544         27839        142(14)
    ## 9                 12.555          7853         703(3)
    ## 10                12.548          9106         418(8)
    ## 11                12.551          7930         556(5)
    ## 12                12.537        -80780       -126(18)
    ## 13                12.550         14736         440(6)
    ## 14                12.548         13430        366(10)
    ## 15                12.545         14727        246(12)
    ## 16                12.545         12968        251(11)
    ## 17                12.545         19458        230(13)
    ## 18                12.539        -38068        -42(17)

Compare against paper.

Prepare our model results…

``` r
# Prepare sall model results to combine with original table
ceplane_prep <- ceplane %>%
  # Replace S1NoCD with S0
  mutate(Scenario = replace(Scenario, Scenario == "S1NoCD", "S0")) %>%
  # Round columns
  mutate(CostpAgentAll = round(CostpAgentAll, 0)) %>%
  mutate(QALYpAgentAll = round(QALYpAgentAll, 3)) %>%
  mutate(ICER = round(ICER, 0)) %>%
  mutate(INMB = round(INMB, 0)) %>%
  # Select relevant columns
  select(Scenario, Interval, CostpAgentAll, QALYpAgentAll, ICER, INMB, Ranking)

ceplane_prep
```

    ##     Scenario Interval CostpAgentAll QALYpAgentAll   ICER INMB Ranking
    ## 1  S1NoCDAvg  3 years          2152        12.538     NA    0      15
    ## 2        S1a  3 years          2430        12.558  13791  703       2
    ## 3        S1b  3 years          2365        12.550  17035  386       9
    ## 4        S1c  3 years          2398        12.552  17438  433       7
    ## 5        S2a  3 years          2284        12.555   7853  703       3
    ## 6        S3a  3 years          2220        12.551   7930  556       5
    ## 7        S3b  3 years          2273        12.550  14736  440       6
    ## 8        S3c  3 years          2233        12.545  14727  246      12
    ## 9        S3d  3 years          2241        12.545  19458  230      13
    ## 10 S1NoCDAvg  5 years          2152        12.538     NA    0      15
    ## 11       S1a  5 years          2355        12.560   9740  868       1
    ## 12       S1b  5 years          2311        12.554  10380  637       4
    ## 13       S1c  5 years          2300        12.544  27839  142      14
    ## 14       S2a  5 years          2235        12.548   9106  418       8
    ## 15       S3a  5 years          2218        12.537 -80780 -126      18
    ## 16       S3b  5 years          2258        12.548  13430  366      10
    ## 17       S3c  5 years          2219        12.545  12968  251      11
    ## 18       S3d  5 years          2222        12.539 -38068  -42      17

Prepare results from the paper…

``` r
# Convert costs to numeric
paper_tab3_prep <- paper_tab3 %>%
  mutate(CostpAgent = readr::parse_number(CostpAgent))

# Append "_paper" to columns (except Scenario and Interval)
icol <- which(names(paper_tab3_prep) %in% c("Scenario", "Interval"))
colnames(paper_tab3_prep)[-icol] <- paste(colnames(paper_tab3_prep)[-icol], "paper", sep = "_")

# Preview dataframe
paper_tab3_prep
```

    ##    Scenario Interval CostpAgent_paper QALYpAgent_paper ICER_paper
    ## 1        S0     <NA>             2151           12.546         NA
    ## 2       S1a  3 years             2438           12.560      19632
    ## 3       S1a  5 years             2356           12.556      19847
    ## 4       S1b  3 years             2363           12.554      25894
    ## 5       S1b  5 years             2296           12.552      23187
    ## 6       S1c  3 years             2386           12.551      46956
    ## 7       S1c  5 years             2313           12.550      38673
    ## 8       S2a  3 years             2286           12.553      18908
    ## 9       S2a  5 years             2246           12.551      17514
    ## 10      S3a  3 years             2234           12.548      30366
    ## 11      S3a  5 years             2207           12.548      22636
    ## 12      S3b  3 years             2292           12.553      18438
    ## 13      S3b  5 years             2250           12.552      16251
    ## 14      S3c  3 years             2256           12.550      23972
    ## 15      S3c  5 years             2224           12.549      20278
    ## 16      S3d  3 years             2263           12.549      28245
    ## 17      S3d  5 years             2227           12.548      27591
    ##    IncrementalNMB_paper Ranking_paper
    ## 1                    NA            NA
    ## 2                   444             1
    ## 3                   312             2
    ## 4                   198             6
    ## 5                   168             8
    ## 6                    15            16
    ## 7                    47            15
    ## 8                   223             4
    ## 9                   176             7
    ## 10                   54            14
    ## 11                   68            12
    ## 12                  241             3
    ## 13                  206             5
    ## 14                  114             9
    ## 15                  107            10
    ## 16                   86            11
    ## 17                   62            13

``` r
original_ceplane_prep <- original_ceplane %>%
  # Replace S1NoCD with S0
  mutate(Scenario = replace(Scenario, Scenario == "S1NoCD", "S0")) %>%
  # Round columns
  mutate(CostpAgentAll = round(CostpAgentAll, 0)) %>%
  mutate(QALYpAgentAll = round(QALYpAgentAll, 3)) %>%
  mutate(ICER = round(ICER, 0)) %>%
  mutate(INMB = round(INMB, 0)) %>%
  # Select relevant columns
  select(Scenario, Interval, CostpAgentAll, QALYpAgentAll, ICER, INMB)

# Append "_repo" to columns (except Scenario and Interval)
icol <- which(names(original_ceplane_prep) %in% c("Scenario", "Interval"))
colnames(original_ceplane_prep)[-icol] <- paste(
  colnames(original_ceplane_prep)[-icol], "repo", sep = "_")

original_ceplane_prep
```

    ##     Scenario Interval CostpAgentAll_repo QALYpAgentAll_repo ICER_repo INMB_repo
    ## 1  S1NoCDAvg  3 years               2151             12.545       NaN         0
    ## 2        S1a  3 years               2439             12.560     18767       446
    ## 3        S1b  3 years               2365             12.552     28168       131
    ## 4        S1c  3 years               2386             12.551     37782        40
    ## 5     S2NoCD  3 years               2151             12.545       NaN         0
    ## 6        S2a  3 years               2287             12.552     21840       186
    ## 7     S3NoCD  3 years               2151             12.545       NaN         0
    ## 8        S3a  3 years               2232             12.548     34146        45
    ## 9        S3b  3 years               2289             12.553     19575       243
    ## 10       S3c  3 years               2255             12.550     21507       148
    ## 11       S3d  3 years               2261             12.550     21157       124
    ## 12 S1NoCDAvg  5 years               2151             12.545       NaN         0
    ## 13       S1a  5 years               2355             12.557     17603       411
    ## 14       S1b  5 years               2298             12.551     29091       142
    ## 15       S1c  5 years               2311             12.551     34119       110
    ## 16    S2NoCD  5 years               2151             12.545       NaN         0
    ## 17       S2a  5 years               2245             12.550     19840       137
    ## 18    S3NoCD  5 years               2151             12.545       NaN         0
    ## 19       S3a  5 years               2207             12.548     22117        67
    ## 20       S3b  5 years               2248             12.551     17541       183
    ## 21       S3c  5 years               2221             12.549     17870       113
    ## 22       S3d  5 years               2226             12.548     25402        67

``` r
calc_diff_perc <- function(df, our_res, paper_res, repo_res, prefix) {
  #' Calculate the difference and percentage difference between two columns
  #' 
  #' @param df Dataframe containing columns
  #' @param our_res Column with results from our run of the model
  #' @param paper_res Column with results from the paper table 3
  #' @param repo_res Column with results from the .md files in their repository
  #' @param prefix String to prefix start of the result columns
  #' 
  #' @return Dataframe with the column pair, results, scenario and interval

  # Create column names for differences
  mydiff <- paste0(prefix, "MyDiff")
  myperc <- paste0(prefix, "MyPerc")
  repodiff <- paste0(prefix, "RepoDiff")
  repoperc <- paste0(prefix, "RepoPerc")

  # Calculate the difference and percentage difference between col1 and col2
  df %>%
    mutate(
      !!sym(mydiff) := !!sym(paper_res) - !!sym(our_res),
      !!sym(myperc) := scales::percent(round(!!sym(mydiff) / !!sym(our_res), 3)),
      !!sym(repodiff) := !!sym(paper_res) - !!sym(repo_res),
      !!sym(repoperc) := scales::percent(round(!!sym(repodiff) / !!sym(repo_res), 3))
    ) %>%
    # Select only those columns, as well as Scenario and Interval
    select(Scenario, Interval,
           !!sym(paper_res), !!sym(our_res), !!sym(repo_res),
           !!sym(mydiff), !!sym(myperc),
           !!sym(repodiff), !!sym(repoperc))
}

# Combine the model and paper results
ceplane_combine <- merge(ceplane_prep, paper_tab3_prep, by=c("Scenario", "Interval")) %>%
  merge(original_ceplane_prep, by=c("Scenario", "Interval"))

# Define the pairs of columns to compare and the prefix to use for their comparison
column_pairs <- list(
  c("CostpAgentAll", "CostpAgent_paper", "CostpAgentAll_repo", "Cost"),
  c("QALYpAgentAll", "QALYpAgent_paper", "QALYpAgentAll_repo", "QALY"),
  c("ICER", "ICER_paper", "ICER_repo", "ICER"),
  c("INMB", "IncrementalNMB_paper", "INMB_repo", "INMB")
)

# Combine model and paper results and apply the function for each pair of columns
ceplane_compare <- column_pairs %>%
  purrr::map(~ calc_diff_perc(ceplane_combine, .x[1], .x[2], .x[3], .x[4])) %>%
  purrr::reduce(left_join, by = c("Scenario", "Interval"))

# Save to csv and view
write.csv(ceplane_compare, paths$tab3_compare, row.names=FALSE)
ceplane_compare
```

    ##    Scenario Interval CostpAgent_paper CostpAgentAll CostpAgentAll_repo
    ## 1       S1a  3 years             2438          2430               2439
    ## 2       S1a  5 years             2356          2355               2355
    ## 3       S1b  3 years             2363          2365               2365
    ## 4       S1b  5 years             2296          2311               2298
    ## 5       S1c  3 years             2386          2398               2386
    ## 6       S1c  5 years             2313          2300               2311
    ## 7       S2a  3 years             2286          2284               2287
    ## 8       S2a  5 years             2246          2235               2245
    ## 9       S3a  3 years             2234          2220               2232
    ## 10      S3a  5 years             2207          2218               2207
    ## 11      S3b  3 years             2292          2273               2289
    ## 12      S3b  5 years             2250          2258               2248
    ## 13      S3c  3 years             2256          2233               2255
    ## 14      S3c  5 years             2224          2219               2221
    ## 15      S3d  3 years             2263          2241               2261
    ## 16      S3d  5 years             2227          2222               2226
    ##    CostMyDiff CostMyPerc CostRepoDiff CostRepoPerc QALYpAgent_paper
    ## 1           8       0.3%           -1         0.0%           12.560
    ## 2           1       0.0%            1         0.0%           12.556
    ## 3          -2      -0.1%           -2        -0.1%           12.554
    ## 4         -15      -0.6%           -2        -0.1%           12.552
    ## 5         -12      -0.5%            0         0.0%           12.551
    ## 6          13       0.6%            2         0.1%           12.550
    ## 7           2       0.1%           -1         0.0%           12.553
    ## 8          11       0.5%            1         0.0%           12.551
    ## 9          14       0.6%            2         0.1%           12.548
    ## 10        -11      -0.5%            0         0.0%           12.548
    ## 11         19       0.8%            3         0.1%           12.553
    ## 12         -8      -0.4%            2         0.1%           12.552
    ## 13         23       1.0%            1         0.0%           12.550
    ## 14          5       0.2%            3         0.1%           12.549
    ## 15         22       1.0%            2         0.1%           12.549
    ## 16          5       0.2%            1         0.0%           12.548
    ##    QALYpAgentAll QALYpAgentAll_repo QALYMyDiff QALYMyPerc QALYRepoDiff
    ## 1         12.558             12.560      0.002       0.0%        0.000
    ## 2         12.560             12.557     -0.004       0.0%       -0.001
    ## 3         12.550             12.552      0.004       0.0%        0.002
    ## 4         12.554             12.551     -0.002       0.0%        0.001
    ## 5         12.552             12.551     -0.001       0.0%        0.000
    ## 6         12.544             12.551      0.006       0.0%       -0.001
    ## 7         12.555             12.552     -0.002       0.0%        0.001
    ## 8         12.548             12.550      0.003       0.0%        0.001
    ## 9         12.551             12.548     -0.003       0.0%        0.000
    ## 10        12.537             12.548      0.011       0.1%        0.000
    ## 11        12.550             12.553      0.003       0.0%        0.000
    ## 12        12.548             12.551      0.004       0.0%        0.001
    ## 13        12.545             12.550      0.005       0.0%        0.000
    ## 14        12.545             12.549      0.004       0.0%        0.000
    ## 15        12.545             12.550      0.004       0.0%       -0.001
    ## 16        12.539             12.548      0.009       0.1%        0.000
    ##    QALYRepoPerc ICER_paper   ICER ICER_repo ICERMyDiff ICERMyPerc ICERRepoDiff
    ## 1            0%      19632  13791     18767       5841      42.4%          865
    ## 2            0%      19847   9740     17603      10107     103.8%         2244
    ## 3            0%      25894  17035     28168       8859      52.0%        -2274
    ## 4            0%      23187  10380     29091      12807     123.4%        -5904
    ## 5            0%      46956  17438     37782      29518     169.3%         9174
    ## 6            0%      38673  27839     34119      10834      38.9%         4554
    ## 7            0%      18908   7853     21840      11055     140.8%        -2932
    ## 8            0%      17514   9106     19840       8408      92.3%        -2326
    ## 9            0%      30366   7930     34146      22436     282.9%        -3780
    ## 10           0%      22636 -80780     22117     103416    -128.0%          519
    ## 11           0%      18438  14736     19575       3702      25.1%        -1137
    ## 12           0%      16251  13430     17541       2821      21.0%        -1290
    ## 13           0%      23972  14727     21507       9245      62.8%         2465
    ## 14           0%      20278  12968     17870       7310      56.4%         2408
    ## 15           0%      28245  19458     21157       8787      45.2%         7088
    ## 16           0%      27591 -38068     25402      65659    -172.5%         2189
    ##    ICERRepoPerc IncrementalNMB_paper INMB INMB_repo INMBMyDiff INMBMyPerc
    ## 1          4.6%                  444  703       446       -259     -36.8%
    ## 2         12.7%                  312  868       411       -556     -64.1%
    ## 3         -8.1%                  198  386       131       -188     -48.7%
    ## 4        -20.3%                  168  637       142       -469     -73.6%
    ## 5         24.3%                   15  433        40       -418     -96.5%
    ## 6         13.3%                   47  142       110        -95     -66.9%
    ## 7        -13.4%                  223  703       186       -480     -68.3%
    ## 8        -11.7%                  176  418       137       -242     -57.9%
    ## 9        -11.1%                   54  556        45       -502     -90.3%
    ## 10         2.3%                   68 -126        67        194    -154.0%
    ## 11        -5.8%                  241  440       243       -199     -45.2%
    ## 12        -7.4%                  206  366       183       -160     -43.7%
    ## 13        11.5%                  114  246       148       -132     -53.7%
    ## 14        13.5%                  107  251       113       -144     -57.4%
    ## 15        33.5%                   86  230       124       -144     -62.6%
    ## 16         8.6%                   62  -42        67        104    -247.6%
    ##    INMBRepoDiff INMBRepoPerc
    ## 1            -2       -0.40%
    ## 2           -99      -24.10%
    ## 3            67       51.10%
    ## 4            26       18.30%
    ## 5           -25      -62.50%
    ## 6           -63      -57.30%
    ## 7            37       19.90%
    ## 8            39       28.50%
    ## 9             9       20.00%
    ## 10            1        1.50%
    ## 11           -2       -0.80%
    ## 12           23       12.60%
    ## 13          -34      -23.00%
    ## 14           -6       -5.30%
    ## 15          -38      -30.60%
    ## 16           -5       -7.50%
