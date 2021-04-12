#include <stdio.h>
#include <string.h>

int contaVogais (char *s);
int retiraVogaisRep (char *s);
int retiraVogaisRep2 (char *s);
int duplicaVogais (char *s);
int duplicaVogais2 (char *s);
int ordenado (int v[], int N);
void merge (int a[], int na, int b[], int nb, int r[]);

int main (){
    //printf ("%d\n",contaVogais("Andrea"));
    //char str[70] = "Esta e uma string coom duplicados";
    //duplicaVogais2 (str);
    //printf ("%s\n",str);
    int array[5] = {1,3,5,7,9};
    int a[5] = {0,2,4,6,8};
    int r[10];
    merge(array,5,a,5,r);
    for (int i = 0; i < 10; i++)printf ("%d\n",r[i]);
}


int isVogal (char c){
    if (c < 97) c += 32;
    if (c == 'a') return 1;
    if (c == 'e') return 1;
    if (c == 'i') return 1;
    if (c == 'o') return 1;
    if (c == 'u') return 1;
    return 0;
}

int contaVogais (char *s){
    int result = 0;
    for (int i = 0; s[i];i++)
        result += isVogal (s[i]);
    return result;
}

void removeIndex(char s[], int n) {
    int j = n;
    while (s[j]){
        s[j]= s[j+1];
        j++;
    }
}


int retiraVogaisRep (char *s){ 
    char new[strlen(s)], ant = s[0];
    int count = 0; 
    new[0] = s[0];
    for (int i = 1, u = 1; s[i];i++){
        if (!(isVogal (s[i]) && isVogal(ant))){
            new[u++] = s[i];
            ant = s[i];
        }
        else count++;
    }
    strcpy (s,new);
    return count;
}

int retiraVogaisRep2 (char *s){
    int count = 0;
    char ant = s[0];
    for (int i = 1; s[i];i++){
        if (isVogal(s[i]) && isVogal(ant)){
            removeIndex (s,i);
            count++;
            i--;
        }
        else ant = s[i];
        
    }
}


int duplicaVogais (char *s){
    char new[strlen(s)*2];
    for (int i = 0, u = 0; s[i];i++){
        if (isVogal(s[i])){
            new[u++] = s[i];
            new[u++] = s[i];
        }
        else new [u++] = s[i];
    }
    strcpy (s,new);
}

int duplicaVogais2 (char *s){
    for (int i = 0; s[i];i++){
        if (isVogal(s[i])){
            for (int u = strlen(s); u > i+1;u--){
                s[u] = s[u-1];
            }
            s[i+1]= s[i];
            i++;
        }
    }
}

int ordenado (int v[], int N){
    for (int i = 0; i < N -1 ; i++)
        if (v[i]> v[i + 1]) return 0; 
    return 1;
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int i_a = 0, i_b = 0,i_r = 0; 
    while (i_a < na || i_b < nb){
        if (i_b == nb ||(i_a < na && a[i_a] < b[i_b])) r[i_r] = a[i_a++];
        else r[i_r] = b[i_b++];
        i_r++;
    }
}