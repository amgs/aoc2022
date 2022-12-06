#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

void reverse(char* s, int size) {
    for (int i = 0; i < size / 2; i++) {
        char tmp = s[i];
        s[i] = s[size - i - 1];
        s[size - i - 1] = tmp;
    }
}

int read_stacks(FILE *f, char ***stacks, int **tops) {
    char *line = NULL;
    size_t len = 0;
    int num_stacks = -1;

    while (true) {
        getline(&line, &len, f);
        line[strlen(line) - 1] = '\0';
        if (strlen(line) == 0) break;
        if (num_stacks == -1) {
            num_stacks = (strlen(line) + 1) / 4;
            printf("Num. Stacks: %d\n", num_stacks);
            *stacks = (char **)malloc(sizeof(char *) * num_stacks);
            *tops = (int *)malloc(sizeof(int) * num_stacks);
            for (int i = 0; i < num_stacks; i++) {
                (*stacks)[i] = (char *)malloc(sizeof(char) * 100);
                (*tops)[i] = -1;
            }
        }
        if (is_digit(line[1])) {
            break;
        }
        for (int i = 0; i < num_stacks; i++) {
            if (line[1 + (i * 4)] != ' ') {
                (*stacks)[i][++(*tops)[i]] = line[1 + (i * 4)];
            }
        }
        free(line);
        line = NULL;
    }
    for(int i = 0; i < num_stacks; i++) {
        reverse((*stacks)[i], (*tops)[i] + 1);
    }
    if (line) free(line);
    return num_stacks;
}

void print_stacks(char **stacks, int *tops, int num_stacks) {
    for (int i = 0; i < num_stacks; i++) {
        printf("%d: (%d)", i, tops[i]);
        for (int j = 0; j <= tops[i]; j++) {
            printf("%c", stacks[i][j]);
        }
        printf("\n");
    }
}

void print_tops(char **stacks, int *tops, int num_stacks) {
    for (int i = 0; i < num_stacks; i++) {
        printf("%c", stacks[i][tops[i]]);
    }
    printf("\n");
}

void execute(char **stacks, int *tops, int amount, int from, int to) {
    for(int i = 0; i < amount; i++) {
        stacks[to-1][++tops[to-1]] = stacks[from-1][tops[from-1]- amount + 1 + i] ;
    }
    tops[from-1] -= amount;
}

int main() {
    FILE *f = fopen("/home/amgs/dev/aoc2022/day5/input.txt", "r");

    char **stacks = NULL;
    int *tops = NULL;
    int num_stacks = -1;

    num_stacks = read_stacks(f, &stacks, &tops);
    print_stacks(stacks, tops, num_stacks);

    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, f);  // empty line
    free(line);
    line = NULL;
    while (feof(f) == 0) {
        getline(&line, &len, f);
        if (len == 0 || strlen(line) == 0) break;

        char *amount = strtok(line, "move ");
        char *from = strtok(NULL, " from ");
        char *to = strtok(NULL, " to ");

        int amount_i = strtol(amount, NULL, 10);
        int from_i = strtol(from, NULL, 10);
        int to_i = strtol(to, NULL, 10);

        printf("amount: %d, from: %d, to: %d\n", amount_i, from_i, to_i);
        execute(stacks, tops, amount_i, from_i, to_i);

        free(line);
        line = NULL;
        len = 0;
    }
    if (line) free(line);

    print_stacks(stacks, tops, num_stacks);

    print_tops(stacks, tops, num_stacks);

    fclose(f);
    for (int i = 0; i < num_stacks; i++) {
        free(stacks[i]);
    }
    free(stacks);
    free(tops);
    return 0;
}