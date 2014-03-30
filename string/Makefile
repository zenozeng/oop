find-words: String.cpp find-words.cpp
	clang++ String.cpp find-words.cpp -Wall
	./a.out

test: String.cpp test.cpp
	clang++ String.cpp test.cpp -Wall
	./a.out

doc: *.cpp
	doxygen ../doxy-config/Doxyfile

.PHONY: test build find-words
