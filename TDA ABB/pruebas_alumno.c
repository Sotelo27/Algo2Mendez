#include "pa2m.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/abb.h"
#include <stdbool.h>

typedef struct cosa {
	int clave;
	char contenido[10];
} cosa;

cosa *crear_elemento(int clave)
{
	cosa *c = (cosa *)malloc(sizeof(cosa));
	if (c)
		c->clave = clave;
	return c;
}

void destruir_elemento(cosa *c)
{
	free(c);
}

void destructor(void *c)
{
	cosa *cosa = c;
	if (cosa) {
		destruir_elemento(c);
	}
}

int comparador(void *c1, void *c2)
{
	cosa *cosa1 = c1;
	cosa *cosa2 = c2;
	return cosa1->clave - cosa2->clave;
}

void abb_prueba_crear_vacio()
{
	pa2m_afirmar(abb_crear(NULL) == NULL,
		     "El ABB no se crea con un sin comparador");
	abb_t *abb = abb_crear(comparador);
	pa2m_afirmar(abb != NULL,
		     "El ABB se creo correctamente con comparador");
	pa2m_afirmar(abb_vacio(abb), "El ABB se creo vacio");
	pa2m_afirmar(abb_tamanio(abb) == 0,
		     "El ABB tiene un tamanio de 0 inicialmente");
	abb_destruir(abb);
}

void abb_prueba_insertar_elementos()
{
	abb_t *abb = abb_crear(comparador);
	cosa *elemento_1 = crear_elemento(1);
	cosa *elemento_2 = crear_elemento(2);
	cosa *elemento_3 = crear_elemento(3);
	cosa *elemento_4 = crear_elemento(4);
	cosa *elemento_5 = crear_elemento(5);
	cosa *elemento_fuera_de_rango = crear_elemento(100);
	pa2m_afirmar(abb != NULL, "Se crea correctamente ");
	abb_insertar(abb, elemento_1);
	pa2m_afirmar(!abb_vacio(abb), "El ABB ya no se encuentra vacio");
	pa2m_afirmar(abb_tamanio(abb) == 1,
		     "El tamanio del ABB es 1 tras ingresar un valor");
	abb_insertar(abb, elemento_2);
	pa2m_afirmar(abb_tamanio(abb) == 2,
		     "El tamanio del ABB es 2 tras ingresar otro valor");
	abb_insertar(abb, elemento_3);
	abb_insertar(abb, elemento_4);
	abb_insertar(abb, elemento_5);
	pa2m_afirmar(abb_tamanio(abb) == 5,
		     "El tamanio del ABB es 5 tras ingresar 5 valores");
	pa2m_afirmar(abb_buscar(abb, elemento_5) != NULL,
		     "El valor 5 si se encuentra en el ABB");
	pa2m_afirmar(abb_buscar(abb, elemento_fuera_de_rango) == NULL,
		     "Buscar un valor que no esta en el ABB retorna NULL");
	destruir_elemento(elemento_fuera_de_rango);
	abb_destruir_todo(abb, destructor);
}

void abb_prueba_quitar_elementos()
{
	abb_t *abb = abb_crear(comparador);
	cosa *elemento_1 = crear_elemento(1);
	cosa *elemento_2 = crear_elemento(2);
	abb_insertar(abb, elemento_1);
	abb_insertar(abb, elemento_2);
	pa2m_afirmar(abb_buscar(abb, elemento_1) != NULL,
		     "El valor 2 se encuentra en el ABB");
	abb_quitar(abb, elemento_1);
	pa2m_afirmar(abb_buscar(abb, elemento_1) == NULL,
		     "Al eliminar un elemento del ABB ya no se puede buscar.");
	pa2m_afirmar(abb_tamanio(abb) == 1, "El tamanio volvio a ser de 1");
	abb_quitar(abb, elemento_2);
	pa2m_afirmar(abb_buscar(abb, elemento_2) == NULL,
		     "Se pudo eliminar la raiz del ABB");
	abb_insertar(abb, elemento_1);
	abb_insertar(abb, elemento_2);

	cosa *elemento_3 = crear_elemento(3);
	abb_insertar(abb, elemento_3);
	abb_insertar(abb, elemento_3);
	abb_quitar(abb, elemento_3);
	pa2m_afirmar(abb_buscar(abb, elemento_3) != NULL,
		     "Se pueden encontrar duplicados en el ABB");
	abb_quitar(abb, elemento_1);
	abb_quitar(abb, elemento_3);
	abb_quitar(abb, elemento_2);
	pa2m_afirmar(
		abb_vacio(abb),
		"Al quitar todos los elementos del ABB se encuentra vacio");
	pa2m_afirmar(abb_buscar(abb, elemento_1) == NULL,
		     "Se retorna NULL al buscar elementos en el abb vacio");
	destruir_elemento(elemento_1);
	destruir_elemento(elemento_2);
	destruir_elemento(elemento_3);
	abb_destruir_todo(abb, destructor);
}

