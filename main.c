#include "Population.h"

int main(){
    srand(time(NULL));

    // ListBit l1 = NULL;
    // ListBit l2 = NULL;

    // l1 =  initializeIndivRecurssif(l1,8);
    // l2 = initializeIndivRecurssif(l2,8);

    // affichageIndiv(l1);
    // affichageIndiv(l2);

    // croisementIdiv(l1,l2,0.9);

    // affichageIndiv(l1);
    // affichageIndiv(l2);

    ListIndiv Popu1 = NULL;

    Popu1 = initializePopu(Popu1,9,8);

    affichagePopu(Popu1);

    return 0;
  
}