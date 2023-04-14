#include <3ds.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdbool.h>
#include <malloc.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int initSocket();
int exitSocket();
int http_get(char* page, char* path, char* output, size_t *outputsize);