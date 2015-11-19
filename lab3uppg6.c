#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*I den här uppgiften ska du implementera ett simpelt spel som låter användaren gissa vilket
 * heltal som ditt program har slumpat fram (i intervallet [1; 50]). Om användaren gissar
 * fel ska en ledtext som avslöjar om det är för högt eller för lågt presenteras på skärmen.
 * När/om användaren till slut gissar rätt så ska programmet skriva ut hur många försök som
 * gick åt
 * */

int main(){
    int tries = 1;          // antal försök
    int guess = 0;          // Datorns gissade tal
    float uGuess = 0;       // Användarens gissade tal

    srand(time(NULL));       // Sätter ett seed till rand
    guess = rand() % 50 + 1; // intervallet [1;50]
    
    printf("Gissa vilket tal jag tänker på (1-50) \n");
    scanf("%f",&uGuess);                                  
    while(uGuess != guess) {                            // Forsätt spelet tills användaren gissar rätt
      while((uGuess - (int)uGuess) > 0) {               // Kontrollera att det är heltal, inte flytal
                printf("Bara heltal! Testa igen\n");
                scanf("%f",&uGuess);
         }
            uGuess > guess ? printf("Det är för högt! \n") : printf("Det är för lågt \n"); // Högt eller för lågt?
            getchar();
            scanf("%f",&uGuess);
            tries++;                                    // räkna hur många gånger användaren gissar
    }
    printf("Du gissade rätt på %d försök! \n", tries);
}
