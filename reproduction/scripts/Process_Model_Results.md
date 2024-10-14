Process Model Results
================
14 October, 2024

This file processes the model results so they match up as closely as
possible to those in the publication.

It aims to produce **Table 3**, **Figure 3** and **Appendix 6**.

``` r
# Clear environment before start
rm(list=ls())

# Set save location for figures generated when knit rmd
knitr::opts_chunk$set(fig.path = "../outputs/")

# Load required libraries
library(dplyr)
library(ggplot2)
library(ggpubr)
```

## Define file paths and import files

``` r
paths <- list(
  # Model results
  s1 = "../outputs/s1.csv",
  sall_3y = "../outputs/sall.csv",
  sall_5y = "../outputs/sall_5y.csv",
  ceplane_3y = "../outputs/ceplane.csv",
  ceplane_5y = "../outputs/ceplane_5y.csv",
  clinical = "../outputs/clinicalresults.csv",

  # Original study results
  paper_tab3 = "../../original_study/tab3.csv",
  original_sall = "../../original_study/sall.csv",
  original_ceplane = "../../original_study/ceplane.csv",

  # Outputs from this .Rmd file
  tab3 = "../outputs/tab3.csv",
  tab3_compare = "../outputs/tab3_compare_to_original.csv",
  fig3 = "../outputs/fig3-1.png",
  apx6 = "../outputs/appendix6-1.png"
)
```

