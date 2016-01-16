cls
cd ../
mkdir buildGCC
cd buildGCC
cmake -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles" ../src
make
cd ..
