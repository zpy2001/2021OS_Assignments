#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int i;
    for (i = 0; i < 3; ++i) {
        pid = fork();// fork another process
        if (pid < 0) { // error occurred
            fprintf(stderr, "Fork Failed");
            exit(-1);
        } else if (pid == 0) {
            fprintf(stdout, "i=%d, pid=%d, parent pid=%d\n", i, getpid(), getppid());
        }
    }
        wait(NULL);
        exit(0);


}