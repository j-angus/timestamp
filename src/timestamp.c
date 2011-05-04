/**
 * timestamp.c
 * Appends the current time to the end of filenames given as arguments.
 * _YYYYmmdd_HHMMSS_sss
 * where sss = milliseconds, 000 - 999
 */


/* includes */
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/* defines */
#define THIS_FILE "timeline.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);
/* _YYYYmmdd_HHMMSS_sss */
#define TIMESTR_MAX 20

int
main(int argc, char **argv)
{	PRINT_FILE_INFO
	struct timespec time_spec;
	struct tm *time_tm;
	char time_str[TIMESTR_MAX+1];
	time_t t;

	clock_gettime(CLOCK_REALTIME, &time_spec);
	t = time_spec.tv_sec;
	time_tm = localtime(&t);
	strftime(time_str, sizeof(time_str), "_%Y%m%d_%H%M%S_", time_tm);
	printf("time_str: %s\n", time_str);

	
	return 0;
}

