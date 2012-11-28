all: dynamicarray.h
	g++ -c dynamicarray.h -o dynamicarray.gch
install: dynamicarray.gch
	sudo mv dynamicarray.gch /usr/include/
