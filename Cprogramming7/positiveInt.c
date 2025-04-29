#include <stdio.h>
#include <stdlib.h>

int *postInt(int *v, int n, int *newSizeVector) {
    int i, count = 0;

   
    for (i = 0; i < n; i++) {
        if (v[i] >= 0) {
            count++;
        }
    }

   
    int *vectorP = malloc(count * sizeof(int));
    if (vectorP == NULL) {
        printf("Error \n");
        return NULL;
    }

    int j = 0;
    for (i = 0; i < n; i++) {
        if (v[i] >= 0) {
            vectorP[j++] = v[i];
        }
    }

    *newSizeVector = count;
    return vectorP;
}

int main() {
    int i, n, *matrix, *vP, newSize;

    printf("Numero de elementos: ");
    scanf("%d", &n);

    matrix = malloc(n * sizeof(int));
    if (matrix == NULL) {
        printf("Error\n");
        return 1;
    }

    printf("Ingrese numeros enteros:\n");
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i+1);
        scanf("%d", &matrix[i]);
    }

    vP = postInt(matrix, n, &newSize);

    printf("Elementos positivos:\n");
    for (i = 0; i < newSize; i++) {
        printf("%d ", vP[i]);
    }
   printf("\n"); 
    free(matrix);
    free(vP);

    return 0;
}

