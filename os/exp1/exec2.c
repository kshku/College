#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Compile command
// gcc exec2.c

int main() {
    printf("Hello! It is before fork\n");

    pid_t q = fork();
    if (q < 0) {
        printf("Error\n");
    } else if (q == 0) {
        printf("I am child having pid %d\n", getpid());
        char *args[] = {"./hello", NULL};
        execv(args[0], args);
        printf("Coming back to child process\n");
    } else {
        printf("I am parent\nMy child's pid is %d\n", q);
    }
    printf("Goodbye!\n");
}
