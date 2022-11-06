#ifndef __POPULATION_H__
#define __POPULATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A -1
#define B 1 


typedef unsigned char Bit;

/**
 * @brief Structure d'un Individu sous forme de liste chainée  
 * @param value unsigned char qui prend en valeur 0 ou 1 
 * @param next pointeur sur la "structure" suivante  
 *
 */
typedef struct bit {
    Bit value;
    struct bit* next;

} Individu;
/**
 * @brief Pointeur sur la liste chainée 
 *
 */
typedef Individu* ListBit;

typedef struct individu{
    
    ListBit Indiv;
    struct individu* next;

}Population; 

typedef Population* ListIndiv ;

int pui(int x , int y);

/**
 * @brief Permet d'ajouter en queux dans la liste chainée ListBit 
 *
 * @param l Pointeur sur la liste chainée Individu
 * @param value Valeur a assigner a value
 * @return ListBit pointeur sur la nouvelle liste chainée 
 */
ListBit ajouterqBit(ListBit l, Bit value);
/**
 * @brief Initialise de manière ittérative un individu 
 *
 * @param l  Pointeur sur la liste chainée Individu
 * @param longIndiv entier représentant la longueur de l'individu 
 * @return ListBit pointeur sur la nouvelle liste chainée 
 */
ListBit initializeIndivIterration(ListBit l, int longIndiv);
/**
 * @brief Initialise de manière récursive un individu 
 *
 * @param l Pointeur sur la liste chainée Individu
 * @param longIndiv entier représentant la longueur de l'individu 
 * @return ListBit pointeur sur la nouvelle liste chainée 
 */
ListBit initializeIndivRecurssif(ListBit l, int longIndiv);
/**
 * @brief Affiche un individu 
 *
 * @param l Pointeur sur la liste chainée Individu
 */
void affichageIndiv(ListBit l);

int decodageIndividu(ListBit l,int longIndiv);

float qualiteIndiv(int valeurIndiv  , int longIndiv);

void croisementIdiv(ListBit l1, ListBit l2, float pCroise);

ListIndiv ajouterqIndiv(ListIndiv Popu, int longIndiv);

ListIndiv initializePopu(ListIndiv Popu, int longPopu, int longIndiv);

void affichagePopu(ListIndiv Popu);

void freePopulation(ListIndiv Popu);
#endif