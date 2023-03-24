#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    
    int n1, n2, s, soma, ax, cont;
    
    printf ("Digite o primeiro termo para a série de Ricci: \n");
    scanf ("%d", &n1);

    printf ("Digite o segundo termo para a série de Ricci: \n");
    scanf ("%d", &n2);
    
    printf ("Digite quantas sequencias deseja: \n");
    scanf ("%d", &s);
    
    printf ("\nA série Ricci é: ");
    printf ("%d-%d", n1, n2);

    ax=n1+n2;
    soma=ax;
    
    for (cont=3; cont<=s; cont++){
        soma = soma+ax;
        printf ("-%d", ax);
        n1=n2;
        n2=ax;
        ax=n1+n2;
    }
    
    printf ("\nA soma da serie de Ricci é: %d\n", soma);
    
return 0;
}  