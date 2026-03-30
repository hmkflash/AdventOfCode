CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: junction
junction: junction.o
	$(CPPC) $(CPPFLAGS) -o junction junction.o
junction.o:
	$(CPPC) $(CPPFLAGS) -c junction.cpp

.PHONY: run
run:
	./junction input.txt

.PHONY: partOne
partOne:
	./junction input.txt 1

.PHONY: partTwo
partTwo:
	./junction input.txt 2

.PHONY: clean
clean:
	rm -f junction log* *.o
