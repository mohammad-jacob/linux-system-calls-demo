#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child Process:\n");
        printf("Child PID: %d\n", getpid());
        printf("Executing 'ls' using exec()...\n\n");

        execl("/bin/ls", "ls", NULL);

        printf("Exec failed!\n");
        exit(1);
    }
    else {
        printf("Parent Process:\n");
        printf("Parent PID: %d\n\n", getpid());

        wait(NULL);

        printf("\nChild process finished.\n");
        printf("Parent exiting...\n");

        exit(0);
    }
}