# 设置make默认目标。如果不设置，就是第一个目标
.DEFAULT_GOAL := build
.PHONY: build clean test

build:
	cargo run

clean:
	rm -rf target Cargo.lock

test:
	./target/debug/rust
