#include "Population.h"

int main(){
    popu new_popu = NULL;
    new_popu = initialize_population(new_popu,10,10);
    affichage_population(new_popu);
    free_population(new_popu);
    return 0;
  
}
