/*
Ash Ketchum quiere convertirse en Maestro Pokémon, el más alto grado de entrenamiento Pokémon.

Para lograrlo necesita entrenar a sus pokémones en batallas y estar también físicamente en forma, así que decide seguir el consejo del doctor Proctor y hacer sentadillas. 
El tema es que la cantidad que debe hacer tiene que ser un número primo… y como a veces se olvida si un número es primo o no, te pide ayuda para que crees un programa que, 
dada la cantidad de sentadillas que Ash quiere hacer, devuelva ese mismo número si éste es primo, o el siguiente número primo, el mayor número primo más próximo al ingresado.

Por ejemplo, si Ash ingresa el número 3, la función devuelve el número 3. Si Ash ingresa el número 4, la función devuelve el número 5.
*/
#include "solucion.h"

int es_primo_aux(int numero, int divisor) {
    if (divisor == 1) {
        return 1; // Indica que es primo
    }

    if (numero % divisor == 0) {
        return 0; // Indica que no es primo
    }

    return es_primo_aux(numero, divisor - 1); // Llamada recursiva
}

int cantidad_sentadillas(size_t sentadillas_ingresadas) {
    int numero = (int)sentadillas_ingresadas;

    while (1) {
        if (es_primo_aux(numero, numero / 2) == 1) {
            return numero; // Si es primo, se retorna el número
        }
        numero++; // Se incrementa para buscar el siguiente número
    }
}