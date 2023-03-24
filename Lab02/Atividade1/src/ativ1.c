#include <stdio.h>
#include <stdlib.h>

int main(){

   int dias;
   float taxa, valordiaria=95, valorTotal;
  
   printf("\nDigite o número de diárias que ficará no Hotel Xulambs para saber o valor total a ser pago (diária + taxa de serviço): ");
   scanf("%d", &dias);
   
   if (dias<15)
   {
      taxa=dias*2.50;
      valorTotal=(dias*valordiaria)+taxa;
   }

   else if (dias==15)
   {   
      taxa=dias*1.50;
      valorTotal=(dias*valordiaria)+taxa;
   }
 
   else if (dias>15)
   {
      taxa=dias*0.50;
      valorTotal=(dias*valordiaria)+taxa;
   }

   printf("\nO valor total a ser pago é %.2f\n", valorTotal);

   return 0;
}
