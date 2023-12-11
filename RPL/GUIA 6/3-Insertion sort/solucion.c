/*
Para finalizar los tres métodos de ordenamiento que se ven en Algo1, se pide implementar el método de inserción.

Si no lo conocen, aquí les dejamos un link de la explicación del mismo de Algo1Mendez https://www.youtube.com/watch?v=NkRFb9t0OXI&ab_channel=algo1mendez

A saber,
Un string ordenado ascendentemente es "ABCDEF", mientras que uno ordenado de manera descendente es "FEDCBA"
*/
#include "solucion.h"

void insertion_sort(char vector_desordenado[MAX_VECTOR], char vector_ordenado[MAX_VECTOR], int tope, bool ascendente) {
    
    strcpy(vector_ordenado, vector_desordenado);

    int i, j;
    char clave;

    for (i = 1; i < tope; i++) {
        clave = vector_ordenado[i];
        j = i - 1;

        // Mover los elementos del vector ordenado que son mayores/menores que la clave
        // a una posición adelante
        if (ascendente) {
            while (j >= 0 && vector_ordenado[j] > clave) {
                vector_ordenado[j + 1] = vector_ordenado[j];
                j = j - 1;
            }
        } else {
            while (j >= 0 && vector_ordenado[j] < clave) {
                vector_ordenado[j + 1] = vector_ordenado[j];
                j = j - 1;
            }
        }
        
        vector_ordenado[j + 1] = clave;
    }
}