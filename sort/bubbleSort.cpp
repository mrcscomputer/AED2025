#include <iostream>
using namespace std;

void print(int *list, int size) {
    int *ptr = list;
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

void bubbleSort(int *&list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(list + j)> *(list + j + 1)) {
                int temp = *(list + j);
                *(list + j)= *(list + j+1);
                *(list + j+1) = temp;
            }
        }
    }
}

int main() {
    int size = 6;
    int *array = new int[size]{5, 2, 9, 1, 5, 6};
    cout << "Lista original: ";
    print(array, size);

    bubbleSort(array, size);

    cout << "Lista ordenada: ";
    print(array, size);
    delete[] array;

    return 0;
}

