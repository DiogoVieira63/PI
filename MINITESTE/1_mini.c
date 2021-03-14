#include <stdio.h>

int main (){ 
    for (int i = 0; i < 25; i++){
        int x = i, r = 0;
        while (x > 0) {
            r += 2;
            x = x - r;
        }
        printf("x = %d, r = %d\n",i,r);
    }
}

//int main (){
//    int x,y;
//    for (y=0;y<8;y++) {    
//        for (x=0;x<8;x++) {
//        if (x + y <= 7) putchar('#');
//        else putchar('.');
//      }
//      putchar('\n');
//    }
//}