#include "renderer/ui.h"
#include <3ds.h>
#include "networking/http.h"
int main(int argc, char* argv[])
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
    initSocket();
    int ret = 0;
    char* site = "www.example.com";
    char* path = "/";
    char* response;
    response = malloc(1024*16);
    unsigned int len = 0;
    ret = http_get(site, path, response, &len);
    if (ret != -1) { 
        /*FILE *fp = fopen("sdmc:/text.txt", "wb");
        fwrite(response, strlen(response), 1024*4, fp);
        fclose(fp);*/
        printf(response);
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
