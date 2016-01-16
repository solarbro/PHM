cls
cd ../
mkdir buildMSVC
cd buildMSVC
cmake -G"Visual Studio 12 2013 Win64" ../src -DCMAKE_BUILD_TYPE="Debug;Release;RelWithDebInfo" 