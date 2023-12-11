/*
Empezamos con el primero de los tres sorts que se ven en la materia Algo2Mendez. 
Como ya estamos en temas de Algo2, en vez de recibir un vector desordenado y otro donde ir enviando los elementos ordenados, se recibe solamente un vector. 
Al principio, se recibe el vector desordenado, y al finalizar el algoritmo, el mismo debe encontrarse ordenado.

Este algoritmo puede hacerse de manera tanto iterativa como recursiva, cualquiera está bien (mientras funcione, claro).

Como venimos viendo hasta ahora, se recibe también un booleano para decidir si debemos ordenar de manera ascendente o descendente el vector.
*/
#include <stdbool.h>

void merge(int arr[], int l, int m, int r, bool ascendente);

void merge_sort(int arr[], int tope, bool ascendente) {
    if (tope > 1) {
        int mid = tope / 2;
        merge_sort(arr, mid, ascendente);
        merge_sort(arr + mid, tope - mid, ascendente);
        merge(arr, 0, mid, tope, ascendente);
    }
}

void merge(int arr[], int l, int m, int r, bool ascendente) {
    int n1 = m - l;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if ((ascendente && L[i] <= R[j]) || (!ascendente && L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}