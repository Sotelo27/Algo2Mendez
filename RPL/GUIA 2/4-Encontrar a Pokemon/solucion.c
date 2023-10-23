/*
Se recibe un entrenador que posee varios pokemones en su vector de pokemones. 
También se recibe el nombre de un pokemon a buscar.
 Si se lo encuentra en el listado, devolver ese pokemon.
 Si no se lo encuentra, devolver NULL.

Recordar que el entrenador pasado o el nombre pasado puede ser NULL. 
Se puede ingresar a los pokemones de un NULL? Tiene sentido que un nombre sea NULL?
 En cualquier caso, devolver NULL también.
*/

#include "solucion.h"
#include <stdio.h>

pokemon_t* pokemon_buscado(entrenador_t* entrenador, char* nombre_pokemon){
    if (!entrenador){
        return NULL;
    }
    if (!nombre_pokemon){
        return NULL;
    }
    int posicion = 0;
    pokemon_t * pokemon_encontrado = calloc(1,sizeof(pokemon_t));
    while (posicion < entrenador->tope){
        if (!strcmp(nombre_pokemon,entrenador->pokemones[posicion].nombre_pokemon)) { //El ! verifica que sean iguales.
				return &entrenador->pokemones[posicion];
			}
        posicion++;
    }
    return NULL;
}