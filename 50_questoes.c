#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define MIN(a,b) a < b ? a : b;
#define MAX(a,b) a > b ? a : b;

void ex_1 (){
    int maior = 0;
    printf ("Escreva números (0 to stop):\n");
    while (1)
    {
        int number;
        scanf ("%d",&number);
        if (number == 0)break;
        if (number > maior) maior = number;
    }
    printf ("O maior número é %d\n",maior);
    
}

void ex_2(){
    double total = 0, n = 0;
    printf ("Escreva números (0 to stop):\n");
    while (1)
    {
        int number;
        scanf ("%d",&number);
        if (number == 0)break;
        n++;
        total += number;
    }
    printf ("A média da sequência é %f\n",total/n);
}

void ex_3 (){
    int maior = 0, snd_maior = 0;
    printf ("Escreva números (0 to stop):\n");
    while (1)
    {
        int number;
        scanf ("%d",&number);
        if (number == 0)break;
        if (number > maior) {
            snd_maior = maior;
            maior = number;
        }
        else if(number > snd_maior) snd_maior = number;
    }
    printf ("O segundo maior número é %d\n",snd_maior);
    
}

int bitsUm (unsigned int n){
    int result = 0;
    while (n)
    {
        result += n&1;
        n >>= 1;
    }
    return result;
}

int trailingZ (unsigned int n){
    int result = 0; 
    if (n == 0) return 32;
    while (n)
    {
        if (!(n&1)) result ++; 
        else break;
        n/=2;
    }
    return result;
}

int qDig (unsigned int n){
    int result = 0; 
    while (n)
    {
        result++;
        n/=10;
    }
    return result;
}

char *mystrcat(char s1[], const char s2[]) {
    int len_1 = strlen (s1), len_2 = strlen(s2);
    char *result = malloc (sizeof (char) * (len_2 + len_1));
    strcpy(result,s1);
    strcpy(result+len_1,s2);
    return result;
}

char *mystrcpy (char *dest, char source[]){
    int len = strlen (source);
    for (int i = 0; i < len; i++)dest[i] = source[i];
    return dest;
}

int mystrcmp (char s1[], char s2[]){
    int i;
    for (i = 0; s1[i] && s2[i];i++){
        if (s1[i] > s2[i]) return 1;
        if (s1[i] < s2[i]) return -1;
    }
    if (s1[i]) return 1;
    if (s2[i]) return -1;
    return 0;
}

int mystrstr (char s1[], char s2[]){
    int u = 0, inicio;
    for (int i = 0; s1[i] && s2[u];i++){
        if (!s2[u]) return inicio;
        if (s1[i] == s2[u]){
            if (u == 0) inicio = i;
            u++;
        }
        else {
            u = 0;
        }
    }
    if (!s2[u]) return inicio;
    else return -1;   
}

int is_vogal (char c){
    if (c < 96) c+= 32;
    if (c == 'a') return 1;
    if (c == 'e') return 1;
    if (c == 'i') return 1;
    if (c == 'o') return 1;
    if (c == 'u') return 1; 
    return 0;
}

void removeIndex(char s[], int n) {
    int j = n;
    while (s[j]){
        s[j]= s[j+1];
        j++;
    }
}

void mystrnoV (char s[]){
    int len = strlen (s);
    char temp[len];
    for (int i = 0; i < len; ){
        if (is_vogal(s[i])) removeIndex (s,i);
        else i++;
    } 
}

void strrev (char s[]){
    int len = strlen (s), i,u;
    char temp[len];
    for (i = len -1, u = 0; i >= 0; i--, u++)temp[u] = s[i];
    for (i = 0; i < len; i++) s[i] = temp[i];
}

void truncW (char t[], int n){
    int contagem = 0;
    for (int i = 0; t[i];i++){
        if (t[i] == ' ')contagem = 0;
        else
        {
            if (contagem >= n)removeIndex (t,i--);
            contagem++;
        }   
    }
}

//se for preciso, usar na função abaixo
char minuscula (char letter){
    if (letter < 96) letter += 32;
    return letter; 
}

char charMaisfreq (char s[]){
    if (!s[0]) return 0;
    char maisFreq = 0;
    int mais = 0;
    for (int i = 0; s[i];i++){
        int count = 0; 
        for (int u = i; s[u]; u++){
            if (s[i] == s[u]) count++;
        }
        if (count > mais) {
            mais = count;
            maisFreq = s[i];
        }
    }
    return maisFreq;
}

