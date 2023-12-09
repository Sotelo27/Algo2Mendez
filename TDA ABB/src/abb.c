#include "abb.h"
#include "abb_estructura_privada.h"
#include <stddef.h>
#include <stdlib.h>

abb_t *abb_crear(abb_comparador comparador)
{
	if (!comparador)
		return NULL;

	abb_t *arbol = calloc(1, sizeof(abb_t));
	if (!arbol)
		return NULL;
	arbol->comparador = comparador;
	arbol->nodo_raiz = NULL;
	arbol->tamanio = 0;
	return arbol;
}

//FUNCION DE LAUTARO MARTIN SOTELO

//PRE: RECIBE LA RECIBE LA RAIZ, EL ELEMENTO A INSERTAR Y EL COMPARADOR.
//POST: INSERTA EL ELEMENTO , EN EL NODO EN EL LUGAR QUE LE CORRESPONDE, EN CASO DE REPETIDO SE CONSIDERA LA POSICION IZQUIERDA.

nodo_abb_t *abb_insertar_nodo(nodo_abb_t *raiz, void *elemento,
			      abb_comparador comparador)
{
	if (!raiz) {
		raiz = malloc(sizeof(nodo_abb_t));
		if (!raiz) {
			return NULL;
		}
		raiz->derecha = NULL;
		raiz->izquierda = NULL;
		raiz->elemento = elemento;
		return raiz;
	}
	if (comparador(elemento, raiz->elemento) <= 0) {
		raiz->izquierda = abb_insertar_nodo(raiz->izquierda, elemento,
						    comparador);
	} else {
		raiz->derecha =
			abb_insertar_nodo(raiz->derecha, elemento, comparador);
	}
	return raiz;
}

abb_t *abb_insertar(abb_t *arbol, void *elemento)
{
	if (!arbol)
		return NULL;
	if (arbol) {
		arbol->nodo_raiz = abb_insertar_nodo(arbol->nodo_raiz, elemento,
						     arbol->comparador);
		arbol->tamanio++;
	}

	return arbol;
}

//FUNCION DE LAUTARO MARTIN SOTELO
//PRE : RECIBE EL NODO ACTUAL
//POST : BUSCA EN EL LADO DERECHO (MAYORES) EL MAYOR.

nodo_abb_t *buscar_predecesor_inorden(nodo_abb_t *nodo)
{
	if (nodo->derecha) {
		return buscar_predecesor_inorden(nodo->derecha);
	}
	return nodo;
}

//FUNCION DE LAUTARO MARTIN SOTELO

//PRE: RECIBE EL ARBOL, EL ELEMENTO BUSCADO A ELIMINAR Y EL NODO ACTUAL.
//POST:EVALUA LAS DIFERENTES CONDICIONES, Y CUANDO LIBERA LA MEMORIA DEL NODO DONDE SE ENCUENTRA EL NODO BUSCADO, CORRIGE LA REFERENCIA DEL NODO PADRE(SI POSEE HIJOS).

nodo_abb_t *eliminar_nodo(abb_t *arbol, nodo_abb_t *nodo,
			  void *elemento_buscado)
{
	if (!nodo)
		return NULL;
	if (arbol->comparador(nodo->elemento, elemento_buscado) == 0) {
		if (!nodo->izquierda) {
			nodo_abb_t *aux = nodo->derecha;
			free(nodo);
			return aux;
		} else if (!nodo->derecha) {
			nodo_abb_t *aux = nodo->izquierda;
			free(nodo);
			return aux;
		} else if (nodo->derecha && nodo->izquierda) {
			nodo_abb_t *predecesor_inmediato =
				buscar_predecesor_inorden(nodo->izquierda);
			nodo->elemento = predecesor_inmediato->elemento;
			nodo->izquierda =
				eliminar_nodo(arbol, nodo->izquierda,
					      predecesor_inmediato->elemento);
		}
	} else if (arbol->comparador(nodo->elemento, elemento_buscado) > 0) {
		nodo->izquierda =
			eliminar_nodo(arbol, nodo->izquierda, elemento_buscado);
	} else if (arbol->comparador(nodo->elemento, elemento_buscado) < 0) {
		nodo->derecha =
			eliminar_nodo(arbol, nodo->derecha, elemento_buscado);
	}
	return nodo;
}

