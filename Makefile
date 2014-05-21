CC=gcc

all: main module.so

main: main.c sdk.c sdk.h
	$(CC) -o main main.c sdk.c -Wall -D_GNU_SOURCE -ldl -Wl,--export-dynamic

module.so: module.c sdk.h
	$(CC) -o module.so module.c --shared -fPIC

clean:
	rm main module.so 2>/dev/null
