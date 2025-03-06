# cd src
# gcc main.c data.c info.c -o calendar


cd c
make
# 将可执行文件移动到 /usr/local/bin 目录下
sudo cp ./bin/calendar /usr/local/bin

# 这样就可以使用命令行来调用程序了

