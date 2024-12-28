CC := gcc
CFLAGS := -Wall -Werror -Wextra -Wformat
SOURCES := $(shell find -type f -name "*.c")
EXECUTABLES := $(SOURCES:%.c=%)
LDFLAGS := -lm

all: $(EXECUTABLES)

$(EXECUTABLES): $(SOURCES)
	$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS)

clean:
	rm -f $(SOURCES:%.c=%)

.PHONY: all clean
