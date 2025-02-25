#include "../inc/header.h"

static void readLevelsFromFile(LevelStatus levels[MAX_LEVELS], int *count) {
    const char *filename = "resource/data/levels_status.csv";
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open for read");
        return;
    }
    char line[128];
    while (fgets(line, sizeof(line), file) && *count < MAX_LEVELS) {
        line[strcspn(line, "\r\n")] = '\0';
        if (sscanf(line, "%d,%15s", &levels[*count].level, levels[*count].status) == 2) {
            (*count)++;
        }
    }
    fclose(file);
}

static void writeLevelsToFile(LevelStatus levels[MAX_LEVELS], int count) {
    const char *filename = "resource/data/levels_status.csv";
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open for write");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s\n", levels[i].level, levels[i].status);
    }
    fclose(file);
}

void mx_updateNextLevelStatus(int finishedLevel) {
    LevelStatus levels[MAX_LEVELS];
    int count = 0;
    
    readLevelsFromFile(levels, &count);

    int targetLevel = finishedLevel + 1;
    for (int i = 0; i < count; i++) {
        if (levels[i].level == targetLevel) {
            strcpy(levels[i].status, "opened");
            break;
        }
    }

    writeLevelsToFile(levels, count);
}
