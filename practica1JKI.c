#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Cambiar esta línea de acuerdo al tamaño de la matriz
#define MAX 5000

int main() {
    int **matrizA = (int **)malloc(MAX * sizeof(int *));
    int **matrizB = (int **)malloc(MAX * sizeof(int *));
    int **matrizC = (int **)malloc(MAX * sizeof(int *));
    
    if (!matrizA || !matrizB || !matrizC) {
        printf("Error en la asignación de memoria\n");
        return 1;
    }
    
    for (int i = 0; i < MAX; i++) {
        matrizA[i] = (int *)malloc(MAX * sizeof(int));
        matrizB[i] = (int *)malloc(MAX * sizeof(int));
        matrizC[i] = (int *)malloc(MAX * sizeof(int));
        
        if (!matrizA[i] || !matrizB[i] || !matrizC[i]) {
            printf("Error en la asignación de memoria\n");
            return 1;
        }
    }
    
    // Inicialización de matrices
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            matrizA[i][j] = 1;
            matrizB[i][j] = 2;
            matrizC[i][j] = 0; // Importante inicializar a 0
        }
    }
    
    // Variables para medir tiempo con alta precisión
    LARGE_INTEGER frecuencia;
    LARGE_INTEGER inicio;
    LARGE_INTEGER fin;
    double tiempo_en_segundos;
    
    // Obtener la frecuencia del contador de rendimiento
    QueryPerformanceFrequency(&frecuencia);
    
    // Marcar el tiempo de inicio
    QueryPerformanceCounter(&inicio);
    
    // Multiplicación de matrices
    for(int j = 0; j < MAX; j++) {
        for(int k = 0; k < MAX; k++) {
            for(int i = 0; i < MAX; i++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    
    // Marcar el tiempo de fin
    QueryPerformanceCounter(&fin);
    
    // Calcular el tiempo transcurrido en segundos
    tiempo_en_segundos = (double)(fin.QuadPart - inicio.QuadPart) / frecuencia.QuadPart;
    
    printf("Tiempo de ejecución: %.9f segundos\n", tiempo_en_segundos);
    
    // Liberar memoria
    for (int i = 0; i < MAX; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizC);
    
    return 0;
}