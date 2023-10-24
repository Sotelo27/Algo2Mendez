#include "pa2m.h"
#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void prueba_creacion_lista_vacia()
{
	lista_t *lista = NULL;
	pa2m_afirmar((lista = lista_crear()) != NULL, "Se Creo una lista");
	printf("\nComprobamos si esta vacia\n");
	pa2m_afirmar((lista_vacia(lista)), "La Lista si se encuentra vacia");
	pa2m_afirmar((lista_tamanio(lista) == 0), "El tamanio si es 0");
	printf("\nProbamos con una lista del tipo NULL\n");
	pa2m_afirmar(lista_tamanio(NULL) == 0,
		     "Una lista de tipo NULL si tiene tamanio 0");
	printf("\nProbamos si el primero y el ultimo elemento son NULL\n");
	pa2m_afirmar(!lista_primero(lista),
		     "Si esta vacia el primer elemento devolvera NULL");
	pa2m_afirmar(!lista_ultimo(lista),
		     "Si esta vacia el ultimo elemento sera NULL");
	pa2m_afirmar(lista_quitar(NULL) == NULL,
		     "Al quitar un elemento de una lista NULL no se quita");
	printf("\nDestruyo la lista\n");
	lista_destruir(lista);
}

bool comprobar_elementos(void *elemento, void *contador)
{
	return true;
}

//PRUEBAS DE ITERACION
void iterar_internamente_en_lista()
{
	lista_t *lista = lista_crear();
	for (int i = 0; i < 100; i++) {
		int *elemento = malloc(sizeof(int));
		if (elemento) {
			*elemento = i + 1;
		}
		lista_insertar(lista, (void *)elemento);
	}
	int tope = 1000;
	size_t elementos_recorridos = lista_con_cada_elemento(
		lista, comprobar_elementos, (void *)&tope);
	pa2m_afirmar(
		elementos_recorridos == lista_tamanio(lista),
		"Se recorrio toda la lista correctamente con el iterador interno");
	tope = 25;
	elementos_recorridos = lista_con_cada_elemento(
		lista, comprobar_elementos, (void *)&tope);
	pa2m_afirmar(
		elementos_recorridos == lista_tamanio(lista),
		"Se recorrio parcialmente toda la lista correctamente con el iterador interno");
	pa2m_afirmar(lista_con_cada_elemento(lista, NULL, (void *)&tope) == 0,
		     "Si el puntero a funcion es NULL devuelve 0");
	pa2m_afirmar(lista_con_cada_elemento(NULL, comprobar_elementos,
					     (void *)&tope) == 0,
		     "Si el puntero a lista es NULL devuelve 0");
	lista_destruir_todo(lista, free);
}

void iterar_externamente_en_lista()
{
	lista_t *lista = lista_crear();
	pa2m_afirmar(!lista_iterador_crear(NULL),
		     "Si la Lista es NULL no se crea");
	pa2m_afirmar(!lista_iterador_avanzar(NULL),
		     "Si la lista es NULL no la avanza");
	pa2m_afirmar(!lista_iterador_elemento_actual(NULL),
		     "Si la lista es NULL su elemento es nulo");
	for (int i = 0; i < 100; i++) {
		int *elemento = malloc(sizeof(int));
		if (elemento) {
			*elemento = i + 1;
		}
		lista_insertar(lista, (void *)elemento);
	}
	int elementos_recorridos = 0;
	lista_iterador_t *iterador;
	for (iterador = lista_iterador_crear(lista);
	     lista_iterador_tiene_siguiente(iterador);
	     lista_iterador_avanzar(iterador)) {
		elementos_recorridos++;
	}
	pa2m_afirmar(
		elementos_recorridos == lista_tamanio(lista),
		"Se recorrio toda la lista correctamente con el iterador externo");
	lista_iterador_destruir(iterador);
	lista_destruir_todo(lista, free);
}

//PRUEBAS DE INSERCION Y BORRAR
void insertar_elementos_lista()
{
	lista_t *lista = lista_crear();
	int elementos[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	lista_insertar(lista, &elementos[0]);
	pa2m_afirmar(lista_primero(lista) != NULL,
		     "Se pudo aniadir correctamente el valor");
	pa2m_afirmar(lista_tamanio(lista) == 1,
		     "EL tamanio es el correcto de 1");
	lista_insertar(lista, &elementos[1]);
	pa2m_afirmar(lista_tamanio(lista) == 2,
		     "EL tamanio es el correcto de 2");
	lista_insertar(lista, &elementos[2]);
	pa2m_afirmar(lista_tamanio(lista) == 3,
		     "EL tamanio es el correcto de 3");
	lista_insertar(lista, &elementos[3]);
	pa2m_afirmar(lista_tamanio(lista) == 4,
		     "EL tamanio es el correcto de 4");
	lista_insertar(lista, &elementos[4]);
	pa2m_afirmar(lista_tamanio(lista) == 5,
		     "EL tamanio es el correcto de 5");
	lista_insertar(lista, &elementos[5]);
	pa2m_afirmar(lista_tamanio(lista) == 6,
		     "EL tamanio es el correcto de 5");
	pa2m_afirmar(lista_primero(lista) == &elementos[0],
		     "El elemento numero 1 es el correcto");
	lista_insertar_en_posicion(lista, &elementos[2], 3);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 3) == &elementos[2],
		     "El elemento insertado en la posicion 3 es el correcto");
	pa2m_afirmar(
		lista_tamanio(lista) == 7,
		"EL tamanio es el correcto de 7 tras insertar en una posicion con elemento");
	lista_insertar_en_posicion(lista, &elementos[5], 4);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 4) == &elementos[5],
		     "El elemento insertado en la posicion 4 es el correcto");
	pa2m_afirmar(
		lista_tamanio(lista) == 8,
		"EL tamanio es el correcto de 8 tras insertar en una posicion con elemento");
	lista_insertar_en_posicion(lista, &elementos[7], 0);
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == &elementos[7],
		     "El elemento insertado en la posicion 0 es el correcto");
	pa2m_afirmar(
		lista_tamanio(lista) == 9,
		"EL tamanio es el correcto de 9 tras insertar en una posicion con elemento");
	lista_insertar_en_posicion(lista, &elementos[10], lista_tamanio(lista));
	pa2m_afirmar(
		lista_elemento_en_posicion(lista, 9) == &elementos[10],
		"El elemento insertado en la ultima posicion es el correcto");
	pa2m_afirmar(lista_ultimo(lista) == &elementos[10],
		     "El elemento ultimo es el correcto");
	lista_destruir(lista);
}

