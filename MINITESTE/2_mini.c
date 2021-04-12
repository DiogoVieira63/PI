#include <stdio.h>
#include <math.h>
int is_primo (int n){
    for (int num = n -1; num > 1;num--){
        if (n%num==0) return 0; 
    }
    return 1;
}


int is_oblongo (int n){
    int flag = 0;
    for (int i = 1; i < n; i++){
        if (i * (i+1) == n) return 1; 
    }
    return 0;
}

  int isPerfectSquare(int x)
    {
       int s = (int)sqrt(x); 
       return (s*s == x);
     } 

int isFibonacci(int x)
   {
      return isPerfectSquare(5*x*x + 4) ||
        isPerfectSquare(5*x*x - 4);
  }

int sumhtpo (int n){
  int r = 0, count = 0;
  while (n != 1) {
    count++;
    printf ("%d\n",n);
    r += n;
    if (n%2 == 0) n = n/2;
    else n = 1+(3*n);
  }
  printf ("The count is %d\n",count);
  return r;
}

int main (){
    //for (int i = 0; i < 100;i++){
    //    if (isFibonacci(i))printf ("%d\n",i);
    //}
    sumhtpo (27);
}