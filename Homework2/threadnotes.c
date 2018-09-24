// Implementing Threads Example 1
// Author: Kenneth Lauritzen

#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5

void *printHello(void *threadid) { // note how theres only 1 argument and is type (void *), explained on line 29
    long tid;               // thread ID
    tid = (long) threadid;  // casts threadid to make sure its type long

    printf("THREAD %ld: Hi, I'm thread #%ld\n", tid, tid);
    pthread_exit(NULL);     // terminates thread (could also do return but idk if thats safe)
}

int main (int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS]; // array to store thread IDs
    int rc;                         // return code from pthread_create() function
    long t;                         // counter for number of threads created

    /* for loop creates threads and handles errors */
    for (t = 0; t < NUM_THREADS; t++) {
        printf("MAIN: Creating thread %d\n", t);

        /* pthread_create(thread, attr, start_routine, arg) arguments:
            thread: thread id
            attr: object that sets attributes like stack size, etc.; make NULL for default
            start_routine: routine that the thread will execute
            arg: argument for routine. Only allowed 1 argument, has to be of type (void *)
        */
        rc = pthread_create(&threads[t], NULL, printHello, (void *)t);
        if (rc) {
            printf("ERROR: pthread_create() returned %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL); // make sure main has this to ensure it doesn't end before threads are done (IMPORTANT)
}

// Note: It's possible to pass threads multiple arguments by using a struct :)