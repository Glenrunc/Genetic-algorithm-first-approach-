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
/**
 * @brief Structure de donnée sous forme de liste chaînée représenatant une population
 * 
 */
typedef struct population{
    
    individu indivPopu;
    struct population* next;

}population;

typedef population* popu;
/**
 * @brief Fonction puissance de x
 * 
 * @param x entier 
 * @param y entier 
 * @return entier
 */
int puissance(int x, int y);
/**
 * @brief ajoute un bit à la liste chaînée listbit
 * 
 * @param l Pointeur sur structure ListBit
 * @param value unsigned char [0,1]
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu  
 */
lBit ajouter_queux_bit(lBit l, Bit value);
/**
 * @brief Initialise un individu récursivement 
 * 
 * @param l Pointeur sur structure ListBit
 * @param longIndiv Taille d'un individu i.e nombre de Bit 
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu  
 */
lBit initialize_individu_recurssif(lBit l, int longIndiv);
/**
 * @brief Initialise un individu itérativement 
 * 
 * @param l Pointeur sur structure ListBit
 * @param longIndiv Taille d'un individu i.e nombre de Bit
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu  
 */
lBit initialize_individu_iteration(lBit l, int longIndiv);
/**
 * @brief Affiche un individu 
 * 
 * @param l Pointeur sur structure ListBit
 */
void affichage_individu(lBit l);
/**
 * @brief Converti la valeur d'un individu de la base 2 à la base 10
 * 
 * @param indiv1 Structure représentant un individu 
 * @return La valeur en base 10
 */
int valeur_base_2_to_base_10(individu indiv1);
/**
 * @brief Calcul la qualité d'un individu selon une fonction précise
 * 
 * @param indiv1 Structure représentant un individu 
 * @return float Qualité de l'individu
 */
float qualite_individu(individu indiv1);
/**
 * @brief Croise deux individu selon une probabilité de croisement bit à bit 
 * 
 * @param indiv1 Structure représentant un individu 
 * @param inidv2  Structure représentant un individu 
 * @param pCroise Probabilité de croisement 
 */
void croisement_individu(individu indiv1, individu inidv2, float pCroise);
/**
 * @brief Ajoute en queux un individu à une population
 * 
 * @param Popu Pointeur sur liste chaînée population 
 * @param longIndiv Taille d'un individu i.e nombre de Bit
 * @return popu Nouvelle liste chaînée avec nouvel individu
 */
popu ajouter_queux_individu(popu Popu, int longIndiv);
/**
 * @brief Initialise une population
 * 
 * @param Popu Pointeur sur liste chaînée population 
 * @param longPopu taille de la population 
 * @param longIndiv Taille d'un individu i.e nombre de Bit
 * @return popu Population initialiser
 */
popu initialize_population(popu Popu, int longPopu, int longIndiv);
/**
 * @brief Affiche la population 
 * 
 * @param Popu Pointeur sur liste chaînée population 
 */
void affichage_population(popu Popu);
/**
 * @brief Trouve le pointeur sur le dernier individu de la population 
 * 
 * @param Popu Pointeur sur liste chaînée population 
 * @return popu Pointeur sur le dernier individu de la population  
 */
popu trouver_queux(popu Popu);
/**
 * @brief Fonction utile au quickSort-> permet de partionner selon un "pivot" i.e toutes les valeurs inférieur au pivot se trouve à gauche de celui
 * si, les autres à droite 
 * 
 * @param premierIndividu Pointeur sur le premier individu
 * @param dernierIndividu Pointeur sur le dernier individu 
 * @return popu Retourne la liste partionner 
 */
popu partionnement(popu premierIndividu, popu dernierIndividu);
/**
 * @brief Trie la population en fonction des qualités des individus à l'aide de l'algorithme du quickSort
 * 
 * @param premierIndividu Pointeur sur le premier individu
 * @param dernierIndividu Pointeur sur le dernier individu
 */
void quick_sort_population(popu premierIndividu, popu dernierIndividu);
/**
 * @brief Selectionne les individu parmis une population et un taux de selection 
 * 
 * @param Popu Pointeur sur liste chaînée population 
 * @param tSelect Taux de selection
 * @param longPopu taille de la population 
 */
void tSelect(popu Popu, int tSelect,int longPopu);
/**
 * @brief Libère la mémoire allouée pour un individu
 * 
 * @param Indiv Pointeur sur liste de bit représentant un individu  
 */
void free_individu(lBit Indiv);
/**
 * @brief Libère la mémoire allouée pour une population
 * 
 * @param Popu Pointeur sur liste chaînée population 
 */
void free_population(popu Popu);
/**
 * @brief Copie un individu 
 * 
 * @param Individu Structure représentant un individu 
 * @return individu 
 */
individu copie_individu(individu Individu);
/**
 * @brief Selectionne un individu aléatoirement dans une population
 * 
 * @param P1 Pointeur sur population
 * @return individu choisit aléatoirement 
 */
individu selection_random_individu(popu P1,int longPopu);
/**
 * @brief Initialise une population sans individu 
 * 
 */
popu initialize_population_vide(popu P1,int longPopu,int longIndiv);
/**
 * @brief Croise une population selon une probabilité de croisement 
 * 
 * @param P1 Pointeur sur population
 * @param taille_popu Nombre d'individu dans la population
 * @param pCroise Probabilité de croisement 
 * @return popu 
 */
popu croisement_population(popu P1,int longPopu,int longIndiv,float pCroise);
/**
 * @brief Sous-programme qui repète n-fois les étapes suivantes-->
 * -Croisement de population
 * -Trie de la population
 * -Selection de la population 
 * 
 * @param P1 Pointeur sur population
 * @param longPopu taille de la population 
 * @param longIndiv Taille d'un individu i.e nombre de Bit
 * @param pCroise Probabilité de croisement 
 * @return popu 
 */
popu nGen(popu P1,int longPopu,int longIndiv,float pCroise,int taux_selection,int nombre_generation);

#endif

