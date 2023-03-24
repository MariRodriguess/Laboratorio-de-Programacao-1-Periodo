#include <stdio.h>
#include <stdlib.h>

   int main(){

   int codfuncionario, tempo;
   float salario, bonus;
   char sexo;
  
   printf("\nDigite o seu código de funcionário: ");
   scanf("%d", &codfuncionario);
   
   printf("\nDigite o seu sexo, 'F' para feminino, e 'M' para masculino: ");
   scanf(" %c", &sexo);
   
   printf("\nDigite o seu tempo de trabalho (em anos) na empresa: ");
   scanf("%d", &tempo);
   
   printf("\nDigite o valor do seu salário: ");
   scanf("%f", &salario);
   
   
   if (((sexo=='M') || (sexo=='m')) && (tempo>15))
   {
      bonus=salario*0.20;
   }

   else if (((sexo=='F') || (sexo=='f')) && (tempo>10))
   {   
      bonus=salario*0.25;
   }
 
   else if (((sexo=='M') || (sexo=='m')) && (tempo<=15))
   {
      bonus=100;
   }

  else if (((sexo=='F') || (sexo=='f')) && (tempo<=10))
   {
      bonus=100;
   }

   printf("\nParabéns!\nO valor do seu bônus de Natal é de: %.2f\n", bonus);

   return 0;
}