#include "Population.h"
int main(){
    //Définition des différentes données d'une population
    srand(time(NULL));
    int taille_population = 300;
    int taux_selection = 290;
    int nombre_generation = 3;

    popu P1 = NULL;
    P1 = initialize_population(P1,taille_population,taille_individu);
    P1 = nGen(P1,taille_population,taille_individu,probabilite_croisement,taux_selection,nombre_generation);
    affichage_population(P1);
    free_population(P1);
   
    return 0;
  
}
