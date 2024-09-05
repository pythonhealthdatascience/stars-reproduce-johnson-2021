Process Model Results
================
05 September, 2024

This file processes the model results so they match up as closely as
possible to those in the publication.

``` r
library(dplyr)
```

    ## 
    ## Attaching package: 'dplyr'

    ## The following objects are masked from 'package:stats':
    ## 
    ##     filter, lag

    ## The following objects are masked from 'package:base':
    ## 
    ##     intersect, setdiff, setequal, union

``` r
library(kableExtra)
```

    ## 
    ## Attaching package: 'kableExtra'

    ## The following object is masked from 'package:dplyr':
    ## 
    ##     group_rows

## Table 3

``` r
# Import the two results files
sall_3y <- read.csv("../outputs/sall.csv") %>% mutate("Interval" = "3 years")
sall_5y <- read.csv("../outputs/sall_5y.csv") %>% mutate("Interval" = "5 years")

# Preview them
rbind(sall_3y, sall_5y) %>%
  arrange(Scenario)
```

    ##    Scenario Agents      Cost CostpAgent    QALY QALYpAgent       ICER
    ## 1    S1NoCD 371579 798567288   2149.118 4660359   12.54204         NA
    ## 2    S1NoCD 371849 803320692   2160.341 4664958   12.54530         NA
    ## 3       S1a 371902 900481317   2421.287 4670660   12.55885   16195.98
    ## 4       S1a 371757 875098848   2353.954 4667327   12.55478   20430.79
    ## 5       S1b 372140 882188218   2370.582 4668622   12.54534   67189.32
    ## 6       S1b 372238 848458397   2279.344 4671548   12.54989   25910.57
    ## 7       S1c 371919 878053058   2360.872 4668922   12.55360   18321.20
    ## 8       S1c 371786 861061064   2316.013 4665869   12.54988   34018.45
    ## 9    S2NoCD 219759 592355610   2695.478 2696622   12.27081         NA
    ## 10   S2NoCD 220397 590082859   2677.363 2704639   12.27167         NA
    ## 11      S2a 221233 644478701   2913.122 2718304   12.28707   13391.77
    ## 12      S2a 220997 631718348   2858.493 2714422   12.28262   16541.19
    ## 13   S3NoCD 172154 494403150   2871.866 1934054   11.23444         NA
    ## 14   S3NoCD 172607 500398655   2899.064 1937979   11.22769         NA
    ## 15      S3a 172660 527017592   3052.343 1941269   11.24331   20354.54
    ## 16      S3a 172800 525843604   3043.076 1941999   11.23842   13424.30
    ## 17      S3b 172336 542053886   3145.332 1937179   11.24071   43606.19
    ## 18      S3b 172689 540529545   3130.075 1941365   11.24197   16178.59
    ## 19      S3c 172314 535046632   3105.068 1939341   11.25469   11516.85
    ## 20      S3c 172313 524243526   3042.391 1936949   11.24088   10873.57
    ## 21      S3d 172882 542727747   3139.296 1943060   11.23922   55904.12
    ## 22      S3d 172648 525750686   3045.217 1938413   11.22755 -978806.42
    ##    IncrementalNMB Interval
    ## 1         0.00000  3 years
    ## 2         0.00000  5 years
    ## 3       568.06558  3 years
    ## 4       280.21312  5 years
    ## 5       -56.65781  3 years
    ## 6       110.63854  5 years
    ## 7       366.13802  3 years
    ## 8        73.13298  5 years
    ## 9         0.00000  3 years
    ## 10        0.00000  5 years
    ## 11      594.95881  3 years
    ## 12      366.38110  5 years
    ## 13        0.00000  3 years
    ## 14        0.00000  5 years
    ## 15      262.85749  3 years
    ## 16      392.37595  5 years
    ## 17       40.09732  3 years
    ## 18      482.93080  5 years
    ## 19      779.23651  3 years
    ## 20      515.73605  5 years
    ## 21      -28.24372  3 years
    ## 22     -153.61976  5 years

