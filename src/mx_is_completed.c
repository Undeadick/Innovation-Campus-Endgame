#include "../inc/header.h"

static FILE *openLevelFile() {
    FILE *file = fopen("resource/data/levels_status.csv", "r");
    if (!file) perror("Failed to read file");
    return file;
}

static int parseLevelStatus(FILE *file) {
    char line[128];
    int highestOpened = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\r\n")] = '\0';
        int lvl;
        char status[16];
        if (sscanf(line, "%d,%15s", &lvl, status) == 2 &&
            strcmp(status, "opened") == 0 && lvl > highestOpened) {
            highestOpened = lvl;
        }
    }
    return highestOpened;
}

bool mx_isLevelCompleted(int level) {
    FILE *file = openLevelFile();
    if (!file) return false;
    int highestOpened = parseLevelStatus(file);
    fclose(file);
    return highestOpened > level;
}
