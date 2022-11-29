#include "Individu.h"

/**
 * @brief ajoute un bit à la liste chaînée listbit
 *
 * @param l Pointeur sur structure ListBit
 * @param value unsigned char [0,1]
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu
 */
lBit ajouter_queue_bit(lBit l, Bit value)
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

/**
 * @brief Initialise un individu récursivement
 *
 * @param l Pointeur sur structure ListBit
 * @param longIndiv Taille d'un individu i.e nombre de Bit
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu
 */
lBit initialize_individu_recurssif(lBit l, int longIndiv)
{

    if (longIndiv == 0) {
        return l;
    } else {
        l = ajouter_queue_bit(l, rand() % 2);
        return initialize_individu_recurssif(l, longIndiv - 1);
    }
}

/**
 * @brief Initialise un individu itérativement
 *
 * @param l Pointeur sur structure ListBit
 * @param longIndiv Taille d'un individu i.e nombre de Bit
 * @return lBit Retourne un pointeur sur sur liste de Bit représentant un individu
 */
lBit initialize_individu_iteration(lBit l, int longIndiv)
{
    for (int i = 1; i <= longIndiv; i++) {
        l = ajouter_queue_bit(l, rand() % 2);
    }

    return l;
}

/**
 * @brief Affiche un individu
 *
 * @param l Pointeur sur structure ListBit
 */
void affichage_individu(lBit l)
{
    if (l == NULL) {
        return;
    } else {
        printf("%d", l->value);
        affichage_individu(l->next);
    }
}

/**
 * @brief Converti la valeur d'un individu de la base 2 à la base 10
 *
 * @param indiv1 Structure représentant un individu
 * @return La valeur en base 10
 */
int valeur_base_2_to_base_10(individu indiv1)
{
    int valueIndiv = 0;
    int longIndiv = indiv1.longIndiv;
    lBit l = indiv1.indiv;
    lBit temp = l;
    while (temp != NULL) {
        longIndiv--;
        valueIndiv = valueIndiv + PUI(longIndiv) * temp->value;
        temp = temp->next;
    }

    return valueIndiv;
}

/**
 * @brief Calcul la qualité d'un individu selon une fonction précise
 *
 * @param indiv1 Structure représentant un individu
 * @return float Qualité de l'individu
 */
float qualite_individu(individu indiv1)
{
    int valeurIndiv = valeur_base_2_to_base_10(indiv1);
    float X = (valeurIndiv / (float)(PUI(indiv1.longIndiv))) * (B - A) + A;
    return -log(X);
}

/**
 * @brief Croise deux individu selon une probabilité de croisement bit à bit
 *
 * @param indiv1 Structure représentant un individu
 * @param inidv2  Structure représentant un individu
 * @param pCroise Probabilité de croisement
 */
void croisement_individu(individu indiv1, individu indiv2, float pCroise)
{

    lBit l1 = indiv1.indiv;
    lBit l2 = indiv2.indiv;
    lBit temp1 = l1;
    lBit temp2 = l2;
    Bit temp;

    while (temp1 != NULL) {
        if (pCroise * 100 > rand() % 100) {
            temp = temp1->value;
            temp1->value = temp2->value;
            temp2->value = temp;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}
/**
 * @brief Utile pour récupérer les paramètres (taille de poupulation, nombre de génération,etc..) de la part de l'utilisateur
 *
 */
void get_integer(int* variable, int borne_inf, int borne_sup, char* nom_variable)
{
    char buffer[BUFFER_SIZE];
    if (borne_inf == 0 && borne_sup == 1) {
        printf("Voulez vous affichez les generations ? (1 pour oui et 0 pour non)\n");
    } else {
        printf("Choisissez une taille de %s [%d,%d]\n", nom_variable, borne_inf, borne_sup);
    }
    scanf("%s", buffer);
    fflush(stdin);

    if (sscanf(buffer, "%d", variable) == EOF || *variable < borne_inf || *variable > borne_sup) {
        do {

            printf("Entre %d et %d\n", borne_inf, borne_sup);
            scanf("%s", buffer);
            fflush(stdin);

        } while (sscanf(buffer, "%d", variable) == EOF || *variable < borne_inf || *variable > borne_sup);
    }
}
/**
 * @brief Libère la mémoire allouée pour un individu
 *
 * @param Indiv Pointeur sur liste de bit représentant un individu
 */
void free_individu(lBit Indiv)
{
    if (Indiv == NULL) {
        return;
    }
    free_individu(Indiv->next);
    free(Indiv);
}