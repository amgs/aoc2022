#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    FILE *file = fopen("day1/input.txt", "r");
    char* line = NULL;
    size_t len = 0;
    int max_calories = 0;
    int sum = 0;
    while(!feof(file)) {
        getline(&line, &len, file);
        line[strlen(line) - 1] = '\0';
        if(strlen(line) == 0) {
            if (sum > max_calories) {
                max_calories = sum;
            }
            sum = 0;
            continue;
        }
        long calories = strtol(line, NULL, 10);
        sum += calories;

        free(line);
        len = 0;
        line = NULL;
    }
    printf("%d\n", max_calories);
    if(line != NULL) free(line);
    fclose(file);
    return 0;
}
