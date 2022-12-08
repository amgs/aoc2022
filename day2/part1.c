#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int score(char other, char mine) {
    int ov = other - 'A' + 1;
    int mv = mine - 'X' + 1;
    int score;
    switch (other) {
        case 'A': // rock
            switch(mine) {
                case 'X': // rock
                    score = 3;
                break;
                case 'Y': // paper
                    score = 6;
                break;
                case 'Z': // scissors
                    score = 0;
                break;
            }
            break;
        case 'B': // paper
            switch(mine) {
                case 'X': // rock
                    score = 0;
                break;
                case 'Y': // paper
                    score = 3;
                break;
                case 'Z': // scissors
                    score = 6;
                break;
            }
            break;
        case 'C': // scissors 
            switch(mine) {
                case 'X': // rock
                    score = 6;
                break;
                case 'Y': // paper
                    score = 0;
                break;
                case 'Z': // scissors
                    score = 3;
                break;
            }
            break;
        default:
            break;
    }

    return score + mv;
}

int main() {
    char other, mine;
    FILE* fp = fopen("day2/input.txt", "r");
    int points = 0;
    while (feof(fp) == 0) {
        fscanf(fp, "%c %c\n", &other, &mine);
        points += score(other, mine);
    }
    printf("%d\n", points);
    fclose(fp);
    return 0;
}
