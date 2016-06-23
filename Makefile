CC=gcc

LIB_PATH=-L ./Queue -L ./Stack -L ./Link
LIBS=-lqueue -lstack -llink

FLAGS=-I ./Queue -I ./Stack -I ./Link

MAIN=myProgram

all:
	make so -C ./Queue
	make so -C ./Stack
	make so -C ./Link
	$(CC) -c $(MAIN).c $(FLAGS)
	$(CC) -o $(MAIN) $(MAIN).o $(LIB_PATH) $(LIBS)


clean:
	make clean -C ./Queue
	make clean -C ./Stack
	make clean -C ./Link
	rm *.o $(MAIN)
