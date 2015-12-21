#include <stdio.h>
#include <string.h>
/*
 * Ett palindrom är ett ord som är detsamma baklänges som framlänges. T.ex ordet Kajak
 * baklänges blir kajaK vilket därmed är ett palindrom. Däremot ordet programmering blir
 * gniremmargorp vilket inte är ett palindrom. Du ska skriva ett program som ber användaren
 * mata in ett ord. Därefter ska ditt program avgöra om det inmatade ordet är ett palindrom
 * eller inte.
 */

int main(){
   char string[16] = {0};
   
   printf("Skriv in ett ord för att kontrollera om det är ett palindrom: \n");
   scanf("%s",string);
   int size = strlen(string)-1;                                // hitta storleken på ordet (minus \0)
   for(int i=0;i<size;i++){
            if(string[i] != string[size-i]){                    // jämför första med sista, andra med näst sista osv
                printf("%s är inte en palindrom \n", string);   // om olikhet är det inte en palidom
             return 0;
             }   
        }
    
   printf("%s är en palindrom.\n", string);                     // annars är det en palidrom
   return 1;              
}
