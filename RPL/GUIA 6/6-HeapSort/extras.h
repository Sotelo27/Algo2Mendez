#ifndef EXTRAS_H_
#define EXTRAS_H_

typedef int (*comparador_t)(const void*, const void*);

void sift_down(int* vector, int tope, int pos_actual, comparador_t comparador);
int heap_extraer_raiz(int* vector, int* tope, comparador_t comparador);

#endif // EXTRAS_H