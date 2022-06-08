CC=clang++
CFLAGS=-I.
DEPS = function.h predCoor.h
OBJ = main.o function.o predCorr.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
