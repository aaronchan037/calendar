cd ././src
echo "##### C programming #####"
gcc main.c data.c info.c -o calendar


set -x
# Run the program
./calendar

./calendar --help


# ./main -h
# ./main --version
# ./main -V

# ./main 2020
# ./main 2025

