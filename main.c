#include "Population.h"

int main(){
    //Définition des différentes données d'une population
    srand(time(NULL));
    int taille_population = rand()%180+20;
    int taux_selection = (rand()%90+10 *taille_population)/100;
    int nombre_generation = rand()%180+20;

    popu P1 = NULL;
    P1 = initialize_population(P1,taille_population,taille_individu);
    //debut

    P1 = nGen(P1,taille_population,taille_individu,probabilite_croisement,nombre_generation);
    quick_sort_population(P1,trouver_queux(P1));
    tSelect(P1,taux_selection,taille_population);

    affichage_population(P1);

    free_population(P1);
   
    return 0;
  
}
