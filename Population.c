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


void freeIndividu(lBit* Indiv)
{

    lBit tmp;
    while (*Indiv) {
        tmp = (*Indiv)->next;
        free(*Indiv);
        *Indiv = tmp;
    }
}