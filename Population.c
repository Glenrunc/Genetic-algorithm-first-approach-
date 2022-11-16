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

lBit ajouterqBit(lBit l, Bit value)
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

lBit initializeIndivRecurssif(lBit l, int longIndiv)
{

    if (longIndiv == 0) {
        return l;
    } else {
        l = ajouterqBit(l, rand() % 2);
        return initializeIndivRecurssif(l, longIndiv - 1);
    }
}

lBit initializeIndivIterration(lBit l, int longIndiv)
{
    for (int i = 1; i <= longIndiv; i++) {
        l = ajouterqBit(l, rand() % 2);
    }

    return l;
}

void affichageIndiv(lBit l)
{
    lBit temp = l;
    if (temp != NULL) {
        while (temp != NULL) {
            printf("%d", temp->value);
            temp = temp->next;
        }
    } else {
        printf("Individu not set");
    }
    printf("\n");
}

int valueBase2ToBase10(individu indiv1)
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

float qualiteIndiv(individu indiv1)
{
    int valeurIndiv = valueBase2ToBase10(indiv1);
    float X = 0;
    float r = 0;
    X = (valeurIndiv / (float)(pui(2, indiv1.longIndiv))) * (B - A) + A;
    r = -(X * X);
    return r;
}

void croisementIdiv(individu indiv1, individu indiv2, float pCroise)
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

popu ajouterqIndiv(popu Popu, int longIndiv)
{

    popu newIndiv = (population*)malloc(sizeof(population));
    (newIndiv->indivPopu).indiv = initializeIndivRecurssif((newIndiv->indivPopu).indiv, longIndiv);
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

popu initializePopu(popu Popu, int longPopu, int longIndiv)
{

    if (longPopu == 0) {
        return Popu;
    } else {
        Popu = ajouterqIndiv(Popu, longIndiv);
        return initializePopu(Popu, longPopu - 1, longIndiv);
    }
}

void affichagePopu(popu Popu)
{

    popu temp = Popu;
    int i = 1;
    while (temp != NULL) {
        printf("Individu %d: " ,i);
        affichageIndiv((temp->indivPopu).indiv);

        i++;
        temp = temp->next;
    }
}

void freeIndividu(lBit Indiv)
{
    if (Indiv == NULL) {
        return;
    }
    freeIndividu(Indiv->next);
    free(Indiv);
}

void freePopulation(popu Popu){
    
    if(Popu == NULL){
        return;
    }
    freeIndividu((Popu->indivPopu).indiv);
    freePopulation(Popu->next);
    free(Popu);

}