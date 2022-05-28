#include <stdio.h>
#include <stdlib.h>

#define Max 100

typedef struct staticStack {
    int sp;
    int values[Max];
} STACK, *SStack;

// Exercício 1 a)
void SinitStack(SStack s) {
    s->sp = 0;
}

// Exercício 1 b)
int SisEmpty(SStack s) {
    return s->sp == 0;
}

// Exercício 1 c)
int Spush(SStack s, int x) {
    if (s->sp == Max) {
        return 1;
    }

    s->values[s->sp] = x;
    s->sp++;

    return 0;
}

// Exercício 1 d)
int Spop(SStack s, int *x) {
    if (SisEmpty(s)) {
        return 1;
    }

    s->sp--;
    *x = s->values[s->sp];

    return 0;
}

// Exercício 1 e)
int Stop(SStack s, int *x) {
    if (SisEmpty(s)) {
        return 1;
    }

    *x = s->values[s->sp - 1];

    return 0;
}

typedef struct staticQueue {
    int front;
    int length;
    int values[Max];
} QUEUE, *SQueue;

// Exercício 2 a)
void SinitQueue(SQueue q) {
    q->front = 0;
    q->length = 0;
}

// Exercício 2 b)
int SisEmptyQ(SQueue q) {
    return q->length == 0;
}

// Exercício 2 c)
int Senqueue(SQueue q, int x) {
    if (q->length == Max) {
        return 1;
    }

    q->length++;
    q->values[q->front + q->length] = x;

    return 0;
}

// Exercício 2 d)
int Sdequeue(SQueue q, int *x) {
    if (SisEmptyQ(q)) {
        return 1;
    }

    *x = q->values[q->front];
    q->front++;
    q->length--;

    return 0;
}

// Exercício 2 e)
int Sfront(SQueue q, int *x) {
    if (SisEmptyQ(q)) {
        return 1;
    }

    *x = q->values[q->front];

    return 0;
}

// Exercício 3
typedef struct dinStack {
    int size;
    int sp;
    int *values;
} *DStack;

typedef struct dinQueue {
    int size;
    int front;
    int length;
    int *values;
} *DQueue;

// Exercício 3.1 a)
void DinitStack(DStack s) {
    s->size = Max;
    s->sp = 0;
    s->values = malloc(sizeof(int) * s->size);
}

// Exercício 3.1 b)
int DisEmpty(DStack s) {
    return s->sp == 0;
}

// Exercício 3.1 c)
int Dpush(DStack s, int x) {
    if (s->sp == s->size) {
        if ((s->values = realloc(s->values, s->size * 2)) == NULL) {
            return 1;
        }
        
        s->size *= 2;
    }

    s->values[s->sp] = x;
    s->sp++;

    return 0;
}

// Exercício 3.1 d)
int Dpop(DStack s, int *x) {
    if (DisEmpty(s)) {
        return 1;
    }

    s->sp--;
    *x = s->values[s->sp];

    return 0;
}

// Exercício 3.1 e)
int Dtop(DStack s, int *x) {
    if (DisEmpty(s)) {
        return 1;
    }

    *x = s->values[s->sp - 1];

    return 0;
}

// Exercício 3.2 a)
void DinitQueue(DQueue q) {
    q->size = Max;
    q->front = 0;
    q->length = 0;
    q->values = malloc(sizeof(int) * Max);
}

// Exercício 3.2 b)
int DisEmptyQ(DQueue q) {
    return q->length = 0;
}

// Exercício 3.2 c)
int Denqueue(DQueue q, int x) {
    if (q->length == q->size) {
        if ((q->values = realloc(q->values, q->size * 2)) == NULL) {
            return 1;
        }

        q->size *= 2;
    }

    q->length++;
    q->values[q->front + q->length] = x;

    return 0;
}

// Exercício 3.2 d)
int Ddequeue(DQueue q, int *x) {
    if (DisEmptyQ(q)) {
        return 1;
    }

    *x = q->values[q->front];
    q->front++;
    q->length--;

    return 0;
}

// Exercício 3.2 e)
int Dfront(DQueue q, int *x) {
    if (DisEmptyQ(q)) {
        return 1;
    }

    *x = q->values[q->front];

    return 0;
}
