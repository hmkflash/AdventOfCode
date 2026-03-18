CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: batteries
batteries: bateries.o
	$(CPPC) $(CPPFLAGS) -o batteries batteries.o
dails.o:
	$(CPPC) $(CPPFLAGS) -c batteries.cpp

.PHONY: run
run:
	./batteries

.PHONY: partOne
partOne:
	./batteries 1

.PHONY: partTwo
partTwo:
	./batteries 2

.PHONY: clean
clean:
	rm -f batteries log* *.c
