#include <stdio.h>
#include <stdlib.h>
#define tamv 9

void imprimevetor(int v[], int tamanho)
{	
	int *p, cont=0;
	p = v;
		
	while(cont<tamanho)
	{
		printf("\n[%d} = %d", cont, *p++);
		cont++;
	}
	printf ("\n");
}

void menoremaior(int v[], int tamanho, int *min, int *max)
{
	int i=0, menor=100000, maior=0;
	
	for (i=0; i<tamanho; i++)
	{
		if (v[i] < menor)
		{
			menor = v[i];
			*min = v[i];
		}
		
		else if (v[i] > maior)
		{
			maior = v[i];
			*max = v[i];
		}	
	}

	printf ("\nO elemento de menor valor eh o = %d", *min);
	printf ("\nO elemento de maior valor eh o = %d\n", *max);
}

void somavetores (int *vetor1, int tamvetor1, int *vetor2, int tamvetor2, int *vetorsoma)
{
	int i=0, tamvetorsoma=0, auxiliar=0;
	
	//vetor1 = (int *) malloc(tamvetor1 * sizeof(int));
	
	printf ("\nDigite os elementos do vetor 1: ");
	
	for (i=0; i<tamvetor1; i++)
	{
		scanf("%d", &vetor1[i]);
	}
	
	//vetor2 = (int *) malloc(tamvetor2 * sizeof(int));
	
	printf ("\nDigite os elementos do vetor 2: ");
	
	for (i=0; i<tamvetor2; i++)
	{
		scanf("%d", &vetor2[i]);
	}
	
	if (tamvetor1 > tamvetor2){
		tamvetorsoma = tamvetor1;
	}
	else if (tamvetor2 > tamvetor1){
		tamvetorsoma = tamvetor2;
	}
	else if (tamvetor1 == tamvetor2){
		tamvetorsoma = tamvetor1;
	}	
		
	vetorsoma = (int*) calloc(tamvetorsoma, sizeof(int));
	
	if (tamvetor1 > tamvetor2)
	{
		auxiliar = tamvetor2;
		for (i=0; i<tamvetorsoma; i++)
		{
			if (i == auxiliar)
			{
				vetorsoma[i] = vetor1[i];
				auxiliar++;
			}else{
				vetorsoma[i] = vetor1[i] + vetor2[i];
			}
		}
	}			
	else if (tamvetor2 > tamvetor1)
	{
		auxiliar = tamvetor1;
		for (i=0; i<tamvetorsoma; i++)
		{
			if (i == auxiliar)
			{
				vetorsoma[i] = vetor2[i];
				auxiliar++;
			}else{
				vetorsoma[i] = vetor1[i] + vetor2[i];
			}
		}
	}
	else if (tamvetor1 == tamvetor2)
	{
		for (i=0; i<tamvetorsoma; i++)
		{
			vetorsoma[i] = vetor1[i] + vetor2[i];
		}			
	}
	
	printf ("\nO vetor 3 com as somas dos elementos do vetor 1 e do vetor 2 eh:\n ");
	imprimevetor(vetorsoma, tamvetorsoma);

}

int main ()
{
	int op=1, vetor[tamv] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, minimo=0, maximo=0, tamanho=0;
	int *num3vetor1, *num3vetor2, *vetorsoma, tamvetor1=0, tamvetor2=0, tamvetorsoma=0;

	num3vetor1 = (int *) malloc(tamvetor1 * sizeof(int));
	num3vetor2 = (int *) malloc(tamvetor2 * sizeof(int));
	vetorsoma = (int*) calloc(tamvetorsoma, sizeof(int));
	
	tamanho = (sizeof(vetor)/sizeof(vetor[0]));
	
	while (op != 0)
	{
		
		printf ("\t\t\t------------------\t\t\t");
		printf ("\nDigite o numero da opcao desejada:\n" );
		printf ("\n1- Imprimir o vetor.\n2- Imprimir o menor e o maior elemento do vetor.\n3- Imprimir a soma de 2 vetores.\n0- Sair.\n");
		printf ("--> ");
		scanf ("%d", &op);
		printf ("\t\t\t------------------\t\t\t");
		
		
	
		switch (op)
		{
				case 0:
				printf ("\nSAINDO DO PROGRAMA.\n");	
				break;
				
				case 1:
				imprimevetor(vetor, tamanho);
				break;
				
				case 2:
				menoremaior(vetor, tamanho, &minimo, &maximo);
				break;
				
				case 3:
				printf("\nInforme o tamanho do vetor 1: \n");
				scanf("%d", &tamvetor1);
				printf("\nInforme o tamanho do vetor 2: \n");
				scanf("%d", &tamvetor2);
				somavetores (num3vetor1, tamvetor1, num3vetor2, tamvetor2, vetorsoma);
				break;
		}
	}
	printf ("\nSAINDO DO PROGRAMA.\n");		
		
return 0;
}
