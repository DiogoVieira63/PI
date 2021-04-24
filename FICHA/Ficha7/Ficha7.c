#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
    } * Palavras;

void libertaLista (Palavras lista){
    while (lista)
    {
        Palavras temp = lista;
        lista = lista->prox;
        free (temp);
    }  
}

int quantasP (Palavras l){
    int count = 0;
    for (Palavras l1 = l; l1; l1 = l1->prox)count++;
    return count;
}

void listaPal (Palavras l){
    Palavras l1;
    printf ("%-15s | Nº\n","Palavras");
    printf ("---------------------\n");
    for ( l1 = l; l1; l1 = l1->prox)
        printf ("%-15s | %d\n",l1->palavra,l1->ocorr);
}

char * ultima (Palavras l){
    if (!l)return NULL;
    Palavras l1;
    for (l1 = l; l1->prox; l1 = l1->prox);
    return l1->palavra;   
}

Palavras acrescentaInicio (Palavras l, char *p){
    Palavras new = malloc (sizeof (struct celula));
    new->palavra = p;
    new->ocorr = 1;
    new->prox = l;
    l = new;
    return l;
}

Palavras acrescentaFim (Palavras l, char *p){
    Palavras *l1;
    for (l1 = &l; *l1; l1 = &((*l1)->prox));
    *l1 = malloc (sizeof (struct celula));
    (*l1)->palavra = p;
    (*l1)->ocorr = 1;
    (*l1)->prox = NULL;
    return l;
}

Palavras acrescenta (Palavras l, char *p){
    int found = 0;
    Palavras *l1;
    for ( l1 = &l; *l1; l1 = &((*l1)->prox)){
        if (!strcmp (p,(*l1)->palavra)){
            found = 1;
            (*l1)->ocorr++;
            break;
        }
        if (strcmp (p,(*l1)->palavra) < 0) break; 
    }
    if (!found) {
        if (!*l1)l = acrescentaFim (l,p);
        else {
            Palavras new = malloc (sizeof (struct celula));
            new->ocorr = 1;
            new->palavra = p;
            new->prox = *l1;
            *l1 = new;
        }
    }
    return l;
}

struct celula * maisFreq (Palavras l){
    struct celula * maior = l;
    for (Palavras *l1 = &l;*l1; l1 = &((*l1)->prox))
        if ((*l1)->ocorr > maior->ocorr) maior = *l1;
    return maior;
}

int main (){
    Palavras lista;
    lista = acrescenta (lista,"Andrea");
    lista = acrescenta (lista,"Andrea");
    lista = acrescenta (lista,"Diogo");
    lista = acrescenta (lista,"Diogo");
    lista = acrescenta (lista,"Beatriz");
    lista = acrescenta (lista,"Tiago");
    lista = acrescenta (lista,"Joao");
    listaPal (lista);
    return 0;
}