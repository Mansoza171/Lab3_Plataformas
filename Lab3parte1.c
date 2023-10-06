#include <stdio.h>

//Funcion búsqueda lineal
int busqLineal(int arreglo[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arreglo[i] == valor) {
            return i;
        }
    }
    return -1; // Valor no encontrado
}

//Funcion búsqueda binaria iterativa
int BinariaIterativa(int arreglo[], int n, int valor) {
    int izquierda = 0;
    int derecha = n - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arreglo[medio] == valor) {
            return medio;
        }
        if (arreglo[medio] < valor) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1; //Valor no encontrado
}

//Funcion búsqueda binaria recursiva
int BinariaRecursiva(int arreglo[], int izquierda, int derecha, int valor) {
    if (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arreglo[medio] == valor) {
            return medio;
        }
        if (arreglo[medio] < valor) {
            return BinariaRecursiva(arreglo, medio + 1, derecha, valor);
        } else {
            return BinariaRecursiva(arreglo, izquierda, medio - 1, valor);
        }
    }
    return -1; //Valor no encontrado
}

int main() {
    int arreglo[] = {2, 4, 6, 23, 56, 79};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int valor;
    printf("Ingrese un valor entero: ");
    scanf("%d", &valor);

    int posicion;

    // Búsqueda lineal
    posicion = busqLineal(arreglo, n, valor);
    if (posicion != -1) {
        printf("Búsqueda Lineal: El valor %d se encuentra en la posición %d \n", valor, posicion);
    } else {
        printf("Búsqueda Lineal: El valor %d no fue encontrado \n", valor);
    }

    //Búsqueda binaria iterativa
    posicion = BinariaIterativa(arreglo, n, valor);
    if (posicion != -1) {
        printf("Búsqueda Binaria Iterativa: El valor %d se encuentra en la posición %d \n", valor, posicion);
    } else {
        printf("Búsqueda Binaria Iterativa: El valor %d no fue encontrado \n", valor);
    }

    //Búsqueda binaria recursiva
    posicion = BinariaRecursiva(arreglo, 0, n - 1, valor);
    if (posicion != -1) {
        printf("Búsqueda Binaria Recursiva: El valor %d se encuentra en la posición %d \n", valor, posicion);
    } else {
        printf("Búsqueda Binaria Recursiva: El valor %d no fue encontrado \n", valor);
    }

    return 0;
}
