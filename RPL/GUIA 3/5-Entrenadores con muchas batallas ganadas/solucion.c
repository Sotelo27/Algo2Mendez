/*
Último ejercicio con iterador interno. Ahora, queremos buscar los entrenadores que ganaron más de cierta cantidad de batallas. 
Para eso, se recibe la lista de todos los entrenadores y una lista vacía a la cual se le debe agregar cada entrenador que cumpla las condiciones. 
Ah, que cuántas batallas tienen que haber ganado? Eso lo recibís por parámetro ;)

No olvides revisar los parámetros! Si alguna de las listas es NULL, no se realiza ninguna operación.
 Si la cantidad de batallas es menor a 0, tampoco se realiza ninguna operación. 
 Por último, este ejercicio no requiere que pidas ni liberes memoria dinámica, así que no te preocupes por eso, nosotros lo resolvemos.
*/
#include "solucion.h"

typedef struct entrenadores_ganadores{
        lista_t * entrenadores;
        int batallas_ganadas_necesarias;
}entrenadores_ganadores_t;

bool verificar_batallas(void* elemento, void* contexto) {
    entrenador_t* entrenador = (entrenador_t*)elemento;
    entrenadores_ganadores_t* parametros = (entrenadores_ganadores_t*)contexto;

    if (entrenador->b_ganadas >= parametros->batallas_ganadas_necesarias) {
        lista_insertar(parametros->entrenadores, entrenador);
    }

    return true; // Continuar iterando
}

void entrenadores_con_muchas_victorias(lista_t* entrenadores, lista_t* entrenadores_ganadores, int batallas_ganadas) {
    if (!entrenadores || !entrenadores_ganadores || batallas_ganadas <= 0) {
        return;
    }

    entrenadores_ganadores_t parametros = {
        .entrenadores = entrenadores_ganadores,
        .batallas_ganadas_necesarias = batallas_ganadas
    };

    lista_con_cada_elemento(entrenadores, verificar_batallas, &parametros);
}