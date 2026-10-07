#ifndef LISTA_H
#define LISTA_H
#include "musica.h"

typedef struct lista* Lista;

Lista criar_lista();
int inserir_inicio(Lista li, Musica* m);
int inserir_final(Lista li, Musica* m);
int inserir_posicao(Lista li, Musica* m, int pos);
int remover_inicio(Lista li);
int remover_final(Lista li);
int remover_posicao(Lista li, int pos);
Musica* consultar_primeira(Lista li);
Musica* consultar_posicao(Lista li, int pos);
int qtd_musicas(Lista li);
void destruir_lista(Lista li);

#endif