#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int get_priority(const char *line) {
    int line_len = strlen(line);
    for (int i = 0; i < line_len / 2; i++) {
        char c = line[i];
        for (int j = line_len / 2; j < line_len; j++) {
            if (c == line[j]) {
                return (c >= 'a' ? c - 'a' + 1 : c - 'A' + 27);
            }
        }
    }
    return 0;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    int priorities = 0;
    FILE *fp = fopen("day3/input.txt", "r");
    while (feof(fp) == 0) {
        getline(&line, &len, fp);
        line[strlen(line) - 1] = '\0';
        priorities += get_priority(line);
        free(line);
        line = NULL;
    }
    if (line) {
        free(line);
    }
    printf("%d\n", priorities);
    fclose(fp);
    return 0;
}