/**
 * 
 * FILE NAME "poly.c"
 * 
 * LANGUAGE "French"
 * 
 * AUTHOR Birame
 * 
 * DESCRIPTION "Ce fichier contient des fonctions implémentant les opérations élèmentaires sur les polynomes."
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "poly.h"
#define DEGRE_MAX 100

void definir_P (polynome p){
	int degre = 0, i;
	printf("Veuillez entrer en premier lieu le degre du polynome que vous souhaitez definir : ");
	scanf("%d", &degre);
	if(degre > DEGRE_MAX){
		printf("\n\tWARNING : Les polynomes de degre superieur à 100 ne sont pas pris en compte  !!!!!!\n");
	}else if(degre < 0){
		printf("Polynome nul\n");//pour obtenir un polynome nul, on donne un degre negatif
	}else{
		printf("Entrer la liste des %d coefficients du polynome en veillant a appuyer sur entrer apres la saisie de chaque coefficient\n",  degre + 1);
		printf("--->ATTENTION : on commence par le coefficient du monomes de plus haut degre :\n");
		for (i = degre; i >= 0; i--)
			scanf ("%lf", &p[i]);
	}
}

int degre_P (polynome p) {
	int i = DEGRE_MAX;
	while(i >= 0 && p[i] == 0){
		i--;
	}
	return i;
}

void affiche_P(polynome p){
	int i, degree = 0;
	degree = degre_P(p);
	if(degree < 0){
		printf("0\n");
		return;
	}
	if(degree == 0){
		printf("%.2lf\n", p[degree]);
		return;
	}
	for (i = degree; i >= 0; i--){
		afficherMonome_P(p, i);
		if(i == 0)
			break;
	}	
}

void somme_P(polynome p1, polynome p2, polynome p3){
	int i;
	for(i = 0; i <= DEGRE_MAX; i++){
        	p3[i] = p1[i] + p2[i];
	}
}

void copier_P(polynome destination, polynome source){
	int i, degre = 0;
	degre = degre_P(source);
	for (i = 0; i <= degre; ++i){
		destination[i] = source[i];
	}
}

void afficherSigne_P(double x){
	if (x >= 0)
		printf(" + ");
	else
		printf(" ");
}

void afficherMonome_P(polynome p, int n){
	if(n == 1){
		printf("%.2lfX", p[n]);
		afficherSigne_P(p[n-1]);
	}else if(n == 0){
		printf("%.2lf\n", p[n]);
		return;
	}else{
		printf("%.2lfX^%d", p[n], n);
		afficherSigne_P(p[n-1]);
	}
}

void produit_P(polynome p1, polynome p2, polynome p3){
	int d1 = 0, d2 = 0, i, j;

	d1 = degre_P(p1);//le degre de p1
	d2 = degre_P(p2);//le degre de p2
	if(d1+d2 > DEGRE_MAX){
		printf("Le resultat donne un polynome de degre %d qui est superieur %d(Le degre maximal)\n", d1+d2, DEGRE_MAX);
		return;
	}
	for (i = 0; i <= d1; ++i){
		for (j = 0; j <= d2; ++j){
			p3[i+j] += p1[i] * p2[j];
		}
	}
}

void produitParScalaire_P(polynome p, double lambda, polynome q){
	int i, degre = 0;
	degre = degre_P(p);
	for (i = 0; i <= degre; ++i){
		q[i] = p[i] * lambda;
	}
}

double evaluer_P(polynome p, double x){
	int i, degre = 0;
	double y;
	degre = degre_P(p);
	y = p[degre];
	for (i = degre-1; i >= 0; --i)
	{
		y = (x * y) + p[i];
	}
	return y;
}

void initialisePoint_P(Point p[], int nombreDePoint){
	int i;
	printf("Entrer les %d points (x, y) : \n", nombreDePoint);
	for(i = 0; i < nombreDePoint; i++){
		scanf("%lf", &p[i].x);
		scanf("%lf", &p[i].y);
		printf("(%.2lf, %.2lf)\n", p[i].x, p[i].y);
	}
}

void interpole_P(polynome p, Point pts[], int nombreDePoint){
	int i, j;
	double alpha;
	polynome lag = {0.0}, res = {0.0}, tmp = {0.0}, p1 = {0.0};
	for(i = 0; i < nombreDePoint; i++){
		alpha = 1;
		lag[0] = 1;
		for(j = 0; j < nombreDePoint; j++){
			if(j != i){
				alpha *= (pts[i].x - pts[j].x);
				//polynome de degre 1 (X - x_j)
				definir_degre1_P(p1, pts[j].x);
				//(X - x_j)*(X - x_j+1)*(X- x_j+2)....
				produit_P(lag, p1, tmp);
				
				copier_P(lag, tmp);
				init_a_zero_P(tmp);
				init_a_zero_P(p1);
			}
		}
		alpha = pts[i].y / alpha;
		produitParScalaire_P(lag, alpha, res);
		somme_P(p, res, p);	

		init_a_zero_P(lag);
		init_a_zero_P(res);
	}
}

void definir_degre1_P(polynome p, double x){
	p[1] = 1;
	p[0] = -x;
}

void init_a_zero_P(polynome p){
	int i;
	for(i = 0; i <= DEGRE_MAX; i++){
        	p[i] = 0;
	}
}