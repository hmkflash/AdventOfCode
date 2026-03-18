CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: fresh
fresh: fresh.o
	$(CPPC) $(CPPFLAGS) -o fresh fresh.o
fresh.o:
	$(CPPC) $(CPPFLAGS) -c fresh.cpp

.PHONY: run
run:
	./fresh input.txt

.PHONY: partOne
partOne:
	./fresh input.txt 1

.PHONY: partTwo
partTwo:
	./fresh input.txt 2

.PHONY: clean
clean:
	rm -f fresh log* *.o
