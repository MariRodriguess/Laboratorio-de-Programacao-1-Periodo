#include <stdio.h>
#include <stdlib.h>

int main (){

    int n, xlinha, quantnumlinha, tamanho = 0;

    printf ("\nDigite um numero inteiro para o seu Triangulo de Floyd:");
    scanf ("%d",&n);
    
    for (xlinha = 1; xlinha <= n; xlinha++){
        for (quantnumlinha=1; quantnumlinha <= xlinha; quantnumlinha++){
            tamanho++;
            printf("%d\t",tamanho);
        }
        printf("\n");
    }
     
    return 0;   
}     