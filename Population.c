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

ListBit ajouterqBit(ListBit l, Bit value)
{
    ListBit new = (Individu*)malloc(sizeof(Individu));
    new->value = value;
    new->next = NULL;

    if (l != NULL) {
        ListBit temp = l;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;

    } else {
        l = new;
    }

    return l;
}

void affichageIndiv(ListBit l)
{
    ListBit temp = l;
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

ListBit initializeIndivIterration(ListBit l, int longIndiv)
{

    for (int i = 1; i <= longIndiv; i++) {
        l = ajouterqBit(l, rand() % 2);
    }

    return l;
}

ListBit initializeIndivRecurssif(ListBit l, int longIndiv)
{

    if (longIndiv == 0) {
        return l;
    } else {
        l = ajouterqBit(l, rand() % 2);
        return initializeIndivRecurssif(l, longIndiv - 1);
    }
}

int ValueBase2ToBase10(ListBit l, int longIndiv)
{
    int valueIndiv = 0;
    ListBit temp = l;
    while (temp != NULL) {
        longIndiv--;
        valueIndiv = valueIndiv + pui(2, longIndiv) * temp->value;
        temp = temp->next;
    }

    return valueIndiv;
}

float qualiteIndiv(int valeurIndiv, int longIndiv)
{
    float X = 0;
    float r = 0;
    X = (valeurIndiv / (float)(pui(2, longIndiv))) * (B - A) + A;
    r = -(X * X);
    return r;
}

void croisementIdiv(ListBit l1, ListBit l2, float pCroise)
{

    ListBit temp1, temp2;
    temp1 = l1;
    temp2 = l2;
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

ListIndiv ajouterqIndiv(ListIndiv Popu, int longIndiv)
{

    ListIndiv newIndiv = (Population*)malloc(sizeof(Population));
    newIndiv->Indiv = initializeIndivRecurssif(newIndiv->Indiv, longIndiv);
    newIndiv->next = NULL;

    if (Popu != NULL) {

        ListIndiv temp = Popu;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newIndiv;
    } else {
        Popu = newIndiv;
    }

    return Popu;
}

ListIndiv initializePopu(ListIndiv Popu, int longPopu, int longIndiv)
{

    if (longPopu == 0) {
        return Popu;
    } else {
        Popu = ajouterqIndiv(Popu, longIndiv);
        return initializePopu(Popu, longPopu - 1, longIndiv);
    }
}

void affichagePopu(ListIndiv Popu)
{

    ListIndiv temp = Popu;
    int i = 1;
    while (temp != NULL) {
        printf("Individu %d :  ", i);
        affichageIndiv(temp->Indiv);
        i++;
        temp = temp->next;
    }
}

void freeIndividu(ListBit* Indiv)
{

    ListBit tmp;
    while (*Indiv) {
        tmp = (*Indiv)->next;
        free(*Indiv);
        *Indiv = tmp;
    }
}

void freePopulation(ListIndiv* Popu)
{
    ListIndiv tmp;
    while (*Popu) {
        tmp = (*Popu)->next;
        freeIndividu(&((*Popu)->Indiv));
        free(*Popu);
        *Popu = tmp;
    }
}

