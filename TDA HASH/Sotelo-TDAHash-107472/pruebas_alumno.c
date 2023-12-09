#include "pa2m.h"
#include "src/hash.h"

void hash_prueba_crear()
{
	hash_t *hash_1 = hash_crear(234);
	pa2m_afirmar(hash_1 != NULL, "El hash se creo correctamente");
	pa2m_afirmar(hash_cantidad(hash_1) == 0, "El nuevo hash esta vacio");
	hash_t *hash_2 = hash_crear(10);
	const char *clave_1 = "Martin";
	const char *clave_2 = "Lautaro";
	int elemento_1 = 5;
	int elemento_2 = 2;
	hash_insertar(hash_1, clave_1, (void *)&elemento_1, NULL);
	pa2m_afirmar(hash_contiene(hash_1, clave_1),
		     "Se inserto el primer elemento en el hash 1");
	hash_insertar(hash_1, clave_2, (void *)&elemento_2, NULL);
	pa2m_afirmar(hash_contiene(hash_1, clave_2),
		     "Se inserto el segundo elemento en el hash 1");
	hash_quitar(hash_1, clave_1);
	pa2m_afirmar(!hash_contiene(hash_1, clave_1),
		     "Se quito el primer elemento en el hash 1");
	hash_quitar(hash_1, clave_2);
	pa2m_afirmar(!hash_contiene(hash_1, clave_2),
		     "Se quito el segundo elemento en el hash 1");
	hash_insertar(hash_2, clave_1, (void *)&elemento_2, NULL);
	pa2m_afirmar(hash_contiene(hash_2, clave_1),
		     "Se inserto el primer elemento en el hash 2");
	hash_insertar(hash_2, clave_2, (void *)&elemento_2, NULL);
	pa2m_afirmar(hash_contiene(hash_2, clave_2),
		     "Se inserto el segundo elemento en el hash 2");
	hash_quitar(hash_2, clave_1);
	pa2m_afirmar(!hash_contiene(hash_2, clave_1),
		     "Se quito el primer elemento en el hash 2");
	hash_quitar(hash_2, clave_2);
	pa2m_afirmar(!hash_contiene(hash_2, clave_2),
		     "Se quito el segundo elemento en el hash 2");
	hash_destruir(hash_1);
	hash_destruir(hash_2);
}

void hashNull_prueba_primitivas()
{
	hash_t *hash = NULL;
	const char *clave_1 = "Martin";
	int elemento_1 = 5;
	pa2m_afirmar(hash_insertar(hash, clave_1, (void *)&elemento_1, NULL) ==
			     NULL,
		     "Si el hash es NULL , no se pueden ingresar elementos.");
	pa2m_afirmar(hash_obtener(hash, clave_1) == NULL,
		     "Si el hash en NULL , no se obtiene elementos");
	pa2m_afirmar(hash_quitar(hash, clave_1) == NULL,
		     "Si es NULL, no se puede quitar algun elemento");
	pa2m_afirmar(hash_cantidad(hash) == 0,
		     "SI es NULL, la cantidad del mismo es de 0");
	pa2m_afirmar(hash_con_cada_clave(hash, false, NULL) == 0,
		     "SI se encuentra NULL el hash, no recorre");
}

