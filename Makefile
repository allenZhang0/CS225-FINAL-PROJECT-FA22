CXX=clang++
#CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror -Iincludes/
CXX_FLAGS=-g -Wall 

run: src/run
tests: src/test


src/run: src/graph.h src/graph.cpp src/trimmer.h src/trimmer.cpp
	${CXX} ${CXX_FLAGS} src/main.cpp src/graph.cpp src/trimmer.cpp -o run

src/test: tests/parse_test.cpp tests/parse_test.h src/graph.h src/graph.cpp
	${CXX} ${CXX_FLAGS} src/main.cpp tests/parse_test.cpp src/graph.cpp -o test

.DEFAULT_GOAL := run
.PHONY: run tests

clean:
	rm -rf bin/*