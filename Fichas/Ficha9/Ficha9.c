#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

ABin newABin(int r, ABin e, ABin d) {
    ABin a = malloc(sizeof(struct nodo));

    if (a != NULL) {
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }

    return a;
}

// Exercício 1 a)
int max(int x, int y) {
    if (x > y) {
        return x;
    }

    return y;
}

int altura(ABin a) {
    if (a == NULL) {
        return 0;
    }
    
    if (a->esq == NULL && a->dir == NULL) {
        return 1;
    }
    else {
        return 1 + max(altura(a->esq), altura(a->dir));
    }
}

// Exercício 1 b)
int nFolhas(ABin a) {
    if (a == NULL) {
        return 0;
    }
    
    if (a->esq == NULL && a->dir == NULL) {
        return 1;
    }
    else {
        return nFolhas(a->esq) + nFolhas(a->dir);
    }
}

// Exercício 1 c)
ABin maisEsquerda(ABin a) {
    if (a == NULL) {
        return NULL;
    }
    
    if (a->esq == NULL) {
        return a;
    }
    else {
        return maisEsquerda(a->esq);
    }
}

// Exercício 1 d)
void imprimeNivel(ABin a, int l) {
    if (a == NULL) {
        return;
    }
    
    if (l >= 0) {
        if (l == 0) {
            printf("Valor: %d\n", a->valor);
        }
        else {
            imprimeNivel(a->esq, l - 1);
            imprimeNivel(a->dir, l - 1);
        }
    }
}

// Exercício 1 e)
int procuraE(ABin a, int x) {
    if (a == NULL) {
        return 0;
    }

    if (a->valor == x) {
        return 1;
    }
    else {
        return procuraE(a->esq, x) || procuraE(a->dir, x);
    }

    return 0;
}

// Exercício 2 f)
struct nodo *procura(ABin a, int x) {
    if (a == NULL) {
        return NULL;
    }

    while (a != NULL && a->valor != x) {
        if (a->valor > x) {
            a = a->esq;
        }
        else {
            a = a->dir;
        }
    }

    return a;
}

// Exercício 2 g)
int nivel(ABin a, int x) {
    int counter = 0;

    while (a != NULL && a->valor != x) {
        if (a->valor > x) {
            a = a->esq;
        }
        else {
            a = a->dir;
        }
        
        counter++;
    }

    if (a == NULL) {
        return -1;
    }

    return counter;
}

// Exercício 2 h)
void imprimeAte(ABin a, int x) {
    if (a == NULL) {
        return;
    }

    imprimeAte(a->esq, x);

    if (a->valor < x) {
        printf("%d\n", a->valor);
        imprimeAte(a->dir, x);
    }
}
