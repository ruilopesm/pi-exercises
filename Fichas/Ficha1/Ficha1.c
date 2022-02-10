# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/* Exercício 1.1
int x, y;
x = 3; y = x + 1;
x = x * y; y = x + y;
printf ("%d %d\n", x, y);

OUTPUT: 12 16
*/

/* Exercício 1.2
int x, y;
x = 0;
printf ("%d %d\n", x, y);

OUTPUT: 0 undefined
*/

/* Exercício 1.3
char a, b, c;
a = 'A'; b = ' '; c = '0';
printf ("%c %d\n", a, a)
a = a + 1; c = c + 2
printf ("%c %d %c %d\n", a, a, c, c);
c = a + b
printf ("%c %d\n", c, c);

OUTPUT: A 65
        B 66 2 50
        b 98
*/

/* Exercício 1.4
int x, y;
x = 200; y = 100;
x = x + y; y = x - y; x = x - y;
printf ("%d %d\n", x, y)

OUTPUT: 100 200
*/

/* Exercício 2.1 a)
int x, y;
x = 3; y = 5;
if (x > y)
    y = 6
printf ("%d %d\n", x, y)

OUTPUT: 3 5
*/

/* Exercício 2.1 b)
int x, y;
x = y = 0
while (x != 11) {
    x = x + 1; y += x;
}
printf ("%d %d\n", x, y)

OUTPUT: 66
*/

/* Exercício 2.1 c)
int i;
for (i = 0; (i < 20); i++)
    if (i % 2 == 0) putchar ('_');
    else putchar ('#');

OUTPUT: _#_#_#_#_#_#_#_#_#_#
*/

/* Exercício 2.1 d)
void f (int n) {
    while (n > 0) {
        if (n % 2 == 0) putchar ('0');
        else putchar ('1');
        n = n / 2;
    }
    putchar ('\n');
}
int main () {
    int i;
    for (i = 0; (i < 16); i++)
        f (i);
    return 0;
}
OUTPUT: 
        1
        01
        11
        001
        101
        011
        111
        0001
        1001
        0101
        1101
        0011
        1011
        0111
        1111
*/

// Exercício 3.1
void quadrado (int n) {
    for (int i = 0; (i < n); i++) {
        for (int j = 0; (j < n); j++) {
            putchar ('#');
        }
        putchar ('\n');
    }
}

// Exercício 3.2
void tabuleiro (int n) {
    for (int i = 0; (i < n); i++) {
        for (int j = 0; (j < n); j++) {
            if ((i + j) % 2 == 0) {
                putchar ('#');
            }
            else {
                putchar ('_');
            }
        }
        putchar ('\n');
    }
}

// Exercício 3.4
int circulo () {
    int raio;
    int written = 0;

    printf ("Raio: ");
    scanf ("%d", &raio);
    
    for (int i = 0; i < 2 * raio + 1; i++) {
        for (int j = 0; j < 2 * raio + 1; j++) {
            int x = raio - i;
            int y = raio - j;
            double dist = sqrt (x * x + y * y);
            if (dist <= raio) {
                putchar ('#');
                written += 1;
            }        
            else {
                putchar (' ');
            }
        }
        putchar ('\n');
    }
    return written;
}