void *abb_quitar(abb_t *arbol, void *elemento)
{
	if (!arbol)
		return NULL;
	void *elemento_eliminado = abb_buscar(arbol, elemento);
	arbol->nodo_raiz = eliminar_nodo(arbol, arbol->nodo_raiz, elemento); 
	arbol->tamanio--;
	return elemento_eliminado;
}

//FUNCION DE LAUTARO MARTIN SOTELO

//PRE: RECIBE EL NODO BUSCADO, EL ELEMENTO QUE SE DESEA BUSCARSE Y EL COMPARADOR.
//POST: EVALUA LAS DIFERENTES CONDICIONES, POR LADO IZQUIERDO Y POR LADO DERECHO, EN CASO DE ENCONTRAR SE DEVOLVERA EL NODO ACTUAL, CASO CONTRARIO NULL.

void *abb_buscar_nodo(nodo_abb_t *nodo_buscado, void *elemento,
		      abb_comparador comparador)
{
	if (!nodo_buscado) {
		return NULL;
	}
	if (comparador(elemento, nodo_buscado->elemento) < 0) {
		return abb_buscar_nodo(nodo_buscado->izquierda, elemento,
				       comparador);
	} else if (comparador(elemento, nodo_buscado->elemento) > 0) {
		return abb_buscar_nodo(nodo_buscado->derecha, elemento,
				       comparador);
	}
	return nodo_buscado;
}

void *abb_buscar(abb_t *arbol, void *elemento)
{
	if (!arbol)
		return NULL;
	nodo_abb_t *nodo_buscado =
		abb_buscar_nodo(arbol->nodo_raiz, elemento, arbol->comparador);
	if (!nodo_buscado)
		return NULL;
	return nodo_buscado->elemento;
}

bool abb_vacio(abb_t *arbol)
{
	if (!arbol || !arbol->nodo_raiz)
		return true;
	return false;
}

size_t abb_tamanio(abb_t *arbol)
{
	if (!arbol)
		return 0;
	return arbol->tamanio;
}

//FUNCION DE LAUTARO MARTIN SOTELO
//PRE: RECIBE LA FUNCION DESTRUCTURA Y EL NODO ACTUAL.
//POST: SI EXISTE EL NODO , VERIFICA SI EXISTE DERECHA O IZQUIERDA Y APLICARA LA FUNCION DESTRUCTURA SI APLICA.

void abb_destruir_hijos(nodo_abb_t *nodo, void (*destructor)(void *))
{
	if (nodo) {
		if (nodo->izquierda)
			abb_destruir_hijos(nodo->izquierda, destructor);
		if (nodo->derecha)
			abb_destruir_hijos(nodo->derecha, destructor);
		if (destructor) //valida si existe, dicha validacion sirve para modular las 2 funciones destructuras.
			destructor(nodo->elemento);
	}
	free(nodo);
}

void abb_destruir(abb_t *arbol)
{
	if (!arbol)
		return;
	abb_destruir_hijos(arbol->nodo_raiz, NULL);
	free(arbol);
}

void abb_destruir_todo(abb_t *arbol, void (*destructor)(void *))
{
	if (!arbol)
		return;
	abb_destruir_hijos(arbol->nodo_raiz, destructor);
	free(arbol);
}

//FUNCION DE LAUTARO MARTIN SOTELO
//PRE : RECIBE EL NODO, LA FUNCION QUE BUSCA APLICARSE, EL CONTADOR DE ELEMENTOS ,
//UNA VARIABLE AUX Y EL BOOLEANO SEGUIR_CORRIENDO QUE DETERMINA
//HASTA CUANDO SE ITERA.
//POST: SIGUIENDO EL METODO DE RECORRER EN POSTORDEN, SE RECORRE EL IZQUIERDO,
//LUEGO EL DERECHO Y LA RAIZ POR ULTIMO.SI LA FUNCION RETORNA FALSE PARA DE ITERAR.

void recorrer_postorden_con_cada_elemento(nodo_abb_t *nodo,
					  bool (*funcion)(void *, void *),
					  void *aux, size_t *contador_elementos,
					  bool *seguir_recorriendo)
{
	if (!nodo || !(*seguir_recorriendo))
		return;
	if (nodo->izquierda && (*seguir_recorriendo)) {
		recorrer_postorden_con_cada_elemento(nodo->izquierda, funcion,
						     aux, contador_elementos,
						     seguir_recorriendo);
	}
	if (nodo->derecha && (*seguir_recorriendo)) {
		recorrer_postorden_con_cada_elemento(nodo->derecha, funcion,
						     aux, contador_elementos,
						     seguir_recorriendo);
	}
	if (!nodo || !(*seguir_recorriendo))
		return;
	if ((*seguir_recorriendo)) {
		(*contador_elementos)++;
	}
	if (funcion(nodo->elemento, aux) == false) {
		*seguir_recorriendo = false;
		return;
	}
}

