/*
En el apunte de punteros a función y en las clases prácticas se vio que es posible programar un sort que pueda ordenar cualquier vector,
 independientemente del tipo de dato que él almacene.

Como siempre, para realmente entender un concepto, hay que ponerlo en práctica. Así que programemos un sort que pueda ordenar un vector de punteros a void*;
 es decir, un sort que pueda ordenar un vector de punteros, y esos punteros pueden apuntar a cualquier tipo de dato.

Para lograrlo, se tiene la firma de esta función, que recibe el vector de punteros, el tope de ese vector y una función que compara dos elementos del vector.
 La función comparadora devuelve un valor positivo si el primer elemento debería ir primero o un valor negativo si el segundo debería ir primero.
  En caso de que sean iguales, se devuelve 0. 
  Es decir, si a la función comparadora le llega A como primer parámetro y B como segundo, y A debe ir primero, se devuelve un valor positivo; si B debe ir primero,
   se devuelve un número negativo.
*/
void sort_semi_generico(void** vector, int cant_elementos, int (*comparador) (void*, void*)){
    if (!vector || !comparador){
        return;
    }
    for(int i = 0; i < cant_elementos ; i ++){
        for (int j = 0; j < cant_elementos-1-i ; j++){
            if (comparador(vector[j],vector[j+1]) < 0){
                void *aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}