``` r
s1 <- read.csv(paths$s1)
sall_3y <- read.csv(paths$sall_3y) %>% mutate("Interval" = "3 years")
sall_5y <- read.csv(paths$sall_5y) %>% mutate("Interval" = "5 years")
ceplane_3y <- read.csv(paths$ceplane_3y) %>% mutate("Interval" = "3 years")
ceplane_5y <- read.csv(paths$ceplane_5y) %>% mutate("Interval" = "5 years")
clinical <- read.csv(paths$clinical)

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

<div class="kable-table">

| Scenario  |   Agents | PropAgents |        Cost | CostpAgent | CostpAgentExcluded | CostpAgentAll |      QALY | QALYpAgent | QALYpAgentExcluded | QALYpAgentAll | IncrementalCosts | IncrementalQALY |  ICERAdj |     ICER |        INMB | Interval |
|:----------|---------:|-----------:|------------:|-----------:|-------------------:|--------------:|----------:|-----------:|-------------------:|--------------:|-----------------:|----------------:|---------:|---------:|------------:|:---------|
| S1NoCDAvg | 37197054 |  1.0000000 | 79930541441 |   2148.841 |              0.000 |      2148.841 | 466645458 |   12.54523 |            0.00000 |      12.54523 |          0.00000 |       0.0000000 |       NA |       NA |   0.0000000 | 3 years  |
| S1NoCDAvg | 37197054 |  1.0000000 | 79930541441 |   2148.841 |              0.000 |      2148.841 | 466645458 |   12.54523 |            0.00000 |      12.54523 |          0.00000 |       0.0000000 |       NA |       NA |   0.0000000 | 5 years  |
| S1a       | 37195779 |  1.0000000 | 90753454326 |   2439.886 |              0.000 |      2439.886 | 467242138 |   12.56170 |            0.00000 |      12.56170 |        291.04522 |       0.0164718 | 17669.33 | 17116.09 | 532.5435790 | 3 years  |
| S1a       | 37197502 |  1.0000000 | 87609315426 |   2355.247 |              0.000 |      2355.247 | 467053611 |   12.55605 |            0.00000 |      12.55605 |        206.40667 |       0.0108217 | 19073.48 | 20089.64 | 334.6763156 | 5 years  |
| S1b       | 37200476 |  1.0000000 | 87878153022 |   2362.286 |              0.000 |      2362.286 | 466988044 |   12.55328 |            0.00000 |      12.55328 |        213.44510 |       0.0080553 | 26497.34 | 24764.46 | 189.3218597 | 3 years  |
| S1b       | 37190655 |  1.0000000 | 85474784067 |   2298.287 |              0.000 |      2298.287 | 466807667 |   12.55175 |            0.00000 |      12.55175 |        149.44599 |       0.0065202 | 22920.31 | 25093.04 | 176.5661465 | 5 years  |
| S1c       | 37192813 |  1.0000000 | 88797560537 |   2387.492 |              0.000 |      2387.492 | 466783360 |   12.55036 |            0.00000 |      12.55036 |        238.65184 |       0.0051384 | 46444.60 | 41646.33 |  18.2691463 | 3 years  |
| S1c       | 37195162 |  1.0000000 | 86086185363 |   2314.446 |              0.000 |      2314.446 | 466843147 |   12.55118 |            0.00000 |      12.55118 |        165.60516 |       0.0059532 | 27817.85 | 30805.50 | 132.0547739 | 5 years  |
| S2NoCD    | 22078563 |  0.5935568 | 58731887921 |   2660.132 |           1402.167 |      2148.841 | 270917818 |   12.27063 |           12.94624 |      12.54523 |          0.00000 |       0.0000000 |       NA |       NA |   0.0084027 | 3 years  |
| S2NoCD    | 22074342 |  0.5934433 | 58922537505 |   2669.277 |           1389.169 |      2148.841 | 270895360 |   12.27196 |           12.94411 |      12.54523 |          0.00000 |       0.0000000 |       NA |       NA |   0.0084027 | 5 years  |
| S2a       | 22077788 |  0.5935359 | 63840415723 |   2891.613 |           1402.167 |      2286.207 | 271190365 |   12.28340 |           12.94624 |      12.55282 |        137.36611 |       0.0075969 | 18081.98 | 18119.00 | 242.4848714 | 3 years  |
| S2a       | 22077777 |  0.5935356 | 62347138314 |   2823.977 |           1389.169 |      2240.779 | 271063504 |   12.27766 |           12.94411 |      12.54855 |         91.93817 |       0.0033250 | 27650.44 | 27108.82 |  74.3210751 | 5 years  |
| S3NoCD    | 17243525 |  0.4635723 | 49933527334 |   2895.784 |           1503.344 |      2148.841 | 193676014 |   11.23181 |           13.68026 |      12.54523 |          0.00000 |       0.0000000 |       NA |       NA |   0.0084027 | 3 years  |
| S3NoCD    | 17254548 |  0.4638687 | 50064966233 |   2901.552 |           1497.584 |      2148.841 | 193797357 |   11.23167 |           13.68174 |      12.54523 |          0.00000 |       0.0000000 |       NA |       NA |   0.0084027 | 5 years  |
| S3a       | 17245589 |  0.4636278 | 53097071421 |   3078.878 |           1503.344 |      2233.805 | 193814317 |   11.23849 |           13.68026 |      12.54819 |         84.96483 |       0.0029590 | 28713.97 | 27428.51 |  62.9938915 | 3 years  |
| S3a       | 17251608 |  0.4637896 | 52066304895 |   3018.055 |           1497.584 |      2202.763 | 193847860 |   11.23651 |           13.68174 |      12.54767 |         53.92205 |       0.0024391 | 22107.45 | 24063.44 |  68.0408589 | 5 years  |
| S3b       | 17248093 |  0.4636951 | 55163743515 |   3198.252 |           1503.344 |      2289.264 | 193983110 |   11.24664 |           13.68026 |      12.55180 |        140.42373 |       0.0065759 | 21354.32 | 20395.72 | 188.3794023 | 3 years  |
| S3b       | 17246874 |  0.4636624 | 53626126689 |   3109.324 |           1497.584 |      2244.887 | 193956939 |   11.24592 |           13.68174 |      12.55234 |         96.04666 |       0.0071128 | 13503.33 | 14580.18 | 259.6024694 | 5 years  |
| S3c       | 17249568 |  0.4637348 | 53820717606 |   3120.120 |           1503.344 |      2253.099 | 193896397 |   11.24065 |           13.68026 |      12.54893 |        104.25841 |       0.0037023 | 28160.79 | 25373.54 |  80.8627246 | 3 years  |
| S3c       | 17246125 |  0.4636422 | 52687996543 |   3055.063 |           1497.584 |      2219.697 | 193867414 |   11.24122 |           13.68174 |      12.55021 |         70.85627 |       0.0049815 | 14223.79 | 16078.26 | 178.2287927 | 5 years  |
| S3d       | 17250373 |  0.4637564 | 54140141633 |   3138.491 |           1503.344 |      2261.654 | 193895422 |   11.24007 |           13.68026 |      12.54861 |        112.81322 |       0.0033800 | 33376.80 | 29382.46 |  56.1946409 | 3 years  |
| S3d       | 17255729 |  0.4639004 | 52823751959 |   3061.230 |           1497.584 |      2222.960 | 193917114 |   11.23784 |           13.68174 |      12.54801 |         74.11923 |       0.0027851 | 26612.42 | 25873.76 |  65.1460215 | 5 years  |

</div>

Combine, organise and modify results as per paper.

``` r
ceplane <- rbind(ceplane_3y, ceplane_5y) %>%
  # Remove scenarios 2 and 3 with no case detection, and scenario 2b
  filter(!(Scenario %in% c("S2NoCD", "S3NoCD", "S2b"))) %>%
  # Remove S1NoCDAvg from 5 years, then set interval of S1NoCDAvg to NA
  filter(!(Scenario == "S1NoCDAvg" & Interval == "5 years")) %>%
  mutate(Interval = ifelse(Scenario == "S1NoCDAvg", NA, Interval)) %>%
  # Remove INMB for S1NoCDAvg
  mutate(INMB = ifelse(Scenario!="S1NoCDAvg", INMB, NA)) %>%
  # Get INMB ranking
  mutate(Ranking = min_rank(desc(INMB)))

