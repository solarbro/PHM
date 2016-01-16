cls
cd ../
mkdir buildGCC
cd buildGCC
cmake -DCMAKE_BUILD_TYPE=Release -G "MinGW Makefiles" ../src
make
cd ..
