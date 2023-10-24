#include <stdlib.h>
#include "pokemon.h"
#include "tipo.h"
#include <stdio.h>
#include "ataque.h"
#include <string.h>

#define MAX_ATAQUES 3

struct pokemon {
	char nombre[20];
	enum TIPO tipo;
	struct ataque ataque_pokemon[MAX_ATAQUES];
};

struct info_pokemon {
	pokemon_t *pokemones;
	int cantidad;
};

//De Lautaro Martin Sotelo
//PRE: recibe un valor tipo char que referencia al tipo de pokemon.
//POST: de devuelve un enum TIPO de acuerdo a que referencia el tipo char pasado.Retorna -1 si no corresponde.
enum TIPO verificar_tipo(char tipo_pokemon)
{
	switch (tipo_pokemon) {
	case 'E':
		return ELECTRICO;

	case 'F':
		return FUEGO;

	case 'N':
		return NORMAL;

	case 'A':
		return AGUA;

	case 'R':
		return ROCA;

	case 'P':
		return PLANTA;

	default:
		return -1;
	}
}

//De Lautaro Martin Sotelo
//PRE: recibe un char tipo.
//POST: si la funcion verificar tipo devuelve -1,significa que no existe el tipo,retorna 1 si es valido, -1 si no.
int validar_datos(char tipo)
{
	int validacion = 1;
	if (verificar_tipo(tipo) == -1) {
		validacion = -1;
	}
	return validacion;
}

//De Lautaro Martin Sotelo
//PRE:Recibe un puntero a pokemon_lista que no sea NULL.
//POST:ordena alfabeticamente con metodo burbuja los elementos del vector.
void ordenar_alfabeticamente(informacion_pokemon_t *pokemon_lista)
{
	pokemon_t poke_aux;
	int letra_anterior;
	for (int i = 0; i < pokemon_lista->cantidad; i++) {
		letra_anterior = i;
		for (int j = i + 1; j < pokemon_lista->cantidad; j++) {
			if (strcmp(pokemon_lista->pokemones[letra_anterior]
					   .nombre,
				   pokemon_lista->pokemones[j].nombre) > 0) {
				letra_anterior = j;
			}
		}
		poke_aux = pokemon_lista->pokemones[i];
		pokemon_lista->pokemones[i] =
			pokemon_lista->pokemones[letra_anterior];
		pokemon_lista->pokemones[letra_anterior] = poke_aux;
	}
}

//De lautaro Martin Sotelo
//PRE:recibe un puntero informacion_pokemon_t que no sea NULL.
//POST: se devuelve un vector mas pequenio que cambiara el tamanio del vector original
informacion_pokemon_t *achicar_vector(informacion_pokemon_t *pokemon_lista)
{
	informacion_pokemon_t *auxiliar_lista =
		malloc(sizeof(informacion_pokemon_t));
	auxiliar_lista->pokemones = malloc(sizeof(pokemon_t));
	auxiliar_lista->cantidad = 0;
	for (int i = 0; i < pokemon_lista->cantidad - 1; i++) {
		auxiliar_lista->pokemones[i] =
			pokemon_lista->pokemones
				[i]; // se guardaran todos los datos menos el ultimo.
		auxiliar_lista->cantidad++;
	}
	pokemon_destruir_todo(pokemon_lista);
	return auxiliar_lista;
}

//De Lautaro Martin Sotelo
//PRE:recibe un puntero a pokemon_lista que no sea null, un char_nombre del pokemon, y un char que referencia al TIPO del mismo.
//POST:creandose un struct auxiliar, se guardan los datos del nombre del pokemon y el tipo en el puntero pokemon_lista.
void caso_2_datos(informacion_pokemon_t *pokemon_lista, char char_nombre[25],
		  char tipo)
{
	pokemon_t pokemon_aux;
	pokemon_lista->pokemones = realloc(
		pokemon_lista->pokemones,
		sizeof(pokemon_t) * ((size_t)(pokemon_lista->cantidad + 1)));
	if (pokemon_lista->pokemones != NULL) {
		strcpy(pokemon_aux.nombre, char_nombre);
		pokemon_aux.tipo = verificar_tipo(
			tipo); //al ser un tipo char, devolvera el TIPO segun corresponda.
		pokemon_lista->pokemones[pokemon_lista->cantidad] = pokemon_aux;
		pokemon_lista->cantidad++; // se aumenta la cantidad.
	}
}

