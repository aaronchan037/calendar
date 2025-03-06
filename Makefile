# 设置make默认目标。如果不设置，就是第一个目标
.DEFAULT_GOAL := build
.PHONY: build test install uninstall

build:
	echo "Hello world"

test:
	bash test.sh

install:
	bash ./scripts/install.sh

uninstall:
	bash ./scripts/uninstall.sh

