# include <stdio.h>

// Exercício 1
float multInt1(int n, float m) {
    float r = 0;

    for (int i = 0; i < n; i++) {
        r += m;
    }
    return r;
}

// Exercício 2
float multInt2(int n, float m) {
    float r = 0;

    while (n > 0) {
        if (n % 2 != 0) {
            r += m;
        }
        n /= 2;
        m *= 2;
    }
    return r;
}

// Exercício 3
int mdc1(int a, int b) {
    int r = 0;
    int n = (a > b) ? b : a;

    for (int i = 1; i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            r = i;
        }
    }
    return r;
}

// Exercício 4
int mdc2(int a, int b) {;
    while (a > 0 && b > 0) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

// Exercício 5
int mdc3(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a + b;
}

// Exercício 6
// a)
int fib1(int n) {
    if (n < 2) {
        return 1;
    }
    else {
        return fib1(n - 1) + fib1(n - 2);
    }
}

// b)
int fib2(int n) {
    int r = 1;

    for (int fib0 = 1, fib1 = 1; n > 1; n--) {
        fib0 = fib1;
        fib1 = r; 
    }
    return r;
}
