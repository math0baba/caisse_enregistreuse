#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ()
{
    double prix, cash;
    srand(time(NULL));

    prix = rand() % 10001 + ((double) rand() / RAND_MAX);
    
    printf("Votre facture est de : %.2f RS\n", prix);
    
    printf ("Veuillez insérer le montant :\n");
    scanf ("%lf", &cash);
    
    while (cash < prix)
    {
        printf ("MONTANT INCORRECT ! SALE PAUVRE -> resaissi le montant :\n");
        scanf ("%lf", &cash);
 
    }
    return 0;
}
