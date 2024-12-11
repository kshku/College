#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Compile command
// gcc fork.c

int main() {
    printf("Hello! It is before fork\n");
    printf("PID = %d\n", getpid());

    // The execution starting point of the child process is after the fork()
    // line
    pid_t q = fork();

    if (q < 0) {  // q = -1 if error
        printf("Error\n");
    } else if (q == 0) {  // for child q = 0
        printf("I am child process having pid %d\n", getpid());
    } else {  // for parent q = child's pid
        printf("I am parent\nMy child's pid is %d\n", q);
    }

    printf("Goodbye!\n");
}
