#include "processer.h"

typedef struct response_raw {
    char* headers;
    char* body;
} response_raw;

typedef struct response_actually {
    char* protocol;
    char* status_code;
    char* content_type;
    char* charset;
    char* connection;
    char* content_encoding;
    char* body_encrypted;
    size_t content_length_encrypted;
    char* body_decrypted;
    size_t content_length_decrypted;
} response_actually;

int splitResponse(char* response_in, response_raw *response_out) {
    char* response = malloc(sizeof(response_in));
    if (response == NULL) {
        return -1;
    }
    strcpy(response, response_in);
    char delim[3] = "\n\n";
    char *_header = strtok(response_in, delim);
    char *_body = strtok(NULL, delim);
    strcpy(response_out->headers, _header);
    strcpy(response_out->body, _body);
    free(response);
    return 0;
}

int fillHeaderStruct(response_raw *response_in, response_actually *response_out) {
    char header[strlen(response_in->headers)];
    strcpy(header, response_in->headers); 
    char *token = strtok(header, "\n");
    if (stringsplit(token, " ", response_out->protocol, response_out->status_code) < 0) { //split string
        return -1; //not a valid header(should have a space between HTTP/1.1 and 200 OK or whatever the response is, and multiple response headers!)
    }
    if (token == NULL) {
        return -1; //not a valid header
    }
    token = strtok(NULL, "\n");
    while (token != NULL) {
        char out1[strlen(token)];
        char out2[strlen(token)];
        //check for every supported header
        if (stringsplit(token, " ",out1, out2) < 0) {
            return -1; //not a valid header
        }
        if (strcmp(out1, "Content-Encoding:") == 0) {
            strcpy(response_out->content_encoding, out2);
        } else if (strcmp(out1, "Content-Length:") == 0) {
            strcpy(response_out->content_length_encrypted, out2);
        } else if (strcmp(out1, "Content-Type:") == 0) {
            char _out1[strlen(out2)];
            char _out2[strlen(out2)];
            if (stringsplit(out2, "; ", _out1, _out2) < 0) {
                return -1; //invalid content-type header syntax
            } else {
                strcpy(response_out->content_type, _out1);
                strcpy(response_out->charset, _out2);
            }
        } else if (strcmp(out1, "Connection:") == 0) {
            strcpy(response_out->connection, out2);
        }
        token = strtok(NULL, "\n");
    }
    
    strcpy(response_out->body_encrypted, response_in->body); //copy body over
    return 0;
}

int decryptBody(response_actually* responseStruct) {

    return 0;
}
