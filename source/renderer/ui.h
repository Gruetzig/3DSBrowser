#include <citro2d.h>
#include <3ds.h>

#define SCREEN_WIDTH_TOP 400
#define SCREEN_WIDTH_BOTTOM 320
#define SCREEN_HEIGHT 240

typedef struct {
    C3D_RenderTarget* top;
    C3D_RenderTarget* bottom;
    u32 defaultBackgroundColor;
} DrawContext;

void uiInit(DrawContext *uictx);
void uiExit();
void drawText(float x, float y, float z, float scale, u32 color, const char* value, u32 flags);
