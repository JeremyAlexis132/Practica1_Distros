#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//cambiar esta linea de acuerdo al tamaño de la matriz
int MAX=1000;

int main() {
    int **matrizA, **matrizB, **matrizC;
    int i=0, j=0, k=0;

    // Asignar memoria para las matrices
    matrizA = (int **)malloc(MAX * sizeof(int *));
    matrizB = (int **)malloc(MAX * sizeof(int *));
    matrizC = (int **)malloc(MAX * sizeof(int *));
    for(i = 0; i < MAX; i++) {
        matrizA[i] = (int *)malloc(MAX * sizeof(int));
        matrizB[i] = (int *)malloc(MAX * sizeof(int));
        matrizC[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Inicializar matrices A y B
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            matrizA[i][j] = 1;
            matrizB[i][j] = 2;
            matrizC[i][j] = 0; 
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

    // Liberar memoria
    for(i = 0; i < MAX; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);

    return 0;
}