void abb_prueba_recorrido()
{
	abb_t *abb = abb_crear(comparador);
	cosa *elemento_1 = crear_elemento(1);
	cosa *elemento_2 = crear_elemento(2);
	cosa *elemento_3 = crear_elemento(3);
	cosa *elemento_4 = crear_elemento(4);
	cosa *elemento_5 = crear_elemento(5);
	abb_insertar(abb, elemento_1);
	abb_insertar(abb, elemento_2);
	abb_insertar(abb, elemento_3);
	abb_insertar(abb, elemento_4);
	abb_insertar(abb, elemento_5);
	void **arbol_inorden = calloc(1, sizeof(void *) * 5);
	void **arbol_preorden = calloc(1, sizeof(void *) * 5);
	void **arbol_postorden = calloc(1, sizeof(void *) * 5);
	size_t cantidad = 0;

	cantidad = abb_recorrer(abb, INORDEN, arbol_inorden, 5);
	pa2m_afirmar(cantidad == 5,
		     "Puedo recorrer todo el árbol con el recorrido inorden");
	cantidad = abb_recorrer(abb, PREORDEN, arbol_preorden, 5);
	pa2m_afirmar(cantidad == 5,
		     "Puedo recorrer todo el árbol con el recorrido preorden");
	cantidad = abb_recorrer(abb, POSTORDEN, arbol_postorden, 5);
	pa2m_afirmar(cantidad == 5,
		     "Puedo recorrer todo el árbol con el recorrido postorden");
	cantidad = abb_recorrer(abb, INORDEN, arbol_inorden, 2);
	pa2m_afirmar(cantidad == 2,
		     "Puedo recorrer parte del árbol con el recorrido inorden");
	cantidad = abb_recorrer(abb, PREORDEN, arbol_preorden, 2);
	pa2m_afirmar(
		cantidad == 2,
		"Puedo recorrer parte del árbol con el recorrido preorden");
	cantidad = abb_recorrer(abb, POSTORDEN, arbol_postorden, 2);
	pa2m_afirmar(
		cantidad == 2,
		"Puedo recorrer parte del árbol con el recorrido postorden");
	free(arbol_inorden);
	free(arbol_preorden);
	free(arbol_postorden);
	abb_destruir_todo(abb, destructor);
}

bool mostrar_acumulado(void *elemento, void *extra)
{
	printf("- %i -", *(int *)elemento);
	return true;
}

bool es_divisor(void *elemento, void *divisor)
{
	int verificacion = true;
	if (*(int *)elemento % *(int *)divisor == 0) {
		//mostrar_acumulado(elemento,divisor);
		verificacion = false;
	}
	return verificacion;
}

void abb_prueba_iterador_interno()
{
	abb_t *abb = abb_crear(comparador);
	cosa *elemento_1 = crear_elemento(5);
	cosa *elemento_2 = crear_elemento(16);
	cosa *elemento_3 = crear_elemento(13);
	cosa *elemento_4 = crear_elemento(27);
	cosa *elemento_5 = crear_elemento(22);
	abb_insertar(abb, elemento_1);
	abb_insertar(abb, elemento_2);
	abb_insertar(abb, elemento_3);
	abb_insertar(abb, elemento_4);
	abb_insertar(abb, elemento_5);
	size_t cantidad_iteraciones = 0;
	//abb_con_cada_elemento(abb, PREORDEN, mostrar_acumulado,NULL);
	//abb_con_cada_elemento(abb, INORDEN, mostrar_acumulado,NULL);
	//abb_con_cada_elemento(abb, POSTORDEN, mostrar_acumulado,NULL);
	int divisor = 2;
	cantidad_iteraciones = abb_con_cada_elemento(abb, INORDEN, es_divisor,
						     (void *)&divisor);
	pa2m_afirmar(
		cantidad_iteraciones == 3,
		"El iterador interno recorrio de manera inorden hasta la posicion 3 encontrar el primer valor divisible(2)");
	cantidad_iteraciones = abb_con_cada_elemento(abb, POSTORDEN, es_divisor,
						     (void *)&divisor);
	pa2m_afirmar(
		cantidad_iteraciones == 2,
		"El iterador interno recorrio de manera postorden hasta la posicion 2 encontrar el primer valor divisible(2)");
	cantidad_iteraciones = abb_con_cada_elemento(abb, PREORDEN, es_divisor,
						     (void *)&divisor);
	pa2m_afirmar(
		cantidad_iteraciones == 2,
		"El iterador interno recorrio de manera preorden hasta la posicion 2encontrar el primer valor divisible(2)");
	cosa *elemento_6 = crear_elemento(100);
	abb_insertar(abb, elemento_6);
	divisor = 100;
	cosa *elemento_7 = crear_elemento(95);
	abb_insertar(abb, elemento_7);
	cantidad_iteraciones = abb_con_cada_elemento(abb, POSTORDEN, es_divisor,
						     (void *)&divisor);
	pa2m_afirmar(
		cantidad_iteraciones == 4,
		"El iterador interno recorre de manera inorden hasta la posicion 4 buscando el valor divisible por 100");
	cantidad_iteraciones = abb_con_cada_elemento(abb, INORDEN, es_divisor,
						     (void *)&divisor);
	pa2m_afirmar(
		cantidad_iteraciones == 7,
		"El iterador interno recorre de manera inorden hasta la posicion 7 buscando el valor divisible por 100");
	cantidad_iteraciones = abb_con_cada_elemento(abb, PREORDEN, es_divisor,
						     (void *)&divisor);
	pa2m_afirmar(
		cantidad_iteraciones == 6,
		"El iterador interno recorre de manera inorden hasta la posicion 6 buscando el valor divisible por 100");
	divisor = 97;
	cantidad_iteraciones = abb_con_cada_elemento(abb, POSTORDEN, es_divisor,
						     (void *)&divisor);
	pa2m_afirmar(
		cantidad_iteraciones == 7,
		"El iterador interno recorre de manera postorden hasta el final al no encontrar un divisible por 97");
	cantidad_iteraciones = abb_con_cada_elemento(abb, INORDEN, es_divisor,
						     (void *)&divisor);
	pa2m_afirmar(
		cantidad_iteraciones == 7,
		"El iterador interno recorre de manera inorden hasta el final al no encontrar un divisible por 97");
	cantidad_iteraciones = abb_con_cada_elemento(abb, PREORDEN, es_divisor,
						     (void *)&divisor);
	pa2m_afirmar(
		cantidad_iteraciones == 7,
		"El iterador interno recorre de manera preorden hasta el final al no encontrar un divisible por 97");
	abb_destruir_todo(abb, destructor);
}

