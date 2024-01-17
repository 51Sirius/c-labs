#include "stdio.h"
#include "stdlib.h"


int main() {
    float array[] = {-3.4, 4.5, -5.6, 6.7};
    float *ptr = array;
    printf("====================================================\n");
    for (int i = 0; i < 4; ++i) {
        printf("|| %f ", *ptr);
        ptr++;
    }
    printf("||\n====================================================\n");
    float *array2 = (float *) malloc(4 * sizeof(float));
    for (int i = 0; i < 4; ++i) {
        array2[i] = array[i];
    }
    for (int i = 0; i < 4; ++i) {
        printf("|| %f ", array2[i]);
    }
    printf("||\n====================================================");
    free(array2);
    return 0;
}