#include "htmltags.h"


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

int checkforTag(char* string, int starting_point, bool ending) { 
    /*
    my magics note:
    -the first " " will end the search, e.g. <a href> where a is all i need, or classes after <p I will understand when I re-read
    -The way ill do this is probably inefficient but has to be enough for now, maybe ill implement some sort of algorithm at some point
    -ending is true/false, like defined, the second [] defines start/end
    */
    for (int i = 0;i < 3;i++) { //the number will be hardcoded for the amount of tags I implemented, currently 3
        for (int j = 0;j < strlen(tags[i][ending])-1;j++) {
            if (string[starting_point+j] == ' ' && tags[i][ending][j] == '>') {
                return i;
            } else if (string[starting_point+j] == '>' && tags[i][ending][j] == '>') {
                return i;
            } else if (string[starting_point+j] != tags[i][ending][j]) {
                break;
            }
        }

    }
    return -1;
}


