CC=gcc
FPIC=-fPIC
SO=-shared

MAIN=link

LIBS=
FLAGS=

OUTPUT_PATH=/usr/lib/

all:

so:
	$(CC) -c $(FPIC) $(MAIN).c
	$(CC) -o lib$(MAIN).so $(SO) $(MAIN).o
	sudo cp lib$(MAIN).so $(OUTPUT_PATH)

clean:
	rm *.o *.so
