#include "Population.h"

int main()
{
    srand(time(NULL));
    //VersionBeta
    // Définition des différentes données d'une population
    int taille_population, taux_selection, nombre_generation,n = -1;

    //récupération depuis l'utilisateur
    get_integer(&taille_population,20,200,"population");
    get_integer(&taux_selection,10,90,"taux de selection");
    get_integer(&nombre_generation,20,200,"generation");
    get_integer(&n,0,1,"affichage");

    //Lancement de la simulation
    popu P1 = NULL;
    P1 = initialize_population(P1, taille_population, taille_individu);
    P1 = nGen(P1, taille_population, taille_individu, probabilite_croisement, taux_selection, nombre_generation,n);

    //affichage du meilleur individu
    quick_sort_population(P1,trouver_queue(P1));
    if(n == 1){
        printf("Taille Population : %d ~ Taux de selection : %d   ~ Nombre de generations : %d \n ",taille_population,taux_selection,nombre_generation);
    }
    printf("\n MEILLEUR INDIVIDU ~qualite (%.3f)~  ~decodage (%d)~ :  ",qualite_individu_f2(P1->indivPopu),valeur_base_2_to_base_10(P1->indivPopu));
    affichage_individu(P1->indivPopu.indiv);
    printf("\n");

    //Libération de la mémoire allouée par la population
    free_population(P1);

    return EXIT_SUCCESS;
}


