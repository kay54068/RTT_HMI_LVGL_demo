#!/bin/bash

# The first argument is the project version

file="./version"
if [ ! -f "$file" ]; then
  echo "version file does not exist"
  exit 1
fi

PROJECT_VERSION="$file"
# PROJECT_VERSION=$1

GIT_COMMIT=
GIT_COMMITTER=
GIT_BRANCH=

# Get the current git commit short hash
# GIT_COMMIT=$(git --no-pager describe --always --dirty --abbrev=8)
GIT_COMMIT=$(git rev-parse --verify --short=8 HEAD)
if [ -n "$(git status --porcelain)" ]; then
  GIT_COMMIT="${GIT_COMMIT}-dirty"
fi

# echo $GIT_COMMIT

# # Get the current date
# BUILD_DATE=$(date +"%Y-%m-%d %T")

# Get the last committer information
GIT_COMMITTER=$(git log -1 --pretty=format:'%an <%ae>')

# Get the current git branch
GIT_BRANCH=$(git rev-parse --abbrev-ref HEAD)

# # Get the last commit timestamp
# GIT_LAST_COMMIT_TIMESTAMP=$(git log -1 --format="%ci")

# # Get the compiler information
# COMPILER_INFO=$(gcc -v 2>&1 | tail -1)

# # Get the build user
# BUILD_USER=$(whoami)

# # Get the build machine name
# BUILD_MACHINE=$(hostname)

# # Get the build operating system
# BUILD_OS=$(uname -a)

# Create the version_numbers.h file
cat <<EOL >src/version_numbers.h
// !!! Automatically generated file; DO NOT EDIT. !!!
#ifndef VERSION_NUMBERS_H
#define VERSION_NUMBERS_H

#define PROJECT_VERSION "$PROJECT_VERSION-$GIT_COMMIT"
#define VERSION_NUMBER "$PROJECT_VERSION"
#define GIT_COMMIT_ID "$GIT_COMMIT"
#define GIT_COMMITTER "$GIT_COMMITTER"
#define GIT_BRANCH "$GIT_BRANCH"

#endif // VERSION_NUMBERS_H
EOL

echo "Done."
