/*
Aumentemos un poquito la dificultad. Vamos a implementar otro método de ordenamiento, heapsort. 
La dificultad radica en ese tercer parámetro que recibimos, comparador comparador, un poco raro, no? Si leíste el apunte de punteros a función, o revisás el archivo solucion.h, 
te darás cuenta de que el tipo de dato comparador se definió allí, como un puntero a función que recibe dos enteros y devuelve un entero.
 Esta función nos servirá para librarnos del horrible bool ascendente que veníamos usando hasta ahora. Este comparador recibe dos parámetros, supongamos A y B.
  Si el comparador devuelve un número negativo (< 0), entonces el parámetro A debería ser el padre de B en el heap; en cambio, si el comparador devuelve un número positivo (> 0),
   entonces el parámetro A debería ser el hijo de B en el heap.

Sí, suena confuso. La intención de esta definición es que nos desliguemos del tipo de ordenamiento que hacemos (ascendente o descendente). 
Ya no nos importa si tenemos que ordenar de una u otra forma, el usuario se encarga de decidirlo cuando confecciona el comparador. 
Vos como implementador solamente te tenés que fijar en lo que devuelve la función comparadora.

--> Si es positivo, el valor que se haya enviado como A debe ser el hijo del valor enviado en B;

--> si es negativo, el valor que se haya enviado como A debe ser el padre del valor enviado en B.

Y como siempre, si el comparador devuelve 0, los valores son iguales.

Con toodo esto en mente, se requiere implementar el método de ordenamiento heapsort, 
que implica utilizar las funciones extraer_raiz y sift_down que habíamos implementado en la guía de heap,
 pero con una pequeña diferencia… ahora, tienen que utilizar el comparador para ordenar correctamente el vector ;)

En el archivo extras.c te dejé la implementación de las dos funciones con algunos comentarios, que te dan la pista de donde deberías reemplazar la comparación 
hecha a mano con una llamada al comparador.

Ah, y el algoritmo debe ser hecho de manera inplace :D
*/
#include "solucion.h"

void heap_sort(int vector[MAX_ELEM], int cantidad, comparador_t comparador) {
    // Construir el heap
    for (int i = cantidad / 2 - 1; i >= 0; i--) {
        sift_down(vector, cantidad, i, comparador);
    }

    // Extraer elementos uno por uno del heap
    for (int i = cantidad - 1; i > 0; i--) {
        // Mover la raíz actual al final
        swap(vector, 0, i);

        // Llamar a sift_down en el heap reducido
        sift_down(vector, i, 0, comparador);
    }
}