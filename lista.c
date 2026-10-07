#include <stdlib.h>
#include "lista.h"

struct elem {
    Musica* musica;
    struct elem* prox;
};
typedef struct elem Elem;

struct lista {
    int qtd;
    Elem* inicio;
};

Lista criar_lista() {
    Lista li = (Lista) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
        li->inicio = NULL;
    }
    return li;
}

int inserir_inicio(Lista li, Musica* m) {
    if(li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no != NULL){
        no->musica = m;
        no->prox = li->inicio;
        li->inicio = no;
        li->qtd++;
        return 1;
    } 
    return 0;
}

int inserir_final(Lista li, Musica* m) {
    if(li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no != NULL){
        no->musica = m;
        no->prox = NULL;
        if(li->inicio == NULL){
            li->inicio = no;
            li->qtd++;
            return 1;
        }
        Elem* aux = li->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        li->qtd++;
        return 1;
    }
    return 0;
}

int inserir_posicao(Lista li, Musica* m, int pos) {
    if (li == NULL || pos < 0 || pos > li->qtd) return 0;
    if (pos == 0) return inserir_inicio(li, m);
    if (pos == li->qtd) return inserir_final(li, m);
    
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->musica = m;
    
    Elem* ant = li->inicio;
    for(int i = 0; i < pos - 1; i++){
        ant = ant->prox;
    }
    no->prox = ant->prox;
    ant->prox = no;
    li->qtd++;
    return 1;
}

int remover_inicio(Lista li) {
    if(li == NULL || li->qtd == 0) return 0;
    Elem* aux = li->inicio;
    li->inicio = aux->prox;
    destruir_musica(aux->musica);
    free(aux);
    li->qtd--;
    return 1;
}

int remover_final(Lista li) {
    if(li == NULL || li->qtd == 0) return 0;
    Elem* aux = li->inicio;
    if(aux->prox == NULL){
        destruir_musica(aux->musica);
        free(aux);
        li->inicio = NULL;
        li->qtd--;
        return 1;
    }
    Elem* ant;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }
    destruir_musica(aux->musica);
    free(aux);
    ant->prox = NULL;
    li->qtd--;
    return 1;
}

int remover_posicao(Lista li, int pos) {
    if (li == NULL || pos < 0 || pos >= li->qtd) return 0;
    if (pos == 0) return remover_inicio(li);
    
    Elem* ant = li->inicio;
    for(int i = 0; i < pos - 1; i++){
        ant = ant->prox;
    }
    Elem* atual = ant->prox;
    ant->prox = atual->prox;
    destruir_musica(atual->musica);
    free(atual);
    li->qtd--;
    return 1;
}

Musica* consultar_primeira(Lista li) {
    if(li == NULL || li->qtd == 0) return NULL;
    return li->inicio->musica;
}

Musica* consultar_posicao(Lista li, int pos) {
    if(li == NULL || pos < 0 || pos >= li->qtd) return NULL;
    Elem* aux = li->inicio;
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
    }
    return aux->musica;
}

int qtd_musicas(Lista li) {
    if(li == NULL) return 0;
    return li->qtd;
}

void destruir_lista(Lista li) {
    if(li == NULL) return;
    Elem* aux = li->inicio;
    while(aux != NULL){
        Elem* atual = aux;
        aux = aux->prox;
        destruir_musica(atual->musica);
        free(atual);
    }
    free(li);
}