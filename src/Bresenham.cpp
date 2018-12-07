
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