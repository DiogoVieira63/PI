#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;


//O(1)
int nota (Aluno a){
    float total = 0;
    for (int i = 0; i < 6;i++)
        total += a.miniT[i];
    total *= 0.5; 
    total += a.teste * 0.7;
    return (int)round (total);
}

//O(N)
int procuraNum (int num, Aluno t[], int N){
    for (int i = 0; i < N;i++){
        Aluno aluno = t[i];
        if (aluno.numero > num) return -1;
        if (aluno.numero == num) return i;
    }
    return -1;
}

// O(N)
void insereAluno (Aluno aluno, Aluno t[], int N){
    int inserted = 0; 
    for (int i = 0; i < N;i++){
        if (aluno.numero < t[i].numero){
            inserted = 1;
            for (int u = N; u > i;u--)
                t[u] = t[u-1];
            t[i] = aluno;
            break;
        }
    }
    if (!inserted) t[N]= aluno;
}


//insertSort | O(N^2)
void ordenaPorNum (Aluno t [], int N){
    Aluno temp[N];
    for (int i = 0; i < N;i++)
        insereAluno(t[i],temp,i);
    for (int i = 0; i < N;i++)
        t[i] = temp[i];
}

//O(N)
void criaIndPorNum (Aluno t [], int N, int ind[]){
    Aluno temp[N];
    for (int i = 0; i < N;i++)
        temp[i] = t[i];
    ordenaPorNum (temp,N);
    for (int i = 0; i < N;i++)
        ind[i] = procuraNum (t[i].numero,temp,N);
        
}

//O(N)
void imprimeTurma (int ind[], Aluno t[], int N){
    Aluno temp[N];
    for (int i = 0; i < N;i++)
        temp[ind[i]] = t[i];
    for (int i = 0; i < N;i++)
        printf ("nome: %s | numero: %d | nota %d\n",temp[i].nome, temp[i].numero,nota(temp[i]));
}


int main (){
    Aluno Turma1 [4] = {{4444, "Diogo", {2,2,1,2,2,2}, 15.8}
                      ,{2222, "Joana", {2,2,2,1,0,0}, 14.5}
                      ,{7777, "Maria", {2,2,2,2,2,2}, 20}
                      ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                      };
                      
    int ind[4];
    criaIndPorNum (Turma1,4,ind);
    imprimeTurma (ind,Turma1,4);
    //for (int i = 0; i < 4;i++){
    //    printf ("Nota = %d\n",nota (Turma1[i]));
    //}
}