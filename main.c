#include "Population.h"

int main(){
    popu new_popu = NULL;
    new_popu = initialize_population(new_popu,10,10);
    affichage_population(new_popu);
    individu new_individu = copie_individu(new_popu->indivPopu);
    printf("\n");
    affichage_individu(new_individu.indiv);
    free_individu(new_individu.indiv);
    free_population(new_popu);
    return 0;
  
}
