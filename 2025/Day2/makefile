CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: ids
ids: ids.o
	$(CPPC) $(CPPFLAGS) -o ids ids.o
ids.o: 
	$(CPPC) $(CPPFLAGS) -c ids.c

.PHONY: run
run: 
	./ids

.PHONY: partOne
partOne:
	./ids 1

.PHONY: partTwo
partTwo:
	./ids 2

.PHONY: clean
clean:
	rm -f ids log* *.o
