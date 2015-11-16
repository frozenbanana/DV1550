#include <stdio.h>

/* en array med olika rabbatter	*/
float const rabatt[3] = {.10,.15,.20};

int main (void){
	int quit = 0;			// medans quit är 0 så körs while
	int input = -1; 		// input kan inte vara noll då input = 0 -> quit = 1
	int total = 0; 			// totalvärdet av inköpen
	
	printf("Köp prylar! (för att gå till kassa tryck 0)\n");
	printf("Välj mellan:\n1.Bok - 340:-\n2.Byxor - 400:-\n3.Bambu - 50:-\n");
	/* Nu startas kundsessionen*/
	while(!quit){
		scanf("%d", &input); // input hanterar kundens val
		if(input == 1){
			total += 340;
			printf("Det blir 340 kr\n");
		}
		else if (input == 2){
			total += 400;
			printf("Det blir 400 kr\n");
		}
		else if (input == 3){
			total += 50;
			printf("Det blir 50 kr\n");
		}
		else if (input == 0){
			if(total >= 3000){ 		// inköp över minst 3000 ger 20 % rabatt
				printf("Du har handlar för 3000 eller mer, du får 20%% rabatt\n");
				printf("total: %.2f:-\n", (float)(1 - rabatt[2])*total);
				}				
			else if(total >= 2000){ // inköp över minst 2000 ger 15 % rabatt
				printf("Du har handlar för 2000 eller mer, du får 15%% rabatt\n");
				printf("total: %.2f:-\n", (float)(1 - rabatt[1])*total);
			}
			else if(total >= 1000){ // inköp över minst 1000 ger 10 % rabatt
				printf("Du har handlar för 1000 eller mer, du får 10%% rabatt\n");
				printf("total: %.2f:-\n", (float)(1 - rabatt[0])*total);
			}
			else					// under 1000 och allt annat = normalpris
				printf("total: %d \n", total);

			quit = 1;
		}	
		else{ 						// vid feltryckning avslutas programmet
			printf("Oj, du skrev något annat än 1,2,3 eller 0\n");
			printf("Programmet avslutas\n");

			quit = 1;
		}

	}

	return 0;
}