cc = gcc
CC_FLAGS = -Wall -Wextra -Werror

all: pzip my-unzip
pzip: pzip.c
	$(cc) -o pzip pzip.c $(CC_FLAGS)

my-unzip: my-unzip.c
	$(cc) -o my-unzip my-unzip.c $(CC_FLAGS)

clean:
	rm -f pzip my-unzip