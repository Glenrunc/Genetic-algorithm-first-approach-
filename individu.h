#ifndef __INDIVIDU_H__
#define __INDIVIDU_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A 0.1
#define B 5
#define taille_individu 16
#define probabilite_croisement 0.5
#define PUI(n) (1 << (n))

typedef unsigned char Bit;
/**
 * @brief Structure de donnée sous forme de liste chaînée représentant une liste de bit
 *
 */
typedef struct bit {
    Bit value;
    struct bit* next;
} listBit;
/**
 * @brief Pointeur sur listBit
 * 
 */
typedef listBit* lBit;
/**
 * @brief Structure d'un individu
 *
 */
typedef struct {
    int longIndiv;
    lBit indiv;
} individu;

/**
 * @brief ajoute un bit à la liste chaînée listbit
 *
 * @param l Pointeur sur structure ListBit
 * @param value unsigned char [0,1]
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu
 */
lBit ajouter_queue_bit(lBit l, Bit value);
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
 * @brief Utile pour récupérer les paramètres (taille de poupulation, nombre de génération,etc..) de la part de l'utilisateur 
 * 
 */
void get_integer(int* variable, int borne_inf, int borne_sup, char* nom_variable)

#endif