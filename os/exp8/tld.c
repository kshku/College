#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char dname[10], fname[10][10];
    int fc;
} dir[10];

int dc = 0;

int search_file(char *file, int di) {
    for (int i = 0; i < dir[di].fc; ++i)
        if (!strcmp(dir[di].fname[i], file)) return i;
    return -1;
}

int search_dir(char *dname) {
    for (int i = 0; i < dc; ++i)
        if (!strcmp(dir[i].dname, dname)) return i;
    return -1;
}

void create_dir(char *dname) {
    strcpy(dir[dc].dname, dname);
    dir[dc++].fc = 0;
    printf("Created directory\n");
}

void create_file(char *file, int di) {
    // Can check whether the file exists or not, but not done in the given
    // program
    strcpy(dir[di].fname[dir[di].fc++], file);
}

void delete_file(char *file, int di) {
    // Get the index of the file
    int index = search_file(file, di);

    if (index == -1) {
        printf("File '%s' not found\n", file);
        return;
    }

    // Copy the last file to here
    strcpy(dir[di].fname[index], dir[di].fname[dir[di].fc - 1]);
    --dir[di].fc;
    printf("File '%s' is deleted\n", file);
}

void display() {
    if (dc == 0) {
        printf("No directories\n");
        return;
    }

    for (int i = 0; i < dc; ++i) {
        printf("Directory: %s\n", dir[i].dname);
        for (int j = 0; j < dir[i].fc; ++j) printf("\t%s\n", dir[i].fname[j]);
    }

    // printf("Files are: ");
    // for (int i = 0; i < dir[di].fc - 1; ++i) printf("%s\t",
    // dir[di].fname[i]); printf("%s\n", dir[di].fname[dir[di].fc - 1]);
}

int main() {
    printf("1.Create directory\n");
    printf("2.Create File\n");
    printf("3.Delete File\n");
    printf("4.Search File\n");
    printf("5.Display Files\n");
    printf("6.Exit\n");

    int ch, di;
    char file[10], directory[10];
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1 || ch == 2 || ch == 3 || ch == 4) {
            printf("Enter the directory name: ");
            scanf("%s", directory);

            if (ch == 2 || ch == 3 || ch == 4) {
                di = search_dir(directory);
                if (di == -1) {
                    printf("Directory '%s' not found\n", directory);
                    continue;
                }

                printf("Enter the file name: ");
                scanf("%s", file);
            }
        }

        switch (ch) {
            case 1:
                create_dir(directory);
                break;
            case 2:
                create_file(file, di);
                break;
            case 3:
                delete_file(file, di);
                break;
            case 4:
                if (search_file(file, di) == -1)
                    printf("File '%s' not found\n", file);
                else
                    printf("File '%s' found\n", file);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
    }
}
