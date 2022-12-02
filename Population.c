#include "Population.h"

/**
 * @brief Ajoute en queux un individu à une population
 *
 * @param Popu Pointeur sur liste chaînée population
 * @param longIndiv Taille d'un individu i.e nombre de Bit
 * @return popu Nouvelle liste chaînée avec nouvel individu
 */
popu ajouter_queue_individu(popu Popu, int longIndiv)
{

    popu newIndiv = (population*)malloc(sizeof(population));
    (newIndiv->indivPopu).indiv = initialize_individu_recurssif((newIndiv->indivPopu).indiv, longIndiv);
    (newIndiv->indivPopu).longIndiv = longIndiv;
    newIndiv->next = NULL;

    if (Popu != NULL) {

        popu temp = Popu;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newIndiv;
    } else {
        Popu = newIndiv;
    }

    return Popu;
}

/**
 * @brief Initialise une population
 *
 * @param Popu Pointeur sur liste chaînée population
 * @param longPopu taille de la population
 * @param longIndiv Taille d'un individu i.e nombre de Bit
 * @return popu Population initialiser
 */
popu initialize_population(popu Popu, int longPopu, int longIndiv)
{

    if (longPopu == 0) {
        return Popu;
    } else {
        Popu = ajouter_queue_individu(Popu, longIndiv);
        return initialize_population(Popu, longPopu - 1, longIndiv);
    }
}

/**
 * @brief Affiche la population
 *
 * @param Popu Pointeur sur liste chaînée population
 */
void affichage_population(popu Popu)
{
    popu temp = Popu;
    int i = 1;
    while(temp != NULL){
        printf("Individu n°%d \t   ~Decodage(%d)~   \t: ",i,valeur_base_2_to_base_10(temp->indivPopu));
        affichage_individu(temp->indivPopu.indiv);
        printf("  \t --> Qualite : %.3f\n",qualite_individu(temp->indivPopu));
        ++i;
        temp=temp->next;
    }
    printf("\n");
}

/**
 * @brief Trouve le pointeur sur le dernier individu de la population
 *
 * @param Popu Pointeur sur liste chaînée population
 * @return popu Pointeur sur le dernier individu de la population
 */
