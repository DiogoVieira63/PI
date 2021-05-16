#include <stdio.h>
#include <stdlib.h>


typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

typedef LInt Stack;


typedef struct {
    LInt inicio,fim;
} Queue;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; 
        r->prox = xs;
    }
return r;
}




void initStack (Stack *s){
    *s = NULL;
}


int SisEmpty (Stack s){
    return (s == NULL);
}

int push (Stack *s, int x){
    *s = newLInt (x,*s);
}

int pop (Stack *s, int *x){
    Stack *l1; 
    for (l1 = s; (*l1)->prox; l1 = &((*l1)->prox));
    if (*l1){
        *x = (*l1)->valor;
        *l1 = NULL;
    }
    else return 1;
    return 0;
}

int top (Stack s, int *x){
    if (s)*x = s->valor;
    else return 1;
    return 0;
}


void printStack (Stack s){
    for (Stack s1 =s; s1; s1 = s1->prox){
        printf ("%d\n",s1->valor);
    }
}


void initQueue (Queue *q){
    (*q).inicio = NULL;
    (*q).fim = NULL;
}

int QisEmpty (Queue q){
    return (q.inicio == NULL);
}

int enqueue (Queue *q, int x){
    int inicio = 0;
    LInt *l1 = l1 = &((*q).fim);
    if (!(*q).inicio) inicio = 1;
    else for (; *l1; l1 = &((*l1)->prox));
    *l1 = malloc (sizeof (struct slist));
    (*l1)->valor = x;
    (*l1)->prox = NULL;
    if (inicio) (*q).inicio = *l1;
    else (*q).fim = *l1;
}

int dequeue (Queue *q, int *x){
    LInt l1 = (*q).inicio;
    *x = l1->valor;
    (*q).inicio = l1->prox;
}

int front (Queue q, int *x){
    *x = q.inicio->valor;
    return 0;
}

void printQueue (Queue q){
    for (LInt l1 = q.inicio; l1 != q.fim;l1 = l1->prox) printf ("%d\n",l1->valor);
    printf ("%d\n",q.fim->valor);
}

typedef LInt QueueC;

void initQueueC  (QueueC *q){
    *q = NULL;
}

int QisEmptyC    (QueueC q){
    return (q == NULL); 
}

int enqueueC (QueueC *q, int x){
    LInt *l1 = q;
    if (*l1){
        do
        {
            l1 = &((*l1)->prox);
        } while ((*l1)->prox != *q);
        
    }
    LInt new = malloc (sizeof (struct slist));
    if (new){
        (new)->valor = x;
        (new)->prox = *q == NULL ? new : *q;
    }
    if (*q) (*l1)->prox = new;
    else (*l1) = new;
}

int dequeueC (QueueC *q, int *x){
    if (!*q) return 1;
    *x = (*q)->valor;
    LInt old = *q;
    q = &((*q)->prox);
    free (old);
    return 0;
}

int frontC (QueueC q, int *x){
    if (!q) return 1;
    *x = q->valor;
    return 0;
}

typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;



void initDeque (Deque *q){
    (*q).back = NULL;
    (*q).front = NULL;
}

int DisEmpty (Deque q){
    return (q.front == NULL);
}

int pushBack (Deque *q, int x){
    DList back = (*q).back;
    DList new = malloc (sizeof (struct dlist));
    new->valor = x;
    if (back){
        new->prox = back->prox;
        new->ant = back;
        back->prox = new;
        (*q).back = new;
    }
    else{
        new->ant = new;
        new->prox = new;
        (*q).front = new;
        (*q).back = new;
    }
}

int pushFront (Deque *q, int x){
    DList front = (*q).front;
    DList new = malloc (sizeof (struct dlist));
    new->valor = x;
    if (front){
        new->prox = front;
        new->ant = front->ant;
        front->ant = new;
        (*q).front = new;
        (*q).back->prox = new;
    }
    else{
        new->ant = new;
        new->prox = new;
        (*q).front = new;
        (*q).back = new;
    }
}

int popBack (Deque *q, int *x){
    DList back = (*q).back;
    if (back){
        *x= back->valor;
        if (back->ant != back){
            back->ant->prox = (*q).front; 
            (*q).back = back->ant;
            (*q).front->ant = (back->ant);
        }
        else {
            back = NULL;
            (*q).front = NULL;
            (*q).back = NULL;
        }
    }
}

int popFront (Deque *q, int *x){
    DList front = (*q).front;
    if (front){
        *x= front->valor;
        if (front->prox != front){
            front->prox->ant = (*q).back; 
            (*q).front = front->prox;
            (*q).back->prox = front->prox;
        }
        else {
            front = NULL;
            (*q).front = NULL;
            (*q).back = NULL;
        }
    } 
}

int popMax (Deque *q, int *x){
    if (DisEmpty (*q)) return 1;
    DList maior = (*q).front;
    DList l1;
    do
    {
        printf ("%d\n",l1->valor);
        if (l1->valor > maior->valor){
            maior = l1;
        }
        l1 = l1->prox;
    } while (l1 != (*q).front);
    
    *x = maior->valor;
    if (maior == (*q).front) popFront (q,x);
    else if (maior == (*q).back) popBack (q,x);
    else {
        if (maior != maior->prox){
            maior->prox->ant = maior->ant;
            maior->ant->prox = maior->prox;
        }
    }
}

int back (Deque q, int *x){
    if (DisEmpty(q))return 1;
    *x = q.back->valor;
    return 0;
}

int dfront (Deque q, int *x){
    if (DisEmpty(q))return 1;
    *x = q.front->valor;
    return 0;
}


void printDequeue (Deque q){
    DList dq = q.front;
    do
    {
        printf ("%d\n",dq->valor);
        dq = dq->prox;
    } while (dq != q.front);
    
}


int main (){
    /*
    Stack s;
    initStack (&s);
    push (&s,3);
    push (&s,2);
    push (&s,1);
    // printStack (s);
    int x;
    while (!SisEmpty(s))
    {
        pop (&s,&x);
        printf ("%d\n",x);
    }
    
    Queue q;
    initQueue (&q);
    enqueue (&q,1);
    enqueue (&q,2);
    enqueue (&q,3);
    //printQueue (q);
    int x;
    while (!QisEmpty (q))
    {
        dequeue (&q,&x);
        printf ("%d\n",x);
    }
    QueueC q;
    initQueueC (&q);
    enqueueC (&q,1);
    enqueueC (&q,2);
    enqueueC (&q,3);
    LInt l1 = q;
    do
    {
        printf ("%d\n",l1->valor);
        l1 = l1->prox;
    } while (l1 != q);
    
    */
    //Deque d;
    //int a,b;
    //initDeque (&d);
    //pushFront (&d,1);
    //pushBack (&d,1);
    //for (int i=0; i<10; i++){
    //    popBack (&d,&a); 
    //    back (d,&b); 
    //    pushBack (&d, a); 
    //    pushFront (&d,a+b);
    //}
   Deque dequeue;
   initDeque (&dequeue);
   pushBack (&dequeue,1);
   pushBack (&dequeue,2);
   pushBack (&dequeue,3);
   pushBack (&dequeue,4);
   pushBack (&dequeue,5);
   //pushFront (&dequeue,4);
   //pushFront (&dequeue,3);
   //pushFront (&dequeue,2);
   //pushFront (&dequeue,1);
   //printDequeue (dequeue);
   int x;
   //while (!DisEmpty (d))
   //{
   //    popFront (&d,&x);
   //    printf ("- %d\n",x);
   //}
   popMax (&dequeue,&x);
   printf ("maior is %d\n",x);
   

}   