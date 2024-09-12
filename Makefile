.SILENT:

CC=gcc
CFLAGS=-Wall

all: cat_to_bf bf_interpreter

cat_to_bf: cat_to_bf.c
	@$(CC) $(CFLAGS) -o cat_to_bf cat_to_bf.c

bf_interpreter: bf_interpreter.c
	@$(CC) $(CFLAGS) -o bf_interpreter bf_interpreter.c

run: all
	@./cat_to_bf $(INPUT) > output.bf
	@./bf_interpreter output.bf
	@$(MAKE) -s clean

clean:
	@rm -f cat_to_bf bf_interpreter output.bf

.PHONY: all run clean
