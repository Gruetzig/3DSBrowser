#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char ***tags;

typedef enum {
    TAG_BODY,
    TAG_HEAD,
    TAG_DIV,
    TAG_CUSTOM,
};