#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

LInt newLInt(int x, LInt xs) {
    LInt r = malloc(sizeof(struct slist));

    if (r != NULL) {
        r->valor = x;
        r->prox = xs;
    }

    return r;
}

typedef LInt Stack;

typedef struct {
    LInt inicio, fim;
} Queue;

// Exercício 1
void initStack(Stack *s) {
    *s = NULL;
}

int SisEmpty(Stack s) {
    return s == NULL;
}

int push(Stack *s, int x) {
    LInt new = newLInt(x, (*s));

    if (new != NULL) {
        (*s) = new;
        return 1;
    }

    return 0;
}

int pop(Stack *s, int *x) {
    if ((*s) == NULL) {
        return 1;
    }

    *x = (*s)->valor;
    (*s) = (*s)->prox;

    return 0;
}

int top(Stack s, int *x) {
    if (s == NULL) {
        return 1;
    }

    *x = s->valor;

    return 0;
}

// Exercício 2
void initQueue(Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty(Queue q) {
    return q.inicio == NULL;
}

int enqueue(Queue *q, int x) {
    LInt new = newLInt(x, NULL);

    if (new != NULL) {
        if (QisEmpty(*q)) {
            q->inicio = new;
            q->fim = new;
        }
        else {
            q->fim->prox = new;
            q->fim = new;
        }

        return 0;
    }

    return 1;
}

int dequeue(Queue *q, int *x) {
    if (QisEmpty(*q)) {
        return 1;
    }

    *x = q->inicio->valor;
    
    LInt temp = q->inicio;
    q->inicio = q->inicio->prox;

    if (q->inicio == NULL) {
        q->fim = NULL;
    }

    free(temp);

    return 0;
}

int frontQ(Queue q, int *x) {
    if (QisEmpty(q)) {
        return 1;
    }

    *x = q.inicio->valor;

    return 0;
}

// Exercício 3
typedef LInt QueueC;

void initQueueC(QueueC *q) {
    (*q) = NULL;
}

int QisEmptyC(QueueC q) {
    return q == NULL;
}

int enqueueC(QueueC *q, int x) {
    if (QisEmptyC(*q)) {
        (*q) = newLInt(x, NULL);

        if ((*q) == NULL) {
            return 1;
        }

        (*q)->prox = (*q);
    }
    else {
        LInt new = newLInt(x, NULL);

        if (new == NULL) {
            return 1;
        }

        QueueC temp = (*q);
        
        while (temp != (*q)->prox) {
            q = &((*q)->prox);
        }

        new->prox = temp;
        (*q)->prox = new;
    }

    return 0;
}

int dequeueC(QueueC *q, int *x) {
    if (QisEmptyC(*q)) {
        return 1;
    }

    *x = (*q)->prox->valor;
    LInt temp = (*q)->prox;

    if ((*q) == (*q)->prox) {
        *q = NULL;
    }
    else {
        (*q)->prox = temp->prox;
    }

    free(temp);

    return 0;
}

int frontC(QueueC q, int *x) {
    if (QisEmptyC(q)) {
        return 1;
    }

    *x = q->valor;

    return 0;
}

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;

// Exercício 4
DList newDList(int x, DList xs) {
    DList r = malloc(sizeof(struct dlist));
    
    if (r != NULL) {
        r->valor = x; 
        r->prox = xs; 
        r->ant = NULL;
    }
    
    return r;
}

void initDeque(Deque *q) {
    q->back = NULL;
    q->front = NULL;
}

int DisEmpty(Deque q) {
    return q.front == NULL && q.back == NULL;
}

int pushBack(Deque *q, int x) {
    DList new = newDList(x, NULL);
    new->ant = q->back;

    if (q->back == NULL) {
        q->front = new;
    }
    else {
        q->back->prox = new;
    }
    
    q->back = new;
    
    return 0;
}

int pushFront(Deque *q, int x) {
    DList new = newDList(x, q->front);

    if (new == NULL) {
        return 1;
    }

    if (q->front == NULL) {
        q->back = new;
    }
    else {
        q->front->ant = new;
    }

    q->front = new;

    return 0;
}

int popBack(Deque *q, int *x) {
    if (q->back == NULL) {
        return 1;
    }

    DList temp = q->back;
    *x = q->back->valor;
    q->back = temp->ant;
    free(temp);

    if (q->back != NULL) {
        q->back->prox = NULL;
    }
    else {
        q->front = NULL;
    }

    return 0;
}

int popFront(Deque *q, int *x) {
    if (q->front == NULL) {
        return 1;
    }

    DList temp = q->front;
    *x = q->front->valor;
    q->front = q->front->prox;
    free(temp);

    if (q->front != NULL) {
        q->front->ant = NULL;
    }
    else {
        q->back = NULL;
    }

    return 0;
}

int popMax(Deque *q, int *x) {
    DList max = q->front;

    if (max == NULL) {
        return 1;
    }

    DList temp = max;

    while (temp->prox != NULL) {
        if (temp->valor > max->valor) {
            max = temp;
        }

        temp = temp->prox;
    }

    *x = max->valor;

    if (max->ant == NULL) { // Primeiro elemento da queue
        if (max->prox != NULL) { // Único elemento da queue
            q->back = NULL;
            q->front = NULL;
        }
        
        q->front = max->prox;
        max->prox->ant = NULL;
    }
    else if (max->prox != NULL) { // Último elemento da queue
        q->back = max->ant;
        max->ant->prox = NULL;
    }

    free(max);

    return 0;
}

int back(Deque q, int *x) {
    if (q.back == NULL) {
        return 1;
    }
    
    *x = q.back->valor;

    return 0;
}

int front(Deque q, int *x) {
    if (q.front == NULL) {
        return 1;
    }

    *x = q.front->valor;

    return 0;
}
