rem generate build files in a folder called "Build"
cmake -O . -B ./Build -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON

rem build project
cmake --build ./Build

rem copy shared .dll files to ouput directory
robocopy "Dependencies/Libraries/Shared/bin/"  "Build/Debug/" /E

rem copy debug .dll files to ouput directory
robocopy "Dependencies/Libraries/Debug/bin/"  "Build/Debug/" /E

echo compilation done!
