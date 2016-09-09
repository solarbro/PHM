cls
cd ../
mkdir -p buildGCC
cd buildGCC
cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../src
make
cd ..
