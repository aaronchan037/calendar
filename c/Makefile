# 设置make默认目标。如果不设置，就是第一个目标
.DEFAULT_GOAL := build
.PHONY: all build clean test

all: build test clean

build:
	mkdir -p bin build
	cmake -S . -B ./build
	cmake --build ./build
	./bin/Calendar-c

test:
	bash test.sh

clean:
	rm -rf bin build



