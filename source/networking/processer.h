#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../utils/utils.h"

typedef struct response_raw response_raw;
typedef struct response_actually response_actually;

int splitResponse(char* response_in, response_raw *response_out);
size_t getResponseActuallyMaxSize(response_raw *response_in);
int fillHeaderStruct(response_raw *response_in, response_actually *response_out);
int decryptBody(response_actually* responseStruct);