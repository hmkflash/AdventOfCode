CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: batteries
batteries: batteries.o
	$(CPPC) $(CPPFLAGS) -o batteries batteries.o
batteries.o:
	$(CPPC) $(CPPFLAGS) -c batteries.cpp

.PHONY: run
run:
	./batteries input.txt

.PHONY: partOne
partOne:
	./batteries input.txt 1

.PHONY: partTwo
partTwo:
	./batteries input.txt 2

.PHONY: clean
clean:
	rm -f batteries log* *.c
