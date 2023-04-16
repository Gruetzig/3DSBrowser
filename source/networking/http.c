#include "http.h"

char* request;

int initSocket() {
    Result ret=0;
    u32 *soc_sharedmem, soc_sharedmem_size = 0x100000;

    soc_sharedmem = memalign(0x1000, soc_sharedmem_size);
    if(soc_sharedmem==NULL) {
        printf("Failed to allocate SOC sharedmem.\n");
        return -1;
    }
    else {
    ret = socInit(soc_sharedmem, soc_sharedmem_size);
    }
    if(R_FAILED(ret)) {
        printf("socInit failed: 0x%08x.\n", (unsigned int)ret);
        return -1;
    }
    return 0;
}
int exitSocket() {
    if (R_FAILED(socExit())) return -1;
    return 0;
}

void getrequest(char* page, char* path) {
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, page);
}

int http_get(char* page, char* path, char* output, size_t *outputsize) {
    struct addrinfo hints, *res; //taken from beej's guide to network programming
    int sockfd;
    int ret = 0;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; //dont care about ipv4 and ipv6
    hints.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(page, "80", &hints, &res);
    if (ret != 0) {
        freeaddrinfo(res);
        return -1;
    }
    waitf("getaddrinfo success\n");
    //create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        freeaddrinfo(res);
        return -1;
    }
    waitf("socket success\n");
    //connect to site
    ret = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (ret != 0) {
        freeaddrinfo(res);
        closesocket(sockfd);
        return -1;
    }
    waitf("connect success\n");
    freeaddrinfo(res);
    
    //send the request
    int bytes_sent;
    request = malloc(1024);
    getrequest(page, path);
    waitf("getrequestgenerator success\n");
    bytes_sent = send(sockfd, request, strlen(request)+1, 0);
    if (bytes_sent < 0) {
        closesocket(sockfd);
        return -1;
    }
    free(request);
    waitf("send success\n");
    char *response;
    response = malloc(1024*16);
    int bytes_received;
    bytes_received = recv(sockfd, response, 1024*16, 0);
    if (bytes_received < 0) {
        closesocket(sockfd);
        return -1;
    }
    waitf("recv success\n");
    *outputsize = strlen(response);
    memcpy(output, response, 1024*16);
    free(response);
    close(sockfd);
    waitf("close success\n");
    return 0;
    


    



    

}
