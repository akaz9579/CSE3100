#include <stdio.h>
#include <stdlib.h>

int visited[129][129];
double two_d_random(int n)
{

	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3 as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.

	

    int x = 0, y = 0;
    int visited_count = 0;
    int total_points = (2 * n - 1) * (2 * n - 1);

    for (int i = 0; i < 129; i++) {
        for (int j = 0; j < 129; j++) {
            visited[i][j] = 0;
        }
    }

    visited[n][n] = 1;
    visited_count++;

    while (x > -n && x < n && y > -n && y < n) {
        int r = rand() % 4;
        if (r == 0) y += 1;      
        else if (r == 1) x += 1;  
        else if (r == 2) y -= 1;  
        else if (r == 3) x -= 1;  

        int array_x = x + n;
        int array_y = y + n;

        if (!visited[array_x][array_y] && x > -n && x < n && y > -n && y < n) {
            visited[array_x][array_y] = 1;
            visited_count++;
        }
    }

    return (double)visited_count / total_points;

	
}

//Do not change the code below
int main(int argc, char *argv[])
{
	int trials = 1000;
	int i, n, seed;
	if (argc == 2) seed = atoi(argv[1]);
	else seed = 12345;

	srand(seed);
	for(n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}

