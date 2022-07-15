#!/bin/bash
# generate build files
cmake -O . -B ./Build -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON

# build project
cmake --build Build
echo compilation done!
