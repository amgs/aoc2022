#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEAM_SIZE 3

int get_badge_priority(char **team) {
    for (int i = 0; i < (int)strlen(team[0]); i++) {
        char c = team[0][i];
        int match_counter = 1;
        for (int j = 1; j < TEAM_SIZE; j++) {
            for (int k = 0; k < (int)strlen(team[j]); k++) {
                if (c == team[j][k]) {
                    match_counter++;
                    break;
                }
            }
        }
        if (match_counter == TEAM_SIZE) {
            return (c >= 'a' ? c - 'a' + 1 : c - 'A' + 27);
        }
    }
    return 0;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    int priorities = 0;
    FILE *fp = fopen("day3/input.txt", "r");

    char *team[TEAM_SIZE];
    while (feof(fp) == 0) {
        for (int i = 0; i < TEAM_SIZE; i++) {
            getline(&line, &len, fp);
            line[strlen(line) - 1] = '\0';
            team[i] = line;
            line = NULL;
        }

        priorities += get_badge_priority(team);

        for (int i = 0; i < TEAM_SIZE; i++) {
            free(team[i]);
        }
    }
    if (line) {
        free(line);
    }
    printf("%d\n", priorities);
    fclose(fp);
    return 0;
}