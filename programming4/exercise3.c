#include <stdio.h>

#define N 3  

void transponerMatriz(float matriz[N][N], float transpuesta[N][N], int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpuesta[j][i] = matriz[i][j]; 
        }
    }
}

void imprimirMatriz(float matriz[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
   
    float matriz[N][N] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    
    float transpuesta[N][N];  

    
    transponerMatriz(matriz, transpuesta, N);

    
    printf("Matriz Original:\n");
    imprimirMatriz(matriz, N);

   
    printf("\nMatriz Transpuesta:\n");
    imprimirMatriz(transpuesta, N);

    return 0;
}

