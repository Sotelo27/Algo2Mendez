/*
Último ejercicio de heaps. Ya vimos cómo insertar en un heap y eliminar de uno. 
Como último ejercicio, veamos cómo construir un heap a partir de un array de elementos con la función heapify.

Al igual que todos los ejercicios pasados, vamos a generar un heap maximal con esta función.

Para pensar, qué tendrías que cambiar del código para que esta función devolviese un heap minimal?
*/
#include "solucion.h"

void sift_down(int* vector, int tope, int pos_actual) {
    int hijo_izq, hijo_der, hijo_mayor, temp;
    int seguir = 1;

    while (seguir) {
        hijo_izq = (pos_actual * 2) + 1;
        hijo_der = (pos_actual * 2) + 2;
        hijo_mayor = pos_actual;

        if (hijo_izq < tope && vector[hijo_izq] > vector[hijo_mayor]) {
            hijo_mayor = hijo_izq;
        }

        if (hijo_der < tope && vector[hijo_der] > vector[hijo_mayor]) {
            hijo_mayor = hijo_der;
        }

        if (hijo_mayor != pos_actual) {
            temp = vector[pos_actual];
            vector[pos_actual] = vector[hijo_mayor];
            vector[hijo_mayor] = temp;

            pos_actual = hijo_mayor;
        } else {
            seguir = 0;
        }
    }
}

void heapify(int vector[MAX_ELEM], int cantidad) {
    for (int i = cantidad / 2 - 1; i >= 0; i--) {
        sift_down(vector, cantidad, i);
    }
}