int iguaisConsecutivos (char s[]){
    int maior_count = 0;
    for (int i = 0; s[i];i++){
        int count = 1;
        for (int u = i+1; s[u] == s[i];u++)count++;
        if (count > maior_count) maior_count = count;
    }
    return maior_count;
}

int different (char s[], int i,int n){
    for (; i < n; i++)if (s[n] == s[i]) return 0;
    return 1;
}

int difConsecutivos (char s[]){
    int maior_count = 0, i, u;
    for (i = 0; s[i];i++){
        int count = 1;
        for (u = i+1; s[u] != s[i] && different(s,i,u) && s[u];u++)count++;
        if (count > maior_count) maior_count = count;
    }
    return maior_count;
}


int maiorPrefixo (char s1 [], char s2 []){
    int i;
    for (i = 0;s1[i] && s2[i];i++){
        if (s1[i] != s2[i]) break;
    }
    return i; 
}

int maiorSufixo (char s1 [], char s2 []){
    int i = strlen(s1)-1, u = strlen (s2) -1, count = 0;
    for (;s1[i] && s2[u];i--,u--,count++){
        if (s1[i] != s2[u]) break;
    }
    return count; 
}

int sufPref (char s1[],char s2[]){
    int i, u;
    for (i = 0, u = 0; s1[i];i++){
        if (s1[i] == s2[u])u++;
        else u = 0;
    }
    return u;
}

int contaPal (char s[]){
    int word = 0, nr_words = 0; 
    for (int i = 0; s[i];i++){
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t'){
            if (!word) nr_words++;
            word = 1;
        }
        else word = 0;
    }
    return nr_words;
}


int contaVogais (char s[]){
    int result = 0;
    for (int i = 0; s[i];i++)result += is_vogal(s[i]);
    return result;
}

int contida (char a[], char b[]){
    for (int i = 0,u; a[i];i++){
        for ( u = 0; b[u]; u++) if (a[i] == b[u]) break;
        if (!b[u]) return 0;
    }
    return 1;
}

int palindrome (char s[]){
    int u = strlen (s) ,i;
    for (i = 0; i < u/2;i++){
        if (s[i] != s[u -i -1]) return 0; 
    }
    return 1;
}

int remRep (char s[]){
   char last;
   int i;
   for (i = 0; s[i];){
        if (i == 0) last = s[i++];
        else {
             if (s[i] == last) removeIndex (s,i);
             else last = s[i++];
       }
   }
   return i; 
}

int limpaEspacos (char s[]){
    int last;
    for (int i = 0;s[i];){
        if (i == 0) last = s[i++];
        else {
            if (s[i] == ' ' && last == ' ')removeIndex(s,i);
            else last =s[i++];
        }
    }
}

void insere (int v[],int N, int x){
    int inserted = 0; 
    for (int i = 0; i < N && !inserted; i++){
        if (x < v[i]){
            for (int u = N; u > i; u--) v[u] = v[u-1];
            v[i] = x;
            inserted = 1;
        }
    }
}

void merge (int r [], int a[], int b[], int na, int nb){
    int xa = 0, xb = 0, xr = 0;
    for (; xa < na || xb < nb;xr++){
        if ((a[xa] < b[xb] || xb == nb )&& xa != na){
            r[xr] = a[xa++];
        }
        else
        {
            r[xr] = b[xb++];
        }
        
    }
}

int crescente (int a[], int i, int j){
    for (; i < j; i++){
        if (a[i] > a[i+1])return 0;
    }
    return 1;
}

void removeIndexArray (int s[], int i,int N){
    while (i < N){
        s[i]= s[i+1];
        i++;
    }

}

int retiraNeg (int v[], int N){
    int i;
    for ( i = 0; i < N;){
        if (v[i] < 0) removeIndexArray(v,i,N--);
        else i++;
    }
}

int menosFreq (int v[], int N){
    int less_count, less_result, first = 1;
    for (int u,i = 0; i < N; i=u){
        int count = 1;
        for (u = i+1; v[i] == v[u];u++)count++;
        if (first){
            less_count = count;
            less_result = v[0];
            first = 0;
        }
        else {
            if (count < less_count){
                less_count =count; 
                less_result = v[i];
            }
        }
    }
    return less_result;
}


int maisFreq (int v[], int N){
        int high_count, high_result, first = 1;
    for (int u,i = 0; i < N; i=u){
        int count = 1;
        for (u = i+1; v[i] == v[u];u++)count++;
        if (first){
            high_count = count;
            high_result = v[0];
            first = 0;
        }
        else {
            if (count > high_count){
                high_count =count; 
                high_result = v[i];
            }
        }
    }
    return high_result;
}

