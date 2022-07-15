rem generate build files in a folder called "Build"
cmake -O . -B ./Build -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON

rem build project
cmake --build ./Build

echo compilation done!
