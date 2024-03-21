#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double calcul_monnaie (double cash, double prix)
{
    double retour;
    retour = cash - prix;
    return retour;
}


int main ()
{
    double prix, cash;
    
    srand(time(NULL));

    prix = rand() % 10001 + ((double) rand() / RAND_MAX);
    prix = round(prix * 100) / 100;
    
    printf("Votre facture est de : %.2f Rs\n", prix);
    
    printf ("Veuillez insérer le montant :");
    scanf ("%lf", &cash);
    cash = round(cash * 100) / 100;
    
    while (cash < prix)
    {
        printf ("MONTANT INCORRECT ! SALE PAUVRE -> resaissi le montant :");
        scanf ("%lf", &cash);
        cash = round(cash * 100) / 100;
    }
    
    double retour = calcul_monnaie(cash, prix);
    printf ("Le change est de : %.2f \n\n", retour);
    
    
    double espece [] = {2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1, 0.5, 0.2, 0.05, 0.01};
    int nombre [] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    while (retour > 0.01)
    {
        for (int i = 0; i < 15; i++)
        {
            if (retour >= espece[i])
            {
                nombre[i] += 1;
                retour -= espece[i];
            }
        }
    }
    for (int i = 0; i < 7; i++ )
    {
        printf ("%d Billet(s) de %.0f\n", nombre[i], espece[i]);
    }
    
    printf ("\n");
    
    for (int i = 7 ; i < 15; i++ )
    {
        printf ("%d Pièce(s) de %.2f\n", nombre[i], espece[i]);
    }
    
    return 0;
}
