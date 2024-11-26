#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    printf("%d about to create 2 child processes\n", getpid());

    int random_sleep;
    pid_t child1, child2;
    child1 = fork();
    if (child1 == 0) {
        srand(getpid());
        random_sleep = rand() % 5 + 1;
        printf("child1: %d %dsec\n", getpid(), random_sleep);
        sleep(random_sleep);
        printf("%d finished after %d sec\n", getpid(), random_sleep);
    } else {
        child2 = fork();
        if (child2 == 0) {
            srand(getpid());
            random_sleep = rand() % 5 + 1;
            printf("child2: %d %dsec\n", getpid(), random_sleep);
            sleep(random_sleep);
            printf("%d finished after %d sec\n", getpid(), random_sleep);
        } else {
            printf("hello from parent\n");
        }
    }
    // printf("%d\n", getpid() % 5 + 1);

    return 0;
}
