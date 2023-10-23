/*
Ya sabemos devolver un void*, ahora aprendamos a usarlo.

Queremos actualizar la cantidad de entrenadores que cierto entrenador venció en el torneo. 
Para hacerlo, se reciben dos void*. S
abemos que el primero representa un entrenador y el segundo representa un entero. 
El entero es la cantidad de otros entrenadores que el nuestro venció en la última batalla.

Por ejemplo, si recibo un entrenador que posee la variable cant_vencidos = 18 y el número 2, 
al finalizar la función el entrenador recibido debería tener 20 victorias almacenadas.

Recordá chequear los parámetros que se reciben. Tiene sentido que la cantidad extra sea negativa? 
Y cero? En caso de que alguno de los parámetros no sea válido o carezca de sentido, no se modifica la cantidad de vencidos.
*/

#include "solucion.h"
#include <stdio.h>
#include <stdlib.h>
void actualizar_victorias(void* entrenador, void* cant_extra){
    if(cant_extra){
           if(entrenador && *(int*)cant_extra > 0){
            entrenador_t * entrenador_actualizado = calloc(1,sizeof(entrenador_t));
            entrenador_actualizado = entrenador;
            entrenador_actualizado->cant_vencidos += *(int*)cant_extra;
        }
    }
}

int main(){
    entrenador_t * entrenador_actualizado = calloc(1,sizeof(entrenador_t));
    int valorInt1 = 1;
    int * valor;
    valor = &valorInt1;
    entrenador_actualizado->cant_vencidos = 20;
    entrenador_actualizado->nombre = "Pepe";
    actualizar_victorias(entrenador_actualizado,valor);
    printf("\nEl valor actualizado del entrenador es : %d\n",entrenador_actualizado->cant_vencidos);
    valorInt1 = 2;
    actualizar_victorias(entrenador_actualizado,valor);
    printf("\nEl valor actualizado del entrenador es : %d\n",entrenador_actualizado->cant_vencidos);
    valorInt1 = -2;
    actualizar_victorias(entrenador_actualizado,valor);
    printf("\nEl valor actualizado del entrenador es : %d\n",entrenador_actualizado->cant_vencidos);
    valorInt1 = 0;
    actualizar_victorias(entrenador_actualizado,valor);
    printf("\nEl valor actualizado del entrenador es : %d\n",entrenador_actualizado->cant_vencidos);
}