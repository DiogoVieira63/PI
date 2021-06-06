#include <stdio.h>
#include <stdlib.h>

void insereOrdenado (int array[],int number, int N){
    int inserted = 0;
    for (int i = 0; i< N;i++){
        if (number < array[i]){
            for (int u = N; u > i;u--)
                array[u] = array[u-1];
            array[i] = number;
        }
        if (number == array[i]) return;
    }
    if (!inserted) array[N] = number;
}


int sumhtpo (int n){
    int array[100];
    int N = 0;
    while (n != 1)
    {
        insereOrdenado (array,n,N++);
        if (n%2 == 0) n = n/2;
        else n = 1 + (3*n);
        if (N > 100) N = 100;
    }
    if (N < 100) return -1;
    return array[99];    
}



int moda (int v[], int N, int *m){
    if (!N)return 0;
    int repete = 0, numModa = 0, freq = 0;
    for (int i = 0; i < N;i++){
        int count = 1;
        for (int u = i +1; u < N;u++)
            if (v[u] == v[i]) count++;
        if (count > numModa){
            repete = 0;
            numModa = count;
            freq = v[i];
        }
        else if (count == numModa) {
            repete = 1;
        }
    }
    if (repete) return 0;
    *m = numModa;
    return freq;
}


typedef struct lint
{
    int valor;
    struct lint* prox;
}*LInt;



int procura (LInt *l, int x){
    LInt *l1 = l;
    while (*l1)
    {
        if ((*l1)->valor == x){
            LInt temp = *l1;
            *l1 = (*l1)->prox;
            temp->prox = *l;
            *l = temp;
            return 1;
        }
        l1 = &((*l1)->prox);
    }
    return 0;
}

typedef struct nodo {
    int valor;
    struct nodo *pai, *esq, *dir;
} *ABin;


int freeAB (ABin a){
    if (!a) return 0;
    int dir = freeAB (a->dir);
    int esq = freeAB (a->esq);
    free (a);
    return 1 + dir + esq;
}


void caminho (ABin a){
    int array[100], N = 0;
    while (a->pai)
    {
        ABin ant = a;
        a = a->pai;
        if (ant == a->dir) array[N++] = 0; 
        else array[N++] = 1;
    }
    for (int i = 0; i < N;i++){
        if (array[i] == 0)printf ("dir\n"); 
        else printf ("esq\n");
    }
    
}

void appendL (LInt *l, int x){
    LInt *l1 = l;
    while (*l1)
        l1 = &((*l1)->prox);
    *l1 = malloc (sizeof (struct lint));
    (*l1)->valor = x;
    (*l1)->prox = NULL; 
}