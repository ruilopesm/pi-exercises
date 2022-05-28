#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula *prox;
} *Palavras;

// Exercício 1
void libertaLista(Palavras l) {
    while (l != NULL) {
        Palavras temp = l;
        l = l->prox;
        free(temp->palavra);
        free(temp);
    }
}

// Exercício 2
int quantasP(Palavras l) {
    int counter = 0;

    while (l != NULL) {
        l = l->prox;
        counter++;
    }

    return counter;
}

// Exercício 3
void listaPal(Palavras l) {
    Palavras aux = l;

    while (aux != NULL) {
        printf("A palavra %s ocorre %d vezes\n", aux->palavra, aux->ocorr);
        aux = aux->prox;
    }
}

// Exercício 4
char *ultima(Palavras l) {
    Palavras aux = l;

    if (l == NULL) {
        return NULL;
    }

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    return aux->palavra;
}

// Exercício 5
Palavras acrescentaInicio(Palavras l, char *p) {
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = p;
    new->ocorr = 1;
    new->prox = l;

    return new;
}

// Exercício 6
Palavras acrescentaFim(Palavras l, char *p) {
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = p;
    new->ocorr = 1;

    if (l == NULL) {
        l = new;
        new->prox = NULL;
    }
    else {
        Palavras aux = l;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = new;
        new->prox = NULL;

        free(aux);
    }

    return l;
}

// Exercício 7
Palavras acrescenta(Palavras l, char *p) {
    Palavras aux = l;
    
    while (aux->prox != NULL) {
        if (strcmp(l->palavra, p) < 0) {
            aux = aux->prox;
        }
    }

    if (aux->prox != NULL && strcmp(l->palavra, p) == 0) {
        aux->ocorr++;
    }
    else {
        Palavras new = malloc(sizeof(struct celula));
        new->palavra = p;
        new->ocorr = 1;
        new->prox = aux;

        if (l != NULL) {
            aux->prox = new->prox;
        }
        else {
            aux = new;
        }

    }
    return l;
}

// Exercício 8
struct celula *maisFreq(Palavras l) {
    struct celula *mais_frequente = l;

    while (l != NULL) {
        if (l->ocorr > mais_frequente->ocorr) {
            mais_frequente = l;
        }

        l = l->prox;
    }

    return mais_frequente;
}
