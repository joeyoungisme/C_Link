CC=gcc
FPIC=-fPIC
SO=-shared

MAIN=stack

LIBS=
FLAGS=

OUTPUT=/usr/lib

all:

so:
	$(CC) -c $(FPIC) $(MAIN).c 
	$(CC) -o lib$(MAIN).so $(SO) $(MAIN).o
	sudo cp lib$(MAIN).so $(OUTPUT)

clean:
	rm *.o *.so
