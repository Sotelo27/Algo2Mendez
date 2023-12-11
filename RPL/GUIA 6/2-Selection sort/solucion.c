/*
Seguimos con otro método de ordenamiento, el llamado Selección. 
Al igual que en el ejercicio pasado, se recibe un vector de caracteres, que se desea ordenar de manera ascendente o descendente, dependiendo del booleano valor pasado por parámetro. 
También se recibe el vector donde se espera que estén los elementos ordenados.

A saber,
Un string ordenado ascendentemente es "ABCDEF".
Mientras que uno ordenado de manera descendente es "FEDCBA".

Si no conocen este algoritmo y cómo se construye, les dejo un link a un video del tema, de la materia Algo1Mendez https://www.youtube.com/watch?v=8L5yhtHws-I&ab_channel=algo1mendez
*/
#include "solucion.h"

void intercambiar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(char vector_desordenado[MAX_VECTOR], char vector_ordenado[MAX_VECTOR], int tope, bool ascendente) {
    // Copiar el vector desordenado al vector ordenado
    strcpy(vector_ordenado, vector_desordenado);

    int i, j;
    for (i = 0; i < tope - 1; i++) {
        int indice_min_max = i;
        for (j = i + 1; j < tope; j++) {
            if (ascendente) {
                if (vector_ordenado[j] < vector_ordenado[indice_min_max]) {
                    indice_min_max = j;
                }
            } else {
                if (vector_ordenado[j] > vector_ordenado[indice_min_max]) {
                    indice_min_max = j;
                }
            }
        }
        // Intercambiar el elemento actual con el elemento más pequeño/más grande encontrado
        if (indice_min_max != i) {
            intercambiar(&vector_ordenado[i], &vector_ordenado[indice_min_max]);
        }
    }
}