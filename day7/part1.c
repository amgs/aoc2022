#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int size;
    char name[80];
} _File, *File;

struct Folder {
    File *files;
    int num_files;
    struct Folder *folders;
    int num_folders;
    char name[80];
};
typedef struct Folder _Folder, *Folder;

int main() {
    FILE *fp = fopen("input.txt", "r");
    assert(fp != NULL);
    char *line = NULL;
    size_t len = 0;
    while (feof(fp) == 0) {
        getline(&line, &len, fp);
        printf("%s", line);

        char *token = strtok(line, " ");
        Folder folder = NULL;

        if (strcmp(token, "$") == 0) {
            token = strtok(NULL, " ");
            if (strcmp(token, "cd") == 0) {
                token = strtok(NULL, " ");
                if (strcmp(token, "..") == 0) {
                    // go up one folder
                } else {
                    // regular folder
                    token = strtok(NULL, " ");  // folder name
                }
            } else if (strcmp(token, "ls") == 0) {
                // list contents of current folder
            }
        } else if (strcmp(token, "dir") == 0) {
            // identifies a folder as content of another folder
            token = strtok(NULL, " ");  // folder name
        } else {
            // identifies a file size
            long size = strtol(token, NULL, 10);
            token = strtok(NULL, " ");  // filename
        }
        free(line);
        line = NULL;
    }
    if (line) free(line);
    fclose(fp);
    return 0;
}
