//exercise 2

#include <stdio.h>


int esSimetrica(int matriz[][3], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {  
      if (matriz[i][j] != matriz[j][i]) {
        return 0;  
         }
      }
    }
  return 1;  
}

int main() {
  int n = 3;  
    
    
  int matriz[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };

    
  if (esSimetrica(matriz, n)) {
      printf("La matriz es simétrica.\n");
  } else {
      printf("La matriz no es simétrica.\n");
  }

  return 0;
}