//FUNCION DE LAUTARO MARTIN SOTELO

//PRE : RECIBE EL NODO, LA FUNCION QUE BUSCA APLICARSE, EL CONTADOR DE ELEMENTOS ,
//UNA VARIABLE AUX Y EL BOOLEANO SEGUIR_CORRIENDO QUE DETERMINA
//HASTA CUANDO SE ITERA.
//POST: SIGUIENDO EL METODO DE RECORRER EN INORDEN, SE RECORRE EL IZQUIERDO,
//LUEGO LA RAIZ Y LA DERECHA POR ULTIMO.SI LA FUNCION RETORNA FALSE PARA DE ITERAR.

void recorrer_inorden_con_cada_elemento(nodo_abb_t *nodo,
					bool (*funcion)(void *, void *),
					void *aux, size_t *contador_elementos,
					bool *seguir_recorriendo)
{
	if (!nodo || !*seguir_recorriendo)
		return;
	if (nodo->izquierda && (*seguir_recorriendo)) {
		recorrer_inorden_con_cada_elemento(nodo->izquierda, funcion,
						   aux, contador_elementos,
						   seguir_recorriendo);
	}
	if ((*seguir_recorriendo)) {
		(*contador_elementos)++;
	}
	if (!nodo || !*seguir_recorriendo)
		return;
	if (funcion(nodo->elemento, aux) == false) {
		*seguir_recorriendo = false;
		return;
	}
	if (nodo->derecha && (*seguir_recorriendo)) {
		recorrer_inorden_con_cada_elemento(nodo->derecha, funcion, aux,
						   contador_elementos,
						   seguir_recorriendo);
	}
}

//FUNCION DE LAUTARO MARTIN SOTELO

//PRE : RECIBE EL NODO, LA FUNCION QUE BUSCA APLICARSE, EL CONTADOR DE ELEMENTOS ,
//UNA VARIABLE AUX Y EL BOOLEANO SEGUIR_CORRIENDO QUE DETERMINA
//HASTA CUANDO SE ITERA.
//POST: SIGUIENDO EL METODO DE RECORRER EN PREORDEN, SE RECORRE LA RAIZ,
//LUEGO LA IZQUIERDA Y POR ULTIMO LA DERECHA.SI LA FUNCION RETORNA FALSE PARA DE ITERAR.

void recorrer_preorden_con_cada_elemento(nodo_abb_t *nodo,
					 bool (*funcion)(void *, void *),
					 void *aux, size_t *contador_elementos,
					 bool *seguir_recorriendo)
{
	if (!nodo || !*seguir_recorriendo)
		return;
	if ((*seguir_recorriendo)) {
		(*contador_elementos)++;
	}
	if (funcion(nodo->elemento, aux) == false) {
		*seguir_recorriendo = false;
		return;
	}
	if (nodo->izquierda && (*seguir_recorriendo)) {
		recorrer_preorden_con_cada_elemento(nodo->izquierda, funcion,
						    aux, contador_elementos,
						    seguir_recorriendo);
	}
	if (nodo->derecha && (*seguir_recorriendo)) {
		recorrer_preorden_con_cada_elemento(nodo->derecha, funcion, aux,
						    contador_elementos,
						    seguir_recorriendo);
	}
}

size_t abb_con_cada_elemento(abb_t *arbol, abb_recorrido recorrido,
			     bool (*funcion)(void *, void *), void *aux)
{
	if (!arbol || funcion == NULL) {
		return 0;
	}
	size_t contador_elementos = 0;
	bool seguir_recorriendo = true;
	switch (recorrido) {
	case INORDEN:
		recorrer_inorden_con_cada_elemento(arbol->nodo_raiz, funcion,
						   aux, &contador_elementos,
						   &seguir_recorriendo);
		break;
	case POSTORDEN:
		recorrer_postorden_con_cada_elemento(arbol->nodo_raiz, funcion,
						     aux, &contador_elementos,
						     &seguir_recorriendo);
		break;
	case PREORDEN:
		recorrer_preorden_con_cada_elemento(arbol->nodo_raiz, funcion,
						    aux, &contador_elementos,
						    &seguir_recorriendo);
		break;
	}
	return contador_elementos;
}

