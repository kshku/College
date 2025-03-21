#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Compile command
// gcc ipc_writer.c -o writer

int main() {
    int fd;
    char *myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char str[100];
    while (1) {
        fd = open(myfifo, O_WRONLY);
        fgets(str, 100, stdin);
        write(fd, str, strlen(str) + 1);
        close(fd);
        fd = open(myfifo, O_RDONLY);
        read(fd, str, sizeof(str));
        printf("User2: %s\n", str);
        close(fd);
    }
}
