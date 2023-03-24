#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){

	int n, soma=0, cont, total;

	printf ("Digite um numero inteiro positivo: ");
	scanf("%d", &n);

	for (cont=1; cont<=n; cont++){
		soma+=pow(cont,2);
	}

	total = (n*(n+1)*((2*n)+1)/6);

	printf ("\nO valor total do primeiro metodo eh '%d' e o do segundo eh '%d'. Ambos iguais!\n", soma, total);
	
return 0;		

}