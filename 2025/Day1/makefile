CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: dials
dials: dials.o
	$(CPPC) $(CPPFLAGS) -o dials dials.o
dails.o:
	$(CPPC) $(CPPFLAGS) -c dials.c

.PHONY: run
run:
	./dials input.txt

.PHONY: partOne
partOne:
	./dials input.txt 1

.PHONY: partTwo
partTwo:
	./dials input.txt 2
	
.PHONY: clean
clean:
	rm -f dials log* *.o