ceplane %>% arrange(Scenario)
```

<div class="kable-table">

| Scenario  |   Agents | PropAgents |        Cost | CostpAgent | CostpAgentExcluded | CostpAgentAll |      QALY | QALYpAgent | QALYpAgentExcluded | QALYpAgentAll | IncrementalCosts | IncrementalQALY |  ICERAdj |     ICER |      INMB | Interval | Ranking |
|:----------|---------:|-----------:|------------:|-----------:|-------------------:|--------------:|----------:|-----------:|-------------------:|--------------:|-----------------:|----------------:|---------:|---------:|----------:|:---------|--------:|
| S1NoCDAvg | 37197054 |  1.0000000 | 79930541441 |   2148.841 |              0.000 |      2148.841 | 466645458 |   12.54523 |            0.00000 |      12.54523 |          0.00000 |       0.0000000 |       NA |       NA |        NA | NA       |      NA |
| S1a       | 37195779 |  1.0000000 | 90753454326 |   2439.886 |              0.000 |      2439.886 | 467242138 |   12.56170 |            0.00000 |      12.56170 |        291.04522 |       0.0164718 | 17669.33 | 17116.09 | 532.54358 | 3 years  |       1 |
| S1a       | 37197502 |  1.0000000 | 87609315426 |   2355.247 |              0.000 |      2355.247 | 467053611 |   12.55605 |            0.00000 |      12.55605 |        206.40667 |       0.0108217 | 19073.48 | 20089.64 | 334.67632 | 5 years  |       2 |
| S1b       | 37200476 |  1.0000000 | 87878153022 |   2362.286 |              0.000 |      2362.286 | 466988044 |   12.55328 |            0.00000 |      12.55328 |        213.44510 |       0.0080553 | 26497.34 | 24764.46 | 189.32186 | 3 years  |       5 |
| S1b       | 37190655 |  1.0000000 | 85474784067 |   2298.287 |              0.000 |      2298.287 | 466807667 |   12.55175 |            0.00000 |      12.55175 |        149.44599 |       0.0065202 | 22920.31 | 25093.04 | 176.56615 | 5 years  |       8 |
| S1c       | 37192813 |  1.0000000 | 88797560537 |   2387.492 |              0.000 |      2387.492 | 466783360 |   12.55036 |            0.00000 |      12.55036 |        238.65184 |       0.0051384 | 46444.60 | 41646.33 |  18.26915 | 3 years  |      16 |
| S1c       | 37195162 |  1.0000000 | 86086185363 |   2314.446 |              0.000 |      2314.446 | 466843147 |   12.55118 |            0.00000 |      12.55118 |        165.60516 |       0.0059532 | 27817.85 | 30805.50 | 132.05477 | 5 years  |       9 |
| S2a       | 22077788 |  0.5935359 | 63840415723 |   2891.613 |           1402.167 |      2286.207 | 271190365 |   12.28340 |           12.94624 |      12.55282 |        137.36611 |       0.0075969 | 18081.98 | 18119.00 | 242.48487 | 3 years  |       4 |
| S2a       | 22077777 |  0.5935356 | 62347138314 |   2823.977 |           1389.169 |      2240.779 | 271063504 |   12.27766 |           12.94411 |      12.54855 |         91.93817 |       0.0033250 | 27650.44 | 27108.82 |  74.32108 | 5 years  |      11 |
| S3a       | 17245589 |  0.4636278 | 53097071421 |   3078.878 |           1503.344 |      2233.805 | 193814317 |   11.23849 |           13.68026 |      12.54819 |         84.96483 |       0.0029590 | 28713.97 | 27428.51 |  62.99389 | 3 years  |      14 |
| S3a       | 17251608 |  0.4637896 | 52066304895 |   3018.055 |           1497.584 |      2202.763 | 193847860 |   11.23651 |           13.68174 |      12.54767 |         53.92205 |       0.0024391 | 22107.45 | 24063.44 |  68.04086 | 5 years  |      12 |
| S3b       | 17248093 |  0.4636951 | 55163743515 |   3198.252 |           1503.344 |      2289.264 | 193983110 |   11.24664 |           13.68026 |      12.55180 |        140.42373 |       0.0065759 | 21354.32 | 20395.72 | 188.37940 | 3 years  |       6 |
| S3b       | 17246874 |  0.4636624 | 53626126689 |   3109.324 |           1497.584 |      2244.887 | 193956939 |   11.24592 |           13.68174 |      12.55234 |         96.04666 |       0.0071128 | 13503.33 | 14580.18 | 259.60247 | 5 years  |       3 |
| S3c       | 17249568 |  0.4637348 | 53820717606 |   3120.120 |           1503.344 |      2253.099 | 193896397 |   11.24065 |           13.68026 |      12.54893 |        104.25841 |       0.0037023 | 28160.79 | 25373.54 |  80.86272 | 3 years  |      10 |
| S3c       | 17246125 |  0.4636422 | 52687996543 |   3055.063 |           1497.584 |      2219.697 | 193867414 |   11.24122 |           13.68174 |      12.55021 |         70.85627 |       0.0049815 | 14223.79 | 16078.26 | 178.22879 | 5 years  |       7 |
| S3d       | 17250373 |  0.4637564 | 54140141633 |   3138.491 |           1503.344 |      2261.654 | 193895422 |   11.24007 |           13.68026 |      12.54861 |        112.81322 |       0.0033800 | 33376.80 | 29382.46 |  56.19464 | 3 years  |      15 |
| S3d       | 17255729 |  0.4639004 | 52823751959 |   3061.230 |           1497.584 |      2222.960 | 193917114 |   11.23784 |           13.68174 |      12.54801 |         74.11923 |       0.0027851 | 26612.42 | 25873.76 |  65.14602 | 5 years  |      13 |

</div>

Reformat to match paper.

``` r
ceplane_pretty <- ceplane %>%
  # Round columns
  mutate(CostpAgentAll = paste0("$", round(CostpAgentAll, 0))) %>%
  mutate(QALYpAgentAll = round(QALYpAgentAll, 3)) %>%
  mutate(ICERAdj = round(ICERAdj, 0)) %>%
  # Create INMB and rank column
  mutate(INMBRank = ifelse(
    Scenario!="S1NoCDAvg",
    paste0(round(INMB, 0), "(", Ranking, ")"),
    NA)) %>%
  # Arrange and relabel the scenarios
  arrange(Scenario) %>%
  mutate(Scenario = recode(Scenario,
                           "S1NoCDAvg" = "S0: No case detection",
                           "S1a" = "(S1a) CDQ ≥ 17 points",
                           "S1b" = "(S1b) Screening spirometry",
                           "S1c" = "(S1c) CDQ + screening spirometry",
                           "S2a" = "(S2a) Screening spirometry",
                           "S3a" = "(S3a) CDQ ≥ 19.5 points",
                           "S3b" = "(S3b) CDQ ≥ 16.5 points",
                           "S3c" = "(S3c) Screening spirometry",
                           "S3d" = "(S3d) CDQ + screening spirometry")) %>%
  # Select, reorder and relabel columns
  select(Scenario, Interval, CostpAgentAll, QALYpAgentAll, ICERAdj, INMBRank) %>%
  rename("Testing interval" = Interval,
         "Costs per patient" = CostpAgentAll,
         "QALYs per patient" = QALYpAgentAll,
         "ICER" = ICERAdj,
         "INMB (ranking)" = INMBRank)

