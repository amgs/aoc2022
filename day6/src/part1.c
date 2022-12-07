#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

bool is_in(char *str, char c) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}

void shift(char *arr, int size, char c) {
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = c;
}

void print_marker(char *marker, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", marker[i]);
    }
    printf("\n");
}

bool is_valid(char *marker, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (marker[i] == ' ' || marker[j] == ' ' || (i != j && marker[i] == marker[j])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    FILE *f = fopen("input.txt", "r");
    assert(f != NULL);
    int marker_size = 4;

    char marker[] = {' ', ' ', ' ', ' '};
    int counter = 0;
    while (!feof(f)) {
        char c;
        fscanf(f, "%c", &c);
        counter++;
        shift(marker, marker_size, c);
        if (is_valid(marker, marker_size)) {
            print_marker(marker, marker_size);
            break;
        }
    }
    printf("%d\n", counter);
    fclose(f);
    return 0;
}