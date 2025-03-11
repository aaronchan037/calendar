# 设置make默认目标。如果不设置，就是第一个目标
.DEFAULT_GOAL := all
.PHONY: all c cpp install uninstall


all: c cpp

c:
	cd c && make all

cpp:
	cd cpp && make all



install:
	bash ./scripts/install.sh

uninstall:
	bash ./scripts/uninstall.sh

