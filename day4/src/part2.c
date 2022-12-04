#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int as, ae, bs, be;
    FILE *f = fopen("input.txt", "r");
    int count = 0;
    while (feof(f) == 0) {
        fscanf(f, "%d-%d,%d-%d\n", &as, &ae, &bs, &be);
        int e = ae < be ? ae : be;
        int s = as > bs ? as : bs;
        if (e - s >= 0) {
            count++;
        }
    }
    printf("%d\n", count);
    fclose(f);
    return 0;
}