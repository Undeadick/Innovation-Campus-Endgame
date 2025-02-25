#include "../inc/header.h"

bool mx_isLevelUnlocked(int level) {
    const char *filename = "resource/data/levels_status.csv";
    FILE *file = fopen(filename, "r");
    if (!file) return SDL_Log("Failed open CSV (%s) for read", filename), false;
    char line[128];
    bool unlocked = false;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\r\n")] = '\0';
        int lvl;
        char status[16];
        if (sscanf(line, "%d,%15s", &lvl, status) == 2) {
            if (lvl == level) {
                if (strcmp(status, "opened") == 0) {
                    unlocked = true;
                }
                break;
            }
        }
    }
    fclose(file);
    return unlocked;
}
