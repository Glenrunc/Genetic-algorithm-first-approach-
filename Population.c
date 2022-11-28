#include "Population.h"


lBit  ajouter_queue_bit(lBit l, Bit value)
{
    lBit new = (listBit*)malloc(sizeof(listBit));
    new->value = value;
    new->next = NULL;

    if (l != NULL) {
        lBit temp = l;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;

    } else {
        l = new;
    }

    return l;
}

lBit initialize_individu_recurssif(lBit l, int longIndiv)
{

    if (longIndiv == 0) {
        return l;
    } else {
        l = ajouter_queue_bit(l, rand() % 2);
        return initialize_individu_recurssif(l, longIndiv - 1);
    }
}

lBit initialize_individu_iteration(lBit l, int longIndiv)
{
    for (int i = 1; i <= longIndiv; i++) {
        l = ajouter_queue_bit(l, rand() % 2);
    }

    return l;
}

void affichage_individu(lBit l)
{
    if (l==NULL){
        return;
    }else{
        printf("%d", l->value);
        affichage_individu(l->next);
    }
}

int valeur_base_2_to_base_10(individu indiv1)
{
    int valueIndiv = 0;
    int longIndiv = indiv1.longIndiv;
    lBit l = indiv1.indiv;
    lBit temp = l;
    while (temp != NULL) {
        longIndiv--;
        valueIndiv = valueIndiv + PUI(longIndiv) * temp->value;
        temp = temp->next;
    }

    return valueIndiv;
}

float qualite_individu(individu indiv1)
{
    int valeurIndiv = valeur_base_2_to_base_10(indiv1);
    float X = (valeurIndiv / (float)(PUI(indiv1.longIndiv))) * (B - A) + A;
    return -(X * X);
}

