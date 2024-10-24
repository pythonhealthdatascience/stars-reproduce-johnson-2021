# Reproduction README

## Model summary

> Johnson, K.M., Sadatsafavi, M., Adibi, A., Lynd, L., Harrison, M., Tavakoli, H., Sin, D., Bryan, S. **Cost Effectiveness of Case Detection Strategies for the Early Detection of COPD**. *Applied Health Economics and Health Policy* 19, p203-215 (2021). <https://doi.org/10.1007/s40258-020-00616-2>.

This study uses a previously validated discrete-event simulation model, EPIC: Evaluation Platform in chronic obstructive pulmonary disease (COPD). The model is written in `C++` with an `R` interface, using R scripts for execution. The model is adapted to evaluate the cost-effectiveness of 16 COPD case detection strategies in primary care, comparing costs, quality-adjusted life years (QALYs), incremental cost-effectiveness ratios (ICER), and incremental net monetary benefits (INMB) across scenarios. Sensitivity analyses are also conducted.

## Scope of the reproduction

In this assessment, we attempted to reproduce 5 items: 4 figures and 1 table.

## Reproducing these results

### Repository overview

```
├── docker
│   └──  ...
├── epicR
│   └──  ...
├── outputs
│   └──  ...
├── renv
│   └──  ...
├── scripts
│   └──  ...
├── tests
│   └──  ...
├── .Rprofile
├── DESCRIPTION
├── johnson2021.Rproj
├── README.md
└── renv.lock
```

* `docker/` - Instructions for creation of docker container.
* `epicR/` - Package used to run the model
* `outputs/` - Outputs files from the scripts (e.g. `.csv`, `.png`)
* `renv/` - Instructions for creation of R environment
* `scripts/` - Scripts to run the base case analysis, sensitivity analysis and generate the tables and figures
* `tests/` - Test to check that a simple run of the model produces consistent results with our reproduction
* `.Rprofile` - Activates R environment
* `DESCRIPTION` - Lists packages that we installed into environment (their dependencies will have also been installed)
* `johnson2021.Rproj` - Project settings
* `README.md` - This file!
* `renv.lock` - Lists R version and all packages in the R environment

### Step 1. Set up environment

Before you can run the model, you will need to create an R environment with the correct version of R and the specified packages.

#### Option A. Renv

An `renv` environment has been provided. To create this environment locally on your machine, you should open the R project with the R environment loaded, and then run:

```
renv::restore()
```

In `renv.lock`, you will see the version of R listed. However, `renv` will not install this for you, so you will need to switch to this yourself if you wish to also use the same version of R. This reproduction has been run in R 4.4.1, and it is possible (although not definite) that later versions of R may not be compatible, or that you may encounter difficulties installing the specified package versions in later versions of R.

#### Option B. Build local docker image

A Dockerfile is provided, which you can use to build the Docker image. The docker image will include the correct version of R, the required packages and their versions, and an installation of RStudio which you can run from your browser. It will also include the scripts and outputs from this directory. For this option and option C, you'll need to ensure that `docker` is installed on your machine.

To create the docker image and then open up RStudio:

1. In the terminal, navigate to the parent directory of your `reproduction/` folder
2. Build the image:

```
docker build --tag johnson2021 . -f ./reproduction/docker/Dockerfile
```

3. Create container and open RStudio:

```
(sleep 2 && xdg-open http://localhost:8888) & sudo docker run -it -p 8888:8787 -e DISABLE_AUTH=true --name johnson2021_docker johnson2021
```

#### Option C. Pull pre-built docker image

A pre-built image is available on the GitHub container registry. To use it:

1. Create a Personal Access Token (Classic) for your GitHub account with `write:packages` and `delete:packages` access
2. On terminal, run the following command and then enter your sudo password (if prompted), followed by the token just generated (which acts as your GitHub password)

```
sudo docker login ghcr.io -u githubusername
```

3. Download the image:

```
sudo docker pull ghcr.io/pythonhealthdatascience/johnson2021
```

4. Create container and open RStudio:

```
(sleep 2 && xdg-open http://localhost:8888) & sudo docker run -it -p 8888:8787 -e DISABLE_AUTH=true --name johnson2021_docker ghcr.io/pythonhealthdatascience/johnson2021:latest
```

### Step 2. Running the model

#### Option A: Execute the R scripts

To run the base case, knit `Case_Detection_Results.Rmd` and `Case_Detection_Results_5yrs.Rmd`. To run the sensitivity analyses, likewise knit the `.Rmd` files in `scripts/Sensitivity_Analysis/`. These files were created from the base case files by running `Sensitivity_Analysis_Prep.R`.

If you want to run these from the command line, you can use:

```
Rscript -e "rmarkdown::render('scripts/Case_Detection_Results.Rmd')"
```

To generate the tables and figures from the article, knit `Process_Model_Results.Rmd`.

### Option B: Testthat

A small version of one the model scenarios (`tests/test_s1nocd.R`) is provided. Run this from the `reproduction/` directory. If the results are consistent, you should see that `expect_equal(s1NoCD, exp_s1NoCD)` returns nothing. If the results differ, you'll see an error message along the lines of:

```
Error: `s1NoCD` not equal to `exp_s1NoCD`.
  Component “Agents”: Mean relative difference: 3.975744
  Component “PatientYears”: Mean relative difference: 3.987842
  Component “CopdPYs”: Mean relative difference: 3.749264
  ...
```

The test should only take about **18 seconds** to run, depending on your machine specs. It is not set up using `testthat` since I could not manage to successfully load the `epicR` package when working with `testthat`.

## Reproduction specs and runtime

Within this reproduction, due to long run times, the model was run on a remote machine. This was an Intel Core i9-13900K with 81GB RAM running Pop!_OS 22.04 Linux. It was run from the command line via multiple terminals simultaneously - hence, the exact times are impacted by the number being ran at once.

The base case scenarios were ran at the same time, and took an overall total time of **20 hours 40 minutes**:

* Base case 3 years: 20.65 hours - 20 hours 39 minutes
* Base case 5 years: 20.67 hours - 20 hours 40 minutes

The sensitivity analysis scenario were all ran at the same time, and took an overall total of **1 day 10 hours 57 minutes**:

* Sen1_No_Smoking_Cessation 1.275262 days and 1.361881 days
* Sen2_50_Med_Adherence 1.2965 days and 1.269854 days
* Sen3_30_Med_Adherence 1.210629 days and 1.186785 days
* Sen4_01_Treat_Util 1.291363 days and 1.415365 days
* Sen5_0_Treat_Util 1.45615 days and 1.315001 days
* Sen6_0_Discount 1.148049 days and 1.163011 days
* Sen7_3_Discount 1.217285 days and 1.276366 days

Four files (scenarios 2 and 3) had to be re-run seperately after fixing a mistake, and when just those were run, the total was **21 hours 26 minutes**:

* Sen2_50_Med_Adherence 21.09425 hours and 21.44028 hours
* Sen3_30_Med_Adherence 21.10292 hours and 21.09909 hours

Based on this, if you were to run all scenarios at once in parallel in seperate terminals, you could expect a run time of **at least 1 day 11 hours**, but would be higher than that (since the more run at once, the lower it takes, as you can see from the scenario 2 and 3 times above).

## Citation

To cite the original study, please refer to the reference above. To cite this reproduction, please refer to the CITATION.cff file in the parent folder.

## License

This repository is licensed under the GNU General Public License v3.0.