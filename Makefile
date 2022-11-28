CXX=clang++
CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror -Iincludes/

tests: src/tests


src/tests: src/graph.h src/graph.cpp src/trimmer.h src/trimmer.cpp
	${CXX} ${CXX_FLAGS} src/main.cpp src/graph.cpp src/trimmer.cpp -o run

.DEFAULT_GOAL := tests
.PHONY: tests

clean:
	rm -rf bin/*