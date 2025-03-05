# 设置make默认目标。如果不设置，就是第一个目标
.DEFAULT_GOAL := build
.PHONY: build clean test install uninstall

build:
	mkdir -p bin build
	cmake -S . -B ./build
	cmake --build ./build
	./bin/Calendar

clean:
	rm -rf bin build

test:
	bash test.sh

install:
	bash install.sh

uninstall:
	bash uninstall.sh

