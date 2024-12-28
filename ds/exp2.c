#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *string, char *pattern, int string_length, int pattern_length) {
    // Do brute force searching
    for (int i = 0; i < (string_length - pattern_length + 1); ++i) {
        bool found = true;  // Assueme we found the pattern
        for (int j = 0; j < pattern_length; ++j) {
            if (string[i + j] != pattern[j]) {  // Characters didn't match
                // We didn't find the pattern from the ith character
                found = false;
                break;  // Go to next position in string
            }
        }
        if (found) {
            // We found the pattern return this index since this is where the
            // pattern starts.
            return i;
        }
    }

    // We haven't found the pattern in entire string.
    return -1;
}

void replaceString(char *string, char *replace, int index, int replace_length) {
    for (int i = 0; i < replace_length; ++i) string[index++] = replace[i];
    // We can use memcpy which is library function as
    // memcpy((void *)(string + index), replace, replace_length);
}

int main() {
    char *string = (char *)malloc(100 * sizeof(char));
    char *pattern = (char *)malloc(100 * sizeof(char));
    char *replace = (char *)malloc(100 * sizeof(char));

    printf("Enter the string: ");
    scanf(" %[^\n]", string);

    printf("Enter the pattern: ");
    scanf(" %[^\n]", pattern);

    printf("Enter the replace string: ");
    scanf(" %[^\n]", replace);

    int string_length = strlen(string), pattern_length = strlen(pattern),
        replace_length = strlen(replace);

    int index = find(string, pattern, string_length, pattern_length);
    if (index == -1) {
        printf("Couldn't find the pattern\n");
        goto release;  // Free the memory and exit
    }

    printf("The pattern starts from the index %d\n", index);

    if (pattern_length != replace_length) {
        printf("The pattern and replace string length should be same\n");
        goto release;
    }

    replaceString(string, replace, index, replace_length);

    printf("Replaced string is: %s\n", string);

release:
    free(string);
    free(pattern);
    free(replace);
}
