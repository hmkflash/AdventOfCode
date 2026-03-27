CPPC=g++
CPPFLAGS=-Wall -pedantic -g

all: tachyon
tachyon: tachyon.o
	$(CPPC) $(CPPFLAGS) -o tachyon tachyon.o
techyon.o:
	$(CPPC) $(CPPFLAGS) -c tachyon.cpp

.PHONY: run
run:
	./tachyon input.txt

.PHONY: partOne
partOne:
	./tachyon input.txt 1

.PHONY: partTwo
partTwo:
	./tachyon input.txt 2

.PHONY: clean
clean:
	rm -f tachyon log* *.o
