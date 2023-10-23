#include <stdlib.h>
#include <string.h>

typedef struct pokemon {
    char* nombre_pokemon;
    int fuerza;  
} pokemon_t;

typedef struct entrenador {
    char* nombre_entrenador;
    pokemon_t* pokemones;
    int tope;
} entrenador_t;

pokemon_t* pokemon_buscado(entrenador_t* entrenador, char* nombre_pokemon);