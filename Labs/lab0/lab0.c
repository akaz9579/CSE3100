#include <stdio.h>
int main(void)
{
    printf("Hello, World!\n");
    int i = 198;
    int out = 0;

    while(i !=0){
        out += i;
        i-=2;
    }
    printf("%d",out);

    return 0;
}