#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10000
#define ESSAIS 15

void printTab(int* tab) {
	int i;
	printf("Tableau :\n[");
	for (i = 0; i < TAILLE; ++i)
	{
		printf("%d", tab[i]);
		if(i+1<TAILLE)
			printf(",\t");
		if(i%4==0)
			printf("\n");
	}
	printf("]\n");
}

int isSorted(int* tab) {
	int i, n=0;
	for (i = 0; i < TAILLE; ++i)
	{
		n+=(tab[i]>tab[i+1]);
	}
	return n==0;
}

void sortArray(int* tab, time_t start) {
	time_t now;
	int i,n,b=1;
	while(b)
	{
		b=0;
		for(i=0; i<TAILLE; i++) {
			/*while((int) difftime(now, start) %5 != 4)
				time(&now);*/
			if(tab[i] > tab[i+1]) {
				n = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = n;
				b=1;
			}
		}
	}
}

void randArray(int* tab) {
	int i;
	for(i=0; i<TAILLE; i++) {
		tab[i] = rand();
	}
}

double average(double* tab) {
	int i;
	double sum = 0, average;
	for (i = 0; i < ESSAIS; ++i)
	{
		sum += tab[i];
	}
	average = sum/ESSAIS;
	return average;
}

double proceed() {
	time_t t_start, t_end;
	int tableau[TAILLE];
	randArray(tableau);
	time(&t_start);
	sortArray(tableau, t_start);
	time(&t_end);
	return difftime(t_end, t_start);
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i;
	double results[ESSAIS];

	
	printf("Exécution du test avec %d tableaux de taille %d.\n", ESSAIS, TAILLE);

	for(i=0; i<ESSAIS; i++) {
		printf("Traitement n°%d : ", i+1);
		results[i] = proceed();
		printf("%.1fs\n", results[i]);
	}


	printf("Effectué avec une moyenne de %f secondes\n", average(results));
	return 0;
}