#include "stdio.h"
#include <math.h>


int main() {
    int a;
    scanf("Enter your angle: %d", &a);
    double z1;
    double z2;
    z1 = cos(a) + cos(2 * a) + cos(6 * a) + cos(7 * a);
    z2 = 4 * cos(a / 2) * cos(5 / 2 * a) * cos(4 * a);
    printf("first function given: %f\nsecond function given: %f", z1,z2);
    return 0;
}