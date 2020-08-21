/**
 *
 * FILE NAME "poly.h"
 * 
 * LANGUAGE "French"
 * 
 * AUTHOR Birame
 * 
 * DESCRIPTION "Ce fichier contient le prototype des fonctions implémentant
 * les opérations de base sur les polynomes.
 * 
 * WARNING : les polynomes doivent systematiquement etre initialiser a zero"
 * 
 */
#ifndef POLY_H
#define POLY_H
#define DEGRE_MAX 100

/**
 * 
 * Définition d'un polynome comme étant un tableau de réel. La taille du tableau est DEGRE_MAX
 * 
 */
typedef double polynome[DEGRE_MAX + 1]; 

/**
 * 
 * Définition d'un point en deux dimensions. X est l'abscisse et Y l'ordonnée.
 * 
 */
typedef struct Point{
	double x;
	double y;
}Point;

/**
 * 
 * Cette fonction permet de définir un polynome et d'entrer les coefficients.
 * 
 */
void definir_P (polynome);

/**
 * 
 * Cette fonction renvoie le degré du polynome fourni en argument.
 *  
 */
int degre_P (polynome);

/**
 * 
 * Cette fonction affiche un polynome fourni en argument.
 * 
 */
void affiche_P (polynome);

/**
 * 
 * Cette fonction fait l'addition de deux polynomes(les deux premiers polynomes) fournis en 
 * parametres et stocke le resultat dans le troisième polynome.
 * 
 */
void somme_P (polynome, polynome, polynome);

/**
 * 
 * Cette fonction copie le deuxième polynome en argument dans le premier.
 * 
 */
void copier_P (polynome, polynome);

/**
 * 
 * Cette fonction affiche le signe " + " si le paramètre est positif sinon elle affiche " "(une espace)
 * 
 */
void afficherSigne_P(double);

/**
 * 
 * Cette fonction affiche un monome du polynome p qui se trouve a la position n.
 * p et n sont passés en paramètre.
 * 
 */
void afficherMonome_P(polynome, int);

/**
 * 
 * Cette fonction fait la multiplication de deux polynomes(les deux premiers arguments) 
 * et stocke le resultat dans le troisème polynome.
 * 
 */
void produit_P(polynome, polynome, polynome);

/**
 * 
 * Cette fonction fait la multiplication d'un polynome p par un scalaire lambda
 * et stocke le resultat dans un troisième polynome
 * 
 */
void produitParScalaire_P(polynome, double, polynome);

/**
 * 
 * Cette fonction calcule l'expression y = P(x) en utilisant la méthode de Horner.
 * x est le deuxième argument.
 * 
 */
double evaluer_P(polynome, double);

/**
 * 
 * Cette fonction initialise les points a interpoler. Elle prend en entrée 
 * un tableau de structure Point et un nombre entier : le nombre de points.
 * 
 */
void initialisePoint_P(Point*, int);

/**
 * 
 * Cette fonction fournit le polynome interpolateur de Lagrange. Elle prend en entrée un polynome,
 * un tableau de Point et un nombre entier : le nombre de points
 * 
 */
void interpole_P(polynome, Point*, int);

/**
 * 
 * Cette fonction initialise le polynome a zéro. Elle prend en entrée un polynome.
 * 
 */
void init_a_zero_P(polynome);

/**
 * 
 * Cette fonction définit un polynome de degre 1. Elle prend en entrée un polynome
 * et le coefficient constant
 * 
 */
void definir_degre1_P(polynome, double);

#endif
