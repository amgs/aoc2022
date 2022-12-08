#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int score(char other, char mine) {
    char my_move;
    int score = mine == 'X' ? 0 : mine == 'Y' ? 3 : 6;
    switch (other) {
        case 'A': // rock
            switch(mine) {
                case 'X': // lose
                    my_move = 'Z';
                break;
                case 'Y': // draw
                    my_move = 'X';
                break;
                case 'Z': // win
                    my_move = 'Y';
                break;
            }
            break;
        case 'B': // paper
            switch(mine) {
                case 'X': // lose
                    my_move = 'X';
                break;
                case 'Y': // draw
                    my_move = 'Y';
                break;
                case 'Z': // win
                    my_move = 'Z';
                break;
            }
            break;
        case 'C': // scissors 
            switch(mine) {
                case 'X': // lose
                    my_move = 'Y';
                break;
                case 'Y': // draw
                    my_move = 'Z';
                break;
                case 'Z': // win
                    my_move = 'X';
                break;
            }
            break;
        default:
            break;
    }

    int mv = my_move - 'X' + 1;
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
