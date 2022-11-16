#ifndef __POPULATION_H__
#define __POPULATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A -1
#define B 1 

typedef unsigned char Bit;
/**
 * @brief Structure de donnée sous forme de liste chaînée représentant une liste de bit
 * 
 */
typedef struct bit{
    Bit value;
    struct bit* next; 
}listBit;

typedef listBit* lBit;
/**
 * @brief Structure d'un individu
 * 
 */
typedef struct{
    int longIndiv;
    lBit indiv;
}individu;

int pui(int x, int y);

lBit ajouterqBit(lBit l, Bit value);

lBit initializeIndivRecurssif(lBit l, int longIndiv);

void affichageIndiv(lBit l);
int valueBase2ToBase10(individu indiv1);
void freeIndividu(lBit* Indiv);
#endif