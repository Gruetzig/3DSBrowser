#include "ui.h"
#include <3ds.h>
#include "http.h"
int main(int argc, char* argv[])
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
    initSocket();
    int ret = 0;
    char* site = "www.gruetzig.dev";
    char* path = "/";
    char* response;
    response = malloc(8192);
    unsigned int len = 0;
    ret = http_get(site, path, response, &len);
    if (ret != -1) { 
        printf("response: %s\n", response);
    }else{
        printf("fail lol %d\n", ret);
    }
    printf("nice");
    free(response);
    while (aptMainLoop())
    {
        gspWaitForVBlank();
        hidScanInput();

        u32 kDown = hidKeysDown();
        if (kDown & KEY_START)
            break;
    }
    exitSocket();
    gfxExit();
}
