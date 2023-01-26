cc = gcc
CC_FLAGS = -Wall -Wextra -Werror

all: my-cat my-grep my-zip my-unzip
my-cat: my-cat.c
	$(cc) -o my-cat my-cat.c $(CC_FLAGS)

my-grep: my-grep.c
	$(cc) -o my-grep my-grep.c $(CC_FLAGS)

my-zip: my-zip.c
	$(cc) -o my-zip my-zip.c $(CC_FLAGS)

my-unzip: my-unzip.c
	$(cc) -o my-unzip my-unzip.c $(CC_FLAGS)

clean:
	rm -f my-cat my-grep my-zip my-unzip