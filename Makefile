# 设置make默认目标。如果不设置，就是第一个目标
.DEFAULT_GOAL := make
.PHONY: make

make:
	bash main.sh
