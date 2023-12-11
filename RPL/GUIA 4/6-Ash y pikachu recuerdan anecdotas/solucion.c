/*
Ash y su mejor amigo Pikachu, guardan sus secretos y anécdotas de una manera muy particular e interesante: 
dada una palabra se reparten las letras de forma intercalada, una letra para Ash y otra para Pikachu. 
Pero esto lleva años de práctica. Ahora, desean recordar todo lo que escribieron.
Te piden que programes una función que, dado el vector donde Ash guarda sus letras y dado el vector donde Pikachu guarda las suyas,
se junten y se muestren por pantalla las palabras correctamente de forma intercalada.

Por ejemplo, si el vector de Ash es

Cmensprsepe

Y el de Pikachu es

apoe o imr!

El vector resultante debe ser

Campeones por siempre!

El mensaje final se debe ingresar en el vector correspondiente. Se puede asumir que éste siempre tendrá espacio suficiente. 
Los tres vectores deben ser tratados como strings.

*/
#include <stdio.h>

#include <stdio.h>

void intercalar_aux(char* letras_de_ash, char* letras_de_pikachu, char* mensaje_final, int indice_ash, int indice_pikachu, int indice_mensaje, int turno) {
    if (letras_de_ash[indice_ash] == '\0' && letras_de_pikachu[indice_pikachu] == '\0') {
        mensaje_final[indice_mensaje] = '\0'; // Agrega el caracter nulo para terminar la cadena
        return;
    }

    if (turno % 2 == 0) {
        if (letras_de_ash[indice_ash] != '\0') {
            mensaje_final[indice_mensaje] = letras_de_ash[indice_ash];
            intercalar_aux(letras_de_ash, letras_de_pikachu, mensaje_final, indice_ash + 1, indice_pikachu, indice_mensaje + 1, turno + 1);
        }
    } else {
        if (letras_de_pikachu[indice_pikachu] != '\0') {
            mensaje_final[indice_mensaje] = letras_de_pikachu[indice_pikachu];
            intercalar_aux(letras_de_ash, letras_de_pikachu, mensaje_final, indice_ash, indice_pikachu + 1, indice_mensaje + 1, turno + 1);
        }
    }
}

void intercalador_de_anecdotas(char* letras_de_ash, char* letras_de_pikachu, char* mensaje_final) {
    intercalar_aux(letras_de_ash, letras_de_pikachu, mensaje_final, 0, 0, 0, 0);
}

int main() {
    char letras_de_ash[] = "Cmensprsepe";
    char letras_de_pikachu[] = "apoe o imr!";
    char mensaje_final[50]; // Asumiendo que el mensaje final tendrá un tamaño máximo de 50 caracteres

    intercalador_de_anecdotas(letras_de_ash, letras_de_pikachu, mensaje_final, 0, 0, 0, 0);

    printf("Mensaje final: %s\n", mensaje_final);

    return 0;
}