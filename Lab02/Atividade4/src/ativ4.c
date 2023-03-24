#include <stdlib.h>
#include <stdio.h>

int main(){
  float popRDB=90000000, popUFM=200000000;
  int i=0;
  
  while (popRDB <= popUFM)
  {
    popRDB = popRDB + (popRDB*0.03);
    popUFM = popUFM + (popUFM*0.015);
    i= i + 1;
  }
  
  printf("\nA quantidade de anos necessária para que a República Democrática dos Bruzundangas alcance ou ultrapasse a população da União Federalista do Milano é de %d anos.\n", i);
  
  return 0;
}

