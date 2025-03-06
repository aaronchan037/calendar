# 设置make默认目标。如果不设置，就是第一个目标
.DEFAULT_GOAL := build
.PHONY: build clean

build:
	mkdir -p bin build
	cmake -S . -B ./build
	cmake --build ./build
	./bin/Calendar-cpp

clean:
	rm -rf bin build


