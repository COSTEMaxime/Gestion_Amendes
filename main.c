#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

#define TAILLETABLEAU 10

int main()
{
    srand(time(NULL));

    int tableau[TAILLETABLEAU] = {};

    //génération du tableau, puis tri, puis passage à la fonction qui calcule l'amende
    printf("L'amende est de %d euros\n", amende(tri(generate_tableau(tableau))));

    if (recherche(tableau,20))   {printf("Le conducteur a deja conduit en etat d'ivresse");}
        else    {printf("Le conducteur n'a jamais conduit en etat d'ivresse");}

    return 0;
}

int* generate_tableau (int tableau[])   {

    int count = 0;

    for (int i = 0; i < TAILLETABLEAU; i++) {

        int x = rand()%(20);
        if (x < 8) {}
        else if (x < 13 && count < 20)   {
            tableau[i] = 2;
            count += 2;
        }else if (x < 16 && count < 20)   {
            tableau[i] = 4;
            count += 4;
        }else if (x < 18 && count < 20)   {
            tableau[i] = 6;
            count += 6;
        }else if (count <= 20)   {

            tableau[i] = 20;
            count += 20;
        }

        if (count >= 20)    {return tableau;}
    }

    return tableau;
}

//tri par selection
int* tri (int tableau[])   {

    for (int i = 0; i < TAILLETABLEAU; i++) {

        int min = i;

        for (int j = i+1; j <= TAILLETABLEAU; j++)  {

            if (tableau[j] < tableau[min])    {min = j;}
        }

        if (min != i)  {

            int temp = tableau[i];
            tableau[i] = tableau[min];
            tableau[min] = temp;
        }
    }
    return tableau;
}

_Bool recherche  (int tableau[], int nombre) {

    int min = 0;
    int max = TAILLETABLEAU;
    int i;
    _Bool trouve = 0;

    while (!trouve && min != max) {

        i = (min+max)/2;

        if (nombre < tableau[i]) {max = i - 1;}
        else    {min = i + 1;}

    }

    if (tableau[i] == nombre)   {return 1;}

    return 0;
}

int amende (int tableau[]) {

    int amende = 0;

    for (int i = 0; i < TAILLETABLEAU; i++)  {

        switch (tableau[i]) {

        case 0 :
            break;
        case 2 :
            amende += 100;
            break;
        case 4 :
            amende += 200;
            break;
        case 6 :
            amende += 300;
            break;
        case 20 :
            amende += 400;
            break;
        default :
            printf("Erreur (tableau[%d] = %d\n", i, tableau[i]);
            break;
        }
    }
    return amende;
}
