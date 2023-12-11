/*
Ya entendimos sift_up y cómo usarla en heap_insertar. 
Pasemos a entender sift_down, que de manera análoga nos sirve para heap_extraer_raiz.

Se recibe el vector de enteros, el tope del mismo y la posición a partir de la cual hay que aplicar la función.
*/
void sift_down(int* vector, int tope, int pos_actual) {
    int hijo_izq, hijo_der, hijo_mayor, temp;
    int seguir = 1;

    while (seguir) {
        hijo_izq = (pos_actual * 2) + 1;
        hijo_der = (pos_actual * 2) + 2;
        hijo_mayor = pos_actual;

        if (hijo_izq < tope && vector[hijo_izq] > vector[hijo_mayor]) {
            hijo_mayor = hijo_izq;
        }

        if (hijo_der < tope && vector[hijo_der] > vector[hijo_mayor]) {
            hijo_mayor = hijo_der;
        }

        if (hijo_mayor != pos_actual) {
            temp = vector[pos_actual];
            vector[pos_actual] = vector[hijo_mayor];
            vector[hijo_mayor] = temp;

            pos_actual = hijo_mayor;
        } else {
            seguir = 0;
        }
    }
}