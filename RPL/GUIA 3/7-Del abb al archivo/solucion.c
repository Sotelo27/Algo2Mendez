/*
Terminemos la guía a lo grande. Se tiene un árbol que contiene pokemones. 

Se pide escribirlos en el archivo pasado por parámetro con el siguiente formato:

nombre_del_pokemon;nivel;fuerza;inteligencia;carisma\n

Un ejemplo sería
Pikachu;5;20;18;40

Hacer uso del iterador interno del abb para modifcar el archivo pasado por parámetro y
 escribir en él los pokemones contenidos en el árbol, en orden alfabético.

No olvides revisar los parámetros!
*/
#include "solucion.h"

#include "solucion.h"

void escribir_pokemon(pokemon_t* pokemon, FILE* archivo) {
    fprintf(archivo, "%s;%d;%d;%d;%d\n", pokemon->nombre, pokemon->nivel, pokemon->fuerza, pokemon->inteligencia, pokemon->carisma);
}

static void escribir_pokemon_archivo(void* elemento, void* extra) {
    FILE* archivo = (FILE*)extra;
    pokemon_t* pokemon = (pokemon_t*)elemento;
    escribir_pokemon(pokemon, archivo);
}

void escribir_pokemones_en_archivo(abb_t* pokemones, FILE* archivo) {
    if (!pokemones || !archivo) {
        return;
    }

    abb_con_cada_elemento(pokemones, ABB_RECORRER_INORDEN, escribir_pokemon_archivo, archivo);
}
