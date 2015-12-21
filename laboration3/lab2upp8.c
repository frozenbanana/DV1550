#include <stdio.h>
#include <math.h>

int main (void){
	int input;

	printf("Ge mig ett årtal så ska jag kolla om det är ett skottår\n");
	scanf("%d", &input);

	while(input < 0 || input > 2015){
		printf("Du får skriva ett årtal som finns i den gregorianska kalendern\n");
		scanf("%d", &input);
	}


	if(!(input % 4)){
		if(!(input % 100) && ((input % 400) > 0)){
			printf("Nej, %d var inte ett skottår.\n", input);
			return 0;
		}
		printf("Yes, %d var ett skottår.\n", input);
	}
	else
		printf("Nej, %d var inte ett skottår.\n", input);
		
	return 0;
}
