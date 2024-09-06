Process Model Results
================
06 September, 2024

This file processes the model results so they match up as closely as
possible to those in the publication.

``` r
knitr::opts_chunk$set(fig.path = "../outputs/")
library(dplyr)
library(ggplot2)
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
  tab3_compare = "../outputs/tab3_compare_to_original.csv",
  fig3 = "../outputs/fig3-1.png"
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

<div class="kable-table">

| Scenario  | Agents | PropAgents |       Cost | CostpAgent | CostpAgentExcluded | CostpAgentAll |    QALY | QALYpAgent | QALYpAgentExcluded | QALYpAgentAll | IncrementalCosts | IncrementalQALY |    ICERAdj |       ICER |        INMB | Interval |
|:----------|-------:|-----------:|-----------:|-----------:|-------------------:|--------------:|--------:|-----------:|-------------------:|--------------:|-----------------:|----------------:|-----------:|-----------:|------------:|:---------|
| S1NoCDAvg | 743240 |  1.0000000 | 1599466443 |   2152.020 |              0.000 |      2152.020 | 9319095 |   12.53848 |            0.00000 |      12.53848 |          0.00000 |       0.0000000 |         NA |         NA |    0.000000 | 3 years  |
| S1NoCDAvg | 743240 |  1.0000000 | 1599466443 |   2152.020 |              0.000 |      2152.020 | 9319095 |   12.53848 |            0.00000 |      12.53848 |          0.00000 |       0.0000000 |         NA |         NA |    0.000000 | 5 years  |
| S1a       | 743762 |  1.0000000 | 1807321435 |   2429.973 |              0.000 |      2429.973 | 9340234 |   12.55809 |            0.00000 |      12.55809 |        277.95257 |       0.0196138 |  14171.293 |  13791.124 |  702.736263 | 3 years  |
| S1a       | 744354 |  1.0000000 | 1752926443 |   2354.963 |              0.000 |      2354.963 | 9349016 |   12.55991 |            0.00000 |      12.55991 |        202.94319 |       0.0214250 |   9472.245 |   9739.527 |  868.308574 | 5 years  |
| S1b       | 744327 |  1.0000000 | 1760175403 |   2364.788 |              0.000 |      2364.788 | 9341640 |   12.55045 |            0.00000 |      12.55045 |        212.76756 |       0.0119708 |  17773.880 |  17035.376 |  385.772441 | 3 years  |
| S1b       | 744122 |  1.0000000 | 1719863654 |   2311.266 |              0.000 |      2311.266 | 9342006 |   12.55440 |            0.00000 |      12.55440 |        159.24546 |       0.0159203 |  10002.688 |  10379.531 |  636.767913 | 5 years  |
| S1c       | 744352 |  1.0000000 | 1784618220 |   2397.546 |              0.000 |      2397.546 | 9343139 |   12.55204 |            0.00000 |      12.55204 |        245.52585 |       0.0135630 |  18102.668 |  17438.189 |  432.622386 | 3 years  |
| S1c       | 744408 |  1.0000000 | 1712210641 |   2300.097 |              0.000 |      2300.097 | 9338065 |   12.54428 |            0.00000 |      12.54428 |        148.07681 |       0.0058020 |  25521.605 |  27838.899 |  142.024090 | 5 years  |
| S2NoCD    | 441551 |  0.5940894 | 1172222127 |   2654.783 |           1416.175 |      2152.019 | 5415116 |   12.26385 |           12.94041 |      12.53847 |          0.00000 |       0.0000000 |         NA |         NA |   -0.420303 | 3 years  |
| S2NoCD    | 441928 |  0.5945966 | 1179924911 |   2669.948 |           1392.382 |      2152.019 | 5422979 |   12.27118 |           12.93050 |      12.53847 |          0.00000 |       0.0000000 |         NA |         NA |   -0.420303 | 5 years  |
| S2a       | 441650 |  0.5942226 | 1270487699 |   2876.684 |           1416.175 |      2284.043 | 5428810 |   12.29211 |           12.94041 |      12.55517 |        132.02380 |       0.0167010 |   7905.166 |   7852.913 |  702.603533 | 3 years  |
| S2a       | 441121 |  0.5935108 | 1240789795 |   2812.811 |           1392.382 |      2235.422 | 5419996 |   12.28687 |           12.93050 |      12.54850 |         83.40312 |       0.0100269 |   8317.911 |   9106.416 |  417.523169 | 5 years  |
| S3NoCD    | 345450 |  0.4647893 | 1009751817 |   2923.004 |           1482.477 |      2152.019 | 3878935 |   11.22864 |           13.67596 |      12.53847 |          0.00000 |       0.0000000 |         NA |         NA |   -0.420303 | 3 years  |
| S3NoCD    | 344713 |  0.4637977 |  996287204 |   2890.193 |           1513.522 |      2152.019 | 3873367 |   11.23650 |           13.66464 |      12.53847 |          0.00000 |       0.0000000 |         NA |         NA |   -0.420303 | 5 years  |
| S3a       | 344340 |  0.4632958 | 1058616300 |   3074.334 |           1482.477 |      2219.978 | 3873043 |   11.24773 |           13.67596 |      12.55097 |         67.95925 |       0.0124963 |   5438.352 |   7929.873 |  556.435226 | 3 years  |
| S3a       | 344831 |  0.4639565 | 1045268642 |   3031.249 |           1513.522 |      2217.681 | 3874091 |   11.23475 |           13.66464 |      12.53728 |         65.66229 |      -0.0011957 | -54917.558 | -80779.766 | -125.865199 | 5 years  |
| S3b       | 344561 |  0.4635932 | 1098068656 |   3186.863 |           1482.477 |      2272.619 | 3875123 |   11.24655 |           13.67596 |      12.54970 |        120.60002 |       0.0112284 |  10740.594 |  14735.648 |  440.401243 | 3 years  |
| S3b       | 344259 |  0.4631869 | 1074556989 |   3121.362 |           1513.522 |      2258.252 | 3874191 |   11.25371 |           13.66464 |      12.54793 |        106.23342 |       0.0094562 |  11234.316 |  13429.701 |  366.153959 | 5 years  |
| S3c       | 345148 |  0.4643830 | 1069636233 |   3099.065 |           1482.477 |      2233.193 | 3879671 |   11.24060 |           13.67596 |      12.54502 |         81.17449 |       0.0065462 |  12400.176 |  14726.663 |  245.717029 | 3 years  |
| S3c       | 344359 |  0.4633214 | 1045425869 |   3035.860 |           1513.522 |      2218.854 | 3873257 |   11.24773 |           13.66464 |      12.54483 |         66.83501 |       0.0063609 |  10507.238 |  12968.139 |  250.787397 | 5 years  |
| S3d       | 344912 |  0.4640654 | 1075013391 |   3116.776 |           1482.477 |      2240.899 | 3876329 |   11.23860 |           13.67596 |      12.54487 |         88.87997 |       0.0063928 |  13903.144 |  19458.355 |  230.339544 | 3 years  |
| S3d       | 343958 |  0.4627819 | 1047428798 |   3045.223 |           1513.522 |      2222.365 | 3863483 |   11.23243 |           13.66464 |      12.53905 |         70.34646 |       0.0005819 | 120887.662 | -38068.150 |  -41.670964 | 5 years  |

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

| Scenario  | Agents | PropAgents |       Cost | CostpAgent | CostpAgentExcluded | CostpAgentAll |    QALY | QALYpAgent | QALYpAgentExcluded | QALYpAgentAll | IncrementalCosts | IncrementalQALY |    ICERAdj |       ICER |       INMB | Interval | Ranking |
|:----------|-------:|-----------:|-----------:|-----------:|-------------------:|--------------:|--------:|-----------:|-------------------:|--------------:|-----------------:|----------------:|-----------:|-----------:|-----------:|:---------|--------:|
| S1NoCDAvg | 743240 |  1.0000000 | 1599466443 |   2152.020 |              0.000 |      2152.020 | 9319095 |   12.53848 |            0.00000 |      12.53848 |          0.00000 |       0.0000000 |         NA |         NA |         NA | NA       |      NA |
| S1a       | 743762 |  1.0000000 | 1807321435 |   2429.973 |              0.000 |      2429.973 | 9340234 |   12.55809 |            0.00000 |      12.55809 |        277.95257 |       0.0196138 |  14171.293 |  13791.124 |  702.73626 | 3 years  |       2 |
| S1a       | 744354 |  1.0000000 | 1752926443 |   2354.963 |              0.000 |      2354.963 | 9349016 |   12.55991 |            0.00000 |      12.55991 |        202.94319 |       0.0214250 |   9472.245 |   9739.527 |  868.30857 | 5 years  |       1 |
| S1b       | 744327 |  1.0000000 | 1760175403 |   2364.788 |              0.000 |      2364.788 | 9341640 |   12.55045 |            0.00000 |      12.55045 |        212.76756 |       0.0119708 |  17773.880 |  17035.376 |  385.77244 | 3 years  |       9 |
| S1b       | 744122 |  1.0000000 | 1719863654 |   2311.266 |              0.000 |      2311.266 | 9342006 |   12.55440 |            0.00000 |      12.55440 |        159.24546 |       0.0159203 |  10002.688 |  10379.531 |  636.76791 | 5 years  |       4 |
| S1c       | 744352 |  1.0000000 | 1784618220 |   2397.546 |              0.000 |      2397.546 | 9343139 |   12.55204 |            0.00000 |      12.55204 |        245.52585 |       0.0135630 |  18102.668 |  17438.189 |  432.62239 | 3 years  |       7 |
| S1c       | 744408 |  1.0000000 | 1712210641 |   2300.097 |              0.000 |      2300.097 | 9338065 |   12.54428 |            0.00000 |      12.54428 |        148.07681 |       0.0058020 |  25521.605 |  27838.899 |  142.02409 | 5 years  |      14 |
| S2a       | 441650 |  0.5942226 | 1270487699 |   2876.684 |           1416.175 |      2284.043 | 5428810 |   12.29211 |           12.94041 |      12.55517 |        132.02380 |       0.0167010 |   7905.166 |   7852.913 |  702.60353 | 3 years  |       3 |
| S2a       | 441121 |  0.5935108 | 1240789795 |   2812.811 |           1392.382 |      2235.422 | 5419996 |   12.28687 |           12.93050 |      12.54850 |         83.40312 |       0.0100269 |   8317.911 |   9106.416 |  417.52317 | 5 years  |       8 |
| S3a       | 344340 |  0.4632958 | 1058616300 |   3074.334 |           1482.477 |      2219.978 | 3873043 |   11.24773 |           13.67596 |      12.55097 |         67.95925 |       0.0124963 |   5438.352 |   7929.873 |  556.43523 | 3 years  |       5 |
| S3a       | 344831 |  0.4639565 | 1045268642 |   3031.249 |           1513.522 |      2217.681 | 3874091 |   11.23475 |           13.66464 |      12.53728 |         65.66229 |      -0.0011957 | -54917.558 | -80779.766 | -125.86520 | 5 years  |      16 |
| S3b       | 344561 |  0.4635932 | 1098068656 |   3186.863 |           1482.477 |      2272.619 | 3875123 |   11.24655 |           13.67596 |      12.54970 |        120.60002 |       0.0112284 |  10740.594 |  14735.648 |  440.40124 | 3 years  |       6 |
| S3b       | 344259 |  0.4631869 | 1074556989 |   3121.362 |           1513.522 |      2258.252 | 3874191 |   11.25371 |           13.66464 |      12.54793 |        106.23342 |       0.0094562 |  11234.316 |  13429.701 |  366.15396 | 5 years  |      10 |
| S3c       | 345148 |  0.4643830 | 1069636233 |   3099.065 |           1482.477 |      2233.193 | 3879671 |   11.24060 |           13.67596 |      12.54502 |         81.17449 |       0.0065462 |  12400.176 |  14726.663 |  245.71703 | 3 years  |      12 |
| S3c       | 344359 |  0.4633214 | 1045425869 |   3035.860 |           1513.522 |      2218.854 | 3873257 |   11.24773 |           13.66464 |      12.54483 |         66.83501 |       0.0063609 |  10507.238 |  12968.139 |  250.78740 | 5 years  |      11 |
| S3d       | 344912 |  0.4640654 | 1075013391 |   3116.776 |           1482.477 |      2240.899 | 3876329 |   11.23860 |           13.67596 |      12.54487 |         88.87997 |       0.0063928 |  13903.144 |  19458.355 |  230.33954 | 3 years  |      13 |
| S3d       | 343958 |  0.4627819 | 1047428798 |   3045.223 |           1513.522 |      2222.365 | 3863483 |   11.23243 |           13.66464 |      12.53905 |         70.34646 |       0.0005819 | 120887.662 | -38068.150 |  -41.67096 | 5 years  |      15 |

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

# Preview dataframe
ceplane_pretty
```

