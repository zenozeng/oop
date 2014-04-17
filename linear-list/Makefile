array_test: array_test.cpp linear_list.hpp
	clang++ array_test.cpp -Wall -std=c++11
	./a.out

list_test: list_test.cpp linear_list.hpp
	clang++ list_test.cpp -Wall -std=c++11
	./a.out

benchmark: benchmark.cpp stack.hpp
	clang++ benchmark.cpp -Wall -std=c++11
	./a.out

debug: benchmark.cpp stack.hpp
	g++ benchmark.cpp -g -std=c++11
	gdb a.out

.PHONY: build
