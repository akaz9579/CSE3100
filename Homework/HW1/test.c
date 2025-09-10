#include <stdio.h>
#include <stdlib.h>


double power(double a ,int n){
		double out=1;

		for(int j=0;j<n;j++){
			out *= a;
		};

		return out;
	};





int main(){
    double n = power(2.0,4);
    printf("%f",n);

    return 0;
}