``` r
# Combine into single dataframe
sall <- rbind(sall_3y, sall_5y) %>%
  # Remove scenarios 2 and 3 with no case detection, and scenario 2b
  filter(!(Scenario %in% c("S2NoCD", "S3NoCD", "S2b"))) %>%
  # Remove S1NoCD from 5 years, then set interval of S1NoCD to NA
  filter(!(Scenario == "S1NoCD" & Interval == "5 years")) %>%
  mutate(Interval = ifelse(Scenario == "S1NoCD", NA, Interval)) %>%
  # Remove INMB for S1NoCD
  mutate(IncrementalNMB = ifelse(Scenario!="S1NoCD", IncrementalNMB, NA)) %>%
  # Round columns
  mutate(CostpAgent = paste0("$", round(CostpAgent, 0))) %>%
  mutate(QALYpAgent = round(QALYpAgent, 3)) %>%
  mutate(ICER = round(ICER, 0)) %>%
  # Get INMB ranking
  mutate(Ranking = min_rank(desc(IncrementalNMB))) %>%
  mutate(INMBRank = ifelse(
    Scenario!="S1NoCD",
    paste0(round(IncrementalNMB, 0), "(", Ranking, ")"),
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
  select(Scenario, Interval, CostpAgent, QALYpAgent, ICER, INMBRank) %>%
  rename("Testing interval" = Interval,
         "Costs ($/patient)" = CostpAgent,
         "QALYs (QALYs/patient)" = QALYpAgent,
         "ICER ($/QALY)" = ICER,
         "INMB (ranking)" = INMBRank)

# Preview dataframe
sall
```

    ##                            Scenario Testing interval Costs ($/patient)
    ## 1             S0: No case detection             <NA>             $2149
    ## 2             (S1a) CDQ ≥ 17 points          3 years             $2421
    ## 3             (S1a) CDQ ≥ 17 points          5 years             $2354
    ## 4        (S1b) Screening spirometry          3 years             $2371
    ## 5        (S1b) Screening spirometry          5 years             $2279
    ## 6  (S1c) CDQ + screening spirometry          3 years             $2361
    ## 7  (S1c) CDQ + screening spirometry          5 years             $2316
    ## 8        (S2a) Screening spirometry          3 years             $2913
    ## 9        (S2a) Screening spirometry          5 years             $2858
    ## 10          (S3a) CDQ ≥ 19.5 points          3 years             $3052
    ## 11          (S3a) CDQ ≥ 19.5 points          5 years             $3043
    ## 12          (S3b) CDQ ≥ 16.5 points          3 years             $3145
    ## 13          (S3b) CDQ ≥ 16.5 points          5 years             $3130
    ## 14       (S3c) Screening spirometry          3 years             $3105
    ## 15       (S3c) Screening spirometry          5 years             $3042
    ## 16 (S3d) CDQ + screening spirometry          3 years             $3139
    ## 17 (S3d) CDQ + screening spirometry          5 years             $3045
    ##    QALYs (QALYs/patient) ICER ($/QALY) INMB (ranking)
    ## 1                 12.542            NA           <NA>
    ## 2                 12.559         16196         568(3)
    ## 3                 12.555         20431         280(9)
    ## 4                 12.545         67189        -57(15)
    ## 5                 12.550         25911        111(11)
    ## 6                 12.554         18321         366(8)
    ## 7                 12.550         34018         73(12)
    ## 8                 12.287         13392         595(2)
    ## 9                 12.283         16541         366(7)
    ## 10                11.243         20355        263(10)
    ## 11                11.238         13424         392(6)
    ## 12                11.241         43606         40(13)
    ## 13                11.242         16179         483(5)
    ## 14                11.255         11517         779(1)
    ## 15                11.241         10874         516(4)
    ## 16                11.239         55904        -28(14)
    ## 17                11.228       -978806       -154(16)
