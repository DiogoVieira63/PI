#include <stdio.h>

float multInt1 (int n, float m){
    float r = 0;
    for (int i = 0; i < n; i++) r += m;
    return r; 
}

float multInt2 (int n, float m){
    float r = 0;
    for (; n > 0; n /= 2) {
        if (n%2 == 1) r += m;
        m*= 2;
    }
    return r;
}

int mdc1 (int a, int b){
    int menor = a < b ? a : b, maior = menor == b ? a : b;
    for (int i = menor; i > 0; i--){
        if (menor%i == 0 && maior%i ==0) return i;  
    }
    return 1;
}

int mdc2 (int a, int b){
    while (a != b && a && b) 
    {
        if (a > b) a -= b;
        else b -= a;
    }
    return a == 0 ? b : a;   
}

int mdc3 (int a, int b){
    while (a != b && a && b)
    {
        if (a > b) a %= b;
        else b %= a;
    }
    return a == 0 ? b : a;   
}

int fib1 (int n){
    if (n < 2) return 1; 
    return fib1 (n-1) + fib1 (n-2);
}

int fib2(int n) {
    int temp, acc1 = 1, acc2 = 1;
    for(int i = 3; i <= n; i++) {
        temp = acc2;
        acc2 += acc1;
        acc1 = temp;
    }
    return acc2;
}

int main (){
    //printf("mdc is %d\n",mdc1(126,45));
    //printf("mdc is %d\n",mdc2(126,45));
    //printf("mdc is %d\n",mdc3(126,45));
    printf("%d\n",fib1 (25));
}