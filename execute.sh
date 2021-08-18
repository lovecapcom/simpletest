rm -rf ./build/*
cd build/
cmake ..
make
cd ../bin
./test
