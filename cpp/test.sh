bin_dir="bin"
main_file="Calendar-cpp"

set -x
./$bin_dir/$main_file
./$bin_dir/$main_file -h
./$bin_dir/$main_file --help
./$bin_dir/$main_file -V
./$bin_dir/$main_file --version
./$bin_dir/$main_file 2025
