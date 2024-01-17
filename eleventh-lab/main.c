#include "functions.c"


int main() {
    int coords[6];
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &coords[i]);
    }
    triangle A = {{coords[0], coords[1]},
                  {coords[2], coords[3]},
                  {coords[4], coords[5]}};
    printf("Your area: %f\n", get_area(A));
    printf("Your len: %f", get_len(A));
    return 0;
}