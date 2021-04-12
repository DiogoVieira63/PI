#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX(a,b) a > b ? a : b
#define quadrado(a) pow (a,2)

//exercicio 1 

/*
a)
CICLO FOR:
1ºiteração:1 1 4
2ºiteração:2 2 6
3ºiteração:3 3 8
4ºiteração:4 4 10
5ºiteração:5 5 12
 

b)
13s
*/

void swapM (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void swap (int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int soma (int v[],int N){
    int sum = 0; 
    for (int i = 0; i < N;i++) sum += v[i];
    return sum;
}


void inverteArray1 (int v[], int N){
    int new[N];
    for (int i = N-1, u = 0; i >= 0; i--,u++)
        new[u] = v[i];
    for (int i = 0; i < N;i++) v[i] = new[i];
}

void inverteArray2 (int v[], int N){
    for (int i = 0; i < N/2;i++)
        swap(v,i, N-1-i);
}

int maximum (int v[], int N, int *m){
    if (N == 0)return 1;
    *m = INT_MIN;
    for (int i = 0; i < N;i++)
        *m = MAX (*m,v[i]);
    return 0;
}

void quadrados (int q[], int N){
    for (int i = 0; i < N;i++)
        q[i] = quadrado (i);
}

void quadrados2 (int q[],int N){
    q[0] = 0;
    for (int i = 1; i < N;i++)
        q[i] = q[i-1] + (2*(i-1)+1);

}

void pascal (int v[],int N){
    N--;
    v[0] = 1;
    v[N] = 1;
    for (int i = 0; i < N/2;i++){
        int x = (v[i] * (N-i))/ (i+1);
        v[i+1] = x; v[N-1-i] =x;
    }    
}

void write_pascal (int N){
    for (int i = 1; i <= N;i++){
        if (i != N)printf("%*c",(N-i), ' ');
        int line[i];
        pascal (line,i);
        for (int u = 0; u < i; u++)printf ("%d ",line[u]);
        putchar ('\n');
    }
}

int main (){
    write_pascal (5);
}
