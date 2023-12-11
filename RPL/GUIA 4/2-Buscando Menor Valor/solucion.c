/*
Combinemos ahora arrays con recursividad. Recibimos un array terminado en \0 == 0, 
y se debe devolver el menor número de ese array.

Por ejemplo, si se recibe el array = [ 1, 3, -2, 14, -50, 0, -100], la respuesta debe ser -50.

Cuidado, se recibe un puntero por parámetro, por lo que se debe verificar que el mismo no es NULL.
 También es posible que se envié un array vacío.
  En ambos casos, devolver el valor 0, con la cte ERROR, ya declarada para estos casos ;).
*/
#include "solucion.h"


int encontrarMinimo(int *array, int minActual) {
    if (*array == 0) {
        return minActual;
    }

    if (*array < minActual) {
        return encontrarMinimo(array + 1, *array);
    }

    return encontrarMinimo(array + 1, minActual);
}

int menor_valor(int *array) {
    if (!array) {
        return ERROR;
    }

    if (*array == 0) {
        return ERROR;
    }

    return encontrarMinimo(array + 1, *array);
}