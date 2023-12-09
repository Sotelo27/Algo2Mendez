/*
EJERCICIO 1

    El teorema maestro proporciona una solucion sencilla para ecuaciones de recurrencia que ocurren en algoritmos recursivos del tipo divide y venceras.
    Solo sirve para ciertos tipos de ecuaciones de recurrencia donde T(n) = aT(n/h) + n^c donde a >= 1 y b > 1

    N es el tamanio del problema.
    a es el numero de subproblemas en la recursion, es decir la cantidad de llamadas recursivas realizadas.
    b es cuanto se divide el problema para cada llamada recursiva.
    n/h implica cual es el tamanio de cada subproblema.
    F(n) = n^c es el costo de trabajo que se realizo fuera de la llamada recursiva, el costo de tiempo que tarda en dividir y combinar.

    En el caso del algoritmo visto analizaremos:

void mostrarPilaInvertida(pila_t* pila, void (*mostrar_elemento)(void*))
{
    if(pila_vacia(pila)) // verifica si esta vacia, pila_vacia es O(1)
        return;
    
    void* elemento = pila_desapilar(pila); // O(1)
    mostrarPilaInvertida(pila); // se realiza una llamada recursiva.
    mostrar_elemento(elemento); 
    pila_apilar(pila, elemento); // O(1)
}

La llamda recursiva se realizara de acuerdo a los n elementos de la pila, siendo asi que el timepo de la suma de las complejidades individuales de cada operacion para cada n elementos.

    Verificara si esta vacia , O(1) * n.
    Desapilara , O(1) * n.
    Llamada recursiva , n llamadas.
    Mostrara el elemento O(1)* n
    Apilara O(1)* n

Siendo asi, si se suma cada operacion O(1)*n (que es igual a O(n) quedaria O(5n), siendo asi que la complejidad de la misma redondeando seria O(n).

----
    EJERCICIO 2

    Quicksort es un tipo de ordenamiento , que utiliza una pila auxiliar y en casos ideales su complejidad es e O(nlog(n)).Su proceso consiste en la particion y reordenamiento del arreglo con las condiciones de que el elemento a[i] esta en un lugar definitivo del arreglo para algun valor de i, ninguno de los elementos a[1],a[2].... es mayor que a[i] y tampoco a[i+1] es menor que a[i].
    Pasos:

    Se elige el elemento de la lista que se llamara pivote.

    Se particiona la lista en tres listas.

    Lista 1 contiene los elementos de L menos v que sean menores o iguales al pivote, Lista 2 tendra el pivote y la Lista 3 contiene los elementos de L menos v que sean mayores o iguales al mismo pivote.

    Se aplica recursion sobre L1 y L3.

    se Unen todas las soluciones para dar una forma final a la lista ordenada
    Apliquemos al vector V = [1,6,9,4,7,2,3,0,8]; con el pivote siendo 4

    Tomamos el pivote , elemento central, V[4] = 7

    Reorganizamos los elementos

    V = [1, 6, 4, 0, 2, 3, 7, 9, 8]

    Dividimos en las sublistas , lista izquierda = [1, 6, 4, 0, 2, 3] y lista derecha = [9,8]

    Aplicamos Quicksort a cada lista:
    Lista Derecha = [9,8];
    Pivote = V[1] = 8;
    Reorganizamos = [8,9]
    Lista Izquierda = [[1, 6, 4, 0, 2, 3]
    Pivote = V[3] = 0;
    Reorganizamos = [0, 1, 6, 4, 2, 3]

    Continuar hasta el ordenamiento deseado , en el caso de la lista izquierda podriamos tomar a 4 como pivote, quedando los menores a la izquierda y 6 a su derecha, y luego tomariamos como pivote a 3, quedando ya de menor a mayor.

2)La complejidad en el caso ideal como se dijo anteriormente es O(nlog(n) pero su complejidad puede ser O(n^2) si la particion esta mas desbalanceada , siendo la primera particion (n-1) elementos,ocurriendo cuando el pivote elegido es el mas chico, o el mayor.Esto provoca que se hagan (n-1) llamadas recursivas y sumandolo, resulta en (n-1)/2.

------ 
EJERCICIO 5
Escriba de forma recursiva (sin utilizar while, for, etc) una función que reciba un vector de enteros, 
un tamaño del vector y otro entero y devuelva un nuevo vector (reservado con malloc) con todos los enteros encontrados iguales al tercer parámetro . Ejemplos:

    [1,2,3,4,5,6,2,3,4], 9, 2 -> [2,2]
    [1,2,1,1], 4, 1 -> [111]
    [1,2,3,4], 4, 9 -> []

No está permitido el uso de strlen o similares.
Se pueden utilizar funciones auxiliares. A efectos de este ejercicio, malloc y amigos nunca fallan.

int contar_ocurrencias(int vector[], int tam, int entero, int indice) {
    if (indice == tam) {
        return 0;
    } else {
        if (vector[indice] == entero) {
            return 1 + contar_ocurrencias(vector, tam, entero, indice + 1);
        } else {
            return contar_ocurrencias(vector, tam, entero, indice + 1);
        }
    }
}

void copiar_ocurrencias(int vector[], int tam, int entero, int indice, int *res, int res_indice) {
    if (indice == tam) {
        res[res_indice] = '\0'; // Agregar el terminador nulo al final del nuevo vector
        return;
    } else {
        if (vector[indice] == entero) {
            res[res_indice] = entero;
            copiar_ocurrencias(vector, tam, entero, indice + 1, res, res_indice + 1);
        } else {
            copiar_ocurrencias(vector, tam, entero, indice + 1, res, res_indice);
        }
    }
}

int* buscar_entero(int vector[], int tam, int entero) {
    int ocurrencias = contar_ocurrencias(vector, tam, entero, 0);
    int *resultado = (int *)malloc((ocurrencias + 1) * sizeof(int)); // +1 para el terminador nulo
    if (resultado == NULL) {
        return NULL;
    }

    copiar_ocurrencias(vector, tam, entero, 0, resultado, 0);

    return resultado;
}

void imprimir_vector(int vector[], int tam) {
    printf("[");
    for (int i = 0; i < tam; i++) {
        printf("%d", vector[i]);
        if (i != tam - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

int main() {
    int vector1[] = {1, 2, 3, 4, 5, 6, 2, 3, 4};
    int tam1 = 9;
    int entero1 = 2;

    int *resultado1 = buscar_entero(vector1, tam1, entero1);
    imprimir_vector(resultado1, contar_ocurrencias(vector1, tam1, entero1, 0));
    free(resultado1);

    int vector2[] = {1, 2, 1, 1};
    int tam2 = 4;
    int entero2 = 1;

    int *resultado2 = buscar_entero(vector2, tam2, entero2);
    imprimir_vector(resultado2, contar_ocurrencias(vector2, tam2, entero2, 0));
    free(resultado2);

    int vector3[] = {1, 2, 3, 4};
    int tam3 = 4;
    int entero3 = 9;

    int *resultado3 = buscar_entero(vector3, tam3, entero3);
    imprimir_vector(resultado3, contar_ocurrencias(vector3, tam3, entero3, 0));
    free(resultado3);

    return 0;
}


-----------------------------------
EJERCICIO 4




Un TDA (tipo de dato abstracto) es un modelo que define valores como tambien pueden definirse operaciones para realizarse en el mismo, los cuales son relevantes de acuerdo al problema.
A su conjunto de operaciones deberian haber denominados un minimo de operaciones, creandose una biblioteca con varias o una estructura relacionadas al dato.Puede tener beneficios como:

    El usuario no puede romper el codigo ya que no peude acceder, los casos bordes solo se generan por parametros recibidos en las funciones declaradas.

    Se encuentra modulizado.

    Quien lo utiliza no debe conocer internamente su funcionamento , solo conocer que puede hacer.

    Provee al usuario mayor flexibilizacion para programar, siendo que si una cambia no cambia todo , de alli el concepto de abstraccion.

// Definición del TDA Cajonera

// Definición de la estructura de un cajón
typedef struct {
    int capacidad; // Capacidad del cajón
    void *contenido; // Contenido del cajón
    int cantidad_elementos; // Cantidad de elementos en el cajón
} Cajon;

// Definición del TDA Cajonera
typedef struct {
    lista_t *cajones; // Arreglo de cajones
} Cajonera;

// Función para crear una cajonera
Cajonera *cajonera_crear() {
    Cajonera *nueva_cajonera = malloc(sizeof(Cajonera));
    
    nueva_cajonera->cajones = lista_crear(); 
    
    return nueva_cajonera;
}

// Función para destruir una cajonera
void cajonera_destruir(Cajonera *cajonera) {
    lista_destruir(cajonera->cajones); // Liberar cajones
    free(cajonera); // Liberar la estructura Cajonera
}

//Funcion que elimina un elemento de un cajon, primero guarda el cajon y iguala el contenido a 0, elimino ese cajon e inserto el nuevo cajon.
void cajoneta_quitar_elemento(Cajonera* cajonera,int posicion){
    Cajon* cajon;
    cajon = lista_elemento_en_posicion(cajonera->cajones,posicion);// busco en la posicion deseada.
    cajon->contenido = NULL;// lo elimino
    cajonera_quitar_cajon(cajonera,posicion);
    cajonera_agregar_cajon(cajonera,cajon->contenido,cajon->cantidad_elementos,cajon->capacidad);
}

//Busca elemento en el cajon
void cajonera_buscar_elemento(Cajonera* cajonera,int posicion){
    Cajon* cajon;
    cajon = lista_elemento_en_posicion(cajonera->cajones,posicion);// busco en la posicion deseada.
    return cajon->contenido;
}

// Función para agregar un elemento a la cajonera
int cajonera_agregar_cajon(Cajonera *cajonera, void *elemento,int cantidad_elementos,int capacidad) {
    Cajon* nuevoCajon = malloc(sizeof(Cajon));
    nuevoCajon->cantidad_elementos = cantidad_elementos;
    nuevoCajon->capacidad = capacidad;
    nuevoCajon->contenido = elemento;
    lista_insertar(cajonera->cajones,nuevoCajon);
    return lista_tamanio(cajonera->cajones);
}

// Función para quitar un elemento de la cajonera
int cajonera_quitar_cajon(Cajonera *cajonera, int posicion_cajon) {
    lista_quitar_de_posicion(cajonera->cajones,posicion_cajon);
    return lista_tamanio(cajonera->cajones);
}

// Función para obtener la cantidad de elementos en la cajonera
int cajonera_cantidad_elementos(Cajonera *cajonera) {
    return lista_tamanio(cajonera->cajones); // Retorna la cantidad de elementos en la cajonera
}

int main(){

    return 0;
}


*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int contar_ocurrencias(int vector[], int tam, int entero, int indice) {
    if (indice == tam) {
        return 0;
    } else {
        if (vector[indice] == entero) {
            return 1 + contar_ocurrencias(vector, tam, entero, indice + 1);
        } else {
            return contar_ocurrencias(vector, tam, entero, indice + 1);
        }
    }
}

void copiar_ocurrencias(int vector[], int tam, int entero, int indice, int *res, int res_indice) {
    if (indice == tam) {
        res[res_indice] = '\0'; // Agregar el terminador nulo al final del nuevo vector
        return;
    } else {
        if (vector[indice] == entero) {
            res[res_indice] = entero;
            copiar_ocurrencias(vector, tam, entero, indice + 1, res, res_indice + 1);
        } else {
            copiar_ocurrencias(vector, tam, entero, indice + 1, res, res_indice);
        }
    }
}

int* buscar_entero(int vector[], int tam, int entero) {
    int ocurrencias = contar_ocurrencias(vector, tam, entero, 0);
    int *resultado = (int *)malloc((ocurrencias + 1) * sizeof(int)); // +1 para el terminador nulo
    if (resultado == NULL) {
        return NULL;
    }

    copiar_ocurrencias(vector, tam, entero, 0, resultado, 0);

    return resultado;
}

void imprimir_vector(int vector[], int tam) {
    printf("[");
    for (int i = 0; i < tam; i++) {
        printf("%d", vector[i]);
        if (i != tam - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

int main() {
    int vector1[] = {1, 1, 1, 1, 1, 6, 2, 3, 4};
    int tam1 = 9;
    int entero1 = 1;

    int *resultado1 = buscar_entero(vector1, tam1, entero1);
    imprimir_vector(resultado1, contar_ocurrencias(vector1, tam1, entero1, 0));
    free(resultado1);

    int vector2[] = {1, 2, 1, 1};
    int tam2 = 4;
    int entero2 = 1;

    int *resultado2 = buscar_entero(vector2, tam2, entero2);
    imprimir_vector(resultado2, contar_ocurrencias(vector2, tam2, entero2, 0));
    free(resultado2);

    int vector3[] = {1, 2, 3, 4};
    int tam3 = 4;
    int entero3 = 9;

    int *resultado3 = buscar_entero(vector3, tam3, entero3);
    imprimir_vector(resultado3, contar_ocurrencias(vector3, tam3, entero3, 0));
    free(resultado3);

    return 0;
}
