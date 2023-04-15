#include "tags.h"


int initTags() {
    tags = malloc(1024*16);
    sprintf(tags[0][0], "<head>");
    sprintf(tags[0][1], "</head>");
    sprintf(tags[1][0], "<body>");
    sprintf(tags[1][1], "</body>");
    sprintf(tags[2][0], "<div>");
    sprintf(tags[2][2], "</div");
}

int exitTags() {
    free(tags);
}

int checkTagBeginning(char* string, int starting_point) {
    for (int i = 0;i < 3;)
}
