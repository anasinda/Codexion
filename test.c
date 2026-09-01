#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>


int main(void)
{
    struct timespec clock_start;
    struct timespec clock_end;
    clock_gettime(CLOCK_MONOTONIC, &clock_start);
    sleep(1);
    clock_gettime(CLOCK_MONOTONIC, &clock_end);
    long ms_start = (clock_start.tv_sec * 1000) + (clock_start.tv_nsec / 1000000);
    long ms_end = (clock_end.tv_sec * 1000) + (clock_end.tv_nsec / 1000000);
    printf("This is how much time passed: %ld\n", ms_end - ms_start);
    return 0;
}
