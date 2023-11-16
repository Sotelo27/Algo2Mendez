/*
Afiancemos nuestros conocimientos del iterador externo con este ejercicio. 
Tenemos una lista de entrenadores, y queremos saber cuál es el que ganó más batallas. 
En caso de que dos entrenadores hayan ganado la misma cantidad de batallas, 
se debe devolver el que menos batallas perdió de los dos. 
Al igual que en el ejercicio anterior, se recibe el iterador de la lista.

La estructura del entrenador se encuentra en el archivo solucion.h. 
No olvidar revisar los parámetros recibidos! 
Se puede recorrer una lista con el iterador, 
si ese iterador es nulo? En caso de recibirse un parámetro NULL, devolver NULL.


else if(auxiliar.b_ganadas = entrenador_campeon->b_ganadas){
            if (auxiliar.b_perdidas < entrenador_campeon->b_perdidas){
                entrenador_campeon->b_ganadas = auxiliar.b_ganadas;
                entrenador_campeon->b_empatadas = auxiliar.b_empatadas;
                entrenador_campeon->b_perdidas = auxiliar.b_perdidas;  
            }
        }
#include "solucion.h"
void actualizar_victorias(void* entrenador, void* cant_extra){
    if(cant_extra){
           if(entrenador && *(int*)cant_extra > 0){
            entrenador_t * entrenador_actualizado = calloc(1,sizeof(entrenador_t));
            entrenador_actualizado = entrenador;
            entrenador_actualizado->cant_vencidos += *(int*)cant_extra;
        }
    }
}
*/

#include "solucion.h"

entrenador_t* entrenador_con_mas_victorias(lista_iterador_t* it_lista){
    if(!it_lista){
        return NULL;
    }
    entrenador_t* entrenador_campeon = calloc(1,sizeof(entrenador_t));
    entrenador_t* auxiliar = calloc(1,sizeof(entrenador_t));
    while(lista_iterador_tiene_siguiente(it_lista)){
        auxiliar = lista_iterador_elemento_actual(it_lista);
        if (auxiliar->b_ganadas > entrenador_campeon->b_ganadas){
            entrenador_campeon->b_ganadas = auxiliar->b_ganadas;
            entrenador_campeon->b_empatadas = auxiliar->b_empatadas;
            entrenador_campeon->b_perdidas = auxiliar->b_perdidas;
        }else if(auxiliar->b_ganadas == entrenador_campeon->b_ganadas){
            if (auxiliar->b_perdidas < entrenador_campeon->b_perdidas){
                entrenador_campeon->b_empatadas = auxiliar->b_empatadas;
                entrenador_campeon->b_perdidas = auxiliar->b_perdidas; 
            }
        }
        lista_iterador_avanzar(it_lista);
    }
    return entrenador_campeon;
}