#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "musica.h"

void adiciona_musica(Lista li, Musica* m) {
    inserir_final(li, m);
}

void adiciona_musica_posicao(Lista li, Musica* m, int pos) {
    inserir_posicao(li, m, pos);
}

void remove_musica(Lista li, int pos) {
    remover_posicao(li, pos);
}

void tempo_restante(Lista li, int pos_atual) {
    int total = 0;
    int qtd = qtd_musicas(li);
    for(int i = pos_atual; i < qtd; i++){
        Musica* m = consultar_posicao(li, i);
        if(m != NULL) {
            total += consultar_duracao(m);
        }
    }
    int minutos = total / 60;
    int segundos = total % 60;
    printf("Tempo restante da playlist: %d min e %d seg.\n", minutos, segundos);
}

void play(Lista li, int* pos_atual) {
    Musica* m = consultar_posicao(li, *pos_atual);
    if(m != NULL) {
        printf("-> Tocando agora: ");
        imprimir_musica(m);
        (*pos_atual)++;
    } else {
        printf("Nao ha mais musicas para tocar.\n");
    }
}

void musicas_reproduzidas(int pos_atual) {
    printf("Musicas ja reproduzidas: %d\n", pos_atual);
}

int main() {
    Lista playlist = criar_lista();
    int posicao_reproducao = 0;

    Musica* m1 = criar_musica("Bohemian Rhapsody", "Queen", 354);
    Musica* m2 = criar_musica("Blinding Lights", "The Weeknd", 200);
    Musica* m3 = criar_musica("Hotel California", "Eagles", 390);
    Musica* m4 = criar_musica("Shape of You", "Ed Sheeran", 233);
    Musica* m5 = criar_musica("Levitating", "Dua Lipa", 203);
    Musica* m6 = criar_musica("Anunciacao", "Alceu Valenca", 270);
    Musica* m7 = criar_musica("Rolling in the Deep", "Adele", 228);
    Musica* m8 = criar_musica("Hey Jude", "The Beatles", 431);
    Musica* m9 = criar_musica("As It Was", "Harry Styles", 167);
    Musica* m10 = criar_musica("Cheia de Manias", "Raca Negra", 212);

    adiciona_musica(playlist, m1);
    adiciona_musica(playlist, m2);
    adiciona_musica(playlist, m3);
    adiciona_musica(playlist, m4);
    adiciona_musica(playlist, m6);
    adiciona_musica(playlist, m7);
    adiciona_musica(playlist, m8);
    adiciona_musica(playlist, m9);
    adiciona_musica(playlist, m10);
    
    adiciona_musica_posicao(playlist, m5, 4);

    remove_musica(playlist, 5);

    printf("--- INICIANDO PLAYLIST ---\n");
    play(playlist, &posicao_reproducao);
    play(playlist, &posicao_reproducao);
    play(playlist, &posicao_reproducao);

    printf("\n--- STATUS DA PLAYLIST ---\n");
    musicas_reproduzidas(posicao_reproducao);
    tempo_restante(playlist, posicao_reproducao);

    printf("\n--- FINAL DA EXECUCAO ---\n");
    printf("Quantidade de musicas na playlist: %d\n", qtd_musicas(playlist));
    printf("Posicao da proxima musica a ser reproduzida: %d\n", posicao_reproducao);

    destruir_lista(playlist);

    return 0;
}