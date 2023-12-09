//#include "solucion.h"
#include <stdio.h>

#define MAX_VECTOR 10

/*
 * Se recibe un vector de letras, su tope y la letra a buscar.
 * Se devuelve la posición de la letra o -1 en caso de que no se encuentre.
*/
int posicion_letra(char vector[MAX_VECTOR], int tope, char letra){
    //tu código
    int posicion = 0;
    int i = 0;
    int encontrado = 0;
    while(i < tope && encontrado!= 1 ){
        if(vector[i] == letra){
            posicion = i;
            encontrado = 1;
        }else{
            posicion = -1;
        }
        i++;
    }
    return posicion;
}

int main(){
    int valor = 0;
    char vector []={'W','B','C','D','A','F','G','H','T','U'};
    printf("\nLa letra es: %c\n",vector[0]);
    valor = posicion_letra(vector,10,'A');
    printf("\n La posicion es %d\n",valor);
    return 0;
}