<div class="kable-table">

| Scenario                         | Testing interval | Costs per patient | QALYs per patient |   ICER | INMB (ranking) |
|:---------------------------------|:-----------------|:------------------|------------------:|-------:|:---------------|
| S0: No case detection            | NA               | \$2152            |            12.538 |     NA | NA             |
| (S1a) CDQ ≥ 17 points            | 3 years          | \$2430            |            12.558 |  14171 | 703(2)         |
| (S1a) CDQ ≥ 17 points            | 5 years          | \$2355            |            12.560 |   9472 | 868(1)         |
| (S1b) Screening spirometry       | 3 years          | \$2365            |            12.550 |  17774 | 386(9)         |
| (S1b) Screening spirometry       | 5 years          | \$2311            |            12.554 |  10003 | 637(4)         |
| (S1c) CDQ + screening spirometry | 3 years          | \$2398            |            12.552 |  18103 | 433(7)         |
| (S1c) CDQ + screening spirometry | 5 years          | \$2300            |            12.544 |  25522 | 142(14)        |
| (S2a) Screening spirometry       | 3 years          | \$2284            |            12.555 |   7905 | 703(3)         |
| (S2a) Screening spirometry       | 5 years          | \$2235            |            12.548 |   8318 | 418(8)         |
| (S3a) CDQ ≥ 19.5 points          | 3 years          | \$2220            |            12.551 |   5438 | 556(5)         |
| (S3a) CDQ ≥ 19.5 points          | 5 years          | \$2218            |            12.537 | -54918 | -126(16)       |
| (S3b) CDQ ≥ 16.5 points          | 3 years          | \$2273            |            12.550 |  10741 | 440(6)         |
| (S3b) CDQ ≥ 16.5 points          | 5 years          | \$2258            |            12.548 |  11234 | 366(10)        |
| (S3c) Screening spirometry       | 3 years          | \$2233            |            12.545 |  12400 | 246(12)        |
| (S3c) Screening spirometry       | 5 years          | \$2219            |            12.545 |  10507 | 251(11)        |
| (S3d) CDQ + screening spirometry | 3 years          | \$2241            |            12.545 |  13903 | 230(13)        |
| (S3d) CDQ + screening spirometry | 5 years          | \$2222            |            12.539 | 120888 | -42(15)        |

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
| S3a      |         67.95925 |       0.0124963 |
| S2a      |        132.02380 |       0.0167010 |
| S1a      |        202.94319 |       0.0214250 |

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
            colour="blue", size=0.1) +
  # Extend y axis to 300 like original (but x is already wider than original)
  ylim(c(0, 300)) +
  # Make 0 to 0.015 and 0 to 300 a square
  coord_fixed(ratio = (0.015 - 0) / (300 - 0)) +
  annotate(geom="text", x = Inf, y = -Inf,
           label = "S1: All Patients\nS2: Symptomatic\nS3: Smoking History\nS1a: CDQ > 17 points",
           hjust = 1.1, vjust = -0.3, size = 2.5)
```

    ## Warning: Using `size` aesthetic for lines was deprecated in ggplot2 3.4.0.
    ## ℹ Please use `linewidth` instead.
    ## This warning is displayed once every 8 hours.
    ## Call `lifecycle::last_lifecycle_warnings()` to see where this warning was
    ## generated.

![](../outputs/fig3-1.png)<!-- -->

``` r
# Not needed if knitting, which will overwrite
ggsave(paths$fig3)
```

    ## Saving 7 x 5 in image
