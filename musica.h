#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica Musica;

Musica* criar_musica(char* titulo, char* artista, int duracao);
char* consultar_titulo(Musica* m);
char* consultar_artista(Musica* m);
int consultar_duracao(Musica* m);
void imprimir_musica(Musica* m);
void destruir_musica(Musica* m);

#endif