#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define n 100 

int cont=0;

typedef struct carros
{
	char modelo[10];
	char fabricante[10];
	int ano;
	float consumo;

}carro;

void quantcarroscadastrados(carro cars[n])
{
	int i=0;
	for(i=0; i<n; i++)
	{
		if(cars[i].consumo!=-1)
		{
			cont++;
		}
	}
}

carro cars[n];

void cadastro(carro cars[n])
{
	int tam=0, i=0;

	for(i=0 ; i<n; i++)
	{
		if(cars[i].consumo == -1)
		{
			getc(stdin);
			printf("\nDigite o modelo do carro: ");
			fflush(stdin);
			fgets(cars[i].modelo,10,stdin);
			tam=strlen(cars[i].modelo);
			cars[i].modelo[tam-1]='\0';

			printf("Digite o fabricante do carro: ");
			fflush(stdin);
			fgets(cars[i].fabricante,10,stdin);
			tam=strlen(cars[i].fabricante);
			cars[i].fabricante[tam-1]='\0';

			printf("Digite o ano de fabricação: ");
			scanf("%d",&cars[i].ano);

			printf("Digite o consumo do carro (km/l): ");
			scanf("%f",&cars[i].consumo);
			i = n;
			getc(stdin);
		}
	}
	
	for (i=0; i<=tam; i++)
	{
		    cars[cont].fabricante[i] = tolower(cars[cont].fabricante[i]);
	}
	
}
		
void imprimevetor (carro cars[n])
{
	int i=0;

	for (i=0; i<n; i++)
	{
		if(cars[i].consumo != -1)
		{
			for(i=0; i<cont; i++)
			{
				printf ("\n[%d] = %s - %s - %d - %f", i, cars[i].modelo, cars[i].fabricante, cars[i].ano, cars[i].consumo);
			}	
		}
	}
}

void listarfabrincante(carro cars[n])
{

	int i=0, tam=0, aux=0;
	char listfabricante[10];

	if(cont == 0)
	{
		printf("\nNão ha nenhum carro cadastrado, reinicie seu codigo e cadastre.");
	}

	if(cont != 0)
	{
		printf("\nDigite o fabricante que vc deseja listar: ");
		getc(stdin);
		fgets(listfabricante,10,stdin);
		listfabricante[strlen(listfabricante)-1]='\0';
		tam=strlen(listfabricante);

		for(i=0; i<=tam; i++)
		{
			listfabricante[i]=tolower(listfabricante[i]);
		}

		for(i=0; i<=tam; i++)
		{
			cars[n].fabricante[i]=tolower(cars[n].fabricante[i]);
		}

		printf("\nOs carros cadastrados do fabricante %s sao:\n", listfabricante);

		for(i=0; i<n; i++)
		{
			if(strcmp(listfabricante, cars[i].fabricante)==0)
			{
				printf("\n%s",cars[i].modelo);
				aux++;
			}
		}
	
		if(aux==0)
		{
			printf("\nNão há nenhum carro cadastrado desse fabricante!\n");
		}
	}

	printf("\n");
}

void removercarros(carro cars[n])
{
	int remover=0, i=0, j=0;

	if(cont == 0)
	{
		printf("\nNão ha nenhum carro cadastrado, reinicie seu codigo e cadastre.\n");
	}

	if(cont!=0)
	{
		printf ("\nDigite o número de qual desses carros deseja remover: ");
		imprimevetor(cars);
        printf ("\n");
		scanf("%d", &remover);

		for (i=0; i<cont; i++)
		{
			if (i==remover)
			{
				if(cars[i+1].consumo != -1)
				{
					for (j=remover; j<cont; j++)
					{
						cars[j].ano = cars[j+1].ano;
						cars[j].consumo = cars[j+i].consumo;
						strcpy(cars[j].modelo, cars[j+1].modelo);
						strcpy(cars[j].fabricante, cars[j+1].fabricante);

					}	
				}
				else
				{
					cars[i].consumo = -1;
				}
			}
		}
		cont--;
		printf("\nO carro foi removido com sucesso!\nAgora restam %d carros.", cont);

	}	
}

