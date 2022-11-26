#ifndef __POPULATION_H__
#define __POPULATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A -1
#define B 1 
#define taille_individu 8
#define probabilite_croisement 0.5



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
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu  
 */
lBit ajouter_queux_bit(lBit l, Bit value);
/**
 * @brief 
 * 
 * @param l 
 * @param longIndiv 
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu  
 */
lBit initialize_individu_recurssif(lBit l, int longIndiv);
/**
 * @brief 
 * 
 * @param l 
 * @param longIndiv 
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu  
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
/**
 * @brief 
 * 
 * @param P1 
 * @return individu 
 */
individu selection_random_individu(popu P1,int longPopu);
/**
 * @brief 
 * 
 */
popu initialize_population_vide(popu P1,int longPopu,int longIndiv);
/**
 * @brief 
 * 
 * @param P1 
 * @param taille_popu 
 * @param pCroise 
 * @return popu 
 */
popu croisement_population(popu P1,int longPopu,int longIndiv,float pCroise);
/**
 * @brief 
 * 
 * @param P1 
 * @param longPopu 
 * @param longIndiv 
 * @param pCroise 
 * @return popu 
 */
popu nGen(popu P1,int longPopu,int longIndiv,float pCroise,int nombre_generation);

#endif

