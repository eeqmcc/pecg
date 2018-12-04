#include <stdio.h>
#include <stdlib.h>
#include "DDA.h"
#include "svpng.inc"

int main(int argc, char **argv)
{

    unsigned char rgba[256 * 256 * 4], *p = rgba;

    dda(rgba, 256, 256, 0, 200, 200, 123);
    dda(rgba, 256, 256, 200, 123, 200, 190);
    dda(rgba, 256, 256, 200, 190, 0, 200);

    FILE *fp = fopen("rgba.png", "wb");
    svpng(fp, 256, 256, rgba, 1);
    fclose(fp);

    return 0;
}
