CC=g++
DEPS = bus.hpp cpu.hpp ram.hpp
OBJ = bus.o cpu.o ram.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

emu-comp: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)