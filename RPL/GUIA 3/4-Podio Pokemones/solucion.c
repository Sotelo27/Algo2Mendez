/*
Sigamos haciendo competir a nuestros pokemones.
 Para eso los capturan los entrenadores, no? Y de paso, practiquemos cómo usar el iterador interno.

Dado un grupo de pokemones, se quiere saber cuáles ganarían la medalla de oro, plata y bronce en una carrera. 
Cada pokemon tiene su nivel de rapidez y por supuesto, el que mayor nivel tenga, más rápido corre.

Para resolver el problema, se presenta la firma de una función que recibe el listado de todos los pokemones y
 una lista vacía donde se insertarán los pokemones que pertenecen al podio. Se pide que los pokemones del podio estén ordenados de la siguiente manera

medalla de oro - medalla de plata - medalla de bronce

No olvides revisar los parámetros! Si alguno de ellos es NULL, no se realiza ninguna operación. 
Por último, este ejercicio no requiere que utilices memoria dinámica de ningún tipo, así que no te preocupes por liberar memoria, nosotros nos encargamos de todo.
#include "solucion.h"
*/

#include "solucion.h"

bool determinar_podio(void* elemento, void* contexto) {
    lista_t* podio = (lista_t*)contexto;
    pokemon_t* pokemon = (pokemon_t*)elemento;

    pokemon_t* oro = lista_elemento_en_posicion(podio, 0);
    pokemon_t* plata = lista_elemento_en_posicion(podio, 1);
    pokemon_t* bronce = lista_elemento_en_posicion(podio, 2);

    if (oro == NULL || pokemon->rapidez > oro->rapidez) {
        lista_borrar_de_posicion(podio, 2);
        lista_insertar_en_posicion(podio, plata, 2);
        lista_borrar_de_posicion(podio, 1);
        lista_insertar_en_posicion(podio, oro, 1);
        lista_borrar_de_posicion(podio, 0);
        lista_insertar_en_posicion(podio, pokemon, 0);
    } else if (plata == NULL || pokemon->rapidez > plata->rapidez) {
        lista_borrar_de_posicion(podio, 2);
        lista_insertar_en_posicion(podio, bronce, 2);
        lista_borrar_de_posicion(podio, 1);
        lista_insertar_en_posicion(podio, pokemon, 1);
    } else if (bronce == NULL || pokemon->rapidez > bronce->rapidez) {
        lista_borrar_de_posicion(podio, 2);
        lista_insertar_en_posicion(podio, pokemon, 2);
    }

    return true;
}


void podio_de_pokemones(lista_t* pokemones, lista_t* podio){
        if (!pokemones || !podio){
                return;
        }
        lista_insertar(podio, NULL); // Medalla de oro
        lista_insertar(podio, NULL); // Medalla de plata
        lista_insertar(podio, NULL); // Medalla de bronce
        lista_con_cada_elemento(pokemones,determinar_podio,podio);
}