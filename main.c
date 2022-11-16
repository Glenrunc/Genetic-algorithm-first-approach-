#include "Population.h"

int main(){
    srand(time(NULL));
    int val;
    individu newIndiv;
    newIndiv.longIndiv = 8;
    newIndiv.indiv = NULL;
    newIndiv.indiv = initializeIndivRecurssif(newIndiv.indiv,newIndiv.longIndiv);
    affichageIndiv(newIndiv.indiv);
    val = valueBase2ToBase10(newIndiv);
    printf("%d\n",val);
    freeIndividu(&(newIndiv.indiv));
    return 0;
  
}
