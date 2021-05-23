#include <stdio.h>
#include <stdlib.h>


typedef struct ligada {
    int valor;
    struct ligada *prox;
} *LInt;



int length (LInt l){
    int count = 0;
    for (LInt l1 = l; l1; l1 = l1->prox) count++;
    return count; 
}

void freeL (LInt l){
    while (l)
    {
       LInt l1 = l->prox;
       free (l);
       l = l1; 
    }
}

void imprimeL (LInt l){
    for (LInt l1 = l; l1; l1 = l1->prox)
        printf ("%d\n",l1->valor);
}

LInt reverseL (LInt l){
    LInt prev = NULL,current = l, next = NULL;
    while (current) {
        next = current->prox;
        current->prox = prev;
        prev = current;
        current = next;
    }
    l = prev;
    return l;
}


LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct ligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}


void insertOrd (LInt *l, int valor){
    LInt new = (LInt) malloc (sizeof (struct ligada));
    new->valor = valor;
    //Empty list or fist place
    if (*l == NULL ||(*l)->valor > valor ) {
        new->prox = *l;
        *l = new; 
        return;
    }

    LInt ant = NULL, prox = (*l)->prox;
    for (LInt l1 = *l;l1; l1 = l1->prox){
        if (valor < l1->valor)
            break;
        ant = l1;
        prox = l1->prox;
    } 
    ant->prox= new;
    new->prox = prox;
}

int removeOneOrd (LInt *l, int n){
    LInt *l1;
    for ( l1 = l; *l1; l1 = &((*l1)->prox)){
        if ((*l1)->valor == n){
            *l1 = (*l1)->prox; 
            return 0;
        }
    }
    return 1;
}

void appendL (LInt *l, int x);


void merge (LInt *r, LInt a, LInt b){
    *r = NULL;
    LInt l1;
    for (l1 = a;l1; l1 = l1->prox){
        appendL (r,l1->valor);
    }
    for ( l1 = b; l1; l1 = l1->prox){
        insertOrd (r,l1->valor);
    }
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    *mx = NULL;
    *Mx = NULL;
    LInt end_mx = *mx, end_Mx = *Mx;
    for (LInt l1 = l; l1; ){
        LInt temp, end;
        temp = l1;
        l1 = l1->prox;
        temp->prox = NULL;
        //mx
        if (temp->valor < x){
            if (end_mx) {
                end_mx->prox = temp; 
                end_mx = end_mx->prox;
            }
            else {
                *mx = temp;
                end_mx = *mx;
            }
        }
        //  Mx
        else {
                if (end_Mx) {
                     end_Mx->prox = temp; 
                     end_Mx = end_Mx->prox;
            }
            else {
                *Mx = temp;
                end_Mx = *Mx;
            }
        }
    }
}

LInt parteAmeio (LInt *l){
    LInt result = *l;
    int mid = length (*l)/2;
    if (!mid)return NULL;
    for (int i = 0; i < mid -1;i++) *l = (*l)->prox;
    LInt temp = *l;
    *l = (*l)->prox;
    temp->prox = NULL;
    return result;
}

int removeAll (LInt *l, int x){
    int count = 0;
    for (LInt *l1 =l; *l1; ){
        if ((*l1)->valor == x){
            *l1 = (*l1)->prox;
            count++;
        }
        else l1 = &((*l1)->prox);
    }
    return count;
}

int removeDups (LInt *l){
    for (LInt l1 = *l; l1; l1 = l1->prox)
        removeAll (&(l1->prox),l1->valor); 
}


int removeMaiorL (LInt *l){
    int maior = (*l)->valor;
    LInt *lMaior = l, *l1;
    for (l1 = &((*l)->prox); *l1; l1 = &((*l1)->prox)){
        if ((*l1)->valor > maior){
            maior = (*l1)->valor;
            lMaior = l1;
        }
    }
    *lMaior = (*lMaior)->prox;
    return maior;
}

