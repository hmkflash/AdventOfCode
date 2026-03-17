CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: paper
paper: paper.o
	$(CPPC) $(CPPFLAGS) -o paper paper.o
paper.o:
	$(CPPC) $(CPPFLAGS) -c paper.c

.PHONY: run
run:
	./paper

.PHONY: partOne
partOne:
	./paper 1

.PHONY: partTwo
partTwo:
	./paper 2

.PHONY: clean
clean:
	rm -f paper log* *.o
