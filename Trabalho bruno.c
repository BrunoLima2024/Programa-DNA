#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//estrutura da pilha

typedef struct {
    char soma[4];
} Genetico;

typedef struct no {
    Genetico g;
    struct no *proximo;
} No;

typedef struct {
    No *topo;
    int tam;
} Pilha;

//Estrutura da lista

typedef struct no3 {
    char resultado[20];
    struct no3 *proximo3;
} No3;

//estrutura da fila

typedef struct node {
    int posicao;
    struct node *proximo_fila;
} Node;


//Codio da pilha


void criar(Pilha *g) {
    g->topo = NULL;
    g->tam = 0;
}

void empilhar(Pilha *g, char *soma) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo) {
        strcpy(novo->g.soma, soma);
        novo->proximo = g->topo;
        g->topo = novo;
        g->tam++;
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

No* desempilhar(Pilha *g) {
    if (g->topo) {
        No *remover = g->topo;
        g->topo = remover->proximo;
        g->tam--;
        return remover;
    } else {
        printf("Pilha vazia.\n");
    }
    return NULL;
}

void imprimir_pilha(Pilha *g) {
    No *aux = g->topo;
    while (aux) {
        printf("Proteina: %s\n", aux->g.soma);
        aux = aux->proximo;
    }
}


// codigo da lista

void inserir_fim(No3 **lista, char *proteina) {
    No3 *aux_lista, *novo_lista = (No3*) malloc(sizeof(No3));

    if (novo_lista) {
        strcpy(novo_lista->resultado, proteina);
        novo_lista->proximo3 = NULL;

        if (*lista == NULL) {
            *lista = novo_lista;
        } else {
            aux_lista = *lista;
            while (aux_lista->proximo3) {
                aux_lista = aux_lista->proximo3;
            }
            aux_lista->proximo3 = novo_lista;
        }
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

void imprimir_Lista(No3 *no3) {
    printf("\n Lista: ");
    while (no3) {
        printf("\n%s ", no3->resultado);
        no3 = no3->proximo3;
    }

    printf("\n\n");
}

//codigo da fila


void inserir_fila(Node **fila, int posicao) {
    Node *aux_fila, *novo_fila = (Node*) malloc(sizeof(Node));
    if (novo_fila) {
        novo_fila->posicao = posicao;
        novo_fila->proximo_fila = NULL;
        if (*fila == NULL) {
            *fila = novo_fila;
        } else {
            aux_fila = *fila;
            while (aux_fila->proximo_fila) {
                aux_fila = aux_fila->proximo_fila;
            }
            aux_fila->proximo_fila = novo_fila;
        }
    } else {
        printf("Erro ao alocar memória.\n");
    }
}

void imprimir_fila(Node *fila) {
    Node *aux = fila;
    while (aux) {
        printf("Fila: %d \n", aux->posicao);
        aux = aux->proximo_fila;
    }
    printf("\n");
}


// Codigo principal

int main() {

    No *remover;
    Pilha g;
    int opcao;
    
    Node *r, *fila = NULL;
    int posicao;
    
    No3 *lista = NULL;

    criar(&g);

    int i, indice;
    char linha[100], soma[4];
    char tct[] = "TCT", tat[] = "TAT", gct[] = "GCT";
    char serina[] = "serina", tirosina[] = "tirosina", alanina[] = "alanina";

    printf("Escreva o DNA: ");
    scanf("%s", linha);

    indice = strlen(linha);

    for (i = 0; i < indice - 2; i++) {
        memcpy(soma, &linha[i], 3);
        
        printf("%s\n", soma);

        if (strcmp(tct, soma) == 0) {
            printf("TCT encontrado!\n");
            
            empilhar(&g, soma);
            inserir_fila(&fila, i);
            inserir_fim(&lista, serina);
            i = i + 2;
        }
        if (strcmp(tat, soma) == 0) {
            printf("TAT encontrado!\n");
            
            empilhar(&g, soma);
            inserir_fila(&fila, i);
            inserir_fim(&lista, tirosina);
            i = i + 2;
        }
        if (strcmp(gct, soma) == 0) {
            printf("GCT encontrado!\n");
            
            empilhar(&g, soma);
            inserir_fila(&fila, i);
            inserir_fim(&lista, alanina);
            i = i + 2;
        }

        imprimir_pilha(&g);
        imprimir_fila(fila);
        imprimir_Lista(lista); 
    }

    return 0;
}; 
