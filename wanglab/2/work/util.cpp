#include <GL/glut.h>
#include <iostream>

static const int WINDOWWIDTH = 1280, WINDOWHEIGHT = 720;

typedef struct
{
    int x;
    int y;
} Coordinate;

typedef struct
{
    int x;
    int y;
} Scale;

class Transform
{
private:
    Coordinate position_offset;
    Coordinate position;
    Scale scale_offset;
    Scale scale;

*** 書き途中 ***
}