//FUNCION DE LAUTARO MARTIN SOTELO
//PRE: RECIBE EL NODO, EL ARRAY Y EL CONTADOR DE ELEMENTOS.
//POST: ASIGNA EL ELEMENTO DEL NODO ACTUAL EN EL ARRAY Y SE AUMENTA EL CONTADOR.

void aumentar_contador_elementos(nodo_abb_t *nodo, void **array,
				 size_t *contador_elementos)
{
	array[*contador_elementos] = nodo->elemento;
	(*contador_elementos)++;
}

//FUNCION DE LAUTARO MARTIN SOTELO
//PRE: RECIBE EL NODO ACTUAL,UN ARRAY PARA ALMACENAR , EL TAMANIO DEL MISMO Y LOS ELEMENTOS CONTADOS.
//POST: SIGUIENDO EL METODO DE RECORRIDO POSTORDEN(IZQUIERDO,DERECHO,RAIZ),COPIA LOS VALORES DEL ARRAY HASTA LA CAPACIDAD ESPECIFICADA.

void recorrer_postorden(nodo_abb_t *nodo, void **array, size_t tamanio_array,
			size_t *contador_elementos)
{
	if (!nodo)
		return;
	if (nodo->izquierda)
		recorrer_postorden(nodo->izquierda, array, tamanio_array,
				   contador_elementos);
	if (nodo->derecha)
		recorrer_postorden(nodo->derecha, array, tamanio_array,
				   contador_elementos);
	if ((*contador_elementos) >= tamanio_array)
		return;
	aumentar_contador_elementos(nodo, array, contador_elementos);
}

//FUNCION DE LAUTARO MARTIN SOTELO

//PRE: RECIBE EL NODO ACTUAL,UN ARRAY PARA ALMACENAR , EL TAMANIO DEL MISMO Y LOS ELEMENTOS CONTADOS.
//POST: SIGUIENDO EL METODO DE RECORRIDO PREORDEN(RAIZ,IZQUIERDO,DERECHO),COPIA LOS VALORES DEL ARRAY HASTA LA CAPACIDAD ESPECIFICADA.

void recorrer_preorden(nodo_abb_t *nodo, void **array, size_t tamanio_array,
		       size_t *contador_elementos)
{
	if (!nodo || (*contador_elementos) >= tamanio_array)
		return;
	aumentar_contador_elementos(nodo, array, contador_elementos);
	if (nodo->izquierda)
		recorrer_preorden(nodo->izquierda, array, tamanio_array,
				  contador_elementos);
	if (nodo->derecha)
		recorrer_preorden(nodo->derecha, array, tamanio_array,
				  contador_elementos);
}

//FUNCION DE LAUTARO MARTIN SOTELO

//PRE: RECIBE EL NODO ACTUAL,UN ARRAY PARA ALMACENAR , EL TAMANIO DEL MISMO Y LOS ELEMENTOS CONTADOS.
//POST: SIGUIENDO EL METODO DE RECORRIDO INORDEN(IZQUIERDO,RAIZ,DERECHO),COPIA LOS VALORES DEL ARRAY HASTA LA CAPACIDAD ESPECIFICADA.

void recorrer_inorden(nodo_abb_t *nodo, void **array, size_t tamanio_array,
		      size_t *contador_elementos)
{
	if (!nodo)
		return;
	if (nodo->izquierda)
		recorrer_inorden(nodo->izquierda, array, tamanio_array,
				 contador_elementos);
	if ((*contador_elementos) >= tamanio_array)
		return;
	aumentar_contador_elementos(nodo, array, contador_elementos);
	if (nodo->derecha)
		recorrer_inorden(nodo->derecha, array, tamanio_array,
				 contador_elementos);
}

size_t abb_recorrer(abb_t *arbol, abb_recorrido recorrido, void **array,
		    size_t tamanio_array)
{
	if (!arbol || !tamanio_array) {
		return 0;
	}
	size_t contador_elementos = 0;
	switch (recorrido) {
	case INORDEN:
		recorrer_inorden(arbol->nodo_raiz, array, tamanio_array,
				 &contador_elementos);
		break;
	case POSTORDEN:
		recorrer_postorden(arbol->nodo_raiz, array, tamanio_array,
				   &contador_elementos);
		break;
	case PREORDEN:
		recorrer_preorden(arbol->nodo_raiz, array, tamanio_array,
				  &contador_elementos);
		break;
	}
	return contador_elementos;
}
