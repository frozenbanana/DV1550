#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct persons		// Struct for person
	{				// Medlemmar
		float weight;
		float length;
	};

struct persons *pr;	// struktpekare 

/* variabler för att hålla totalvärden*/
float totWeight;	
float totLength;
float totBMI;

/*skapar nya objekt av struketen*/
int persAdd (int amountofpeople){
	/*sätter minne med storleken av vår struct */
	pr = (struct persons*) malloc(amountofpeople*sizeof(struct persons));

	int i;
	for (int i = 1; i <= amountofpeople; i++)
	{
		/* fyller objekt med värden */
		printf("Struct för person%d skapas..\n", i);
		getchar();
		printf("Ange vikt (KG): ");
		scanf("%f", &pr[i].weight);
		printf("Ange längd (M): ");
		scanf("%f", &pr[i].length);

		/* sparar indiviuella värden i totalvariabel */
		totWeight += pr[i].weight;
		totLength += pr[i].length;
		totBMI += pr[i].weight/pow(pr[i].length,2);
		printf("person%d = %.2f KG, %.2f M, %.2f BMI\n",i, pr[i].weight, pr[i].length, pr[i].weight)/(pow(pr[i].length,2));
	}
		return 0;
}

int main(void){
	int amountofpeople = 0;
	printf("Benämn antal personer i beräkning:");
	scanf("%d", &amountofpeople);

	/* genererar objekt */
	persAdd(amountofpeople);
	int i;
	
	printf("total weight = %.2f\n",totWeight); 
	printf("average weight = %.2f\n", totWeight/amountofpeople); 
	printf("total length = %.2f\n",totLength); 
	printf("average length = %.2f\n", totLength/amountofpeople);
	printf("total BMI = %.2f\n", totBMI); 
	printf("average BMI = %.2f\n", totBMI/amountofpeople);
	
	/* frisätter pekare */
	if (pr){ 
		free(pr);
	}
	getchar();

	return 0;
}




