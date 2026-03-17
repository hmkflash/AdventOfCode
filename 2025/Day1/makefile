CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: dials
dials: dials.o
	$(CPPC) $(CPPFLAGS) -o dials dials.o
dails.o:
	$(CPPC) $(CPPFLAGS) -c dials.c

.PHONY: run
run:
	./dials

.PHONY: partOne
partOne:
	./dials 1

.PHONY: partTwo
partTwo:
	./dials 2
	
.PHONY: clean
clean:
	rm -f dials log* *.o