void croisement_individu(individu indiv1, individu indiv2, float pCroise)
{

    lBit l1 = indiv1.indiv;
    lBit l2 = indiv2.indiv;
    lBit temp1 = l1;
    lBit temp2 = l2;
    Bit temp;

    while (temp1 != NULL) {
        if (pCroise * 100 > rand() % 100) {
            temp = temp1->value;
            temp1->value = temp2->value;
            temp2->value = temp;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

popu ajouter_queue_individu(popu Popu, int longIndiv)
{

    popu newIndiv = (population*)malloc(sizeof(population));
    (newIndiv->indivPopu).indiv = initialize_individu_recurssif((newIndiv->indivPopu).indiv, longIndiv);
    (newIndiv->indivPopu).longIndiv = longIndiv;
    newIndiv->next = NULL;

    if (Popu != NULL) {

        popu temp = Popu;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newIndiv;
    } else {
        Popu = newIndiv;
    }

    return Popu;
}

popu initialize_population(popu Popu, int longPopu, int longIndiv)
{

    if (longPopu == 0) {
        return Popu;
    } else {
        Popu = ajouter_queue_individu(Popu, longIndiv);
        return initialize_population(Popu, longPopu - 1, longIndiv);
    }
}

void affichage_population(popu Popu)
{
    if (Popu==NULL){
        return;
    }else{
        affichage_individu((Popu->indivPopu).indiv);
        printf(" qualite %.2f",qualite_individu(Popu->indivPopu));
        printf("\n");
        affichage_population(Popu->next);
    }
}
popu trouver_queue(popu Popu)
{
    popu temp = Popu;

    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}
popu partionnement(popu premierIndividu, popu dernierIndividu)
{
    popu pivot = premierIndividu;
    popu avancement = premierIndividu;
    individu temp;
    while (avancement != NULL && avancement != dernierIndividu) {

        if (qualite_individu(avancement->indivPopu) > qualite_individu(dernierIndividu->indivPopu)) {
            pivot = premierIndividu;

            temp = premierIndividu->indivPopu;
            premierIndividu->indivPopu = avancement->indivPopu;
            avancement->indivPopu = temp;

            premierIndividu = premierIndividu->next;
        }

        avancement = avancement->next;
    }
    temp = premierIndividu->indivPopu; // on place le pivot à la bonne place 
    premierIndividu->indivPopu = dernierIndividu->indivPopu;
    dernierIndividu->indivPopu = temp;

    return pivot;
}

void quick_sort_population(popu premierIndividu, popu dernierIndividu)
{
    if (premierIndividu == dernierIndividu) {
        return;
    }
    popu pivot = partionnement(premierIndividu, dernierIndividu);

    if (pivot != NULL && pivot->next != NULL) {
        quick_sort_population(pivot->next, dernierIndividu);
    }

    if (pivot != NULL && premierIndividu != pivot) {
        quick_sort_population(premierIndividu, pivot);
    }
}

void tSelect(popu Popu, int tSelect, int longPopu)
{   
    int i = 0;

    if ((longPopu - tSelect) <= 0) {
        return;
    } else {
        popu demarrage= Popu;
        popu avancement  = Popu;
        while(i<tSelect){
            demarrage=demarrage->next; //  On se place à la position tSelect 
            i++;
        }
        while(demarrage != NULL){ // Puis on copie chaque individu en partant du début 
            free_individu((demarrage->indivPopu).indiv);
            demarrage->indivPopu = copie_individu(avancement->indivPopu);
            demarrage=demarrage->next;
            avancement= avancement->next;
        }
    }
    return;
}

void free_individu(lBit Indiv)
{
    if (Indiv == NULL) {
        return;
    }
    free_individu(Indiv->next);
    free(Indiv);
}

void free_population(popu Popu)
{

    if (Popu == NULL) {
        return;
    }
    free_individu((Popu->indivPopu).indiv);
    free_population(Popu->next);
    free(Popu);
}


individu copie_individu(individu Individu){ 
    individu new_individu;
    new_individu.longIndiv = Individu.longIndiv; 
    new_individu.indiv =NULL;
    lBit temp = Individu.indiv;

    while(temp!=NULL){
        new_individu.indiv = ajouter_queue_bit(new_individu.indiv,temp->value);
        temp=temp->next;
    }    

    return new_individu;
}

//Peut être opti
popu initialize_population_vide(popu P1,int longPopu,int longIndiv){
   int i = 0;
   P1 = (popu)malloc(sizeof(population));
   (P1->indivPopu).longIndiv =longIndiv;
   (P1->indivPopu).indiv=NULL;
   P1->next =NULL;
   popu temp = P1;
   
   while (i<longPopu-1){
        temp->next = (popu)malloc(sizeof(population));
        (temp->indivPopu).longIndiv =longIndiv;
        (temp->indivPopu).indiv=NULL;
        temp->next->next = NULL;
        temp=temp->next;
        i++;
    }
    
    return P1;
}

individu selection_random_individu(popu P1,int longPopu){
    
    individu random_individu;
    popu temp_P1 = P1;
    int i = 0;
    int nombre_aleatoire = rand()% longPopu+1; 
    while(i < nombre_aleatoire-1){
        temp_P1=temp_P1->next;
        i++;
    }

    random_individu = copie_individu(temp_P1->indivPopu);
    
    return random_individu;
}

//TODO: a optimiser
popu croisement_population(popu P1,int longPopu,int longIndiv,float pCroise){
    
    int i = 0;
    popu P2 = NULL;
    P2 = initialize_population_vide(P2,longPopu,longIndiv);
    popu temp_p2 = P2;
    individu individu_temporaire_1;
    individu individu_temporaire_2;
    
    while(i<longPopu){
        individu_temporaire_1 = selection_random_individu(P1,longPopu);
        individu_temporaire_2 = selection_random_individu(P1,longPopu);
        croisement_individu(individu_temporaire_1,individu_temporaire_2,pCroise);
        temp_p2->indivPopu = individu_temporaire_1;
        temp_p2 = temp_p2->next;
        ++i;

        if (i != longPopu) {
            temp_p2->indivPopu = individu_temporaire_2;
            temp_p2 = temp_p2->next;
            ++i;
        }
    }

    return P2;
}

popu nGen(popu P1,int longPopu,int longIndiv,float pCroise,int taux_selection,int nombre_generation){ 
    int i = 0;
    popu temp =NULL;
    while(i<nombre_generation){
        temp = P1;
        P1 = croisement_population(P1,longPopu,longIndiv,pCroise);
        quick_sort_population(P1,trouver_queue(P1));
        tSelect(P1,taux_selection,longPopu);
        free_population(temp);
        ++i;
    }
    return P1;
}


