#ifndef __POPULATION_H__
#define __POPULATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A -1
#define B 1 
#define taillePopu 10
#define tailleIndiv 10

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
/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int pui(int x, int y);
/**
 * @brief 
 * 
 * @param l 
 * @param value 
 * @return lBit 
 */
lBit ajouter_queux_bit(lBit l, Bit value);
/**
 * @brief 
 * 
 * @param l 
 * @param longIndiv 
 * @return lBit 
 */
lBit initialize_individu_recurssif(lBit l, int longIndiv);
/**
 * @brief 
 * 
 * @param l 
 * @param longIndiv 
 * @return lBit 
 */
lBit initialize_individu_iterration(lBit l, int longIndiv);
/**
 * @brief 
 * 
 * @param l 
 */
void affichage_individu(lBit l);
/**
 * @brief 
 * 
 * @param indiv1 
 * @return int 
 */
int valeur_base_2_to_base_10(individu indiv1);
/**
 * @brief 
 * 
 * @param indiv1 
 * @return float 
 */
float qualite_individu(individu indiv1);
/**
 * @brief 
 * 
 * @param indiv1 
 * @param inidv2 
 * @param pCroise 
 */
void croisement_individu(individu indiv1, individu inidv2, float pCroise);
/**
 * @brief 
 * 
 * @param Popu 
 * @param longIndiv 
 * @return popu 
 */
popu ajouter_queux_individu(popu Popu, int longIndiv);
/**
 * @brief 
 * 
 * @param Popu 
 * @param longPopu 
 * @param longIndiv 
 * @return popu 
 */
popu initialize_population(popu Popu, int longPopu, int longIndiv);
/**
 * @brief 
 * 
 * @param Popu 
 */
void affichage_population(popu Popu);
/**
 * @brief 
 * 
 * @param Popu 
 * @return popu 
 */
popu trouver_queux(popu Popu);
/**
 * @brief 
 * 
 * @param premierIndividu 
 * @param dernierIndividu 
 * @return popu 
 */
popu partionnement(popu premierIndividu, popu dernierIndividu);
/**
 * @brief 
 * 
 * @param premierIndividu 
 * @param dernierIndividu 
 */
void quick_sort_population(popu premierIndividu, popu dernierIndividu);
/**
 * @brief 
 * 
 * @param Popu 
 * @param tSelect 
 * @param longPopu 
 */
void tSelect(popu Popu, int tSelect,int longPopu);
/**
 * @brief 
 * 
 * @param Indiv 
 */
void free_individu(lBit Indiv);
/**
 * @brief 
 * 
 * @param Popu 
 */
void free_population(popu Popu);
/**
 * @brief 
 * 
 * @param Individu 
 * @return individu 
 */
individu copie_individu(individu Individu);
#endif

