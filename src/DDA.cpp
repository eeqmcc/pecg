#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "defines.h"
#include "DDA.h"

int dda(unsigned char *image, int width, int height, int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int lx = abs(dx);
    int ly = abs(dy);
    int length = lx >= ly ? lx : ly;
    float deltaX = 1.0f * dx / length;
    float deltaY = 1.0f * dy / length;
    float x = x1 + 0.5f;
    float y = y1 + 0.5f;

    for (int i = 0; i < length; i++) {
        int ix = static_cast<int>(floorf(x));
        int iy = static_cast<int>(floorf(y));

        image[iy * width * 4 + 4 * ix] = 255;
        image[iy * width * 4 + 4 * ix + 1] = 0;
        image[iy * width * 4 + 4 * ix + 2] = 0;
        image[iy * width * 4 + 4 * ix + 3] = 255;

        x += deltaX;
        y += deltaY;
    }

    return 0;
}
