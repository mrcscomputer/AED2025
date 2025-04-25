#include <stdio.h>
#include <stdlib.h>

// struct class
struct Class {
    int numEstudiantes;    
    float *calificaciones; 
};

int main() {
    struct Class miClase;
    int i;
    float mayorNota = 0.0;

    printf("Cantidad de estudiantes: ");
    scanf("%d", &miClase.numEstudiantes);

    
    miClase.calificaciones = (float *)malloc(miClase.numEstudiantes * sizeof(float));

    if (miClase.calificaciones == NULL) {
        printf("no hay espacio suficiente en memoria.\n");
        exit(1);
    }

    // Ingresamos las calificaciones
    for (i = 0; i < miClase.numEstudiantes; i++) {
    	printf("nota de estudiante %d: ", i + 1);
        scanf("%f", &miClase.calificaciones[i]);
    }

    mayorNota = miClase.calificaciones[0]; 
    
    for (i = 1; i < miClase.numEstudiantes; i++) {
        if (*(miClase.calificaciones + i) > mayorNota) {
            mayorNota = *(miClase.calificaciones + i);
        }
    }

 
    printf("\nLa nota mas alta es: %.2f\n", mayorNota);

    
    free(miClase.calificaciones);

    return 0;
}