//De Lautaro Martin Sotelo
//PRE :recibe un puntero a pokemon_lista que no sea NULL,tipo char nombre, un char de tipo, un unsigned int del poder, y la pos (servira para ubicar los ataques en la lista).
//POST:se accede a los datos almacenados en el puntero pokemon_lista y se los guarda en el espacio de ataque_pokemon.
void caso_3_datos(informacion_pokemon_t *pokemon_lista, char char_nombre[25],
		  char tipo, unsigned int poder_ataque, int pos)
{
	pokemon_lista
		->pokemones[pokemon_lista->cantidad -
			    1] //se resta el valor en 1 para hacer referencia al pokemon anterior.
		.ataque_pokemon[pos]
		.poder = poder_ataque;
	pokemon_lista->pokemones[pokemon_lista->cantidad - 1]
		.ataque_pokemon[pos]
		.tipo = verificar_tipo(tipo);
	strcpy(pokemon_lista->pokemones[pokemon_lista->cantidad - 1]
		       .ataque_pokemon[pos]
		       .nombre,
	       char_nombre);
}

//De Lautaro Martin Sotelo;
//PRE: recibe la cantidad de pokemones correctos, y el puntero no NULL con datos pokemon_lista.
//POST: devuelve un int con valor 1 si cumplio las validaciones o -1 si no.
int validaciones_pokes_correctos(int correctos,
				 informacion_pokemon_t *pokemon_lista)
{
	int validacion = 1;
	if (correctos == 0) {
		pokemon_lista->cantidad =
			1; //estas condicinoes sirver para eliminar todo.
		validacion = -1;
	} else if (correctos == 1 && correctos < pokemon_lista->cantidad) {
		pokemon_lista->cantidad =
			correctos + 1; //se le aumenta 1 para reducirlo luego.
		validacion = -1;

	} else if (correctos > 1 && correctos < pokemon_lista->cantidad - 1) {
		pokemon_lista->cantidad = correctos;
		validacion = -1;
	}
	return validacion;
}

//De Lautaro Martin Sotelo
//PRE: recibe un puntero a archivo, lista y validar que no sean del tipo NULL.
//POST: recorre las lineas del archivo y toma los datos para guardarlo en el pokemon_lista.Tambien se guarda en el tipo validar -1 o 1 si hay un TIPO invalido o valido respectivamente.
void leer_linea(FILE *archivo, informacion_pokemon_t *pokemon_lista,
		int *validar)
{
	char linea[100];
	int pos = 0; // referencia a la pos del ataque
	int validar_aux = 1; //validacion general.
	int validar_ataque = 1; //validacion de ataque valido
	int contador_lineas = 0;
	int correctos = 0; // referencia a pokemones con 3 ataques
	while (fgets(linea, sizeof(linea), archivo) != NULL &&
	       validar_aux == 1 && validar_ataque == 1) {
		unsigned int poder_ataque = 0;
		char char_nombre[25];
		char tipo;
		int resultado = sscanf(linea, "%[^;];%c;%u", char_nombre, &tipo,
				       &poder_ataque);
		validar_aux = validar_datos(tipo);
		if (contador_lineas == 4 &&
		    pos < 3) { //condicion que sirve par saber que haya habido almenos 3 ataques,sino se corta.
			validar_ataque = -1;

		} else if (contador_lineas == 4 && pos == 3) {
			correctos += 1;
			contador_lineas = 0;
		}

		if (resultado == 2 && validar_aux == 1) {
			caso_2_datos(pokemon_lista, char_nombre, tipo);
			pos = 0;
			contador_lineas++;
		} else if (resultado == 3 && validar_aux == 1) {
			caso_3_datos(pokemon_lista, char_nombre, tipo,
				     poder_ataque, pos);
			pos++;
			contador_lineas++;
		}
	}
	validar_aux = validaciones_pokes_correctos(correctos, pokemon_lista);
	*validar = validar_aux;
}

