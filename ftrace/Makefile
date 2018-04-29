all: ftrace.a
ftrace.a: ftrace.o
	$(AR) rcs $@ $^
ftrace.o: ftrace.c
	$(CC) -c -o $@ $<
