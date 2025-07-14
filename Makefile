CC = gcc
CFLAGS = -Wall -Wextra -Werror
C_SRC_DIR = c

RUSTC = rustc
RUST_SRC_DIR = rust

C_SOURCES := $(wildcard $(C_SRC_DIR)/*.c)
RUST_SOURCES := $(wildcard $(RUST_SRC_DIR)/*.rs)

all: $(C_SOURCES:.c=) $(RUST_SOURCES:.rs=)

# C compile rule
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Rust compile rule
%: %.rs
	$(RUSTC) $< -o $@

clean:
	rm -f $(C_SOURCES:.c=) $(RUST_SOURCES:.rs=)

.PHONY: all clean