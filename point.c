#include <stdio.h>
//lalala
int main(){
    int x = 21;
    int *P = &x;

    printf("x: %d\n",x);
    printf("&x: %p\n",&x);
    printf("*P: %d\n",*P);
    printf("P point %p\n",P);
    printf("&*P  %p\n",&*P);
    x = 23;
    printf("x: %d\n",x);
    printf("&x: %p\n",&x);
    printf("*P: %d\n",*P);
    printf("P point: %p\n",P);
    printf("&*P %p\n",&*P);



    return 0;
}