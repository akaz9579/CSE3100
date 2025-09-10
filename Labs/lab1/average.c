// Only this line of comment is provided 
#include <stdio.h>


int main(){
    double total, average, x;
    int count = 0;

    total = 0;
    while (scanf("%lf", &x) == 1) { 
        count += 1; 
        total += x;
        average = total/(double) count;
        printf("Total=%f Average=%f\n", total, average);
    };
    
    return 0;
}