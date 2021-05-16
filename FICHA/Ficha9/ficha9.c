#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

#define MAX(a,b) a > b ? a : b

int altura (ABin tree){
    if (!tree)return 0;
    int esq = 1 + altura (tree->esq);
    int dir = 1 + altura (tree->dir);
    return MAX(esq,dir);
}



void imprimeAUx (ABin t, char s[]){
  if (t){
    int length =strlen (s);
    printf ("%s%d\n",s,t->valor);
    char left[length+2];
    strcpy (left,s);
    char right[length+2];
    strcpy (right,s);
    char r = '>';
    char l = '<';
    imprimeAUx (t->dir,strncat(right,&r,1));
    imprimeAUx (t->esq,strncat(left,&l,1));
  }
}

void imprime(ABin t){
  char s[] = "";
  imprimeAUx (t,s);
}


int nFolhas (ABin tree){
    if (!tree) return 0;
    return 1 + nFolhas (tree->esq) + nFolhas (tree->dir);

}

ABin maisEsquerda (ABin tree){
    if (!tree)return NULL;
    if (tree->esq) return maisEsquerda (tree->esq);
    else return tree;
    
}

void imprimeNivel (ABin tree, int l){
    if (!tree) return;
    if (!l)
        printf ("%d\n",tree->valor);
    else {
        imprimeNivel (tree->dir,l-1);
        imprimeNivel (tree->esq,l-1);
    }
}

int procuraE (ABin tree, int x){
    if (!tree) return 0;
    if (tree->valor == x) return 1;
    return procuraE (tree->esq,x) || procuraE (tree->dir,x);
}

//arvores de procura


struct nodo *procura (ABin tree, int x){
    if (!tree) return NULL;
    if (tree->valor == x) return tree;
    if (tree->valor > x) return procura (tree->esq,x);
    if (tree->valor < x) return procura (tree->dir,x);
}


int nivel (ABin tree, int x){
    if (!tree) return -1;
    if (tree->valor == x) return 0;
    if (tree->valor > x) {
        int esq = nivel(tree->esq,x);
        return esq == -1 ? -1 : 1 + esq;
    }
    if (tree->valor < x){
        int dir = nivel (tree->dir,x);
        return dir == -1 ? -1 : 1 + dir;
    }
}

void imprimeAte (ABin tree, int x){
    if (!tree) return;
    if (tree->valor >= x) imprimeAte (tree->esq,x);
    else
    {
        imprimeAte (tree->esq,x);
        printf ("%d\n",tree->valor);
        imprimeAte (tree->dir,x);
    }    
}

int main (){
    ABin tree;
    tree = newABin (2,NULL,NULL);
    tree->esq = newABin (1,NULL,NULL);
    tree->dir = newABin (3,NULL,NULL);
    tree->dir->dir = newABin (4,NULL,NULL);
    imprime (tree);
    imprimeAte (tree,4);
    //printf ("n folhas -> %d\n",nFolhas (tree));
    //printf ("Altura -> %d\n",altura (tree));
    //ABin esquerda = maisEsquerda (tree);
    //imprime (esquerda);
    //imprimeNivel (tree,0);
    //printf ("%d\n",procuraE(tree,5));
    //printf ("%d\n",nivel (tree,2));
}