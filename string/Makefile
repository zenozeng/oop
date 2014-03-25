build: *.cpp
	clang++ *.cpp -Wall

test: build
	./a.out

CXXFLAGS = -I. -fPIC
SOURCES = *.cpp
HEADERS = *.h

doc: build
	doxygen Doxyfile

.PHONY: test build doc
