/**
 * 
 * FILE NAME "main.c"
 * 
 * LANGUAGE "French"
 * 
 * AUTHOR Birame
 * 
 * DESCRIPTION "Ce fichier contient la fonction principale pour les jeux de test : WARNING
 * 
 * WARNING : les polynomes doivent systematiquement etre initialiser a zero"
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "poly.h"
#define NOMBRE_DE_POINTS_MAX 4

int main(int argc, char **argv){

	Point listePoints[NOMBRE_DE_POINTS_MAX];
	polynome polynomeInterpolateur = {0.0};
	
	initialisePoint_P(listePoints, NOMBRE_DE_POINTS_MAX);

	interpole_P(polynomeInterpolateur, listePoints, NOMBRE_DE_POINTS_MAX);

	affiche_P(polynomeInterpolateur);

	return 0;
}

