#include <stdio.h>
#include "ftrace/ftrace.h"
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char a[1638400];
	int i = 0;
	clean_tracer();
	trace_fun("__do_page_fault");
	for (i = 0; i < 1638400; i++) {
		a[i] = 'c';
		printf("access %x\n", (unsigned)(a+i));
		if (a[i] != 0)
			printf("a[%d]:%d\n", i, a[i]);
	}
	clean_tracer();
}
