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

typedef struct population{
    
    individu indivPopu;
    struct population* next;

}population;

typedef population* popu;

int pui(int x, int y);
lBit ajouterqBit(lBit l, Bit value);
lBit initializeIndivRecurssif(lBit l, int longIndiv);
lBit initializeIndivIterration(lBit l, int longIndiv);
void affichageIndiv(lBit l);
int valueBase2ToBase10(individu indiv1);
float qualiteIndiv(individu indiv1);
void croisementIdiv(individu indiv1, individu inidv2, float pCroise);
popu ajouterqIndiv(popu Popu, int longIndiv);
popu initializePopu(popu Popu, int longPopu, int longIndiv);
void affichagePopu(popu Popu);
popu findTail(popu Popu);
popu partionnement(popu premierIndividu, popu dernierIndividu);
void quickSortPopulation(popu premierIndividu, popu dernierIndividu);
void freeIndividu(lBit Indiv);
void freePopulation(popu Popu);
#endif

