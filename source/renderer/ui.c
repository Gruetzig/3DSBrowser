#include "ui.h"

void uiInit(DrawContext *uictx) {
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
    uictx->top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    uictx->bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
    uictx->defaultBackgroundColor = C2D_Color32(0x2B, 0x2A, 0x33, 0xFF);
}

void uiExit() {
    C2D_Fini();
    C3D_Fini();
}

void drawText(float x, float y, float z, float scale, u32 color, const char* value, u32 flags) //ty mechanicaldragon0687
{
    C2D_TextBuf buf=C2D_TextBufNew(4096);
    C2D_Text text;
    C2D_TextParse(&text, buf, value);
    C2D_TextOptimize(&text);
    C2D_DrawText(&text, C2D_WithColor | flags, x, y, z, scale, scale, color);
    C2D_TextBufDelete(buf);
}