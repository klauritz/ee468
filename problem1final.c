#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main( ) {
    pid_t pid;
    int status = 0;
    int i;
    for (i = 0; i < 100; i++) {
        pid = fork( );
        if (pid < 0) {
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if (pid == 0) {
            printf("I am child # %d\n", i);
            return 0;
        }
    }
    while ((pid = wait(&status)) > 0);
    printf("All child processes are done \n");
    return 0;
} /* end of main */
