CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: ids
ids: ids.o
	$(CPPC) $(CPPFLAGS) -o ids ids.o
ids.o: 
	$(CPPC) $(CPPFLAGS) -c ids.cpp

.PHONY: run
run: 
	./ids input.txt

.PHONY: partOne
partOne:
	./ids input.txt 1

.PHONY: partTwo
partTwo:
	./ids input.txt 2

.PHONY: clean
clean:
	rm -f ids log* *.o
