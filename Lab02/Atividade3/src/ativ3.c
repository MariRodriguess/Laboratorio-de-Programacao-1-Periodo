#include <stdio.h>
#include <stdlib.h>

int main(){

   int op;
   float N1, N2, N3, media, formula;
  
   printf("\nQual tipo de média você deseja calcular:\n");
   printf("\n1- Média Aritmética");
   printf("\n2- Média Ponderada");
   printf("\n3- Média Harmônica\n");
   scanf("%d", &op);
   
   printf("\nInsira as três notas: ");
   scanf("%f", &N1); 
   scanf("%f", &N2);
   scanf("%f", &N3);
   
   switch(op){  
    case 1:
      formula = N1+N2+N3;
      media = formula/3;
      break;
          
    case 2:
      formula = (N1*3)+(N2*3)+(N3*4);
      media = formula/(3+3+4);
      break;
          
    case 3: 
      formula = (1/N1)+(1/N2)+(1/N3);
      media = 3/formula;
      break;
          
    default:
      printf("\nNão há está opção.");
}
                          
   printf("\nA média das notas é: %.3f\n", media);

   return 0;
}