void economico(carro cars[n])
{
	int i=0, aux=0;
	char copiamodelo[10];

	if(cont == 0)
	{
		printf("\nNão ha nenhum carro cadastrado, reinicie seu codigo e cadastre.\n");
	}else{
		for(i=0; i<cont; i++)
		{
			if(cars[i].consumo>aux)
			{
				aux=cars[i].consumo;
			}

		}

		for (i=0; i<cont; i++)
		{
			if (cars[i].consumo == aux)
			{
				strcpy(copiamodelo,cars[i].modelo);
				printf("\nCarro mais economico = %s",copiamodelo);

			}	
		}
	}		
}

void maiorconsumo (carro cars[n])
{
	int i, aux=1000000;
	char copiamodelo[10];

	if(cont == 0)
	{
		printf("\nNão ha nenhum carro cadastrado, reinicie seu codigo e cadastre.\n");
	}else{

		for(i=0; i<cont; i++)
		{
			if(cars[i].consumo<aux)
			{
				aux=cars[i].consumo;
			}

		}

		for (i=0; i<cont; i++)
		{
			if (cars[i].consumo == aux)
			{
				strcpy(copiamodelo,cars[i].modelo);
				printf("\nCarro que consome mais:  %s",copiamodelo);

			}	
		}

	}	

}

void carromaisnovo (carro cars[n])
{
	int i=0, j=0, aux=0;
	char copiamodelo[10];

	if(cont == 0)
	{
		printf("\nNão ha nenhum carro cadastrado, reinicie seu codigo e cadastre.\n");
	}else{

		for(i=0; i<cont; i++)
		{
			if(cars[i].ano>aux)
			{
				aux=cars[i].ano;
			}
		}	
		for(j=0; j<cont; j++)
		{
			if (cars[j].ano == aux)	
			{	
				strcpy(copiamodelo,cars[j].modelo);
				printf("\nCarro mais novo = %s, foi fabricado em = %d",copiamodelo, aux);
			}
		}
	}

}	

int main()
{
	FILE *arq;
	int i=0, op=1;
	carro cars[n];

	arq = fopen("dados.bin", "rb");
	if (arq == NULL)
	{
		arq = fopen ("dados.bin", "wb");

		for(i=0; i<n; i++)
		{
			cars[i].consumo=-1;
		}
		cont=0;
	}
	else
	{
		fread (cars, sizeof(carro), n, arq);
		quantcarroscadastrados(cars);
	}

	fclose(arq);

	while(op!=0)
	{
		printf("\n\t\t   MENU   \t\t\n");
		printf("\nDigite o numero da opcao desejada\n");
		printf("\n1 - Cadastrar carro.");
		printf("\n2 - Remover carro.");
		printf("\n3 - Listar carros de determinado fabricante.");
		printf("\n4 - Listar carro mais economico.");
		printf("\n5 - Listar o carro com maior consumo.");
		printf("\n6 - Listar o carro mais novo.");
		printf("\n7 - Imprimir o vetor.");
		printf("\n0 - Sair.\n");
        printf("-> ");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
			cadastro(cars);
			cont++;
			break;

			case 2:
			removercarros(cars);
			break;

			case 3:
			listarfabrincante(cars);
			break;

			case 4:
			economico(cars);
			break;

			case 5:
			maiorconsumo(cars);
			break;

			case 6:
			carromaisnovo(cars);
			break;

			case 7:
			imprimevetor(cars);
			break;

			case 0:
			break;
		}
		
	}

	arq = fopen ("dados.bin", "wb");
	fwrite(cars, sizeof(carro), n, arq);
	fclose(arq);
	
 return 0;
}	
