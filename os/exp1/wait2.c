#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

// Compile command
// gcc wait2.c

int main() {
    // Here we are assuming there will not be any error. (we are not checking
    // whether fork returns -1)
    if (fork() == 0) {  // child right?
        printf("Hello from the child\nChild is running\n");
    } else {  // parent
        printf("Hello from the parent\nParent is runnnig\n");
        wait(NULL);
        printf("Back to parent\nChild got terminated\n");
    }
    printf("Bye!\n");
}
