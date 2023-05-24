#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char ***tags;

typedef enum {
    TAG_BODY,
    TAG_HEAD,
    TAG_DIV,
    TAG_STYLE,
    TAG_HTML,
} HTMLTAGS;

int initTags();
int exitTags();
int checkforTag(char* string, int starting_point, bool ending);