# Save to csv
write.csv(ceplane_pretty, paths$tab3, row.names=FALSE)

# View dataframe
ceplane_pretty
```

<div class="kable-table">

| Scenario                         | Testing interval | Costs per patient | QALYs per patient |  ICER | INMB (ranking) |
|:---------------------------------|:-----------------|:------------------|------------------:|------:|:---------------|
| S0: No case detection            | NA               | \$2149            |            12.545 |    NA | NA             |
| (S1a) CDQ ≥ 17 points            | 3 years          | \$2440            |            12.562 | 17669 | 533(1)         |
| (S1a) CDQ ≥ 17 points            | 5 years          | \$2355            |            12.556 | 19073 | 335(2)         |
| (S1b) Screening spirometry       | 3 years          | \$2362            |            12.553 | 26497 | 189(5)         |
| (S1b) Screening spirometry       | 5 years          | \$2298            |            12.552 | 22920 | 177(8)         |
| (S1c) CDQ + screening spirometry | 3 years          | \$2387            |            12.550 | 46445 | 18(16)         |
| (S1c) CDQ + screening spirometry | 5 years          | \$2314            |            12.551 | 27818 | 132(9)         |
| (S2a) Screening spirometry       | 3 years          | \$2286            |            12.553 | 18082 | 242(4)         |
| (S2a) Screening spirometry       | 5 years          | \$2241            |            12.549 | 27650 | 74(11)         |
| (S3a) CDQ ≥ 19.5 points          | 3 years          | \$2234            |            12.548 | 28714 | 63(14)         |
| (S3a) CDQ ≥ 19.5 points          | 5 years          | \$2203            |            12.548 | 22107 | 68(12)         |
| (S3b) CDQ ≥ 16.5 points          | 3 years          | \$2289            |            12.552 | 21354 | 188(6)         |
| (S3b) CDQ ≥ 16.5 points          | 5 years          | \$2245            |            12.552 | 13503 | 260(3)         |
| (S3c) Screening spirometry       | 3 years          | \$2253            |            12.549 | 28161 | 81(10)         |
| (S3c) Screening spirometry       | 5 years          | \$2220            |            12.550 | 14224 | 178(7)         |
| (S3d) CDQ + screening spirometry | 3 years          | \$2262            |            12.549 | 33377 | 56(15)         |
| (S3d) CDQ + screening spirometry | 5 years          | \$2223            |            12.548 | 26612 | 65(13)         |

</div>

### Compare between our results, the paper, and their repository

Prepare our model results…

``` r
# Prepare sall model results to combine with original table
ceplane_prep <- ceplane %>%
  # Replace S1NoCDAvg with S0
  mutate(Scenario = replace(Scenario, Scenario == "S1NoCDAvg", "S0")) %>%
  # Round columns
  mutate(CostpAgentAll = round(CostpAgentAll, 0)) %>%
  mutate(QALYpAgentAll = round(QALYpAgentAll, 3)) %>%
  mutate(ICERAdj = round(ICERAdj, 0)) %>%
  mutate(INMB = round(INMB, 0)) %>%
  # Select relevant columns
  select(Scenario, Interval, CostpAgentAll, QALYpAgentAll, ICERAdj, INMB, Ranking)
