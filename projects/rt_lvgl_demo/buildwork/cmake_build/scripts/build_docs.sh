#!/bin/bash

VERSION=1.0.0
rm -rf build/build_docs
mkdir build/build_docs
cd build/build_docs

cmake ../.. -DBUILD_DOC=ON -DDOCS_VERSION=$VERSION
make -j$(nproc) docs

read -n 1 -p "Press any key to continue..."
make -j$(nproc) docs_open
