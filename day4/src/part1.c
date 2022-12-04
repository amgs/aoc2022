#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main() {
    int as, ae, bs, be;
    FILE *f = fopen("input.txt", "r");
    int count = 0;
    while(feof(f) == 0) {
        fscanf(f, "%d-%d,%d-%d\n", &as, &ae, &bs, &be);
        if(as >= bs && ae <= be || bs >= as && be <= ae) {
            count++;
        }
    }
    printf("%d\n", count);
    fclose(f);
    return 0;
}