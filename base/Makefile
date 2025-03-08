.DEFAULT_GOAL := build
.PHONY: all build clean

all: build clean

build:
	mkdir -p bin build
	cmake -S . -B ./build
	cmake --build ./build

clean:
	rm -rf bin build
