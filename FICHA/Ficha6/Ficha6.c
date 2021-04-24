#include <stdio.h>
#include <stdlib.h>

#define Max 100

struct staticStack {
    int sp;
    int values [Max];
};

typedef struct staticStack* SStack;

void SinitStack (SStack s){
    s->sp = 0;
}

int SisEmpty (SStack s){
    return s->sp == 0;
}

int Spush (SStack s, int x){
    if (s->sp >= Max)return 1;
    s->values[s->sp++] = x;
    return 0;
}

int Spop (SStack s, int *x){
    if (SisEmpty(s))return 1;
    *x = s->values[--s->sp];
    return 0;
}

int Stop (SStack s, int *x){
    if (SisEmpty (s))return 1;
    *x = s->values[s->sp - 1];
    return 0; 
}

struct staticQueue {
    int front;
    int length;
    int values [Max];
};

typedef struct staticQueue* SQueue;

void SinitQueue (SQueue q){
    q->length = 0;
}

int SisEmptyQ (SQueue q){
    return q->length == 0;
}

int Senqueue (SQueue q, int x){
    if (q->length - q->front == Max)return 1;
    q->values[q->front + q->length++] = x;
    return 0;
}

int Sdequeue (SQueue q, int *x){
    if (SisEmptyQ (q)) return 1;
    *x = q->front++;
    q->length--;
    return 0;
}

int Sfront (SQueue q, int *x){
    if (SisEmptyQ (q))return 1;
    *x = q->values[q->front];
    return 0;
}

typedef struct dinStack {
    int size; 
    int sp;
    int *values;
} *DStack;

void DSinitStack (DStack s){
    s->sp = 0;
    s->size = 100;
    s->values = malloc (sizeof (int) * s->size);
}

int DSisEmpty (DStack s){
    return s->sp == 0;
}

int DSpush (DStack s, int x){
    if (s->size == s->sp){
        s->size *= 2;
        s->values = realloc (s->values, sizeof (int) * s->size);
        if (!s->values) return 1;
    }
    s->values[s->sp++] = x;
    return 0;
}

int DSpop (DStack s, int *x){
    if (DSisEmpty (s)) return 1;
    *x = s->values[--s->sp];
    return 0;
}

int DStop (DStack s, int *x){
    if (DSisEmpty (s))return 1;
    *x = s->values[s->sp - 1];
    return 0; 
}


typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;

void DinitQueue (DQueue q){
    q->length = 0;
    q->size = 10;
    q->values = malloc (sizeof (int) * q->size); 
}

int DisEmptyQ (DQueue q){
    return q->length == 0;
}

int Denqueue (DQueue q, int x){
    if (q->length - q->front == q->size){
        q->size *= 2;
        q->values = realloc (q->values,sizeof (int) * q->size);
    }
    q->values[q->front + q->length++] = x;
    return 0;
}

int Ddequeue (DQueue q, int *x){
    if (DisEmptyQ (q)) return 1;
    *x = q->front++;
    q->length--;
    return 0;
}

int Dfront (DQueue q, int *x){
    if (DisEmptyQ (q))return 1;
    *x = q->values[q->front];
    return 0;
}


int main (){
    return 0;
}