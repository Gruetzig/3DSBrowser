#include "utils.h"

void waitf(const char* string) {
    printf(string);
    while (1) {
        hidScanInput();
        u32 kdown = hidKeysDown();
        if (kdown & KEY_A) {
            break;
        }
    }
}

int stringsplit(char* original, const char* delimiter, char* split1, char* split2) { //sometimes you dont have to understand the code you use~
    char first_part[strlen(original)];
    char second_part[strlen(original)];
    char* delimiter_position = strchr(original, delimiter);
    if (delimiter_position != NULL) {
        size_t delimiter_index = delimiter_position - original;
        strncpy(first_part, original, delimiter_index);
        first_part[delimiter_index] = '\0';
        strncpy(second_part, original + delimiter_index + 1, sizeof(second_part));
        second_part[sizeof(second_part) - 1] = '\0';
        strcpy(split1, first_part);
        strcpy(split2, second_part);
        return 0;
    } else {
        return -1;
    }
}