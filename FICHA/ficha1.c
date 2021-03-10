#include <stdio.h>
/*

EXERCICIO 1

1-
    int x, y;
    x = 3; y = x+1;
    x = x*y; y = x + y;
    printf("%d %d\n", x, y);

OUTPUT: 
12 16

2-
    int x, y;
    x = 0;
    printf ("%d %d\n", x, y);

OUTPUT: 
0 0

3- 
    char a, b, c;
    a = 'A'; b = ' ' ; c = '0';
    printf ("%c %d\n", a, a);
    a = a+1; c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c);
    c = a + b;
    printf ("%c %d\n", c, c);

OUTPUT:
A 65
B 66 2 50
b 98

4- 

    int x, y;
    x = 200; y = 100;
    x = x+y;y = x-y; x = x-y;
    printf ("%d %d\n", x, y);

OUTPUT: 
100 200

EXERCICIO 2

a-
    int x, y;
    x = 3; y = 5;
    if (x > y)
        y = 6;
    printf ("%d %d\n", x, y);

OUTPUT:
3 5

b-
    int x, y;
    x = y = 0;
    while (x != 11) {
        x = x+1; y += x;
    }
    printf ("%d %d\n", x, y);

OUTPUT:
10 66

c-

void f (int n) {
    while (n>0) {
        if (n%2 == 0) putchar ('0');
        else putchar ('1');
    n = n/2;
    }
    putchar ('\n');
}
    int main () {
        int i;
        for (i=0;(i<16);i++)
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

void ex3_1 (int n){
    for (int i = 0; i < n; i++){
        for (int u = 0; u < n; u++) putchar ('#'); 
        putchar ('\n');
    }
}

void ex3_2(int n){
    for (int i = 0; i < n; i++){
        for (int u = 0; u < n; u++){
            if ((i+u)%2 == 0)putchar('#');
            else putchar ('_');
        }
        putchar ('\n');
    }
}

void triangulo_horizontal (int n){
    int add = 1; 
    for (int i = 1; i <= n && i >0;i += add){
        for (int u = 0; u < i;u++)putchar('#');
        putchar('\n');
        if (i == n) add = -1;
    }
}

void triangulo_vertical (int n){
    for (int i = 0; i < n; i++){
        printf("%*s", n - (i+1), "");//fazer os espaços para cada linha -> linha 0 começa com n-1 espaços
        for (int u = 0; u < 2 * i +1; u++)putchar ('#');//para meter os # necessários. 2 * nºlinha +1
        putchar ('\n'); //mudar de linha
    }
}

int main (){
    int num;
    printf("Choose a number:\n");
    scanf ("%d",&num);
    ex3_1(num);
    putchar ('\n');
    ex3_2(num);
    putchar ('\n');
    triangulo_horizontal(num);
    putchar ('\n');
    triangulo_vertical(num);
    putchar ('\n');
}
