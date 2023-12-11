/*
Continuamos con strings, pero ahora con una vuelta de tuerca.
 Recibimos un string desordenado y debemos ordenarlo de manera ascendente o descendente según el booleano pasado por parámetro.
  El string ordenado se devuelve en el segundo vector pasado por parámetro.

Recordemos que un string ordenado ascendentemente es "ABCDEF".
Mientras que uno ordenado de manera descendente es "FEDCBA".
*/
#include "solucion.h"

#include <string.h>

void intercambiar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(char string_desordenado[MAX_VECTOR], char string_ordenado[MAX_VECTOR], bool ascendente) {
    strcpy(string_ordenado, string_desordenado);
    
    int length = strlen(string_ordenado);
    int i, j;

    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (ascendente) {
                if (string_ordenado[j] > string_ordenado[j + 1]) {
                    intercambiar(&string_ordenado[j], &string_ordenado[j + 1]);
                }
            } else {
                if (string_ordenado[j] < string_ordenado[j + 1]) {
                    intercambiar(&string_ordenado[j], &string_ordenado[j + 1]);
                }
            }
        }
    }
}