#include "math.h"
#include "struct.h"

double get_distance(struct Coord A, struct Coord B) {
    return sqrt((A.x - B.x)*(A.x - B.x)  + (A.y - B.y) * (A.y - B.y));
}

double get_area(triangle A) {
    double cof = (A.B.x - A.A.x) * (A.C.y - A.A.y) - (A.C.x - A.A.x) * (A.B.y - A.A.y);
    if (cof > 0) {
        return 0.5 * cof;
    } else {
        return -0.5 * cof;
    }
}

double get_len(triangle A) {
    return get_distance(A.A, A.B) + get_distance(A.A, A.C) + get_distance(A.B, A.C);
}