void hash_prueba_insertar_elementos()
{
	const char *clave_1 = "Martin";
	const char *clave_2 = "Lautaro";
	const char *clave_3 = "Juan";
	const char *clave_4 = "Ariel";
	const char *clave_5 = "Lalo";
	const char *clave_6 = "Facundo";
	const char *clave_7 = "Hector";
	const char *clave_8 = "No existo";
	const char *clave_9 = "Pedro";
	const char *clave_10 = "PEPE";

	int elemento_1 = 5;
	int elemento_2 = 2;
	int elemento_3 = 7;
	int elemento_4 = 10;
	int elemento_5 = 22;
	int elemento_6 = 23;
	int elemento_7 = 30;
	int elemento_8 = 25;
	int elemento_9 = 39;
	int elemento_10 = 42;
	hash_t *hash = hash_crear(9);
	hash_insertar(hash, clave_1, (void *)&elemento_1, NULL);
	pa2m_afirmar(
		hash_cantidad(hash) == 1,
		"Se inserto el primer elemento en el hash 1 y la cantidad es la correcta");
	pa2m_afirmar(hash_contiene(hash, clave_1),
		     "El elemento insertado esta y es el correcto");
	hash_insertar(hash, clave_2, (void *)&elemento_2, NULL);
	pa2m_afirmar(hash_cantidad(hash) == 2,
		     "La cantidad de elementos ahora es de 2");
	hash_insertar(hash, clave_3, (void *)&elemento_3, NULL);
	pa2m_afirmar(hash_cantidad(hash) == 3,
		     "La cantidad de elementos ahora es de 3");
	hash_insertar(hash, clave_4, (void *)&elemento_4, NULL);
	pa2m_afirmar(hash_cantidad(hash) == 4,
		     "La cantidad de elementos ahora es de 4");
	hash_insertar(hash, clave_5, (void *)&elemento_5, NULL);
	pa2m_afirmar(hash_cantidad(hash) == 5,
		     "La cantidad de elementos ahora es de 5");
	hash_insertar(hash, clave_6, (void *)&elemento_6, NULL);
	pa2m_afirmar(hash_cantidad(hash) == 6,
		     "La cantidad de elementos ahora es de 6");
	hash_insertar(hash, clave_7, (void *)&elemento_7, NULL);
	pa2m_afirmar(hash_cantidad(hash) == 7,
		     "Se inserto 7 elementos en el hash correctamente");
	pa2m_afirmar(!hash_contiene(hash, clave_8),
		     "Si se busca una clave que no esta retorna false");
	hash_insertar(hash, clave_8, (void *)&elemento_8, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_8),
		     "Si se busca una clave que no estaba ahora la encuentra");
	pa2m_afirmar(hash_cantidad(hash) == 8,
		     "Se inserto 8 elementos en el hash correctamente");
	hash_insertar(hash, clave_9, (void *)&elemento_9, NULL);
	pa2m_afirmar(hash_cantidad(hash) == 9,
		     "Se inserto 9 elementos en el hash correctamente");
	hash_insertar(hash, clave_10, (void *)&elemento_10, NULL);
	pa2m_afirmar(
		hash_cantidad(hash) == 10,
		"Se inserto 10 elementos en el hash correctamente, mas de la capacidad inicial");
	int cambia_elemento = 8;
	hash_insertar(hash, clave_1, (void *)&cambia_elemento, NULL);
	pa2m_afirmar(
		hash_obtener(hash, clave_1) == &cambia_elemento,
		"Si vuelvo a insertar un elemento con una clave existente, cambia su valor");
	hash_destruir(hash);
}

