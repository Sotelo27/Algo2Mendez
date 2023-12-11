#include "extras.h"

void swap(int *vector, int pos1, int pos2)
{
	int aux = vector[pos1];
	vector[pos1] = vector[pos2];
	vector[pos2] = aux;
}

void sift_down(int *vector, int tope, int pos_actual, comparador_t comparador)
{
	int hijo_derecho = 2 * pos_actual + 2;
	int hijo_izquierdo = 2 * pos_actual + 1;
	if (hijo_izquierdo > tope - 1) //0 hijos
		return;

	int pos_menor = hijo_izquierdo;

	if (hijo_derecho <= tope - 1) {
		if (comparador(&vector[hijo_derecho], &vector[hijo_izquierdo]) < 0)
			pos_menor = hijo_derecho;
	}

	if (comparador(&vector[pos_menor], &vector[pos_actual]) < 0) {
		swap(vector, pos_actual, pos_menor);
		return sift_down(vector, tope, pos_menor, comparador);
	}
}

int heap_extraer_raiz(int *vector, int *tope, comparador_t comparador)
{
	if (*tope == 0 || !vector)
		return 0;

	int aux = vector[0];
	vector[0] = vector[*tope - 1];
	vector[*tope - 1] = aux;
	(*tope)--;

	sift_down(vector, *tope, 0, comparador);

	return aux;
}