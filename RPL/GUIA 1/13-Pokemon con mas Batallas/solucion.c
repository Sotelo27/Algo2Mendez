/*
Terminemos esta guía a lo grande!

Último ejercicio de archivos. Ahora, lo almacenado en el archivo corresponde a información de pokemones. 
No se sabe cuántos pokemones hay en el archivo, pero te aviso que que no va a haber más de 10.

También conocemos cómo están organizados:

Vulpix;
15;20;19;

Donde Vulpix es el nombre de ese pokemon, 15 es la cantidad de batallas ganadas, 
20 es la cantidad de batallas perdidas y 19 es la cantidad de batallas empatadas.

Se pide devolver el pokemon que compitió en más batallas, contando las que ganó, empató y perdió. 
Se puede asumir que no se va a recibir un archivo nulo.

Y no te preocupes por el archivo, nosotros lo cerramos detrás de bambalinas ;)
*/

#include "solucion.h"

pokemon_t pokemon_con_mas_batallas(FILE* archivo){
    pokemon_t pokemon_mayor;
    int ganadas = 0;
    int perdidas = 0;
    int empatadas = 0;
    char char_nombre[MAX_NOMBRE];
    int mayor = 0;
    int cant_partidas_actual = 0;
    while (fscanf(archivo ,"\n%[^;];", char_nombre) == 1){
        fscanf(archivo,"%i;%i;%i;",&ganadas,&perdidas,&empatadas);
        cant_partidas_actual = ganadas + perdidas + empatadas;
        if (mayor < cant_partidas_actual){
            pokemon_mayor.b_empatadas = empatadas;
            pokemon_mayor.b_ganadas = ganadas;
            pokemon_mayor.b_perdidas = perdidas;
            strcpy(pokemon_mayor.nombre,char_nombre);
            mayor = cant_partidas_actual;
        }
    }
    return pokemon_mayor;
}

int main(){
	FILE *archivo = fopen("prueba.txt", "r");
    pokemon_t pokemon_mayor;
    pokemon_mayor = pokemon_con_mas_batallas(archivo);
    int cantidad_batallas = pokemon_mayor.b_empatadas + pokemon_mayor.b_ganadas + pokemon_mayor.b_perdidas; 
    printf("\nEl pokemon con mas batallas es %s y tiene un total de %d batallas\n",pokemon_mayor.nombre,cantidad_batallas);
    fclose(archivo);
}