void hash_prueba_quitar_elementos()
{
	const char *clave_1 = "Martin";
	const char *clave_2 = "Lautaro";
	const char *clave_3 = "Juan";
	const char *clave_4 = "Ariel";
	const char *clave_5 = "Lalo";
	const char *clave_6 = "Facundo";
	const char *clave_7 = "Hector";
	const char *clave_8 = "No existo";
	const char *clave_9 = "Pedro";
	const char *clave_10 = "PEPE";
	int elemento_1 = 5;
	int elemento_2 = 2;
	int elemento_3 = 7;
	int elemento_4 = 10;
	int elemento_5 = 22;
	int elemento_6 = 23;
	int elemento_7 = 30;
	int elemento_8 = 25;
	int elemento_9 = 39;
	int elemento_10 = 42;
	hash_t *hash = hash_crear(5);
	hash_insertar(hash, clave_1, (void *)&elemento_1, NULL);
	hash_insertar(hash, clave_2, (void *)&elemento_2, NULL);
	hash_insertar(hash, clave_3, (void *)&elemento_3, NULL);
	hash_insertar(hash, clave_4, (void *)&elemento_4, NULL);
	hash_insertar(hash, clave_5, (void *)&elemento_5, NULL);
	hash_insertar(hash, clave_6, (void *)&elemento_6, NULL);
	hash_insertar(hash, clave_7, (void *)&elemento_7, NULL);
	hash_insertar(hash, clave_8, (void *)&elemento_8, NULL);
	hash_insertar(hash, clave_9, (void *)&elemento_9, NULL);
	hash_insertar(hash, clave_10, (void *)&elemento_10, NULL);
	pa2m_afirmar(hash_cantidad(hash) == 10,
		     "La cantidad de elementos ahora es de 10");
	hash_quitar(hash, clave_1);
	pa2m_afirmar(!hash_contiene(hash, clave_1),
		     "Se quito correctamente el primer elemento");
	pa2m_afirmar(hash_cantidad(hash) == 9,
		     "La cantidad de elementos ahora es de 9");
	hash_quitar(hash, clave_2);
	pa2m_afirmar(!hash_contiene(hash, clave_2),
		     "Se quito correctamente el segundo elemento");
	pa2m_afirmar(hash_cantidad(hash) == 8,
		     "La cantidad de elementos ahora es de 8");
	hash_quitar(hash, clave_3);
	pa2m_afirmar(!hash_contiene(hash, clave_3),
		     "Se quito correctamente el tercero elemento");
	pa2m_afirmar(hash_cantidad(hash) == 7,
		     "La cantidad de elementos ahora es de 7");
	hash_quitar(hash, clave_4);
	pa2m_afirmar(!hash_contiene(hash, clave_4),
		     "Se quito correctamente el cuarto elemento");
	pa2m_afirmar(hash_cantidad(hash) == 6,
		     "La cantidad de elementos ahora es de 6");
	hash_quitar(hash, clave_5);
	pa2m_afirmar(!hash_contiene(hash, clave_5),
		     "Se quito correctamente el quinto elemento");
	pa2m_afirmar(hash_cantidad(hash) == 5,
		     "La cantidad de elementos ahora es de 5");
	hash_quitar(hash, clave_6);
	pa2m_afirmar(!hash_contiene(hash, clave_6),
		     "Se quito correctamente el sexto elemento");
	pa2m_afirmar(hash_cantidad(hash) == 4,
		     "La cantidad de elementos ahora es de 4");
	hash_quitar(hash, clave_7);
	pa2m_afirmar(!hash_contiene(hash, clave_7),
		     "Se quito correctamente el septimo elemento");
	pa2m_afirmar(hash_cantidad(hash) == 3,
		     "La cantidad de elementos ahora es de 3");
	hash_quitar(hash, clave_8);
	pa2m_afirmar(!hash_contiene(hash, clave_8),
		     "Se quito correctamente el octavo elemento");
	pa2m_afirmar(hash_cantidad(hash) == 2,
		     "La cantidad de elementos ahora es de 2");
	hash_quitar(hash, clave_9);
	pa2m_afirmar(!hash_contiene(hash, clave_9),
		     "Se quito correctamente el noveno elemento");
	pa2m_afirmar(hash_cantidad(hash) == 1,
		     "La cantidad de elementos ahora es de 1");
	hash_quitar(hash, clave_10);
	pa2m_afirmar(!hash_contiene(hash, clave_10),
		     "Se quito correctamente el decimo elemento");
	pa2m_afirmar(hash_cantidad(hash) == 0,
		     "La cantidad volvio a ser de 0 tras quitar todo");
	hash_destruir(hash);
}

//Sirve para mostrar el nombre clave en el hash.

bool mostrar_Nombre(const char *clave, void *valor, void *aux)
{
	if (!clave)
		return false;

	aux = aux;
	//int *ptr = (int *)valor; // Convierte el puntero void* a int*
	//int poder= *ptr;
	//printf("\nSu nombre es %s y su poder es de %d !!\n", clave,poder);

	return true;
}