void abb_prueba_nulos()
{
	pa2m_afirmar(abb_con_cada_elemento(NULL, INORDEN, es_divisor, NULL) ==
			     0,
		     "Iterar sobre un arbol nulo devuelve 0");
	void *vector_prueba[5];
	int aux = 0;
	pa2m_afirmar(
		abb_insertar(NULL, (void *)&aux) == NULL,
		"Si el arbol se encuentra nulo, no se pueden insertar elementos");
	pa2m_afirmar(abb_recorrer(NULL, INORDEN, vector_prueba, 5) == 0,
		     "Recorrer un arbol nulo de manera inorden retorna 0");
	pa2m_afirmar(abb_recorrer(NULL, PREORDEN, vector_prueba, 5) == 0,
		     "Recorrer un arbol nulo de manera inorden retorna 0");
	pa2m_afirmar(abb_recorrer(NULL, POSTORDEN, vector_prueba, 5) == 0,
		     "Recorrer un arbol nulo de manera inorden retorna 0");
	abb_t *abb = abb_crear(comparador);
	cosa *elemento_1 = crear_elemento(5);
	cosa *elemento_2 = crear_elemento(16);
	cosa *elemento_3 = crear_elemento(13);
	cosa *elemento_4 = crear_elemento(27);
	cosa *elemento_5 = crear_elemento(22);
	abb_insertar(abb, elemento_1);
	abb_insertar(abb, elemento_2);
	abb_insertar(abb, elemento_3);
	abb_insertar(abb, elemento_4);
	abb_insertar(abb, elemento_5);
	pa2m_afirmar(
		abb_con_cada_elemento(abb, INORDEN, NULL, (void *)&aux) == 0,
		"El iterando internamente inorden sin una funcion retorna 0");
	pa2m_afirmar(
		abb_con_cada_elemento(abb, PREORDEN, NULL, (void *)&aux) == 0,
		"El iterando internamente preorden sin una funcion retorna 0");
	pa2m_afirmar(
		abb_con_cada_elemento(abb, POSTORDEN, NULL, (void *)&aux) == 0,
		"El iterando internamente postorden sin una funcion retorna 0");
	pa2m_afirmar(abb_recorrer(abb, INORDEN, NULL, 0) == 0,
		     "Recorrer sobre un array de tamanio 0 retorna 0");
	pa2m_afirmar(abb_recorrer(abb, POSTORDEN, NULL, 0) == 0,
		     "Recorrer sobre un array de tamanio 0 retorna 0");
	pa2m_afirmar(abb_recorrer(abb, PREORDEN, NULL, 0) == 0,
		     "Recorrer sobre un array de tamanio 0 retorna 0");
	abb_destruir_todo(abb, destructor);
}

int main()
{
	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nCrear ABB\n");
	abb_prueba_crear_vacio();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando Insercion de elementos en ABB\n");
	abb_prueba_insertar_elementos();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando Quitar elementos en ABB\n");
	abb_prueba_quitar_elementos();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando recorrido en ABB\n");
	abb_prueba_recorrido();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando el iterador interno del ABB\n");
	abb_prueba_iterador_interno();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando valores nulos en ABB\n");
	abb_prueba_nulos();

	return pa2m_mostrar_reporte();
}
