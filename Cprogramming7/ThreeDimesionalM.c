#include <stdio.h>
#include <stdlib.h>


double ***matrixTD(int m, int n, int k) {
    double ***mtd = malloc(m * sizeof(double **));
    if (!mtd) {
        printf("Error\n");
        return NULL;
    }

    for (int i = 0; i < m; i++) {
        mtd[i] = malloc(n * sizeof(double *));
        if (!mtd[i]) {
            printf("Error en mtd[%d]\n", i);
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            mtd[i][j] = malloc(k * sizeof(double));
            if (!mtd[i][j]) {
                printf("Error en mtd[%d][%d]\n", i, j);
                return NULL;
            }
            
            for (int l = 0; l < k; l++) {
                mtd[i][j][l] = 0.0;
            }
        }
    }

    return mtd;
}

int main() {
    int x, y, z;
    double ***matrix;

    printf("Ingrese dimensiones (x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    matrix = matrixTD(x, y, z);
    if (matrix == NULL) {
        return 1;
    }

    // Impresion de matriz 3d
    printf("Matriz 3D inicializada:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("%.1f ", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("---\n");
    }

 
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

