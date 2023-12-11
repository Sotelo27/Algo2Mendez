/*

Lo prometido es deuda, aquí está el link de introducción de Algo1Mendez:
https://www.youtube.com/watch?v=aXhsI_8KUy0&ab_channel=algo1mendez

Ahora sí, empecemos con el método de ordenamiento más conocido: Bubblesort.

Se recibe un vector de caracteres, que deseo ordenar de manera ascendente o descendente, dependiendo del booleano pasado por parámetro.
 También se recibe el vector donde quiero que estén los elementos ordenados.

Por si no tienen ni idea de sobre qué les estoy hablando, acá les dejo un video de Algo1Mendez donde se explica este algoritmo: 
https://www.youtube.com/watch?v=QgU47ejV7mg&ab_channel=algo1mendez

A saber, un string ordenado ascendentemente es "ABCDEF", mientras que uno ordenado de manera descendente es "FEDCBA".
*/

#include "solucion.h"
#include <string.h>

void intercambiar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(char vector_desordenado[MAX_VECTOR], char vector_ordenado[MAX_VECTOR], int tope, bool ascendente) {
    strncpy(vector_ordenado, vector_desordenado, MAX_VECTOR);

    for (int i = 0; i < tope - 1; ++i) {
        for (int j = 0; j < tope - i - 1; ++j) {
            if ((ascendente && vector_ordenado[j] > vector_ordenado[j + 1]) ||
                (!ascendente && vector_ordenado[j] < vector_ordenado[j + 1])) {
                intercambiar(&vector_ordenado[j], &vector_ordenado[j + 1]);
            }
        }
    }
}