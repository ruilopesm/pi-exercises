#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct {
    LInt inicio, fim;
} Queue;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc(sizeof(struct slist));
    
    if (r != NULL) {
        r->valor = x; 
        r->prox = xs;
    }
    
    return r;
}

void initQueue(Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty(Queue q) {
    return q.inicio == NULL;
}

void enqueue(Queue *q, int x) {
    if (QisEmpty(*q)) {
        q->inicio = newLInt(x, NULL);
        q->fim = q->inicio;
    }
    else {
        LInt new = newLInt(x, NULL);
        q->fim->prox = new;
        q->fim = new;
    }
}

int dequeue(Queue *q, int *x) {
    LInt temp = NULL;

    if (QisEmpty(*q)) {
        return 1;
    }
    
    *x = q->inicio->valor;
    temp = q->inicio;

    q->inicio = q->inicio->prox;

    if (q->inicio == NULL) {
        q->fim = NULL;
    }

    free(temp);

    return 0;
}

typedef LInt QueueC;

void initQueueC(QueueC *q) {
    (*q) = NULL;
}

int QCisEmpty(QueueC q) {
    return q == NULL;
}

void enqueueC(QueueC *q, int x) {
    if (QCisEmpty(*q)) {
        (*q) = newLInt(x, NULL);
        (*q)->prox = *q;
    }
    else {
        LInt new = newLInt(x, NULL);
        new->prox = (*q)->prox;
        *q = new;
    }
}

int dequeueC(QueueC *q, int *x) {
    LInt temp;

    if (QCisEmpty(*q)) {
        return 1;
    }

    *x = (*q)->prox->valor;
    temp = (*q)->prox;
    
    // Verifica se é circular
    if (*q == (*q)->prox) {
        *q = NULL;
    }
    else {
        (*q)->prox = temp->prox;
    }

    free(temp);

    return 0;
}
