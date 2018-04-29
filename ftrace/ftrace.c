#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>

void clean_tracer(void)
{
	int tracing_on, ret, trace;
	tracing_on = open("/sys/kernel/debug/tracing/tracing_on", O_WRONLY);
	if (tracing_on < 0) {
		perror("error:");
		exit(-1);
	}
	ret = write(tracing_on, "0", 1);
	if (ret < 0) {
		perror("error:");
		exit(-1);
	}
	trace = open("/sys/kernel/debug/tracing/trace", O_WRONLY);
	if (trace < 0) {
		perror("error:");
		exit(-1);
	}
	ret = write(trace, "0", 1);
	if (ret < 0) {
		perror("error:");
		exit(-1);
	}
}

void trace_fun(char *fname)
{
	int pid, set_ftrace_pid, current_tracer, set_ftrace_filter, tracing_on, ret;
	tracing_on = open("/sys/kernel/debug/tracing/tracing_on", O_WRONLY);
	if (tracing_on < 0) {
		perror("error:");
		exit(-1);
	}
	ret = write(tracing_on, "1", 1);
	if (ret < 0) {
		perror("error:");
		exit(-1);
	}
	pid = getpid();
	char buffer[20] = {0, 0};
	set_ftrace_pid = open("/sys/kernel/debug/tracing/set_ftrace_pid", O_WRONLY);
	if (set_ftrace_pid < 0) {
		perror("error:");
		exit(-1);
	}
	sprintf(buffer, "%d", pid);
	ret = write(set_ftrace_pid, buffer, strlen(buffer));
	if (ret < 0) {
		perror("error:");
		exit(-1);
	}
	current_tracer = open("/sys/kernel/debug/tracing/current_tracer", O_WRONLY);
	if (current_tracer < 0) {
		perror("error:");
		exit(-1);
	}
	ret = write(current_tracer, "function", strlen("function"));
	if (ret < 0) {
		perror("error:");
		exit(-1);
	}
	/*set_ftrace_filter = open("/sys/kernel/debug/tracing/set_ftrace_filter", O_WRONLY);
	if (set_ftrace_filter < 0) {
		perror("error:");
		exit(-1);
	}
	ret = write(set_ftrace_filter, fname, strlen(fname));
	if (ret < 0) {
		perror("error:");
		exit(-1);
	}*/
}