//PRE y POST detallas en el .h (pokemon.h)
informacion_pokemon_t *pokemon_cargar_archivo(const char *path)
{
	if (path == NULL) { //primero se verifica que sea un path valido.
		return NULL;
	}
	informacion_pokemon_t *pokemon_lista =
		malloc(sizeof(informacion_pokemon_t)); //inicializo
	if (pokemon_lista == NULL) {
		return NULL;
	}
	pokemon_lista->pokemones = malloc(sizeof(pokemon_t));
	pokemon_lista->cantidad = 0;
	if (pokemon_lista->pokemones == NULL) {
		free(pokemon_lista);
		return NULL;
	}
	FILE *archivo = fopen(path, "r");
	if (archivo == NULL) {
		pokemon_destruir_todo(
			pokemon_lista); // si es NULL se libera el espacio guardado.
		return NULL;
	}
	int validar = 0;
	leer_linea(archivo, pokemon_lista, &validar);
	fclose(archivo);
	if (validar == -1 && pokemon_lista->cantidad > 1) { //solo reduce en 1.
		pokemon_lista = achicar_vector(pokemon_lista);
	} else if (pokemon_lista->cantidad == 1 &&
		   validar == -1) { //elimina todo.
		pokemon_destruir_todo(pokemon_lista);
		return NULL;
	}
	ordenar_alfabeticamente(
		pokemon_lista); // Se ordena alfabeticamente con metodo burbuja.
	return pokemon_lista;
}

//PRE y POST detallas en el .h (pokemon.h)
pokemon_t *pokemon_buscar(informacion_pokemon_t *ip, const char *nombre)
{
	if (ip != NULL && nombre != NULL) {
		for (int i = 0; i < ip->cantidad; i++) {
			if (!strcmp(nombre,
				    ip->pokemones[i]
					    .nombre)) { //El ! verifica que sean iguales.
				return &ip->pokemones[i];
			}
		}
	}
	return NULL;
}

//PRE y POST detallas en el .h (pokemon.h)
int pokemon_cantidad(informacion_pokemon_t *ip)
{
	if (ip != NULL) {
		return ip->cantidad;
	}
	return 0;
}

//PRE y POST detallas en el .h (pokemon.h)
const char *pokemon_nombre(pokemon_t *pokemon)
{
	return pokemon->nombre;
}

//PRE y POST detallas en el .h (pokemon.h)
enum TIPO pokemon_tipo(pokemon_t *pokemon)
{
	if (pokemon != NULL &&
	    pokemon->tipo !=
		    -1) { //Verifico que primero no sea NULL el contenido de pokemon, y si es -1, no es un tipo valido.
		return pokemon->tipo;
	}
	return NORMAL;
}

//PRE y POST detallas en el .h (pokemon.h)
const struct ataque *pokemon_buscar_ataque(pokemon_t *pokemon,
					   const char *nombre)
{
	for (int i = 0; i < MAX_ATAQUES;
	     i++) { //Se itera de acuerdo a la cantidad de ataques del pokemon.
		if (!strcmp(nombre, pokemon->ataque_pokemon[i].nombre)) {
			return &pokemon->ataque_pokemon[i];
		}
	}
	return NULL;
}

//PRE y POST detallas en el .h (pokemon.h)
int con_cada_pokemon(informacion_pokemon_t *ip, void (*f)(pokemon_t *, void *),
		     void *aux)
{
	int cant_pokemon = 0;
	if (ip == NULL || f == NULL) { //Verifico que no tengas datos NULL.
		return 0;
	}
	for (int i = 0; i < ip->cantidad; i++) {
		f(&ip->pokemones[i], aux);
		cant_pokemon++;
	}
	return cant_pokemon;
}

//PRE y POST detallas en el .h (pokemon.h)
int con_cada_ataque(pokemon_t *pokemon,
		    void (*f)(const struct ataque *, void *), void *aux)
{
	int cant_ataques = 0;
	if (pokemon == NULL || f == NULL) { //Verifico que no tengas datos NULL.
		return 0;
	}
	for (int i = 0; i < MAX_ATAQUES;
	     i++) { //Se itera de acuerdo a la cantidad de ataques del pokemon
		f(&pokemon->ataque_pokemon[i], aux);
		cant_ataques++;
	}
	return cant_ataques;
}

//PRE y POST detallas en el .h (pokemon.h)
void pokemon_destruir_todo(informacion_pokemon_t *ip)
{
	if (ip) { //Verifico que exista, tal caso, se libera la memoria.
		free(ip->pokemones);
		free(ip);
	}
}