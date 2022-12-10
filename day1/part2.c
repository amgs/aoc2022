#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

void update(int *arr, int value) {
    for (int i = 0; i < 3; i++) {
        if(arr[i] < value) {
            arr[i+1] = arr[i];
            arr[i] = value;
            break;
        }
    }
    qsort(arr, 4, sizeof(int), cmpfunc);
    arr[3] = 0;
}

int main() {
    FILE *file = fopen("day1/input.txt", "r");
    char *line = NULL;
    size_t len = 0;
    int max_calories[] = {0, 0, 0, 0};
    int sum = 0;
    while (!feof(file)) {
        getline(&line, &len, file);
        line[strlen(line) - 1] = '\0';
        if (strlen(line) == 0) {
            update(max_calories, sum);
            sum = 0;
            continue;
        }
        long calories = strtol(line, NULL, 10);
        sum += calories;

        free(line);
        len = 0;
        line = NULL;
    }
    update(max_calories, sum);
    sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += max_calories[i];
    }
    printf("%d\n", sum);
    if (line != NULL) free(line);
    fclose(file);
    return 0;
}
