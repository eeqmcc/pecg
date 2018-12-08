#include <stdlib.h>
#include <math.h>

int bresenhamOctant1(unsigned char *image, int width, int height, int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    float m = 1.0f * dy / dx;
    float e = m - 0.5f;

    int x = x1;
    int y = y1;
    for (int i = 0; i < dx; i++) {
        image[y * width * 4 + 4 * x] = 255;
        image[y * width * 4 + 4 * x + 1] = 0;
        image[y * width * 4 + 4 * x + 2] = 0;
        image[y * width * 4 + 4 * x + 3] = 255;
        while (e >= 0) {
            y++;
            e -= 1;
        }
        x++;
        e += m;
    }

    return 0;
}

int bresenhamOctant1i(unsigned char *image, int width, int height, int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int e = 2 * dy - dx;

    int x = x1;
    int y = y1;
    for (int i = 0; i < dx; i++) {
        image[y * width * 4 + 4 * x] = 255;
        image[y * width * 4 + 4 * x + 1] = 0;
        image[y * width * 4 + 4 * x + 2] = 0;
        image[y * width * 4 + 4 * x + 3] = 255;
        while (e >= 0) {
            y++;
            e -= 2 * dx;
        }
        x++;
        e += 2 * dy;
    }

    return 0;
}

int bresenhamLine(unsigned char *image, int width, int height, int x1, int y1, int x2, int y2)
{
    int x = x1;
    int y = y1;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int s1 = dx == 0 ? 0 : (dx > 0 ? 1 : -1);
    int s2 = dy == 0 ? 0 : (dy > 0 ? 1 : -1);
    int interChange, e;

    if (dy > dx) {
        int tmp = dx;
        dx = dy;
        dy = tmp;
        interChange = 1;
    } else
        interChange = 0;

    e = 2 * dy - dx;
    for (int i = 0; i < dx; i++) {
        image[y * width * 4 + 4 * x] = 255;
        image[y * width * 4 + 4 * x + 1] = 0;
        image[y * width * 4 + 4 * x + 2] = 0;
        image[y * width * 4 + 4 * x + 3] = 255;
        while (e >= 0) {
            if (interChange) {
                x += s1;
            } else {
                y += s1;
            }
            e -= 2 * dx;
        }
        if (interChange) {
            y += s2;
        } else {
            x += s1;
        }
        e += 2 * dy;
    }

    return 0;
}