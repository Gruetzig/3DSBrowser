#include "ui.h"
#include <3ds.h>
int main(int argc, char* argv[])
{
    gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    u32 color_white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
    C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    while (aptMainLoop()) {
        hidScanInput();
		u32 kDown = hidKeysDown();
        if (kDown & KEY_START) break;
        		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        C2D_TargetClear(top, C2D_Color32(0x00, 0x00, 0x00, 0xFF));
        C2D_SceneBegin(top);
        drawText(10, 10, 0, 1.0f, color_white, "Hello World", C2D_AlignLeft);
        C3D_FrameEnd(0);
    }
    C2D_Fini();
	C3D_Fini();
	gfxExit();
}