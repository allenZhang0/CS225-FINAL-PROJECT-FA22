CXX=clang++
CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror -Iincludes/
#CXX_FLAGS=-g -Wall 

run: src/run
tests: tests/test1


src/run: src/graph.h src/graph.cpp src/trimmer.h src/trimmer.cpp
	${CXX} ${CXX_FLAGS} src/main.cpp src/graph.cpp src/trimmer.cpp -o run

tests/test1: src/graph.h src/graph.cpp tests/test.cpp
	${CXX} ${CXX_FLAGS} tests/test.cpp src/graph.cpp -o t1


.DEFAULT_GOAL := run
.PHONY: run tests

clean:
	rm -rf bin/*