ceplane_prep
```

<div class="kable-table">

| Scenario | Interval | CostpAgentAll | QALYpAgentAll | ICERAdj | INMB | Ranking |
|:---------|:---------|--------------:|--------------:|--------:|-----:|--------:|
| S0       | NA       |          2149 |        12.545 |      NA |   NA |      NA |
| S1a      | 3 years  |          2440 |        12.562 |   17669 |  533 |       1 |
| S1b      | 3 years  |          2362 |        12.553 |   26497 |  189 |       5 |
| S1c      | 3 years  |          2387 |        12.550 |   46445 |   18 |      16 |
| S2a      | 3 years  |          2286 |        12.553 |   18082 |  242 |       4 |
| S3a      | 3 years  |          2234 |        12.548 |   28714 |   63 |      14 |
| S3b      | 3 years  |          2289 |        12.552 |   21354 |  188 |       6 |
| S3c      | 3 years  |          2253 |        12.549 |   28161 |   81 |      10 |
| S3d      | 3 years  |          2262 |        12.549 |   33377 |   56 |      15 |
| S1a      | 5 years  |          2355 |        12.556 |   19073 |  335 |       2 |
| S1b      | 5 years  |          2298 |        12.552 |   22920 |  177 |       8 |
| S1c      | 5 years  |          2314 |        12.551 |   27818 |  132 |       9 |
| S2a      | 5 years  |          2241 |        12.549 |   27650 |   74 |      11 |
| S3a      | 5 years  |          2203 |        12.548 |   22107 |   68 |      12 |
| S3b      | 5 years  |          2245 |        12.552 |   13503 |  260 |       3 |
| S3c      | 5 years  |          2220 |        12.550 |   14224 |  178 |       7 |
| S3d      | 5 years  |          2223 |        12.548 |   26612 |   65 |      13 |

</div>

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

<div class="kable-table">

| Scenario | Interval | CostpAgent_paper | QALYpAgent_paper | ICER_paper | IncrementalNMB_paper | Ranking_paper |
|:---------|:---------|-----------------:|-----------------:|-----------:|---------------------:|--------------:|
| S0       | NA       |             2151 |           12.546 |         NA |                   NA |            NA |
| S1a      | 3 years  |             2438 |           12.560 |      19632 |                  444 |             1 |
| S1a      | 5 years  |             2356 |           12.556 |      19847 |                  312 |             2 |
| S1b      | 3 years  |             2363 |           12.554 |      25894 |                  198 |             6 |
| S1b      | 5 years  |             2296 |           12.552 |      23187 |                  168 |             8 |
| S1c      | 3 years  |             2386 |           12.551 |      46956 |                   15 |            16 |
| S1c      | 5 years  |             2313 |           12.550 |      38673 |                   47 |            15 |
| S2a      | 3 years  |             2286 |           12.553 |      18908 |                  223 |             4 |
| S2a      | 5 years  |             2246 |           12.551 |      17514 |                  176 |             7 |
| S3a      | 3 years  |             2234 |           12.548 |      30366 |                   54 |            14 |
| S3a      | 5 years  |             2207 |           12.548 |      22636 |                   68 |            12 |
| S3b      | 3 years  |             2292 |           12.553 |      18438 |                  241 |             3 |
| S3b      | 5 years  |             2250 |           12.552 |      16251 |                  206 |             5 |
| S3c      | 3 years  |             2256 |           12.550 |      23972 |                  114 |             9 |
| S3c      | 5 years  |             2224 |           12.549 |      20278 |                  107 |            10 |
| S3d      | 3 years  |             2263 |           12.549 |      28245 |                   86 |            11 |
| S3d      | 5 years  |             2227 |           12.548 |      27591 |                   62 |            13 |

</div>

``` r
original_ceplane_prep <- original_ceplane %>%
  # Replace "NA" string with actual NaN for the interval
  mutate(Interval = replace(Interval, Interval == "NA", NA_character_)) %>%
  # Remove scenarios 2 and 3 with no case detection, and scenario 2b
  filter(!(Scenario %in% c("S2NoCD", "S3NoCD", "S2b"))) %>%
  # Replace S1NoCDAvg with S0
  mutate(Scenario = replace(Scenario, Scenario == "S1NoCDAvg", "S0")) %>%
  # Round columns
  mutate(CostpAgentAll = round(CostpAgentAll, 0)) %>%
  mutate(QALYpAgentAll = round(QALYpAgentAll, 3)) %>%
  mutate(ICERAdj = round(ICERAdj, 0)) %>%
  mutate(INMB = round(INMB, 0)) %>%
  # Select relevant columns
  select(Scenario, Interval, CostpAgentAll, QALYpAgentAll, ICERAdj, INMB)
# Append "_repo" to columns (except Scenario and Interval)
icol <- which(names(original_ceplane_prep) %in% c("Scenario", "Interval"))
colnames(original_ceplane_prep)[-icol] <- paste(
  colnames(original_ceplane_prep)[-icol], "repo", sep = "_")
original_ceplane_prep
```

<div class="kable-table">

| Scenario | Interval | CostpAgentAll_repo | QALYpAgentAll_repo | ICERAdj_repo | INMB_repo |
|:---------|:---------|-------------------:|-------------------:|-------------:|----------:|
| S0       | NA       |               2151 |             12.545 |           NA |         0 |
| S1a      | 3 years  |               2439 |             12.560 |        19665 |       446 |
| S1b      | 3 years  |               2365 |             12.552 |        31076 |       131 |
| S1c      | 3 years  |               2386 |             12.551 |        42697 |        40 |
| S2a      | 3 years  |               2287 |             12.552 |        21184 |       186 |
| S3a      | 3 years  |               2232 |             12.548 |        32247 |        45 |
| S3b      | 3 years  |               2289 |             12.553 |        18157 |       243 |
| S3c      | 3 years  |               2255 |             12.550 |        20700 |       148 |
| S3d      | 3 years  |               2261 |             12.550 |        23462 |       124 |
| S0       | NA       |               2151 |             12.545 |           NA |         0 |
| S1a      | 5 years  |               2355 |             12.557 |        16600 |       411 |
| S1b      | 5 years  |               2298 |             12.551 |        25501 |       142 |
| S1c      | 5 years  |               2311 |             12.551 |        29600 |       110 |
| S2a      | 5 years  |               2245 |             12.550 |        20394 |       137 |
| S3a      | 5 years  |               2207 |             12.548 |        22694 |        67 |
| S3b      | 5 years  |               2248 |             12.551 |        17325 |       183 |
| S3c      | 5 years  |               2221 |             12.549 |        19250 |       113 |
| S3d      | 5 years  |               2226 |             12.548 |        26517 |        67 |

</div>

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
  c("ICERAdj", "ICER_paper", "ICERAdj_repo", "ICER"),
  c("INMB", "IncrementalNMB_paper", "INMB_repo", "INMB")
)
# Combine model and paper results and apply the function for each pair of columns
ceplane_compare <- column_pairs %>%
  purrr::map(~ calc_diff_perc(ceplane_combine, .x[1], .x[2], .x[3], .x[4])) %>%
  purrr::reduce(left_join, by = c("Scenario", "Interval"))
# Remove duplicates
ceplane_compare <- ceplane_compare[!duplicated(ceplane_compare), ]
# Save to csv and view
write.csv(ceplane_compare, paths$tab3_compare, row.names=FALSE)
ceplane_compare
```

