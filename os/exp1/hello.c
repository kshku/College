#include <stdio.h>
#include <unistd.h>

// Compile command
// gcc hello.c -o hello

int main() {
    printf("I am hello.c\n");
    printf("PID of hello.c is %d\n", getpid());
}
