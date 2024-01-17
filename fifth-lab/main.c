#include "stdio.h"

int main() {
    int ls[6] = {34, 45, 56, 67, 78, 89};
    printf("---------------------------\n");
    for (int i = 0; i < 6; ++i) {
        printf("%d||", ls[i]);
    }
    printf("\n---------------------------");
    int matrix1[2][2];
    int matrix2[2][2];
    matrix1[0][0] = 1;
    matrix1[0][1] = 1;
    matrix1[1][0] = 0;
    matrix1[1][1] = 1;
    matrix2[0][0] = 2;
    matrix2[0][1] = 0;
    matrix2[1][0] = 3;
    matrix2[1][1] = 0;
    int matrix3[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrix3[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }

        }
    }
    printf("\n%d %d\n%d %d", matrix3[0][0], matrix3[0][1], matrix3[1][0], matrix3[1][1]);
    return 0;
}