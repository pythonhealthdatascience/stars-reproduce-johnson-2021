# Get base image from rocker
FROM rocker/rstudio:4.4.1

# Set version of packages installed outside the lockfile
ENV STRINGI_VERSION '1.8.4'
ENV OPENSSL_VERSION '2.2.0'

# Install system dependencies
RUN apt-get update && \
	apt-get install -y \
	libcurl4-openssl-dev \
	libssl-dev \
	libxml2-dev \
	libglpk-dev \
	libicu-dev \
	tk

# Set user to rstudio, so we have access to the renv/ and files
USER rstudio

# Set project directory (otherwise files will copy into an inaccessible location,
# as the rstudio rocker image home is this path)
ENV PROJDIRECTORY "/home/rstudio/"
WORKDIR ${PROJDIRECTORY}

# Copy desired files (inc. renv.lock)
# (run individually rather than with COPY all and .dockerignore, as that was
# inadvertently copying over something that was causing issues)
COPY --chown=rstudio ./reproduction/DESCRIPTION DESCRIPTION
COPY --chown=rstudio ./reproduction/docker docker
COPY --chown=rstudio ./reproduction/epicR epicR
COPY --chown=rstudio ./reproduction/outputs outputs
COPY --chown=rstudio ./reproduction/scripts scripts
COPY --chown=rstudio ./reproduction/tests tests
COPY --chown=rstudio ./reproduction/renv.lock renv.lock
COPY --chown=rstudio ./reproduction/README.md README.md
COPY --chown=rstudio ./reproduction/johnson2021.Rproj johnson2021.Rproj

# Copy renv auto-loader tools
RUN mkdir -p renv/library
COPY ./reproduction/.Rprofile .Rprofile
COPY ./reproduction/renv/activate.R renv/activate.R

# Install seperately before restore (due to issues with finding system dependencies)
# Running the `renv::` commands will automatically install renv for us
RUN R -e "renv::install('stringi@${STRINGI_VERSION}')"
RUN R -e "renv::install('openssl@${OPENSSL_VERSION}')"

# Install remaining packages
RUN R -e "renv::restore(lockfile='${PROJDIRECTORY}/renv.lock', repos = c(CRAN = 'https://packagemanager.rstudio.com/all/__linux__/focal/latest'))"

# Set user back to root
USER root