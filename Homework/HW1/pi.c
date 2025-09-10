#include <stdio.h>
#include <stdlib.h>


double power(double a ,int n){
		double out=1;

		for(int j=0;j<n;j++){
			out *= a;
		};

		return out;
	};

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);

	double pi = 0.;
	//TODO
	//add code below 
	double sum = 0.0;


	for(i=0;i<=n;i++){

		double frac = 1.0/power(16.0,i);

		sum+= ( (4/(8.0*i+1)) - (2/(8.0*i+4)) - (1/(8.0*i+5)) - (1/(8.0*i+6))) *frac;
		
	};
	
	pi = sum;
	printf("PI = %.10f\n", pi);
	return 0;
}
