#include <stdio.h>

/*
I denna uppgift ska du implementera en växelmaskin. Användaren ska mata in ett heltalsbelopp i kronor. Därefter ska en utskrift presenteras det antal av varje valör som ackumuleras till det belopp som användaren matade in.

*/
int main(void){
        int valor[9] = {1000,500,200,100,50,20,10,5,1};	// Sedlarnas/myntens värde
	int valorAntal[9] = {0};			// antal sedlar/mynt

	int total = 0;					// totalet som ska växlas
					
	printf("Skriv in totalbelopp som skall växlas: ");
	scanf("%d", &total);				// inmatning
	printf("Du får %d kr i:\n", total);
	int i;
	for(i=0;i<9;i++){
		valorAntal[i] = total/valor[i];		// antalet sedlar är heltals division med totalet och sedel/mynt-värdet
		if(i>6) 				// dem sista tre valörerna är mynt
			printf("%d-mynt: %d st\n",valor[i], valorAntal[i]);
		else	
			printf("%d-lapp(ar): %d st\n",valor[i], valorAntal[i]);
		total -= valorAntal[i]*valor[i]; 	// total minskas med antalet sedlar som växlas tills allt är växlat
	} 
	
	
	return 0;
}

