/*
En esta guía, buscamos programar las funciones más importantes del heap. 
Para eso, iremos paso por paso programando lo que necesitamos y asegurándonos de que funciona, antes de pasar a la siguiente parte. 
En la página de la materia hay un apunte donde se explica la lógica de cada una de las funciones que implementaremos.

Uno de los primeros métodos que se elige programar de un tda es el insertar. 
Para implementar la versión de esta función en el heap, es conveniente empezar con esta función, sift_up. 
Se recibe el vector de enteros y la posicion a partir de la cual se debe hacer sift_up.

No te confundas, no estás programando heap_insertar todavía. 
Esa función es la del siguiente ejercicio, ahora estás programando sift_up, que será muy útil para heap insertar.

Aclaración: en todos los ejercicios, supondremos que se tiene un heap maximal.
*/

void sift_up(int* vector, int pos_actual) {
    int temp = vector[pos_actual]; // Almacenar el valor actual
    int padre = (pos_actual - 1) / 2; // Calcular la posición del padre

    // Mientras no se alcance la raíz y el valor del padre sea menor que el valor a insertar
    while (pos_actual > 0 && vector[padre] < temp) {
        vector[pos_actual] = vector[padre]; // Mover el valor del padre hacia abajo
        pos_actual = padre; // Actualizar la posición actual
        padre = (pos_actual - 1) / 2; // Calcular la nueva posición del padre
    }

    vector[pos_actual] = temp; // Colocar el valor en su posición final
}