<div class="kable-table">

|     | Scenario | Interval | CostpAgent_paper | CostpAgentAll | CostpAgentAll_repo | CostMyDiff | CostMyPerc | CostRepoDiff | CostRepoPerc | QALYpAgent_paper | QALYpAgentAll | QALYpAgentAll_repo | QALYMyDiff | QALYMyPerc | QALYRepoDiff | QALYRepoPerc | ICER_paper | ICERAdj | ICERAdj_repo | ICERMyDiff | ICERMyPerc | ICERRepoDiff | ICERRepoPerc | IncrementalNMB_paper | INMB | INMB_repo | INMBMyDiff | INMBMyPerc | INMBRepoDiff | INMBRepoPerc |
|:----|:---------|:---------|-----------------:|--------------:|-------------------:|-----------:|:-----------|-------------:|:-------------|-----------------:|--------------:|-------------------:|-----------:|:-----------|-------------:|:-------------|-----------:|--------:|-------------:|-----------:|:-----------|-------------:|:-------------|---------------------:|-----:|----------:|-----------:|:-----------|-------------:|:-------------|
| 1   | S0       | NA       |             2151 |          2149 |               2151 |          2 | 0.1%       |            0 | 0.0%         |           12.546 |        12.545 |             12.545 |      0.001 | 0%         |        0.001 | 0%           |         NA |      NA |           NA |         NA | NA         |           NA | NA           |                   NA |   NA |         0 |         NA | NA         |           NA | NA           |
| 17  | S1a      | 3 years  |             2438 |          2440 |               2439 |         -2 | -0.1%      |           -1 | 0.0%         |           12.560 |        12.562 |             12.560 |     -0.002 | 0%         |        0.000 | 0%           |      19632 |   17669 |        19665 |       1963 | 11.1%      |          -33 | -0.2%        |                  444 |  533 |       446 |        -89 | -16.7%     |           -2 | -0.40%       |
| 18  | S1a      | 5 years  |             2356 |          2355 |               2355 |          1 | 0.0%       |            1 | 0.0%         |           12.556 |        12.556 |             12.557 |      0.000 | 0%         |       -0.001 | 0%           |      19847 |   19073 |        16600 |        774 | 4.1%       |         3247 | 19.6%        |                  312 |  335 |       411 |        -23 | -6.9%      |          -99 | -24.10%      |
| 19  | S1b      | 3 years  |             2363 |          2362 |               2365 |          1 | 0.0%       |           -2 | -0.1%        |           12.554 |        12.553 |             12.552 |      0.001 | 0%         |        0.002 | 0%           |      25894 |   26497 |        31076 |       -603 | -2.3%      |        -5182 | -16.7%       |                  198 |  189 |       131 |          9 | 4.8%       |           67 | 51.10%       |
| 20  | S1b      | 5 years  |             2296 |          2298 |               2298 |         -2 | -0.1%      |           -2 | -0.1%        |           12.552 |        12.552 |             12.551 |      0.000 | 0%         |        0.001 | 0%           |      23187 |   22920 |        25501 |        267 | 1.2%       |        -2314 | -9.1%        |                  168 |  177 |       142 |         -9 | -5.1%      |           26 | 18.30%       |
| 21  | S1c      | 3 years  |             2386 |          2387 |               2386 |         -1 | 0.0%       |            0 | 0.0%         |           12.551 |        12.550 |             12.551 |      0.001 | 0%         |        0.000 | 0%           |      46956 |   46445 |        42697 |        511 | 1.1%       |         4259 | 10.0%        |                   15 |   18 |        40 |         -3 | -16.7%     |          -25 | -62.50%      |
| 22  | S1c      | 5 years  |             2313 |          2314 |               2311 |         -1 | 0.0%       |            2 | 0.1%         |           12.550 |        12.551 |             12.551 |     -0.001 | 0%         |       -0.001 | 0%           |      38673 |   27818 |        29600 |      10855 | 39.0%      |         9073 | 30.7%        |                   47 |  132 |       110 |        -85 | -64.4%     |          -63 | -57.30%      |
| 23  | S2a      | 3 years  |             2286 |          2286 |               2287 |          0 | 0.0%       |           -1 | 0.0%         |           12.553 |        12.553 |             12.552 |      0.000 | 0%         |        0.001 | 0%           |      18908 |   18082 |        21184 |        826 | 4.6%       |        -2276 | -10.7%       |                  223 |  242 |       186 |        -19 | -7.9%      |           37 | 19.90%       |
| 24  | S2a      | 5 years  |             2246 |          2241 |               2245 |          5 | 0.2%       |            1 | 0.0%         |           12.551 |        12.549 |             12.550 |      0.002 | 0%         |        0.001 | 0%           |      17514 |   27650 |        20394 |     -10136 | -36.7%     |        -2880 | -14.1%       |                  176 |   74 |       137 |        102 | 137.8%     |           39 | 28.50%       |
| 25  | S3a      | 3 years  |             2234 |          2234 |               2232 |          0 | 0.0%       |            2 | 0.1%         |           12.548 |        12.548 |             12.548 |      0.000 | 0%         |        0.000 | 0%           |      30366 |   28714 |        32247 |       1652 | 5.8%       |        -1881 | -5.8%        |                   54 |   63 |        45 |         -9 | -14.3%     |            9 | 20.00%       |
| 26  | S3a      | 5 years  |             2207 |          2203 |               2207 |          4 | 0.2%       |            0 | 0.0%         |           12.548 |        12.548 |             12.548 |      0.000 | 0%         |        0.000 | 0%           |      22636 |   22107 |        22694 |        529 | 2.4%       |          -58 | -0.3%        |                   68 |   68 |        67 |          0 | 0.0%       |            1 | 1.50%        |
| 27  | S3b      | 3 years  |             2292 |          2289 |               2289 |          3 | 0.1%       |            3 | 0.1%         |           12.553 |        12.552 |             12.553 |      0.001 | 0%         |        0.000 | 0%           |      18438 |   21354 |        18157 |      -2916 | -13.7%     |          281 | 1.5%         |                  241 |  188 |       243 |         53 | 28.2%      |           -2 | -0.80%       |
| 28  | S3b      | 5 years  |             2250 |          2245 |               2248 |          5 | 0.2%       |            2 | 0.1%         |           12.552 |        12.552 |             12.551 |      0.000 | 0%         |        0.001 | 0%           |      16251 |   13503 |        17325 |       2748 | 20.4%      |        -1074 | -6.2%        |                  206 |  260 |       183 |        -54 | -20.8%     |           23 | 12.60%       |
| 29  | S3c      | 3 years  |             2256 |          2253 |               2255 |          3 | 0.1%       |            1 | 0.0%         |           12.550 |        12.549 |             12.550 |      0.001 | 0%         |        0.000 | 0%           |      23972 |   28161 |        20700 |      -4189 | -14.9%     |         3272 | 15.8%        |                  114 |   81 |       148 |         33 | 40.7%      |          -34 | -23.00%      |
| 30  | S3c      | 5 years  |             2224 |          2220 |               2221 |          4 | 0.2%       |            3 | 0.1%         |           12.549 |        12.550 |             12.549 |     -0.001 | 0%         |        0.000 | 0%           |      20278 |   14224 |        19250 |       6054 | 42.6%      |         1028 | 5.3%         |                  107 |  178 |       113 |        -71 | -39.9%     |           -6 | -5.30%       |
| 31  | S3d      | 3 years  |             2263 |          2262 |               2261 |          1 | 0.0%       |            2 | 0.1%         |           12.549 |        12.549 |             12.550 |      0.000 | 0%         |       -0.001 | 0%           |      28245 |   33377 |        23462 |      -5132 | -15.4%     |         4783 | 20.4%        |                   86 |   56 |       124 |         30 | 53.6%      |          -38 | -30.60%      |
| 32  | S3d      | 5 years  |             2227 |          2223 |               2226 |          4 | 0.2%       |            1 | 0.0%         |           12.548 |        12.548 |             12.548 |      0.000 | 0%         |        0.000 | 0%           |      27591 |   26612 |        26517 |        979 | 3.7%       |         1074 | 4.1%         |                   62 |   65 |        67 |         -3 | -4.6%      |           -5 | -7.50%       |

