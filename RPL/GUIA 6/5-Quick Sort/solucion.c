/*
Terminamos los tres métodos de ordenamiento con quick sort. Programar ahora este algoritmo, cumpliendo las mismas condiciones de los ejercicios anteriores.
*/
#include <stdbool.h>

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int arr[], int bajo, int alto, bool ascendente) {
    int pivote = arr[alto];
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++) {
        if ((ascendente && arr[j] < pivote) || (!ascendente && arr[j] > pivote)) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quick_sort_recursivo(int arr[], int bajo, int alto, bool ascendente) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto, ascendente);

        quick_sort_recursivo(arr, bajo, pi - 1, ascendente);
        quick_sort_recursivo(arr, pi + 1, alto, ascendente);
    }
}

void quick_sort(int arr[], int tope, bool ascendente) {
    quick_sort_recursivo(arr, 0, tope - 1, ascendente);
}