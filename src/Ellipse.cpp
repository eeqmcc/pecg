#include <math.h>
#include "Ellipse.h"

int ellipse1(unsigned char *image, int width, int height, int cx, int cy, int a, int b)
{
    int x = static_cast<int>(floorf(a + 0.5f));
    int y = 0;
    float d = 0;
    int ix, iy;

    while (b * b * (x - 0.5f) > a * a * (y + 1)) {
        //set pixel(x, y)
        ix = x + cx;
        iy = y + cy;
        image[iy * width * 4 + 4 * ix] = 255;
        image[iy * width * 4 + 4 * ix + 1] = 0;
        image[iy * width * 4 + 4 * ix + 2] = 0;

        iy = -y + cy;
        image[iy * width * 4 + 4 * ix] = 255;
        image[iy * width * 4 + 4 * ix + 1] = 0;
        image[iy * width * 4 + 4 * ix + 2] = 0;
        image[iy * width * 4 + 4 * ix + 3] = 255;
        image[iy * width * 4 + 4 * ix + 3] = 255;

        ix = -x + cx;
        image[iy * width * 4 + 4 * ix] = 255;
        image[iy * width * 4 + 4 * ix + 1] = 0;
        image[iy * width * 4 + 4 * ix + 2] = 0;
        image[iy * width * 4 + 4 * ix + 3] = 255;

        iy = y + cy;
        image[iy * width * 4 + 4 * ix] = 255;
        image[iy * width * 4 + 4 * ix + 1] = 0;
        image[iy * width * 4 + 4 * ix + 2] = 0;
        image[iy * width * 4 + 4 * ix + 3] = 255;
        d = b * b * (2 * x * x - 2 * x + 0.5f) + a * a * (2 * y * y + 4 * y + 2) - 2 * a * a * b * b;
        if (d < 0) {
            y++;
        }
        else {
            x--;
            y++;
        }
    }

    d = b * b * (2 * x * x - 4 * x + 2) + a * a * (2 * y * y + 2 * y + 0.5f) - 2 * a * a * b * b;
    while (x >= 0) {
        // set pixel
        ix = x + cx;
        iy = y + cy;
        image[iy * width * 4 + 4 * ix] = 255;
        image[iy * width * 4 + 4 * ix + 1] = 0;
        image[iy * width * 4 + 4 * ix + 2] = 0;
        image[iy * width * 4 + 4 * ix + 3] = 255;

        iy = -y + cy;
        image[iy * width * 4 + 4 * ix] = 255;
        image[iy * width * 4 + 4 * ix + 1] = 0;
        image[iy * width * 4 + 4 * ix + 2] = 0;
        image[iy * width * 4 + 4 * ix + 3] = 255;
        image[iy * width * 4 + 4 * ix + 3] = 255;

        ix = -x + cx;
        image[iy * width * 4 + 4 * ix] = 255;
        image[iy * width * 4 + 4 * ix + 1] = 0;
        image[iy * width * 4 + 4 * ix + 2] = 0;
        image[iy * width * 4 + 4 * ix + 3] = 255;

        iy = y + cy;
        image[iy * width * 4 + 4 * ix] = 255;
        image[iy * width * 4 + 4 * ix + 1] = 0;
        image[iy * width * 4 + 4 * ix + 2] = 0;
        image[iy * width * 4 + 4 * ix + 3] = 255;
        if (d < 0) {
            x--;
            y++;
        }
        else {
            x--;
        }
        d = b * b * (2 * x * x - 4 * x + 2) + a * a * (2 * y * y + 2 * y + 0.5f) - 2 * a * a * b * b;
    }

    return 0;
}