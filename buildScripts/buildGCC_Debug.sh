clear
cd ../
mkdir -p buildGCC
cd buildGCC
cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" ../src
make
cd ..
