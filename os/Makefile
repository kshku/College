CC := gcc
CFLAGS := -Wall -Werror -Wextra -Wformat -fopenmp
SOURCES := $(shell find -type f -name "*.c")
EXECUTABLES := $(SOURCES:%.c=%)

all: $(EXECUTABLES)

$(EXECUTABLES): $(SOURCES)
	$(CC) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(SOURCES:%.c=%)

.PHONY: all clean
