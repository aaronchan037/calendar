cd ././src
echo "##### C programming #####"
gcc main.c -o main


set -x
# Run the program
./main
./main --help
./main -h
./main --version
./main -V

set +x

echo "##### C++ programming #####"
g++ main.cpp -o main

set -x
./main
./main --help
./main -h
./main --version
./main -V
