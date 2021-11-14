#ifndef COMMON_H
#define COMMON_H

#include <GL/glut.h>

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

static const Coordinate WINDOWPOSITION = {100, 100};
static const Scale WINDOWSIZE = {800, 400};

#endif

