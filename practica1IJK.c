#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//cambiar esta linea de acuerdo al tamaño de la matriz
#define MAX 100

int main() {
    int matrizA[MAX][MAX], matrizB[MAX][MAX], matrizC[MAX][MAX];
    int i=0, j=0, k=0;
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            matrizA[i][j] = 1;
            matrizB[i][j] = 2;
        }
    }
    clock_t start = clock();
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            for(k=0; k<MAX; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %f\n", time);
    return 0;
}