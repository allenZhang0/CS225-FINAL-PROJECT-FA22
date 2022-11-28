CXX=clang++
CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror -Iincludes/

run: src/run
tests: tests/test1


src/run: src/graph.h src/graph.cpp src/trimmer.h src/trimmer.cpp
	${CXX} ${CXX_FLAGS} src/main.cpp src/graph.cpp src/trimmer.cpp -o run

tests/test1: src/graph.h src/graph.cpp tests/parse_test.cpp tests/parse_test.h
	${CXX} ${CXX_FLAGS} tests/parse_test.cpp src/graph.cpp -o test

.DEFAULT_GOAL := run
.PHONY: run tests

clean:
	rm -rf bin/*