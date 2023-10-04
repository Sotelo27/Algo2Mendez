/*
Ahora que vimos la diferencia entre vector de chars y strings, 
incluyamos la biblioteca de strings y aprovechémosla!

Se reciben tres strings (como avisamos que son strings, se puede asumir que poseen el '\0'). 
Se pide que el primero se concatene con el segundo, y que se devuelva el resultado de comparar este nuevo string con el tercero.
 Cuál iría antes en el diccionario? Si el string concatenado aparecería primero o ambos son iguales, se devuelve la letra 'C' . 
 Si el tercer string pasado por parámetro aparecería primero, se devuelve la letra 'S'.

Veamos un ejemplo. Recibo los strings "Algo", "ritmo" y "Programación".
 Si concateno el primer y segundo string, obtengo "Algoritmo".
  Comparo "Algoritmo" con "Programación" y obtengo que "Algoritmo" debería ir primero en el diccionario, 
  así que debo devolver la letra 'C'.

Ya incluimos por vos la librería en solucion.h ;)

Ayudita: buscá qué funciones interesantes hay en la biblioteca string.h ;)
*/


#include "solucion.h"
#include <stdio.h> 

char ejercicio(char string1[MAX_STRING], char string2[MAX_STRING], char string3[MAX_STRING]){
    char caracter = 'c' ;
    size_t tamanio_string1 = strlen(string1);
    for(size_t i = 0; i<(strlen(string2)+1);i++){
        string1[tamanio_string1 + i] = string2[i]; 
    }
    if(strcmp(string1,string3) > 0){
        caracter = 's';
    }
    return caracter;
}

int main(){
    char string[MAX_STRING];
    char string_2[MAX_STRING];
    char string_3[MAX_STRING];
    strcpy(string, "Algo");
    strcpy(string_2, "rito");
    strcpy(string_3, "Programa");
    printf("\n El resultado es : %c\n",ejercicio(string,string_2,string_3));
     strcpy(string, "Algo");
    strcpy(string_2, "ritmo");
    strcpy(string_3, "Algoritmo");
    printf("\n El resultado es : %c\n",ejercicio(string,string_2,string_3));
    strcpy(string, "Progra");
    strcpy(string_2, "ma");
    strcpy(string_3, "Algoritmo");
    printf("\n El resultado es : %c\n",ejercicio(string,string_2,string_3));
}