#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	
	int n;
	
	printf("n = ");
	scanf("%d", &n);

	int m = n;
	//add code below
	
	int arr[100];
	int sum = 0;
	int digit = 0;
	

	while(true){
		sum =0;
		while(n!=0){
			digit = n%10;
			n/=10;
			sum+=digit*digit; 	
		}
		printf("%d\n",sum);
		

		if(sum==1||sum==4){
			
			break;
		}else{
			n=sum;
		}
	}

	n= sum;


	if(n==1) printf("%d is a happy number.\n", m);
	else printf("%d is NOT a happy number.\n", m);
	return 0;
	
}


 /*
	int m = n%10;
	n= n/10;
	int o = n%10;
	n = n/10;
	int p = n%10;
	n = n/10;
	int q = n%10;


	

	printf("%d\n",m);
	printf("%d\n",o);
	printf("%d\n",p);
	printf("%d\n",q);	
*/
