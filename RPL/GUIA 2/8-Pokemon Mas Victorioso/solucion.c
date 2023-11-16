/*
Intro teórica

Ya vimos cómo recibir un puntero a función para invocar una función que desconocemos y devolver su resultado. 
Ahora, vamos a hacer lo mismo, pero en vez de recibir una sola función… recibimos un vector de funciones!
Consigna

Ahora que tenemos pokemones, por supuesto que queremos que batallen, no? 
Para eso, en otro archivo se declararon varias funciones de pelea entre dos pokemones. 
Pero no sólo queremos que batallen, no no. Buscamos saber cuál pokemon ganaría la mayoría de las batallas.

Para eso, se declaró la firma de esta función, que recibe los dos pokemones a batallar y un vector de funciones.
 Cada una de las funciones en el vector es un puntero a un tipo de batalla distinto. 
 Por ejemplo, la primer función podría decirnos qué pokemon es más rápido, la segunda podría decirnos qué pokemon es más fuerte, 
 etc. Te aseguramos que sólo se va a enviar una cantidad impar de batallas, para que no haya empates. 
 Se requiere devolver el pokemón que más batallas ganó.

Recordar que se deben verificar los parámetros pasados. Tiene sentido que los pokemones sean nulos?
*/

#include "solucion.h"

pokemon_t* pokemon_mas_victorioso(pokemon_t* poke1, pokemon_t* poke2, pokemon_t* (*funciones_batallas[MAX])(pokemon_t*, pokemon_t*), 
    int tope) {
    int iteraciones = 0;
    //pokemon_t * auxiliar = malloc(sizeof(pokemon_t));
    int victorias_1 = 0;
    int victorias_2 = 0;

    if(!poke1){
        return NULL;
    }
    if(!poke2){
        return NULL;
    }
    if(!funciones_batallas){
        return NULL;
    }
    while(iteraciones < tope){
        if(funciones_batallas[iteraciones](poke1,poke2) == poke1){
            victorias_1++;
        }else{
            victorias_2++;
        }
        iteraciones++;
    }
    if(victorias_1 > victorias_2){
        return poke1;
    }else{
        return poke2;
    }
}