void eliminar_elementos_lista()
{
	lista_t *lista = lista_crear();
	int elementos[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	lista_insertar(lista, &elementos[0]);
	lista_insertar(lista, &elementos[1]);
	lista_insertar(lista, &elementos[2]);
	lista_insertar(lista, &elementos[3]);
	lista_insertar(lista, &elementos[4]);
	size_t tamanio_inicial = lista_tamanio(lista);
	void *ultimo_elemento = lista_ultimo(lista);
	lista_quitar(lista);
	pa2m_afirmar(lista_tamanio(lista) == tamanio_inicial - 1,
		     "Se a eliminado un elemento de la lista");
	pa2m_afirmar(lista_ultimo(lista) != ultimo_elemento,
		     "Se actualizo el ultimo elemento de la lista");
	void *primer_elemento = lista_primero(lista);
	lista_quitar_de_posicion(lista, 0);
	pa2m_afirmar(lista_primero(lista) != primer_elemento,
		     "Se actualizo el primer elemento de la lista");
	ultimo_elemento = lista_ultimo(lista);
	pa2m_afirmar(
		lista_quitar_de_posicion(lista, 1000) == ultimo_elemento,
		"Al sacar de una posicion mayor a la del tamanio quita el ultimo elemento");
	tamanio_inicial = lista_tamanio(lista);
	lista_quitar_de_posicion(lista, 2);
	pa2m_afirmar(
		lista_tamanio(lista) == tamanio_inicial - 1,
		"Se a eliminado un elemento de la lista arbitrario y su tamanio es el correcto");
	lista_destruir(lista);
}

//PRUEBAS DE TDA

void prueba_TDA_cola()
{
	cola_t *cola = cola_crear();
	int elementos[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	pa2m_afirmar(cola != NULL, "Se a creado correctamente la cola");
	pa2m_afirmar(cola_tamanio(cola) == 0, "La cola se encuentra vacia");

	cola_encolar(cola, &elementos[0]);
	cola_encolar(cola, &elementos[1]);
	cola_encolar(cola, &elementos[2]);
	cola_encolar(cola, &elementos[3]);
	cola_encolar(cola, &elementos[4]);

	pa2m_afirmar(cola_tamanio(cola) == 5,
		     "El tamanio del TDA cola es el correcto");

	void *desencolado = cola_desencolar(cola);
	pa2m_afirmar(*(char *)desencolado == elementos[0],
		     "Se quita el primer elemento de la cola correctamente");
	pa2m_afirmar(*(char *)cola_frente(cola) == elementos[1],
		     "El primer elemento es el correcto");
	pa2m_afirmar(!cola_vacia(cola),
		     "La cola tiene aun elementos, y no esta vacia");

	cola_destruir(cola);
}

void prueba_TDA_pila()
{
	pila_t *pila = pila_crear();
	int elementos[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	pa2m_afirmar(pila != NULL, "Se a creado correctamente la pila");
	pa2m_afirmar(pila_tamanio(pila) == 0, "La pila se encuentra vacia");

	pila_apilar(pila, &elementos[0]);
	pila_apilar(pila, &elementos[1]);
	pila_apilar(pila, &elementos[2]);
	pila_apilar(pila, &elementos[3]);
	pila_apilar(pila, &elementos[4]);

	pa2m_afirmar(pila_tamanio(pila) == 5,
		     "El tamanio del TDA cola es el correcto");

	void *desapilado = pila_desapilar(pila);
	pa2m_afirmar(*(char *)desapilado == elementos[4],
		     "Se quita el primer elemento de la cola correctamente");
	pa2m_afirmar(*(char *)pila_tope(pila) == elementos[3],
		     "El primer elemento es el correcto");
	pa2m_afirmar(!pila_vacia(pila),
		     "La cola tiene aun elementos, y no esta vacia");

	pila_destruir(pila);
}

int main()
{
	pa2m_nuevo_grupo("\nPRUEBA LISTA CREANDO\n");
	prueba_creacion_lista_vacia();
	pa2m_nuevo_grupo("\nPRUEBA DE INSERCION\n");
	insertar_elementos_lista();
	pa2m_nuevo_grupo("\nPRUEBA DE BORRADO\n");
	eliminar_elementos_lista();
	pa2m_nuevo_grupo("\nPRUEBA DE ITERACION INTERNA\n");
	iterar_internamente_en_lista();
	pa2m_nuevo_grupo("\nPRUEBA DE ITERACION EXTERNA\n");
	iterar_externamente_en_lista();
	pa2m_nuevo_grupo("\nPRUEBA DE TDA COLA\n");
	prueba_TDA_cola();
	pa2m_nuevo_grupo("\nPRUEBA DE TDA PILA\n");
	prueba_TDA_pila();
	return pa2m_mostrar_reporte();
}