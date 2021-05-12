# set to your installed visual studio version "Visual Studio 16 2019" if lower as 2019 then remove the '-A x64' flag
cmake -G "Visual Studio 16 2019" -A x64 -B ./build -DCMAKE_BUILD_TYPE=Release
cmake --build ./build --config Release