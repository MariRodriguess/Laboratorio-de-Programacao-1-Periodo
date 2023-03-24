#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){

	int n=0, j=0, fat=0, k=0;
	float soma=0, d=0;

	printf ("\nDigite qual a sequencia:\n");
	scanf ("%d", &n);

	for (j=1; j<=n; j++){

		fat=1;
		k=j;
        d = (d*2)+1;

        while (k>1){
            fat=fat*k;
            k--;
        }

        if (j%2==0){
            soma=soma-(float)fat/d;
        }else {
            soma=soma+(float)fat/d;
        }	
    }

    printf ("O valor total %.2f\n", soma);

return 0;

}    