int maxCresc (int v[], int N){
    int max_count = -1;
    for (int i = 0,u; i < N;i =u){
        int count = 1;
        for (u = i +1; v[u-1] <= v[u] && u < N; u++)count++;
        if (count > max_count) max_count = count;
    }
    return max_count;
}

int elimRep (int v[], int N){
    for (int i = 0; i < N;i++){
        for (int u = i+1; u < N;){
            if (v[i] == v[u])removeIndexArray(v,u,N--);
            else u++;
        }
    }
    return N;
}

int elimRepOrd (int v[], int N){
    for (int i = 0; i < N;i++){
        for (int u = i+1; v[i] == v[u] && u < N;){
            if (v[i] == v[u])removeIndexArray(v,u,N--);
            else u++;
        }
    }
    return N;
}

int comunsOrd (int a[], int na, int b[], int nb){
    int i,u,result = 0;
    for (i = 0, u = 0; i < na && u < nb;){
        if (a[i] == b[u]){
            result++;
            i++;
            u++;
        }
        else if (a[i] > b[u])u++;
        else i++;
    }
    return result;
}

int comuns (int a[], int na, int b[], int nb){
    int result = 0;
    for (int i = 0; i < na;i++){
        for (int u = 0; u < nb;u++){
            if (a[i] == b[u]) {
                result++;
                break;
            }
        }
    }
    return result;
}

int minInd (int v[], int n){
    int menor = INT_MAX, menor_index = -1;
    for (int i = 0; i < n;i++){
        if (v[i] < menor){
            menor = v[i];
            menor_index =i;
        }
    }
    return menor_index;
}

void somasAc (int v[], int Ac [], int N){
    int soma = 0;
    for (int i = 0; i < N;i++){
        soma += v[i]; 
        Ac[i] = soma;
    }
}

int triSup (int N, float m [N][N]){
    for (int i = 1; i < N;i++){
        for (int u = 0; u < i; u++){
            if (m [i][u] != 0) return 0;
        }
    }
    return 1;
}

int transposta (int N, float m [N][N]){
    for (int i = 1; i < N;i++){
        for (int u = 0; u < i; u++){
            int temp = m[i][u];
            m[i][u] = m[u][i];
            m[u][i] = temp;
        }
    }
}

void addTo (int N, int M, int a [N][M], int b[N][M]){
    for (int i = 0; i< N; i++){
        for (int u = 0; u <M; u++){
            a[i][u] += b[i][u];
        }
    }
}


int unionSet (int N, int v1[N], int v2[N], int r[N]){
    for (int i = 0; i < N; i++)
        r[i] = v1[i] || v2[i];
}


int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    for (int i = 0; i < N; i++)
        r[i] = v1[i] && v2[i];
}

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    for (int i = 0; i < N;i++)
        r[i] = MIN (v1[i],v2[i]);
}

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    for (int i = 0; i < N;i++)
        r[i] = MAX (v1[i],v2[i]);
}

int cardinalMSet (int N, int v[N]){
    int result = 0; 
    for (int i = 0; i< N;i++)
        result += v[i];
    return result;
}

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;


Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    for (int i = 0; i < N; i++){
        switch (mov[i])
        {
        case Norte:
            inicial.y++;
            break;
        case Sul:
            inicial.y--;
            break;
        case Este:
            inicial.x++;
            break;
        case Oeste:
            inicial.x--;
            break;
        }
    }
    return inicial;
}

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i = 0;
    while (inicial.x != final.x && i < N)
    {
        if (inicial.x > final.x) {
            inicial.x--;
            mov[i]= Oeste;
        }
        else {
            mov[i] = Este;
            inicial.x++;
        }
        i++;
    }
    while (inicial.y != final.y && i < N)
    {
        if (inicial.y > final.y) {
            inicial.y--;
            mov[i] = Sul;
        }
        else{
            mov[i] = Norte;
            inicial.y++;
        }
        i++;
    }
    return inicial.x == final.x && inicial.y == final.y ? i : -1;
}

int maiscentral (Posicao pos[], int N){
    int index = -1;
    float result = FLT_MAX;  
    for (int i = 0; i < N;i++){
        float current = sqrt (pow(pos[i].x,2) + pow (pos[i].y,2));
        if (current < result){
            index = i;
            result = current;
        } 
    }
    return index; 
}

int vizinhos (Posicao p, Posicao pos[], int N){
    int result = 0;
    for (int i = 0; i < N;i++){
        int horizontal = abs (pos[i].x - p.x);
        int vertical = abs (pos[i].y - p.y);
        if (vertical + horizontal == 1)result++;
    }
    return result;
}

int main (){

}
