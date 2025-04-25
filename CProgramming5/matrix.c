#include <stdio.h>

#define MAX_FILAS 10
#define MAX_COLUMNAS 10


typedef struct {
  int filas;
  int columnas;
  int datos[MAX_FILAS][MAX_COLUMNAS]; 

} Matriz;



// imprimir una matriz
void imprimirMatriz(Matriz m) {
  for (int i = 0; i < m.filas; i++) {
    for (int j = 0; j < m.columnas; j++) {
      printf("%d ", m.datos[i][j]);
    }
    printf("\n");
  }
}

// Suma de dos matrices
Matriz sumarMatrices(Matriz a, Matriz b) {
  Matriz resultado;
  resultado.filas = a.filas;
  resultado.columnas = a.columnas;

  for (int i = 0; i < a.filas; i++) {
    for (int j = 0; j < a.columnas; j++) {
      resultado.datos[i][j] = a.datos[i][j] + b.datos[i][j];
    }
  }

  return resultado;
}

// Multiplicacion
Matriz multiplicarMatrices(Matriz a, Matriz b) {
  Matriz resultado;
  resultado.filas = a.filas;
  resultado.columnas = b.columnas;

  for (int i = 0; i < a.filas; i++) {
    for (int j = 0; j < b.columnas; j++) {
      resultado.datos[i][j] = 0;
      for (int k = 0; k < a.columnas; k++) {
        resultado.datos[i][j] += a.datos[i][k] * b.datos[k][j];
      }
    }
  }

  return resultado;
}

// Transpuesta
Matriz transponerMatriz(Matriz m) {
  Matriz resultado;
  resultado.filas = m.columnas;
  resultado.columnas = m.filas;

  for (int i = 0; i < m.filas; i++) {
      for (int j = 0; j < m.columnas; j++) {
          resultado.datos[j][i] = m.datos[i][j];
      }
  }

  return resultado;
}


int main() {
  
  Matriz A = {2, 2, {{1, 0}, {3, 4}}};
  Matriz B = {2, 2, {{4, 2}, {7, 8}}};

  printf("Matriz A:\n");
  imprimirMatriz(A);

  printf("\nMatriz B:\n");
  imprimirMatriz(B);

  
  Matriz suma = sumarMatrices(A, B);
  printf("\nSuma A + B:\n");
  imprimirMatriz(suma);

 
  Matriz producto = multiplicarMatrices(A, B);
  printf("\nProducto A * B:\n");
  imprimirMatriz(producto);

  Matriz transpuesta = transponerMatriz(A);
  printf("\nTranspuesta de A:\n");
  imprimirMatriz(transpuesta);

return 0;
}

