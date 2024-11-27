#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    printf("%d about to create 2 child processes\n", getpid());

    pid_t child1, child2;

    child1 = fork();
    if (child1 == 0) {
        srand(getpid());
        int sleep1 = rand() % 5 + 1;
        printf("%d %dsec\n", getpid(), sleep1);
        sleep(sleep1);
        printf("%d finished after %d sec\n", getpid(), sleep1);
        return sleep1;
    } else {
        child2 = fork();
        if (child2 == 0) {
            srand(getpid());
            int sleep2 = rand() % 5 + 1;
            printf("%d %dsec\n", getpid(), sleep2);
            sleep(sleep2);
            printf("%d finished after %d sec\n", getpid(), sleep2);
            return sleep2;
        } else {
            int status;
            int exited_pid = wait(&status); // waiting for a child to finish
            printf("Main Process %d is done. Child %d slept for %d sec.\n", getpid(), exited_pid, WEXITSTATUS(status));
            exit(0);
            wait(NULL);
        }
    }

    return 0;
}
