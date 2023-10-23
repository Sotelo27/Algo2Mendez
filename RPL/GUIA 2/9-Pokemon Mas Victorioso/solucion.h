#define MAX 10
#include <stdlib.h>
#include <stdbool.h>

typedef struct pokemon {
    int rapidez;
    int inteligencia;
    int carisma;
    int fuerza;
} pokemon_t;

pokemon_t* pokemon_mas_victorioso(pokemon_t* poke1, pokemon_t* poke2, pokemon_t* (*funciones_batallas[MAX])(pokemon_t*, pokemon_t*), int tope);