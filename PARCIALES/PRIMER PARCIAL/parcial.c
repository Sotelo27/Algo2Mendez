/*
- 1) 

La complejidad computacional nos permite analizar/estudiar el coste de un algoritmo o cuantos `recursos computacionales` para resolver un problema, refiriendose al tiempo y espacio que se requiere.Los recursos podrian ser por ejemplo `el tiempo de computo ` o la `utilizacion de memoria` , asi con esto podemos saber cual manera de resolver el problema solicitado es el mas eficiente.
Relacionado a lo mencionado anteriormente, Big O es una notacion matematica que nos permite describir como se comporta una funcion de acuerdo a si tiende a un valor determinado o infinito su argumento.Si un tiempo de ejecucion fuese O(n) su maximo tiempo de ejecucion es k.f(n) con k siendo la constante,` dando el maximo que puede tardar el algoritmo`.

Un ejemplo simple seria:


```c
if(n ==0)
	print("Hola!");// instruccion_1 analizamos de acuerdo a que instrucciones se ejecutan.
for int(i = 0; i< n ; i++ ){
	instruccion_2; // Esra instruccion se ejecuta n veces
}

```

Con el algoritmo de ejemplo anterior, podriamos definir como el siguiente:

- T(n) (TIEMPO DE EJECUCION)

- T(n)=t1 + t2*n;


Algunos ejemplos de funciones:

- `c`:Constante.
- `logn`:Logaritmica.
-  `n` :Lineal.
- `!n` :Factorial.


- 2)

- La complejidad computacional del algoritmo 1 seria de O(n)  :

```c
int algoritmo1(int n)
{
    if(i <= 0) // destacar que no se definio correctamente el valor i, deberia escribirse : int i <= 0.
        return 0; // 1 instruccion.

    int acumulado = 1; // 1 instruccion.
    for(int i=0;i<n;i++) { // n
        acumulado *= algoritmo1(i-1); // 1 instruccion que se ejecuta n veces.
    }

    return acumulado; // 1 instruccion.
}
//Por lo tanto quedaria un total de n + 3 , ya que el valor dentro del if no se cuenta.
```
Pero , teniendo en cuenta de que siendo n + 3, la valor constante dejara de importar mientras mas grande sea n y mas se recorra, por lo tanto seria O(n) , lineal.

- Para el caso del algoritmo dos tendriamos que analizar 2 casos:

```c

int algoritmo2(int n) {
    for(int i = 0; i<n ; i++) { // n veces
        if(i < MAX_HOLAS) {
            for(int j=0;j<n;j++) {
                printf("Hola mundo");
            }
        }
        else {
            for(int j=n;j>0;j/=2) { // n veces
                printf("Chau mundo"); // 1 instruccion
            }
        }
    }
}

```
Para los dos casos, se ejecuta n veces inicialmente en el primer for, para luego, en caso de entrar en el if, 
tendria una complejidad de O(n^2), ya que el for dentro se ejecuta n veces hasta que `j<n`.Para de que entre en el else,
 el bucle if se ejecuto de igual manera, ya que , por ejemplo si MAX_HOLAS seria 1, entraria en el bucle if la primera vez.
 Por lo tanto tendriamos ya O(n^2), y recien entraria al else, que se ejecuta n veces hasta que n/2 > 0.
 Por lo tanto tendriamos que su complejidad seria de O(n^2) + n/2 El cual seria el peor de los casos.

-----------------------------------------EJERCICIO 2-----------------------------------

- 1)

El algoritmo de 'heapify' nos permite ordenar un determinado vector, como el dado en el ejemplo, como heap , el cual puede ser maximal o mininal, es decir, ordenarlo de una manera que el valor mas grande este arriba o el menor.

```c
V = [7, 9, 1, 2, 0, 5, 3, 2];
```

Tengamos en cuenta que queramos ordenarlo de manera maximal, mediante el proceso de sift up, en el cual subiremos comparando la posicion padre con el siguiente, podemos definir algo como lo siguiente


```c
void sift_up(int *vector,int posicion){
        if (posicion == 0){
                return; 
        }
        int post_padre = (posicion - 1) / 2; // obtenemos el padre, se redondea hacia abajo.
        if(vector[post_padre] < vector[posicion]){ //comparamos con el padre.
                int padre = vector[post_padre];  
                vector[post_padre] = vector[posicion]; // si es mayor, la posicion del padre toma la posicion actual.
                vector[posicion] = padre; //al ser menor el padre, toma la posicion de abajo.
                sift_up(vector,post_padre); 
        }
}
```

y la funcion de heapify podriamos definir asi:

```c
void heapify (int*vector,int tamanio){
        int tope = 0;

        while (tope < tamanio){
                sift_up(vector,tope); // primero llamamos a la funcion que verifique.
                tope++; // seguimos recorriendo.
        }
}
```

La cual misma funcion comparara los valores del vector, para ordenarlo de manera maximal.Por lo tanto, el estado del vector paso a paso seria :

```c
V = [7, 9, 1, 2, 0, 5, 3, 2]; // inicial
V = [9,7,1,2,0,5,3,2] // Una vez comparado con el padre que en ese momento seria el 7
V = [9,7,1,2,0,5,3,2]
V = [9,7,1,2,0,5,3,2]
V = [9,7,1,2,0,5,3,2]
V = [9,7,5,2,0,1,3,2]
V = [9,7,5,2,0,1,3,2]//Finalizado y ordenado de manera maximal
```
Como finalizacion , la complejidad de este procedimiento seria (O(n logn)) usando sift up, siendo menos eficiente que utilizar el sift down sobre el vector, (O(n))

 ---

- 2)

Heapsort es un tipo de ordenamiento utilizando las propiedades que poseen los heap, y asi podemos ordenar los elementos del mismo.Para ello le damos forma de heap a un arreglo (teniendo coste computacional 0(n) ya que recorremos todo), luego buscamos el maximo (siendo la posicion 0 no tendria mas que un costo de 0(1) y cambiamos el valor del primero con el ultimo (tambien 0(1))Asi aplicamos un sift down al padre (O(logn) como se explico anteriormente).Si finalmente hay elementos aun por ordenar, volvemos a iniciar el proceso (salteando la parte de darle forma de heap).
Por lo tanto la complejidad final seria de O(nlogn) teniendo en cuenta que debemos primero darle forma de heap, y luego aplicar el sift - down.
-------------------------EJERCICIO 5----------------------------------------------------------------------

bool string_has_4_or_fewer_characters(char* str) {
    if (str == NULL) {
        return false;
    }
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length <= 4;
}

bool begins_with_l(char* str) {
    if (str == NULL || str[0] == '\0') {
        return false;
    }
    return str[0] == 'L';
}

char** filtrar_auxiliar(char** vector, bool (*filtro)(char*), int posicion_actual, int posicion_resultante) {
    if (vector[posicion_actual] == NULL) {
        vector[posicion_resultante] = NULL; // aca verifico el null, que me indica el final del vector
        return vector;
    }
    
    if (filtro(vector[posicion_actual])) { // compruebo de acuerdo a la funcion f, si es true 
        vector[posicion_resultante] = vector[posicion_actual]; // toma el valor
        return filtrar_auxiliar(vector, filtro, posicion_actual + 1, posicion_resultante + 1); //continua su recursividad
    } else {
        return filtrar_auxiliar(vector, filtro, posicion_actual + 1, posicion_resultante);
    }
}

char** filtrar(char** vector, bool (*filtro)(char*)){
        return filtrar_auxiliar(vector,filtro,0,0); // utilizo una funcion auxiliar , inicializo en 0 las posiciones.
        
}

int main()
{
        char* v1[] = {"Hola", "World", "ABC", "DEFGH", "123", "456", NULL};
        char* v2[] = {"Lucas", "Mariano", "Lorenzo", "Azul", NULL};

        char** result1 = filtrar(v1, string_has_4_or_fewer_characters);
        char** result2 = filtrar(v2, begins_with_l);

        // Print the filtered results
        for (int i = 0; result1[i] != NULL; i++) {
                printf("%s\n", result1[i]);
        }

       for (int i = 0; result2[i] != NULL; i++) {
               printf("%s\n", result2[i]);
        }

}

----------------------------EJERCICIO 4------------------------------------------

Explique con sus palabras qué es un TDA.

Desarrolle el TDA Libreta de direcciones que permita hacer cosas que se pueden hacer con una libreta de direcciones (por lo menos 4 operaciones diferentes, creación y destrucción no cuentan como operaciones). Di

    Muestre el contrato (en forma de código) del TDA y justifique por qué cada una de las operaciones debe ser parte del TDA.
    Implemente las 4 operaciones definidas.
    Por lo menos una de las operaciones debe permitir buscar una persona por nombre en la libreta.
    Discuta la complejidad computacional de cada una de las 4 operaciones implementadas.
    Se pueden utilizar TDAs de los vistos en la materia si es necesario.
    Para este ejercicio se puede suponer que las operaciones de memoria (malloc y amigos) no fallan.

Consejo: Piense en la definición de TDA y tenga en cuenta al definir el contrato si las operaciones tienen o no sentido para el TDA. Piense en qué datos son necesarios para las operaciones.


*/

