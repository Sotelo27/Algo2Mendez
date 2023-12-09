/*
La estructura de control más conocida es el if-else, que seguramente
 ya usaste antes. Pero no es la única.

La función a programar recibe una letra por parámetro,
que representa la inicial de un pokémon. Se pide devolver la cantidad
 de batallas ganadas por el mismo, utilizando la estructura condicional switch.

Se sabe que

    A es la inicial de Arbok y que ganó 20 batallas en el torneo.
    R es la inicial de Rattata y que ganó 17 batallas en el torneo.
    L es la inicial de Lapras y que ganó 15 batallas en el torneo.
    G es la inicial de Golem y que ganó 30 batallas en el torneo.
    F es la inicial de Flareon y que ganó 8 batallas en el torneo.
    O es la inicial de Onix y que ganó 27 batallas en el torneo.
    T es la inicial de Treecko y que ganó 5 batallas en el torneo.
    C es la inicial de Charizard y que ganó 39 batallas en el torneo.
    B es la inicial de Bulbassaur y que ganó 10 batallas en el torneo.

Si se recibe cualquier otra letra, se debe devolver -1,
indicando que no se conoce la cantidad de batallas ganadas de
ese pokémon. Ya definimos la variable ERROR para mantener las buenas
prácticas.*/

/*
 * Se recibe una letra. Si ella se corresponde con alguna de las proveídas
 en el enunciado (A, R, L, G, F, O, T, C, R, B) se devuelve la cantidad de
 batallas ganadas por el pokemon respectivo.
 */

#include <stdio.h>
int batallas_ganadas(char letra) {
  // tu código
  int ganadas = 0;
  switch (letra) {
  case 'A':
    ganadas = 20;
    break;
  case 'R':
    ganadas = 17;
    break;
  case 'L':
    ganadas = 15;
    break;
  case 'G':
    ganadas = 30;
    break;
  case 'F':
    ganadas = 8;
    break;
  case 'O':
    ganadas = 27;
    break;
  case 'T':
    ganadas = 5;
    break;
  case 'C':
    ganadas = 39;
    break;
  case 'B':
    ganadas = 10;
    break;
  default:
    ganadas = -1;
    break;
  }
  printf("\nValor es %d\n", ganadas);
  return ganadas;
}

int main() {
  int valor = 0;
  valor = batallas_ganadas('A');
  printf("\nValor es %d\n", valor);
  return 0;
}