typedef struct entrenador {
    char* nombre;
    int cant_vencidos;
} entrenador_t;

void actualizar_victorias(void* entrenador, void* cant_extra);