void init (LInt *l){
    LInt *l1 = l;
    while ((*l1)->prox)
        l1 = &((*l1)->prox);
    *l1 =NULL;
}

void appendL (LInt *l, int x){
    LInt *l1 = l;
    while (*l1)
        l1 = &((*l1)->prox);
    *l1 = malloc (sizeof (struct ligada));
    (*l1)->valor = x;
    (*l1)->prox = NULL; 
}

void concatL (LInt *a, LInt b){
    LInt *l1 = a;
    while (*l1)
        l1 = &((*l1)->prox);
    *l1 = b;
}

LInt cloneL (LInt l){
    LInt result = NULL;
    for (LInt l1 = l;l1; l1 = l1->prox)
        appendL (&result,l1->valor);
    return result;
}

LInt cloneRev (LInt l){
    LInt result = NULL;
    for (LInt l1 = l; l1; l1 = l1->prox)
        result = newLInt (l1->valor,result);
    return result;
}

#define MAX(a,b) a > b ? a : b

int maximo (LInt l){
    int maior = l->valor;
    for (LInt l1 = l->prox; l1; l1 = l1->prox)
        maior = MAX (maior,l1->valor);
    return maior;
}

int take (int n, LInt *l){
    int i = 0;
    LInt *l1 = l;
    while (*l1 && i < n){
        l1 = &((*l1)->prox);
        i++;
    }
    if (*l1) freeL (*l1);
    *l1 = NULL;
    return length (*l);
    
}


int drop (int n, LInt *l){
    LInt l1 = *l, inicio = *l;
    int len = length (*l);
    for (int i = 0; i < n -1 && l1; i++)
        l1 = l1->prox;
    if (!l1) 
        *l = NULL;
    else {
        *l = l1->prox;
        l1->prox = NULL;
    }
    freeL (inicio);
    return len - length (*l);
}

LInt Nforward (LInt l, int N){
    LInt *l1 = &l;
    for (int i = 0; i < N && *l1; i++,l1 = &((*l1)->prox));
    return *l1;
}

int listToArray (LInt l, int v[], int N){
    int count = 0;
    for (LInt l1 = l; l1 && count < N; l1 = l1->prox)
        v[count++] = l1->valor;
    return count;
}

LInt arrayToList (int v[], int N){
    LInt new = NULL;
    for (int i = 0; i < N; i++)
        appendL (&new,v[i]);
    return new;
}


LInt somasAcL (LInt l){
    int soma = 0;
    LInt new = NULL;
    for (LInt l1 = l; l1; l1 = l1->prox)
        appendL (&new,soma+=l1->valor);
    return new;
}

void remreps (LInt l){
    if (!l) return;
    LInt ant = l;
    for (LInt l1 = l->prox; l1; l1 = l1->prox){
        if (l1->valor == ant->valor){
            ant->prox = l1->prox;
            free (l1);
        }
        else ant = l1;
    }
}

LInt rotateL (LInt l){
    if (!l || !l->prox)return l;
    LInt *l1, inicio = l->prox;
    for (l1 = &l; *l1; l1 = &((*l1)->prox));
    l->prox = NULL;
    *l1 = l;
    return inicio;
}

LInt parte (LInt l){
    LInt pares = NULL;
    for (LInt l1 = l; l1; l1 = l1->prox){
        if (l1->prox){
            appendL (&pares,l1->prox->valor);
            l1->prox = l1->prox->prox;
        }
    }
    return pares;
}

//ARVORES BINÁRIAS

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int altura (ABin tree){
    if (!tree)return 0;
    return MAX ( 1 + altura (tree->dir), 1 + altura(tree->esq));
}


ABin cloneAB (ABin tree){
    if (!tree) return NULL;
    ABin new =  malloc (sizeof (struct nodo));
    new->valor = tree->valor;
    new->dir = cloneAB (tree->dir);
    new->esq = cloneAB (tree->esq);
    return new;
}


