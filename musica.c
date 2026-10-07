#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

struct musica {
    char titulo[100];
    char artista[100];
    int duracao;
};

Musica* criar_musica(char* titulo, char* artista, int duracao) {
    Musica* m = (Musica*) malloc(sizeof(struct musica));
    if (m != NULL) {
        strcpy(m->titulo, titulo);
        strcpy(m->artista, artista);
        m->duracao = duracao;
    }
    return m;
}

char* consultar_titulo(Musica* m) {
    if (m == NULL) return NULL;
    return m->titulo;
}

char* consultar_artista(Musica* m) {
    if (m == NULL) return NULL;
    return m->artista;
}

int consultar_duracao(Musica* m) {
    if (m == NULL) return 0;
    return m->duracao;
}

void imprimir_musica(Musica* m) {
    if (m != NULL) {
        printf("Musica: %s | Artista: %s | Duracao: %ds\n", m->titulo, m->artista, m->duracao);
    }
}

void destruir_musica(Musica* m) {
    if (m != NULL) {
        free(m);
    }
}