popu trouver_queue(popu Popu)
{
    popu temp = Popu;

    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

/**
 * @brief Fonction utile au quickSort-> permet de partionner selon un "pivot" i.e toutes les valeurs inférieur au pivot se trouve à gauche de celui
 * si, les autres à droite
 *
 * @param premierIndividu Pointeur sur le premier individu
 * @param dernierIndividu Pointeur sur le dernier individu
 * @return popu Retourne la liste partionner
 */
popu partionnement(popu premierIndividu, popu dernierIndividu)
{
    popu pivot = premierIndividu;
    popu avancement = premierIndividu;
    individu temp;
    while (avancement != NULL && avancement != dernierIndividu) {

        if (qualite_individu(avancement->indivPopu) > qualite_individu(dernierIndividu->indivPopu)) {
            pivot = premierIndividu;

            temp = premierIndividu->indivPopu;
            premierIndividu->indivPopu = avancement->indivPopu;
            avancement->indivPopu = temp;

            premierIndividu = premierIndividu->next;
        }

        avancement = avancement->next;
    }
    temp = premierIndividu->indivPopu; // on place le pivot à la bonne place
    premierIndividu->indivPopu = dernierIndividu->indivPopu;
    dernierIndividu->indivPopu = temp;

    return pivot;
}

/**
 * @brief Trie la population en fonction des qualités des individus à l'aide de l'algorithme du quickSort
 *
 * @param premierIndividu Pointeur sur le premier individu
 * @param dernierIndividu Pointeur sur le dernier individu
 */
void quick_sort_population(popu premierIndividu, popu dernierIndividu)
{
    if (premierIndividu == dernierIndividu) {
        return;
    }
    popu pivot = partionnement(premierIndividu, dernierIndividu);

    if (pivot != NULL && pivot->next != NULL) {
        quick_sort_population(pivot->next, dernierIndividu);
    }

    if (pivot != NULL && premierIndividu != pivot) {
        quick_sort_population(premierIndividu, pivot);
    }
}

/**
 * @brief Selectionne les individu parmis une population et un taux de selection
 *
 * @param Popu Pointeur sur liste chaînée population
 * @param tSelect Taux de selection
 * @param longPopu taille de la population
 */
void tSelect(popu Popu, int tSelect, int longPopu)
{
    int i = 0;
    int reel_t_select = (tSelect * longPopu) /100;
    if ((longPopu - reel_t_select) <= 0) {
        return;
    } else {
        popu demarrage = Popu;
        popu avancement = Popu;
        while (i < reel_t_select) {
            demarrage = demarrage->next; //  On se place à la position reel_t_select
            i++;
        }
        while (demarrage != NULL) { // Puis on copie chaque individu en partant du début
            free_individu((demarrage->indivPopu).indiv);
            demarrage->indivPopu = copie_individu(avancement->indivPopu);
            demarrage = demarrage->next;
            avancement = avancement->next;
        }
    }
    return;
}
    

/**
 * @brief Libère la mémoire allouée pour une population
 *
 * @param Popu Pointeur sur liste chaînée population
 */
void free_population(popu Popu)
{

    if (Popu == NULL) {
        return;
    }
    free_individu((Popu->indivPopu).indiv);
    free_population(Popu->next);
    free(Popu);
}

/**
 * @brief Selectionne un individu aléatoirement dans une population
 *
 * @param P1 Pointeur sur population
 * @return individu choisit aléatoirement
 */
individu selection_random_individu(popu P1, int longPopu)
{

    individu random_individu;
    popu temp_P1 = P1;
    int i = 0;
    int nombre_aleatoire = rand() % longPopu + 1;
    while (i < nombre_aleatoire - 1) {
        temp_P1 = temp_P1->next;
        i++;
    }

    random_individu = copie_individu(temp_P1->indivPopu);

    return random_individu;
}

/**
 * @brief Initialise une population sans individu
 *
 */
popu initialize_population_vide(popu P1, int longPopu, int longIndiv)
{
    int i = 0;
    P1 = (popu)malloc(sizeof(population));
    (P1->indivPopu).longIndiv = longIndiv;
    (P1->indivPopu).indiv = NULL;
    P1->next = NULL;
    popu temp = P1;

    while (i < longPopu - 1) {
        temp->next = (popu)malloc(sizeof(population));
        (temp->indivPopu).longIndiv = longIndiv;
        (temp->indivPopu).indiv = NULL;
        temp->next->next = NULL;
        temp = temp->next;
        i++;
    }

    return P1;
}

/**
 * @brief Croise une population selon une probabilité de croisement
 *
 * @param P1 Pointeur sur population
 * @param taille_popu Nombre d'individu dans la population
 * @param pCroise Probabilité de croisement
 * @return popu
 */
popu croisement_population(popu P1, int longPopu, int longIndiv, float pCroise)
{

    int i = 0;
    popu P2 = NULL;
    P2 = initialize_population_vide(P2, longPopu, longIndiv);
    popu temp_p2 = P2;
    individu individu_temporaire_1;
    individu individu_temporaire_2;

    while (i < longPopu) {
        individu_temporaire_1 = selection_random_individu(P1, longPopu);
        individu_temporaire_2 = selection_random_individu(P1, longPopu);
        croisement_individu(individu_temporaire_1, individu_temporaire_2, pCroise);
        temp_p2->indivPopu = individu_temporaire_1;
        temp_p2 = temp_p2->next;
        ++i;

        if (i != longPopu) {
            temp_p2->indivPopu = individu_temporaire_2;
            temp_p2 = temp_p2->next;
            ++i;
        }
    }

    return P2;
}

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
popu nGen(popu P1, int longPopu, int longIndiv, float pCroise, int taux_selection, int nombre_generation,int affichage)
{
    int i = 1;
    popu temp = NULL;
    while (i < nombre_generation+1) {
        temp = P1;
        P1 = croisement_population(P1, longPopu, longIndiv, pCroise);
        quick_sort_population(P1, trouver_queue(P1));
        tSelect(P1, taux_selection, longPopu);
        if(affichage == 1){
            printf("Generation n° %d \n\n",i);
            affichage_population(P1);
        }
        free_population(temp);
        ++i;
    }
    return P1;
}
