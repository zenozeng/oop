build: *.cpp
	clang++ *.cpp -Wall

test: String.cpp test.cpp
	clang++ String.cpp test.cpp
	./a.out

doc: *.cpp
	doxygen ../doxy-config/Doxyfile

.PHONY: test build doc
