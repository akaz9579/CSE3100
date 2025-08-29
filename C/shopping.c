#include <stdio.h>
#include <string.h>

int main(){

    char item[50] = "";
    float price = 0.0;
    int amount = 0;
    float total = 0.0;


    printf("What do you wanna buy? " );
    fgets(item, sizeof(item),stdin );
    item[strlen(item)-1] = '\0';

    printf("How much is it? ");
    scanf(" %f",&price);
    printf("how many do you want? ");
    scanf(" %d",&amount);

    total = price * amount;
    printf("%d %s at $%.2f is $%.2f",amount, item, price, total);

    return 0;
}