</div>

## Figure 3

``` r
# Process data
ceplane_plot <- rbind(ceplane_3y, ceplane_5y) %>%
  # Remove scenario 2b
  filter(!(Scenario == "S2b")) %>%
  # Replace the NoCD results with a single NoCD category
  mutate(Scenario = ifelse(
    Scenario %in% c("S1NoCDAvg", "S2NoCD", "S3NoCD"), "NoCD", Scenario)) %>%
  # Add colour for S1a
  mutate(Colour = ifelse((Scenario == "S1a" & Interval == "3 years"), "A", "B"))
```

Find the efficiency frontier

``` r
# Remove negative QALY and then...
# Find highest ICER and remove those with a QALY less than that but ICER above
find_frontier <- ceplane_plot %>%
  filter(!(IncrementalQALY <= 0)) %>%
  arrange(ICERAdj) %>%
  filter(!(IncrementalQALY <= first(IncrementalQALY) & ICERAdj > first(ICERAdj)))

# Add first row to frontier df, and remove from the other
frontier <- find_frontier[1, , drop=FALSE]
find_frontier <- find_frontier[-1,]

# Repeat that, each time adding to frontier, until there are none remaining after filter
while (nrow(find_frontier) > 0){
  find_frontier <- find_frontier %>%
    arrange(ICERAdj) %>%
    filter(!(IncrementalQALY <= first(IncrementalQALY) & ICERAdj > first(ICERAdj)))
  frontier <- rbind(frontier, find_frontier[1, , drop=FALSE])
  find_frontier <- find_frontier[-1,]
}

# Add NoCD to start of frontier
frontier <- frontier %>%
  select(Scenario, IncrementalCosts, IncrementalQALY) %>%
  add_row(Scenario="NoCD", IncrementalCosts=0, IncrementalQALY=0) %>%
  arrange(IncrementalCosts)
frontier
```

<div class="kable-table">

