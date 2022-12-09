#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../lib/stack/stack.h"

typedef struct {
    long size;
    char name[80];
} _File, *File;

struct Folder {
    struct Folder *parent;
    File files[100];
    int num_files;
    struct Folder *folders[100];
    int num_folders;
    char name[80];
};
typedef struct Folder _Folder, *Folder;

Folder read_info(const char *filename);

long folder_size(Folder folder);

long folders_under_size(Folder folder, long max_size);

void free_folder(Folder folder);

void print_folder(Folder folder, int indent);

int main() {
    Folder root = read_info("day7/input.txt");
    // print_folder(root, 0);
    long sizes = folders_under_size(root, 100000L);
    printf("Total size: %ld\n", sizes);
    free_folder(root);
    return 0;
}

Folder read_info(const char *filename) {
    FILE *fp = fopen(filename, "r");
    assert(fp != NULL);
    char *line = NULL;
    size_t len = 0;
    Folder folder = NULL;
    while (feof(fp) == 0) {
        getline(&line, &len, fp);
        line[strlen(line) - 1] = '\0';
        char *token = strtok(line, " ");
        if (strcmp(token, "$") == 0) {
            token = strtok(NULL, " ");
            if (strcmp(token, "cd") == 0) {
                token = strtok(NULL, " ");
                if (strcmp(token, "..") == 0) {
                    // go up one folder
                    folder = folder->parent;
                } else {
                    // regular folder
                    if (folder == NULL) {
                        folder = malloc(sizeof(_Folder));
                        folder->num_files = 0;
                        folder->num_folders = 0;
                        folder->parent = NULL;
                        strcpy(folder->name, "/");
                    } else {
                        for (int i = 0; i < folder->num_folders; i++) {
                            if (strcmp(folder->folders[i]->name, token) == 0) {
                                folder = folder->folders[i];
                                break;
                            }
                        }
                    }
                }
            } else if (strcmp(token, "ls") == 0) {
                // list contents of current folder
                // nothing to do
            }
        } else if (strcmp(token, "dir") == 0) {
            // identifies a folder as content of another folder
            token = strtok(NULL, " ");  // folder name
            Folder child = malloc(sizeof(_Folder));
            child->num_files = 0;
            child->num_folders = 0;
            child->parent = folder;
            strcpy(child->name, token);
            folder->folders[folder->num_folders++] = child;
        } else {
            // identifies a file size
            long size = strtol(token, NULL, 10);
            token = strtok(NULL, " ");  // filename
            File file = malloc(sizeof(_File));
            file->size = size;
            strcpy(file->name, token);
            folder->files[folder->num_files++] = file;
        }
        free(line);
        line = NULL;
    }
    if (line) free(line);
    fclose(fp);
    // Return the root
    while (folder->parent != NULL) {
        folder = folder->parent;
    }
    return folder;
}

long folders_under_size(Folder folder, long max_size) {
    long sum = 0;
    Stack to_visit = stack_new();
    Stack visited = stack_new();

    stack_push(to_visit, folder);

    while (!stack_is_empty(to_visit)) {
        Folder f = stack_pop(to_visit);
        stack_push(visited, f);
        long size = folder_size(f);
        if (size <= max_size) {
            sum += size;
        }
        for (int i = 0; i < f->num_folders; i++) {
            if (!stack_contains(visited, f->folders[i])) {
                stack_push(to_visit, f->folders[i]);
            }
        }
    }
    stack_free(to_visit);
    stack_free(visited);
    return sum;
}

long folder_size(Folder folder) {
    long size = 0;
    for (int i = 0; i < folder->num_files; i++) {
        size += folder->files[i]->size;
    }
    for (int i = 0; i < folder->num_folders; i++) {
        size += folder_size(folder->folders[i]);
    }
    return size;
}

void free_folder(Folder folder) {
    for (int i = 0; i < folder->num_files; i++) {
        free(folder->files[i]);
    }
    for (int i = 0; i < folder->num_folders; i++) {
        free_folder(folder->folders[i]);
    }
    free(folder);
}

void print_folder(Folder folder, int indent) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("%s\n", folder->name);
    for (int i = 0; i < folder->num_files; i++) {
        for (int j = 0; j < indent + 2; j++) {
            printf(" ");
        }
        printf("%s (%ld)\n", folder->files[i]->name, folder->files[i]->size);
    }
    for (int i = 0; i < folder->num_folders; i++) {
        print_folder(folder->folders[i], indent + 2);
    }
}