void hash_prueba_iterador_interno()
{
	const char *clave_1 = "Goku";
	const char *clave_2 = "Vegeta";
	const char *clave_3 = "Yamcha";
	const char *clave_4 = "Krillin";
	const char *clave_5 = "Nappa";
	const char *clave_6 = "Tenshin";
	const char *clave_7 = "Bulma";
	const char *clave_8 = "No existo";
	const char *clave_9 = "Gohan";
	const char *clave_10 = "Trunks";
	int elemento_1 = 5;
	int elemento_2 = 2;
	int elemento_3 = 7;
	int elemento_4 = 10;
	int elemento_5 = 22;
	int elemento_6 = 23;
	int elemento_7 = 30;
	int elemento_8 = 25;
	int elemento_9 = 39;
	int elemento_10 = 42;
	hash_t *hash = hash_crear(10);
	hash_insertar(hash, clave_1, (void *)&elemento_1, NULL);
	pa2m_afirmar(hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 1,
		     "Se recorrieron 81 elementos, con 1 elemento insertado.");
	hash_insertar(hash, clave_2, (void *)&elemento_2, NULL);
	pa2m_afirmar(hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 2,
		     "Se recorrieron 2 elementos, con 2 elementos insertados.");
	hash_insertar(hash, clave_3, (void *)&elemento_3, NULL);
	pa2m_afirmar(hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 3,
		     "Se recorrieron 3 elementos,con 3 elementos insertados.");
	hash_insertar(hash, clave_4, (void *)&elemento_4, NULL);
	pa2m_afirmar(hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 4,
		     "Se recorrieron 4 elementos, con 4 elementos insertados.");
	hash_insertar(hash, clave_5, (void *)&elemento_5, NULL);
	pa2m_afirmar(hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 5,
		     "Se recorrieron 5 elementos, con 5 elementos insertados.");
	hash_insertar(hash, clave_6, (void *)&elemento_6, NULL);
	pa2m_afirmar(hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 6,
		     "Se recorrieron 6 elementos, con 6 elementos insertados.");
	hash_insertar(hash, clave_7, (void *)&elemento_7, NULL);
	pa2m_afirmar(hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 7,
		     "Se recorrieron 7 elementos, con 7 elementos insertados.");
	hash_insertar(hash, clave_8, (void *)&elemento_8, NULL);
	pa2m_afirmar(hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 8,
		     "Se recorrieron 8 elementos, con 8 elementos insertados.");
	hash_insertar(hash, clave_9, (void *)&elemento_9, NULL);
	pa2m_afirmar(hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 9,
		     "Se recorrieron 9 elementos, con 9 elementos insertados.");
	hash_insertar(hash, clave_10, (void *)&elemento_10, NULL);
	pa2m_afirmar(hash_cantidad(hash) == 10,
		     "Se insertaron los 10 elementos");
	pa2m_afirmar(
		hash_con_cada_clave(hash, mostrar_Nombre, NULL) == 10,
		"Se recorrieron 10 elementos, con 10 elementos insertados.");

	hash_destruir(hash);
}

void hash_prueba_con_contenido()
{
	const char *clave_1 = "Goku";
	const char *clave_2 = "Vegeta";
	const char *clave_3 = "Yamcha";
	const char *clave_4 = "Krillin";
	const char *clave_5 = "Nappa";
	const char *clave_6 = "Tenshin";
	const char *clave_7 = "Bulma";
	const char *clave_8 = "No existo";
	const char *clave_9 = "Gohan";
	const char *clave_10 = "Trunks";
	int elemento_1 = 5;
	int elemento_2 = 2;
	int elemento_3 = 7;
	int elemento_4 = 10;
	int elemento_5 = 22;
	int elemento_6 = 23;
	int elemento_7 = 30;
	int elemento_8 = 25;
	int elemento_9 = 39;
	int elemento_10 = 42;
	hash_t *hash = hash_crear(10);
	hash_insertar(hash, clave_1, (void *)&elemento_1, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_1),
		     "El elemento 1 insertado esta y es el correcto");
	hash_insertar(hash, clave_2, (void *)&elemento_2, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_2),
		     "El elemento 2 insertado esta y es el correcto");
	hash_insertar(hash, clave_3, (void *)&elemento_3, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_3),
		     "El elemento 3 insertado esta y es el correcto");
	hash_insertar(hash, clave_4, (void *)&elemento_4, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_4),
		     "El elemento 4 insertado esta y es el correcto");
	hash_insertar(hash, clave_5, (void *)&elemento_5, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_5),
		     "El elemento 5 insertado esta y es el correcto");
	hash_insertar(hash, clave_6, (void *)&elemento_6, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_6),
		     "El elemento 6 insertado esta y es el correcto");
	hash_insertar(hash, clave_7, (void *)&elemento_7, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_7),
		     "El elemento 7 insertado esta y es el correcto");
	hash_insertar(hash, clave_8, (void *)&elemento_8, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_8),
		     "El elemento 8 insertado esta y es el correcto");
	hash_insertar(hash, clave_9, (void *)&elemento_9, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_9),
		     "El elemento 9 insertado esta y es el correcto");
	hash_insertar(hash, clave_10, (void *)&elemento_10, NULL);
	pa2m_afirmar(hash_contiene(hash, clave_10),
		     "El elemento 10 insertado esta y es el correcto");

	hash_destruir(hash);
}