void mirror (ABin *tree){
    if (!*tree)return;
    ABin temp = (*tree)->dir;
    (*tree)->dir = (*tree)->esq;
    (*tree)->esq = temp;
    mirror (&((*tree)->dir));
    mirror (&((*tree)->esq));
}

void inorderAux (ABin tree, LInt *l){
    if (!tree)return;
    inorderAux (tree->esq,l);
    appendL (l,tree-> valor);
    inorderAux (tree->dir,l);

}

void inorder (ABin tree, LInt *l){
    *l = NULL;
    inorderAux (tree,l);
}

void preorderAux (ABin tree, LInt *l){
    if (!tree)return;
    appendL (l,tree->valor);
    preorderAux (tree->esq,l);
    preorderAux (tree->dir,l);
}

void preorder (ABin tree, LInt *l){
    *l = NULL;
    preorderAux (tree,l);
}

void posorderAux (ABin tree, LInt *l){
    if (!tree)return;
    posorderAux (tree->esq,l);
    posorderAux (tree->dir,l);
    appendL (l,tree->valor);
}

void posorder (ABin tree, LInt *l){
    *l = NULL;
    posorderAux (tree,l);
}

#define MIN(a,b) a < b ? a : b

int depth(ABin a, int x) {
    if(!a) return -1;
    if(a->valor == x) return 1;

    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);

    if(esq == -1 && dir == -1) return -1;
    if(esq == -1) return 1 + dir;
    if(dir == -1) return 1 + esq;
    return MIN (dir+1,esq+1);

}


int freeAB (ABin tree){
    if (!tree) return 0;
    int dir = freeAB (tree->dir), esq = freeAB (tree->esq);
    free (tree);
    return 1 + dir +esq;
}


int pruneAB (ABin *tree, int l){
    if (!*tree)return 0;
    if (!l){
        int count= freeAB (*tree);
        *tree = NULL;
        return count;
    }
    return pruneAB (&((*tree)->esq),l-1) + pruneAB (&((*tree)->dir), l-1);
}


int iguaisAB (ABin a, ABin b){
    if (!a && !b) return 1;  
    if (!a && b) return 0;
    if (a && !b) return 0;
    if (a && b)
        if (a->valor != b->valor) return 0;
    return iguaisAB (a->esq,b->esq) * iguaisAB (a->dir,b->dir);
}

void nivelLAux (ABin tree, int n, LInt *l){
    if (!tree)return;
    if (n == 1){
        appendL (l,tree->valor);
        return;
    }
    nivelLAux (tree->esq,n-1,l);
    nivelLAux (tree->dir,n-1,l);
}

LInt nivelL (ABin tree, int n){
    LInt new = NULL;
    nivelLAux (tree,n,&new);
    return new;
}

void nivelVAux (ABin tree, int n, int v[],int *size){
    if (!tree)return;
    if (n == 1){
        v[*size] = tree->valor;
        *size += 1;
        return;
    }
    nivelVAux (tree->esq,n-1,v,size);
    nivelVAux (tree->dir,n-1,v,size);
}

int nivelV (ABin tree, int n, int v[]){
    int size = 0;
    nivelVAux (tree,n,v,&size);
    return size;
}

void dumpAbinAux (ABin tree, int v[], int N, int *size){
    if (!tree) return;
    if (N == *size) return;
    dumpAbinAux (tree->esq,v,N,size);
    v[*size] = tree->valor;
    *size += 1;
    dumpAbinAux (tree->dir,v,N,size);

}


int dumpAbin (ABin tree, int v[], int N){
    int size = 0;
    dumpAbinAux (tree,v,N,&size);
    return size;
}


int somaTotal (ABin tree){
    if (!tree)return 0;
    return tree->valor + somaTotal (tree->dir) + somaTotal (tree->esq);
}

void doNodo (ABin *tree, int valor);

