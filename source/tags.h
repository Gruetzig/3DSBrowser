#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char ***tags;

typedef enum {
    TAG_BODY,
    TAG_HEAD,
    TAG_DIV,
    TAG_CUSTOM,
};