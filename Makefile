all: dynamicarray.h
	g++ -c dynamicarray.cpp
clean:
	rm -rf *.o *.out