| Scenario | IncrementalCosts | IncrementalQALY |
|:---------|-----------------:|----------------:|
| NoCD     |          0.00000 |       0.0000000 |
| S3b      |         96.04666 |       0.0071128 |
| S1a      |        291.04522 |       0.0164718 |

</div>

``` r
# Create plot
ggplot(data=ceplane_plot, aes(x=IncrementalQALY, y=IncrementalCosts)) + 
  geom_point(aes(shape=factor(Interval), colour=factor(Colour))) +
  geom_text(aes(label=Scenario, colour=factor(Colour)),vjust=-0.5, size=3) + 
  geom_abline(intercept=0, slope=50000, colour="grey", linetype="dashed") +
  scale_colour_manual(values=c("red", "black")) +
  theme_bw() +
  labs(x="Incremental QALYs", y="Incremental Costs", shape="Testing Interval") +
  theme(legend.position="bottom") +
  guides(colour="none") +
  # Add the efficiency frontier
  geom_path(data=frontier, aes(x=IncrementalQALY, y=IncrementalCosts),
            colour="blue", linewidth=0.1) +
  # Extend y axis to 300 like original (but x is already wider than original)
  ylim(c(0, 300)) +
  # Make 0 to 0.015 and 0 to 300 a square
  coord_fixed(ratio = (0.015 - 0) / (300 - 0)) +
  annotate(geom="text", x = Inf, y = -Inf,
           label = "S1: All Patients\nS2: Symptomatic\nS3: Smoking History\nS1a: CDQ > 17 points",
           hjust = 1.1, vjust = -0.3, size = 2.5)
```

![](../outputs/fig3-1.png)<!-- -->

``` r
# Not needed if knitting, which will overwrite
ggsave(paths$fig3)
```

    ## Saving 7 x 5 in image

## Appendix 6

``` r
# Create version of S1 with scenarios renamed
s1_scen <- s1 %>%
  mutate(Scenario = recode(Scenario,
                           "S1a" = "Case Detection",
                           "S1NoCDAvg" = "No Case Detection"))

ap6_df <- s1_scen %>%
  # Get the relevant scenarios
  filter(Scenario %in% c("Case Detection", "No Case Detection")) %>%
  # Adjust results so they reflect population of 1000
  mutate(across(c(Mild, Moderate, Severe, VerySevere), ~ . / (Agents/1000))) %>%
  # Tidy and make long format for plotting
  select(Scenario, Mild, Moderate, Severe, VerySevere) %>%
  tidyr::pivot_longer(cols=-Scenario, names_to="Severity", values_to="Exacerbations")

p1 <- ggplot(ap6_df, aes(x=Severity, y=Exacerbations, fill=Scenario)) +
  geom_bar(stat="identity", position="dodge") +
  labs(x="", y="Number of exacerbations", fill="") +
  theme_bw()

ap6_df <- s1_scen %>%
  # Get the relevant scenarios
  filter(Scenario %in% c("Case Detection", "No Case Detection")) %>%
  # Adjust results so they reflect population of 1000
  mutate(across(c(NoCOPD, GOLD1, GOLD2, GOLD3, GOLD4), ~ . / (Agents/1000))) %>%
  # Tidy and make long format for plotting
  select(Scenario, NoCOPD, GOLD1, GOLD2, GOLD3, GOLD4) %>%
  tidyr::pivot_longer(cols=-Scenario, names_to="Severity", values_to="Years") %>%
  # Reorder Severity to have NoCOPD first
  mutate(Severity = factor(Severity, levels = c("NoCOPD", "GOLD1", "GOLD2", "GOLD3", "GOLD4")))

p2 <- ggplot(ap6_df, aes(x=Severity, y=Years, fill=Scenario)) +
  geom_bar(stat="identity", position="dodge") +
  labs(x="", y="Patient years", fill="") +
  ylim(c(0, 15000)) +
  theme_bw()

ap6_df <- s1_scen %>%
  # Get the relevant scenarios
  filter(Scenario %in% c("Case Detection", "No Case Detection")) %>%
  # Adjust results so they reflect population of 1000
  mutate(across(c(DiagnosedPYs), ~ . / (Agents/1000)))

p3 <- ggplot(ap6_df, aes(x=Scenario, y=DiagnosedPYs, fill=Scenario)) +
  geom_bar(stat="identity", position="dodge") +
  labs(x="", y="COPD patient years diagnosed", fill="") +
  theme_bw()

ap6_df <- s1_scen %>%
  # Get the relevant scenarios
  filter(Scenario %in% c("Case Detection", "No Case Detection")) %>%
  # Adjust
  mutate(across(c(SABA, LAMA, LAMALABA, ICSLAMALABA), ~ . * 2000)) %>%
  # Tidy and make long format for plotting
  select(Scenario, SABA, LAMA, LAMALABA, ICSLAMALABA) %>%
  tidyr::pivot_longer(cols=-Scenario, names_to="Group", values_to="Years") %>%
  # Reorder group to have NoCOPD first
  mutate(Group = factor(Group, levels = c("SABA", "LAMA", "LAMALABA", "ICSLAMALABA")))

p4 <- ggplot(ap6_df, aes(x=Group, y=Years, fill=Scenario)) +
  geom_bar(stat="identity", position="dodge") +
  labs(x="", y="Patient years on treatment", fill="") +
  theme_bw()

ggarrange(p1, p2, p3, p4, ncol=2, nrow=2, common.legend = TRUE, legend="bottom")
```

![](../outputs/appendix6-1.png)<!-- -->

``` r
ggsave(paths$apx6, width = 12, height = 10)
```