ABin somasAcA (ABin tree){
    if (!tree)return NULL;
    ABin new;
    doNodo (&new,somaTotal (tree));
    new->esq = somasAcA (tree->esq);
    new->dir = somasAcA (tree->dir); 
    return new;

}


int contaFolhas (ABin tree){
    if (!tree) return 0;
    if (!tree->dir && !tree->esq) return 1;
    return contaFolhas (tree->esq) + contaFolhas (tree->dir);
}

ABin cloneMirror (ABin tree){
    if (!tree) return NULL;
    ABin new; 
    doNodo (&new,tree->valor);
    new->esq = cloneMirror(tree->dir);
    new->dir = cloneMirror(tree->esq);
    return new;
}

int addOrd (ABin *tree, int x){
    if (!*tree) {
        ABin new = malloc (sizeof (struct nodo));
        new->valor = x;
        new->dir = NULL;
        new->esq = NULL;
        *tree = new;
        return 0;
    }
    if ((*tree)->valor == x) return 1;
    if (x > (*tree)->valor) return addOrd (&((*tree)->dir),x);
    else return addOrd (&((*tree)->esq),x);
}

int lookupAB (ABin tree, int x){
    if (!tree)return 0;
    if (tree->valor == x) return 1;
    if (x > tree->valor) return lookupAB (tree->dir,x);
    else return lookupAB (tree->esq,x);
}

int depthOrdAux (ABin tree, int x){
    if (!tree) return 0;
    if (tree->valor == x) return 1;
    if (x > tree->valor) return 1 + depthOrdAux (tree->dir,x);
    else return 1 + depthOrdAux (tree->esq,x);
}

int depthOrd (ABin tree, int x){
    if (!lookupAB (tree,x)) return -1;
    return depthOrdAux (tree,x);
}

int maiorAB (ABin tree){
    if (!tree->dir) return tree->valor;
    return maiorAB (tree->dir);
}

void removeMaiorA (ABin *tree){
    if (!*tree) return;
    if (!(*tree)->dir) *tree = (*tree)->esq;
    else removeMaiorA (&((*tree)-> dir));
}

int quantosMaiores (ABin tree, int x){
    if (!tree) return 0;
    if (tree->valor > x) return 1+ quantosMaiores (tree->dir,x) + quantosMaiores (tree->esq,x);
    else return quantosMaiores (tree->dir,x);
}


void listToBTree (LInt l, ABin *tree){
    for (;l;l = l->prox)
        addOrd(tree,l->valor);
}

int deProcuraAux(ABin tree, int x, int maior) {
    if(!tree) return 1;
    if((maior && tree->valor < x) || (!maior && tree->valor > x)) return 0;
    return deProcuraAux(tree->esq,x,maior) && deProcuraAux(tree->dir,x,maior);
}

int deProcura (ABin tree) {
    if(!tree) return 1;
    int b = deProcuraAux(tree->esq,tree->valor, 0) && deProcura(tree->esq);
    int c = deProcuraAux(tree->dir,tree->valor, 1) && deProcura(tree->dir);
    return b && c;
}

void doNodo (ABin *tree, int valor){
    *tree = malloc (sizeof (struct nodo));
    (*tree)->valor = valor;
    (*tree)->dir = NULL;
    (*tree)->esq = NULL;
}


int main (){
    /*
    l = newLInt (5,l);
    l = newLInt (4,l);
    l = newLInt (3,l);
    l = newLInt (2,l);
    l = newLInt (1,l);
    //insertOrd (&l,0);
    //LInt result = parte (l);
    //imprimeL (result);
    //imprimeL (l);
    //printf ("%d\n",maximo(l));
    */
    ABin tree;
    doNodo (&tree,1);
    doNodo (&tree->dir,3);
    doNodo (&tree->esq,2);
    /*
    LInt result = NULL;
    preorder (tree,&result);
    imprimeL (result);
    */
}