/*
correccion:
-----------------------

EJERCICIO 1

EL ALGORITMO 2 ES O(N*LOG(N))
EL ALGORITMO 1 ES 2^N
------------------

EJERCICIO 4

typedef struct{
    char nombreCompleto[50];
    char domicilio[20];
}contacto_t

typedef struct{
    abb_t* contactos;
}Libreta

Libreta* libretra_crear(){
    Libreta *l = malloc(sizeof(libreta));
    l->contactos = abb_crear(comparador_contactos)
}

int libreta_agregrar_contacto(Libreta *l,char *nombreCompleto,char*domicilio){
    contacto_t* nuevoContacto = malloc(sizeof(contacto_t));
    strcpy(nuevoContacto->nombreCompleto,nombreCompleto);
    strcpy(nuevoContacto->domicilio,domicilio);
    if(abb_buscar(l.contactos,nuevoContacto) != NULL){
        return -1;
    }
    abb_insertar(l->contactos,nuevoContacto);
    return abb_tamanio(l->contactos);
}

contacto_t* libreta_buscar_contacto(libreta*; , char*nombreCOmpleto){
    contacto_t nuevoContacto;
    strcpy(nuevoContacto.nombreCompleto,nombreCompleto);
    return abb_buscar(l.contactos,&nuevoCOntacto);
}
int libreta_eliminar_contacto(libreta*l,char*nombreCompleto){
    contacto_t nuevoContacto;
    strcpy(nuevoContacto.nombreCOmpleto,nombreCompleto);
    abb_quitar(l.contactos,&nuevoContacto);
    return abb_tamanio(l.contactos);
}
int libreta_cantidad_contactos(libreta *l){
    return abb_tamanio(l.contactos);
}

En el PUNTO H VA: 

las funciones de antes mas :
libreta_destruir(Libreta*);

------------------

EJERCICIO 3

struct rojo{
    struct rojo*izq;
    struct rojo*derech;
    struct rojo**medio;
}

int main(){
    struct rojo * rojos[4];
    struct rojo ** vector = calloc(4,sizeof(rojo*));
    rojos[0] = calloc(1,sizeof(structrojo));
    rojos[1] = calloc(1,sizeof(structrojo));
    rojos[2] = calloc(1,sizeof(structrojo));
    rojos[3] = calloc(1,sizeof(structrojo));
    if(!vector || rojos[0] || rojos[1] || rojos[2] || rojos[3]){
        free(vector);
        free(rojos[0]);
        free(rojos[1]);
        free(rojos[2]);
        free(rojos[3]);
    }
    // todo reservado

    for(int i = 0;i < 4 ; i ++){
        vector[i] = rojos[i];
    }

    for (int i = 0; i< 4 ; i++){
        rojos[i].der = rojos[modulo(i+1,4)];
        rojos[i].izq = rojos[modulo(i-1,4)];
        rojos[i].medio = vector+modulo(i+2,4);
    }

    struct rojo * una_cosa = rojos[0];

    free(vector);
        free(rojos[0]);
        free(rojos[1]);
        free(rojos[2]);
        free(rojos[3]);
}

*/

#include <stdio.h>
#include <stdbool.h>

int main(){

}