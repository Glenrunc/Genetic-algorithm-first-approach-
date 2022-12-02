#ifndef __POPULATION_H__
#define __POPULATION_H__

#include "Individu.h"

/**
 * @brief Structure de donnée sous forme de liste chaînée représenatant une population
 *
 */
typedef struct population {

    individu indivPopu;
    struct population* next;

} population;
/**
 * @brief Pointeur sur population 
 * 
 */
typedef population* popu;

/**
 * @brief Ajoute en queux un individu à une population
 *
 * @param Popu Pointeur sur liste chaînée population
 * @param longIndiv Taille d'un individu i.e nombre de Bit
 * @return popu Nouvelle liste chaînée avec nouvel individu
 */
popu ajouter_queue_individu(popu Popu, int longIndiv);

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
popu trouver_queue(popu Popu);
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
void tSelect(popu Popu, int tSelect, int longPopu);
/**
 * @brief Libère la mémoire allouée pour une population
 *
 * @param Popu Pointeur sur liste chaînée population
 */
void free_population(popu Popu);
/**
 * @brief Selectionne un individu aléatoirement dans une population
 *
 * @param P1 Pointeur sur population
 * @return individu choisit aléatoirement
 */
individu selection_random_individu(popu P1, int longPopu);
/**
 * @brief Initialise une population sans individu
 *
 */
popu initialize_population_vide(popu P1, int longPopu, int longIndiv);
/**
 * @brief Croise une population selon une probabilité de croisement
 *
 * @param P1 Pointeur sur population
 * @param taille_popu Nombre d'individu dans la population
 * @param pCroise Probabilité de croisement
 * @return popu
 */
popu croisement_population(popu P1, int longPopu, int longIndiv, float pCroise);
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
popu nGen(popu P1, int longPopu, int longIndiv, float pCroise, int taux_selection, int nombre_generation, int affichage);

#endif
