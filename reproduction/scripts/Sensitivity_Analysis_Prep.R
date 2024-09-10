# This file generates .Rmd files for the sensitivity analysis, based on the
# provided files `Case_Detection_Results.Rmd` and `Case_Detection_Results_5yrs.Rmd`.

modify_rmd <- function(new_file, new_title, old_param, new_param) {
  #' Modifies the model .Rmd files to run sensitivity analyses
  #' 
  #' @param new_file path to save new .Rmd file
  #' @param new_title title for .Rmd file
  #' @param old_param line of code with parameter to be replaced
  #' @param new_param new line (to put in place of old_param)

  # List files to be modified
  files = list(
    c("Case_Detection_Results.Rmd", "3yrs"),
    c("Case_Detection_Results_5yrs.Rmd", "5yrs")
  )

  # Repeat this for the 3 year and 5 year model
  for (x in 1:length(files)) {

    # Read content of the original .Rmd file
    content <- readLines(file.path("scripts", files[[x]][1]))

    # Replace title
    mod_content <- gsub(
      "title: \"Case Detection Scenario Main Analysis\"",
      paste0("title: \"Sensitivity analysis: ", new_title, "\""), content)
  
    # Replace parameter
    mod_content <- gsub(old_param, new_param, mod_content)

    # Create the new .Rmd file
    writeLines(mod_content, file.path(
      "scripts/Sensitivity_Analysis", paste0(new_file, files[[x]][2], ".Rmd")))
  }
}

modify_rmd(
  new_file = "Sen1_No_Smoking_Cessation",
  new_title = "No Smoking Cessation",
  old_param = "smoking_adherence=0.7",
  new_param = "smoking_adherence=0"
)

modify_rmd(
  new_file = "Sen2_50_Med_Adherence",
  new_title = "50% Medication Adherence",
  old_param = "medication_adherence=0.7",
  new_param = "medication_adherence=0.5"
)

modify_rmd(
  new_file = "Sen3_30_Med_Adherence",
  new_title = "30% Medication Adherence",
  old_param = "medication_adherence=0.7",
  new_param = "medication_adherence=0.3"
)

modify_rmd(
  new_file = "Sen4_01_Treat_Util",
  new_title = "0.01 Treatment Utility",
  old_param = "medication_utility=0.0367",
  new_param = "medication_utility=0.01"
)

modify_rmd(
  new_file = "Sen5_0_Treat_Util",
  new_title = "0 Treatment Utility",
  old_param = "medication_utility=0.0367",
  new_param = "medication_utility=0"
)

modify_rmd(
  new_file = "Sen6_0_Discount",
  new_title = "0% Discount Rate",
  old_param = "discount_rate=0.015",
  new_param = "discount_rate=0"
)

modify_rmd(
  new_file = "Sen7_3_Discount",
  new_title = "3% Discount Rate",
  old_param = "discount_rate=0.015",
  new_param = "discount_rate=0.03"
)
