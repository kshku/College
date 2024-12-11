#include <stdio.h>
#include <unistd.h>

// Compile command
// gcc exec.c

int main() {
    printf("I am in exec.c\n");
    printf("PID of exec.c is %d\n", getpid());
    // char * => string
    // char *[] => array of strings
    // args[0] = command to be executed
    // Should be null terminated
    char *args[] = {"./hello", NULL};
    // Execute the command with given arguments
    execv(args[0], args);
    printf("Coming back to exec.c\n");
}
