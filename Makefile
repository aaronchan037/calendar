# 设置make默认目标。如果不设置，就是第一个目标
.DEFAULT_GOAL := test
.PHONY: test install uninstall

test:
	bash test.sh

install:
	bash install.sh

uninstall:
	bash uninstall.sh

