CC=clang++
CFLAGS=-std=c++11
CFLAGS+=-stdlib=libc++
CFLAGS+=-I.
DEBUG=-g


DEPS = function.h RK4.h PolyReg.h vector_fwrd.h
OBJ = Kieran_MacDonald_e2_w14.o function.o RK4.o PolyReg.o


%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< $(DEBUG)

run: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(DEBUG)

clean:
	rm -f *.o run
run.o: main.cpp
