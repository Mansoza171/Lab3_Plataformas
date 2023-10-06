#include <stdio.h>

//Encontrar el valor mínimo en el arreglo
int encontrarMinimo(int arreglo[], int longitud) {
    int minimo = arreglo[0];

    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < minimo) {
            //Se actualiza el mínimo si se encuentra un valor menor
            minimo = arreglo[i]; 
        }
    }

    return minimo;
}

//Encontrar el valor máximo en el arreglo
int encontrarMaximo(int arreglo[], int longitud) {
    int maximo = arreglo[0];

    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }

    return maximo;
}

//Encontrar el valor mínimo y máximo utilizando punteros
void encontrarMinMax(int *arreglo, int *minimo, int *maximo, int longitud) {
    //Se supone que el primer elemento es tanto el mínimo como el máximo
    *minimo = *maximo = arreglo[0]; 

    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < *minimo) {
            //Se actualiza el mínimo si encontramos un valor menor
            *minimo = arreglo[i]; 
        } else if (arreglo[i] > *maximo) {
            //Se actualiza el máximo si encontramos un valor mayor
            *maximo = arreglo[i]; 
        }
    }

    printf("Mínimo (punteros): %d\n", *minimo);
    printf("Máximo (punteros): %d\n", *maximo);
}

int main() {
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);
    int minimo, maximo;

    //Uso de las funciones separadas para encontrar el mínimo y el máximo
    minimo = encontrarMinimo(arreglo, longitud);
    maximo = encontrarMaximo(arreglo, longitud);

    printf("Mínimo: %d\n", minimo);
    printf("Máximo: %d\n", maximo);

    //Uso de punteros para encontrar el mínimo y el máximo
    encontrarMinMax(arreglo, &minimo, &maximo, longitud);
    
    return 0;
}
