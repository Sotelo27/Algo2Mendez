/*
Habiendo repasado los iteradores de la lista, pasamos ahora al iterador de árbol.
 Misma idea que para los iteradores de lista; cuando usamos el árbol, no podemos acceder a la estructura del mismo.
  Entonces, si queremos aplicar cierta función a cada nodo del árbol, tenemos el iterador de abb.

Empecemos con algo simple. Tenemos un árbol de números (ints), y queremos meter los números impares en un nuevo árbol.

Aviso, este ejercicio no implica manejo de memoria dinámica. No te preocupes por crear o liberar memoria, nosotros nos ocupamos de eso.

No olvides revisar los parámetros!
*/
#include "solucion.h"

void comparar_impares(void *elemento, void *abb){
    abb_t * abb_impares = (abb_t*) abb;
    int numero_impar = *((int*) elemento);

    if (numero_impar % 2 != 0) {
        arbol_insertar(abb_impares, &numero_impar);
    }
}


void elementos_impares(abb_t* abb_original, abb_t* abb_impares){
        if (!abb_original || !abb_impares){
                return;
        }
        abb_con_cada_elemento(abb_original,ABB_RECORRER_INORDEN ,comparar_impares,abb_impares);
}