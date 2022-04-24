#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Exercício 1 a)
int main() {
    int x[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int *y, *z, i;
    y = x;
    z = x + 3;
    for (i = 0; i < 5; i++) {
        printf("%d %d %d\n", x[i], *y, *z);
        y = y + 1; z = z + 2;
    }
}

OUTPUT: 1 1 4
        2 2 6
        3 3 8
        4 4 10
        5 5 12
*/

/* Exercício 1 b)
int main() {
    int i, j, *a, *b;

    i = 3; j = 5;
    a = b = 42;
    a = &i; b = &j;
    i++;
    j = i + *b;
    b = a;
    j = j + *b;
    b = a;
    j = j + *b;
    printf("%d\n", j);

    return 0;
}

OUTPUT: 13
*/

// Exercício 2
void swapM(int *x, int *y) {
    int temp = *x;

    *x = *y;
    *y = temp;
}

// Exercício 3
void swap(int v[], int i, int j) {
    int temp = v[i];

    v[i] = v[j];
    v[j] = temp;
}

// Exercício 4
int soma(int v[], int N) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += v[i];
    }
    
    return total;
}

// Exercício 5 -- função 'swapM'
void inverteArray(int v[], int N) {
    for (int i = 0; i < N / 2; i++) {
        swapM(v + i, v + N - 1 - i);
    }
}

// Exercício 5 -- função 'swap'
void inverteArray_2(int v[], int N) {
    for (int i = 0; i < N / 2; i++) {
        swap(v, i, N - 1 - i);
    }
}

// Exercício 6
int maximum(int v[], int N, int *m) {
    int max = INT_MIN;

    if (N < 0) {
        return 1;
    }
    
    for (int i = 0; i < N; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    
    *m = max;
    
    return 0;
}

// Exercício 7
void quadrados(int q[], int N) {
    q[0] = 0;
    
    for (int i = 1; i < N; i++) {
        q[i] = q[i - 1] + (2 * i - 1); // 2 * (i - 1) + 1
    }
}

// Exercício 8
void pascal(int v[], int N) {
    if (N == 1) {
        v[0] = 1;
    }
    else {
        int anterior[N - 1];
        pascal(anterior, N - 1);

        v[0] = 1;
        v[N - 1] = 1;

        for (int i = 1; i < N - 1; i--) {
            v[i] = anterior[i - 1] + anterior[i];
        }
    }
}
