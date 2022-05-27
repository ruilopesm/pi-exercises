#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT[6];
    float teste;
} Aluno;

// Exercício 1
int nota(Aluno a) {
    int nota_miniT = 0;

    for (int i = 0; i < 6; i++) {
        nota_miniT += a.miniT[i];
    }

    float nota_final = a.teste * 0.75 + nota_miniT * 0.25;

    if (nota_final < 9.5) {
        return 0;
    }

    return nota_final;
}

// Exercício 2
int procuraNum(int num, Aluno t[], int N) {
    int init = 0, final = N - 1, mid;

    while (init <= final) {
        mid = (init + final) / 2;

        if (t[mid].numero == num) {
            return mid;
        }
        else if (t[mid].numero > num) {
            final = mid;
        }
        else {
            init = mid;
        }
    }

    return -1;
}

// Exercício 3
void swap_aluno(Aluno t[], int i, int j) {
    Aluno temp = t[i];

    t[i] = t[j];
    t[j] = temp;
}

void ordenaPorNum(Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (t[i].numero > t[j].numero) {
                swap_aluno(t, i, j);
            }
        }
    }
}

// Exercício 4
void swap_pointers(int *i, int *j) {
    int temp = *i;

    *i = *j;
    *j = temp;
}

void criaIndPorNum(Aluno t[], int N, int ind[]) {
    for (int i = 0; i < N; i++) {
        ind[i] = i;
    }

    for (int i = 0; i < N; i++) {
        int min = i;
        
        for (int j = i + 1; j < N; j++) {
            if (t[ind[i]].numero > t[ind[j]].numero) {
                min = j;
            }
        }
        
        swap_pointers(ind + i, ind + min);
    }
}

// Exercício 5
void imprimeTurma(int ind[], Aluno t[], int N) {
    for (int i = 0; i < N; i++) {
        int index = ind[i];
        printf("Aluno %d: %d | %s | %lg\n", i, t[index].numero, t[index].nome, t[index].teste);
    }
}

// Exercício 6
int procuraNum_2(int num, Aluno t[], int N, int ind[]) {
    for (int i = 0; i < N; i++) {
        if (t[ind[i]].numero == num) {
            return ind[i];
        }
    }

    return -1;
}

// Exercício 7
void criaIndPorNome(Aluno t[], int N, int ind[]) {
    for (int i = 0; i < N; i++) {
        ind[i] = i;
    }

    for (int i = 0; i < N; i++) {
        int min = i;
        
        for (int j = i + 1; j < N; j++) {
            if (strcmp(t[ind[i]].nome, t[ind[j]].nome) > 0) {
                min = j;
            }
        }
        
        swap_pointers(ind + i, ind + min);
    }
}
