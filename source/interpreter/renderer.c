#include "renderer.h"

bool gethtml(char *htmlin, char *htmlout) {
    char *beg = strstr(htmlin, tags[TAG_HTML][0]) + strlen(tags[TAG_HTML][0]);
    if (beg == NULL) {
        return false;
    }
    char *end = strstr(beg, tags[TAG_HTML][1]);
    if (end == NULL) {
        return false;
    }
    strncpy(htmlout, beg, (end-beg));
    return true;
}


bool gethead(char *html, char *head) {
    char *beg = strstr(html, tags[TAG_HEAD][0]) + strlen(tags[TAG_HEAD][0]);
    if (beg == NULL) {
        return false;
    }
    char *end = strstr(beg, tags[TAG_HEAD][1]) - 1;
    if (end == NULL) {
        return false;
    }
    strncpy(head, beg, (end-beg));
    return true;
}

bool getbody(char* html, char* body) {
    char *beg = strstr(html, tags[TAG_BODY][0]) + strlen(tags[TAG_BODY][0]);
    if (beg == NULL) {
        return false;
    }
    char *end = strstr(beg, tags[TAG_BODY][1]) - 1;
    if (end == NULL) {
        return false;
    }
    strncpy(body, beg, (end-beg));
    return true;
}

int prepwork(char* body_in) {
    char _body[strlen(body_in)+1];
    strcpy(_body, body_in);
    char *html = malloc(strlen(_body)+1);
    if (!(gethtml(_body, html))) {
        return -1;
    }
    char *head = malloc(strlen(html)+1); 
    if (!(gethead(html, head))) {
        return -1;
    }
    char *body = malloc(strlen(html)+1);
    if (!(getbody(html, body))) {
        return -1;
    }
    html = realloc(html, strlen(html)+1);
    head = realloc(head, strlen(head)+1);
    body = realloc(body, strlen(body)+1);
    
    
}