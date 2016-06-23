CC=gcc
FPIC=-fPIC
SO=-shared

MAIN=stack

LIBS=
FLAGS=


all:

so:
	$(CC) -c $(FPIC) $(MAIN).c
	$(CC) -o lib$(MAIN).so $(SO) $(MAIN).o


clean:
	rm *.o *.so
