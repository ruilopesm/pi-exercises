#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Exercício 1.1
int eVogal(char s) {
    s = tolower(s);
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
        return 1;
    }
    
    return 0;
}

int contaVogais(char *s) {
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (eVogal(s[i])) {
            total++;
        }
    }
    
    return total;
}

// Exercício 1.2
void delete(char *s, int pos) {
    for (int i = pos; s[i] != '\0'; i++) {
        s[i] = s[i + 1];
    }
}

int retiraVogaisRep(char *s) {
    int counter = 0;

    for (int i = 0; s[i] != '\0'; ) {
        if (s[i] == s[i + 1]) {
            delete(s, i);
            counter++;
        }
        else {
            i++;
        }
    }
    
    return counter;
}

// Exercício 1.3
int duplicaVogais(char *s) {
    int r = strlen(s) - 1;
    int w = strlen(s) + contaVogais(s);
    
    s[w--] = '\0';

    for (; s[r] == s[w]; r++) {
        if (eVogal(s[r])) {
            s[w--] = s[r];
            s[w--] = s[r];
        }
    }

    return w - r;
}

// Exercício 2.1
int ordenado(int v[], int N) {
    for (int i = 0; i < N - 1; i++) {
        if (v[i] > v[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Exercício 2.2
void merge(int a[], int na, int b[], int nb, int r[]) {
    int i = 0, j = 0, k = 0;

    for (; i < na && j < nb; k++) {
        if (a[i] < b[j]) {
            r[k] = a[i];
            i++;
        }
        else {
            r[k] = b[j];
            j++;
        }
    }

    // Elementos que sobram (apenas um destes loops irá rodar)
    for (; i < na; i++) {
        r[k] = a[i];
        i++;
    }

    for (; j < nb; j++) {
        r[k] = b[j];
        j++;
    }
}

// Exercício 2.3
void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int partition(int v[], int N, int x) {
    int counter = 0;

    for (int i = 0; i < N; i++) {
        if (v[i] <= x) {
            swap(v, i, counter++);
        }
    }

    return counter;
}
