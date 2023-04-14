#include "ui.h"
#include <3ds.h>
#include "http.h"
int main(int argc, char* argv[])
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
    initSocket();
    int ret = 0;
    char* site = "www.google.com";
    char* path = "/";
    char* response = "nope";
    unsigned int len = 0;
    ret = http_get(site, path, response, &len);
    if (ret != -1) { 
        printf("response: %s", response);
    }else{
        printf("fail lol %d", ret);
    }
    printf("nice");
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
