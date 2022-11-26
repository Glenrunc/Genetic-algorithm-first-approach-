#include "Population.h"

int pui(int x, int y)
{
    int r = 1;
    while (y != 0) {
        r = r * x;
        y--;
    }
    return r;
}

lBit  ajouter_queux_bit(lBit l, Bit value)
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
        l = ajouter_queux_bit(l, rand() % 2);
        return initialize_individu_recurssif(l, longIndiv - 1);
    }
}

lBit initialize_individu_iterration(lBit l, int longIndiv)
{
    for (int i = 1; i <= longIndiv; i++) {
        l = ajouter_queux_bit(l, rand() % 2);
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
        valueIndiv = valueIndiv + pui(2, longIndiv) * temp->value;
        temp = temp->next;
    }

    return valueIndiv;
}

float qualite_individu(individu indiv1)
{
    int valeurIndiv = valeur_base_2_to_base_10(indiv1);
    float X = 0;
    float r = 0;
    X = (valeurIndiv / (float)(pui(2, indiv1.longIndiv))) * (B - A) + A;
    r = -(X * X);
    return r;
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

popu ajouter_queux_individu(popu Popu, int longIndiv)
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
        Popu = ajouter_queux_individu(Popu, longIndiv);
        return initialize_population(Popu, longPopu - 1, longIndiv);
    }
}

void affichage_population(popu Popu)
{
    if (Popu==NULL){
        return;
    }else{
        affichage_individu((Popu->indivPopu).indiv);
        printf("\n");
        affichage_population(Popu->next);
    }
}
popu trouver_queux(popu Popu)
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
            pivot = premierIndividu; // Pour garder le même pivot à chaque fois 

            temp = premierIndividu->indivPopu;
            premierIndividu->indivPopu = avancement->indivPopu;
            avancement->indivPopu = temp;

            premierIndividu = premierIndividu->next;
        }

        avancement = avancement->next;
    }
    temp = premierIndividu->indivPopu;
    premierIndividu->indivPopu = dernierIndividu->indivPopu;
    dernierIndividu->indivPopu = temp;

    return pivot;
}

void quickSortPopulation(popu premierIndividu, popu dernierIndividu)
{
    if (premierIndividu == dernierIndividu) {
        return;
    }
    popu pivot = partionnement(premierIndividu, dernierIndividu);

    if (pivot != NULL && pivot->next != NULL) {
        quickSortPopulation(pivot->next, dernierIndividu);
    }

    if (pivot != NULL && premierIndividu != pivot) {
        quickSortPopulation(premierIndividu, pivot);
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
        new_individu.indiv = ajouter_queux_bit(new_individu.indiv,temp->value);
        temp=temp->next;
    }    

    return new_individu;
}

individu selection_random_individu(popu P1,int longPopu){
    
    individu random_individu;
    popu temp_P1 = P1;
    int i = 0;
    int nombre_aleatoire = rand()% longPopu+1; 
    while(i < nombre_aleatoire){
        temp_P1=temp_P1->next;
        i++;
    }

    random_individu = copie_individu(temp_P1->indivPopu);

    return random_individu;
}


popu nGen(popu P1,int longPopu,float pCroise){
    popu P2 = NULL;

}


