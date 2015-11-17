#include <stdio.h>
#include <time.h>

int main(){
/*	int random, seed;
	char* result;
	seed = timme(NULL);
	srand(seed);
	random = rand();

	if(random%2)
		random = "Krona";
	else if (!random%2)
		random = "klave";
	else
		printf("Något är fel\n");
	printf("Det blev %s \n", result);
*/


	int dots;

	int random, seed;
        char* result;
        seed = time(NULL);
        srand(seed);
        random = rand();
	dots = random % 6 + 1; 	// finns ingen tärningssida med 0 prickar
	
	switch(dots)
	{
		case 1:
			printf("Etta\n");
			break;
                case 2:
                        printf("Tvåa\n");
                        break;
                case 3:
                        printf("Trea\n");
                        break;
                case 4:
                        printf("Fyra\n");
                        break;
                case 5:
                        printf("Femma\n");
                        break;
                case 6:
                        printf("Sexa\n");
                        break;
		default:
			printf("Något blev fel");
	}
	return 0;
}
