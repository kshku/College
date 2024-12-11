#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char dname[10], fname[10][10];
    int fc;
} dir;

int search_file(char *file) {
    for (int i = 0; i < dir.fc; ++i)
        if (!strcmp(dir.fname[i], file)) return i;
    return -1;
}

void create_file(char *file) {
    // Can check whether the file exists or not, but not done in the given
    // program
    strcpy(dir.fname[dir.fc++], file);
}

void delete_file(char *file) {
    // Get the index of the file
    int index = search_file(file);

    if (index == -1) {
        printf("File '%s' not found\n", file);
        return;
    }

    // Copy the last file to here
    strcpy(dir.fname[index], dir.fname[dir.fc - 1]);
    --dir.fc;
    printf("File '%s' is deleted\n", file);
}

void display() {
    if (dir.fc == 0) {
        printf("Directory is empty\n");
        return;
    }

    printf("Files are: ");
    for (int i = 0; i < dir.fc - 1; ++i) printf("%s\t", dir.fname[i]);
    printf("%s\n", dir.fname[dir.fc - 1]);
}

int main() {
    printf("Enter the directory name: ");
    scanf("%s", dir.dname);

    dir.fc = 0;

    printf("1.Create File\n");
    printf("2.Delete File\n");
    printf("3.Search File\n");
    printf("4.Display Files\n");
    printf("5.Exit\n");

    int ch;
    char file[10];
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1 || ch == 2 || ch == 3) {
            printf("Enter the file name: ");
            scanf("%s", file);
        }

        switch (ch) {
            case 1:
                create_file(file);
                break;
            case 2:
                delete_file(file);
                break;
            case 3:
                if (search_file(file) == -1)
                    printf("File '%s' not found\n", file);
                else
                    printf("File '%s' found\n", file);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
    }
}
