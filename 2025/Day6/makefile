CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: math
math: math.o
	$(CPPC) $(CPPFLAGS) -o math math.o
fresh.o:
	$(CPPC) $(CPPFLAGS) -c math.cpp

.PHONY: run
run:
	./math input.txt

.PHONY: partOne
partOne:
	./math input.txt 1

.PHONY: partTwo
partTwo:
	./math input.txt 2

.PHONY: clean
clean:
	rm -f math log* *.o