void hash_prueba_con_obtencion()
{
	const char *clave_1 = "Goku";
	const char *clave_2 = "Vegeta";
	const char *clave_3 = "Yamcha";
	const char *clave_4 = "Krillin";
	const char *clave_5 = "Nappa";
	const char *clave_6 = "Tenshin";
	const char *clave_7 = "Bulma";
	const char *clave_8 = "No existo";
	const char *clave_9 = "Gohan";
	const char *clave_10 = "Trunks";
	int elemento_1 = 5;
	int elemento_2 = 2;
	int elemento_3 = 7;
	int elemento_4 = 10;
	int elemento_5 = 22;
	int elemento_6 = 23;
	int elemento_7 = 30;
	int elemento_8 = 25;
	int elemento_9 = 39;
	int elemento_10 = 42;
	hash_t *hash = hash_crear(10);
	hash_insertar(hash, clave_1, (void *)&elemento_1, NULL);
	hash_insertar(hash, clave_2, (void *)&elemento_2, NULL);
	hash_insertar(hash, clave_3, (void *)&elemento_3, NULL);
	hash_insertar(hash, clave_4, (void *)&elemento_4, NULL);
	hash_insertar(hash, clave_5, (void *)&elemento_5, NULL);
	hash_insertar(hash, clave_6, (void *)&elemento_6, NULL);
	hash_insertar(hash, clave_7, (void *)&elemento_7, NULL);
	hash_insertar(hash, clave_8, (void *)&elemento_8, NULL);
	hash_insertar(hash, clave_9, (void *)&elemento_9, NULL);
	hash_insertar(hash, clave_10, (void *)&elemento_10, NULL);
	pa2m_afirmar(hash_obtener(hash, clave_1) == &elemento_1,
		     "El elemento en la primera clave es el esperado");
	pa2m_afirmar(hash_obtener(hash, clave_2) == &elemento_2,
		     "El elemento en la segunda clave es el esperado");
	pa2m_afirmar(hash_obtener(hash, clave_3) == &elemento_3,
		     "El elemento en la tercera clave es el esperado");
	pa2m_afirmar(hash_obtener(hash, clave_4) == &elemento_4,
		     "El elemento en la cuarta clave es el esperado");
	pa2m_afirmar(hash_obtener(hash, clave_5) == &elemento_5,
		     "El elemento en la quinta clave es el esperado");
	pa2m_afirmar(hash_obtener(hash, clave_6) == &elemento_6,
		     "El elemento en la sexta clave es el esperado");
	pa2m_afirmar(hash_obtener(hash, clave_7) == &elemento_7,
		     "El elemento en la septima clave es el esperado");
	pa2m_afirmar(hash_obtener(hash, clave_8) == &elemento_8,
		     "El elemento en la octava clave es el esperado");
	pa2m_afirmar(hash_obtener(hash, clave_9) == &elemento_9,
		     "El elemento en la novena clave es el esperado");
	pa2m_afirmar(hash_obtener(hash, clave_10) == &elemento_10,
		     "El elemento en la decima clave es el esperado");

	hash_destruir(hash);
}

int main()
{
	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nCrear HASH\n");
	hash_prueba_crear();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbar en un HASH NULL las funciones primitivas\n");
	hashNull_prueba_primitivas();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando Insertar elementos en HASH\n");
	hash_prueba_insertar_elementos();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando Quitar elementos en HASH\n");
	hash_prueba_quitar_elementos();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando el iterador interno del HASH\n");
	hash_prueba_iterador_interno();

	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando el contenido en HASH\n");
	hash_prueba_con_contenido();
	pa2m_nuevo_grupo(
		"\n================================================\n");

	pa2m_nuevo_grupo("\nProbando lo que se obtiene en HASH\n");
	hash_prueba_con_obtencion();

	pa2m_mostrar_reporte();
}
