.DEFAULT_GOAL := all
.PHONY: all build clean

all: build clean

build:
	mkdir -p bin build
	cmake -S . -B ./build
	cmake --build ./build
	./bin/calendar

clean:
	rm -rf bin build
