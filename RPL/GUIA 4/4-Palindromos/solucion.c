/*
En este ejercicio de recursividad vamos a confeccionar una función que determine si una palabra es palíndromo o no. 
Es decir, si la palabra tiene el mismo significado leyéndola de izquierda a derecha que de derecha a izquierda.

Acordate que recibís un puntero, y como todo puntero, puede ser NULL. En ese caso, se debe devolver false.
*/

#include "solucion.h"

bool es_palindromo(const char *cadena, size_t tope) {
    if (cadena == NULL) {
        return false; 
    }

    if (tope <= 1) {
        return true; 
    }

    if (cadena[0] != cadena[tope - 1]) {
        return false;
    }

    return es_palindromo(cadena + 1, tope - 2);
}