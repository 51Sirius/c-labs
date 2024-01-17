#ifndef H_STRUCT
#define H_STRUCT

#include "math.h"
#include "stdio.h"


struct Coord{
    int x;
    int y;
};


typedef struct Triangle {
    struct Coord A;
    struct Coord B;
    struct Coord C;
} triangle;

#endif
