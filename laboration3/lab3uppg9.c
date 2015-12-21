/* 
Uppgift 9 Lottodragning 1 Skriv ett lottodragningsprogram. Programmet ska skriva ut en lottorad med 7 st heltal i intervallet [1; 35].
Anmärkning: Tänk på att inga dubbletter i lottoraden tillåts.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int isNotUnique(int* y, int x, int currentSize){
    
    for(int i; i<currentSize; i++){
        if(y[i] == x)
            return 1;
    }
    return 0;
}

int main(){
    int randNum = 0;
    srand(time(NULL));
    int lotto[7] = {0};
    for(int i=0;i<7;i++){
        randNum = rand()%35 + 1;
        lotto[i] = randNum;
        while(isNotUnique(lotto, randNum, i)){ 
            randNum = rand()%35 + 1;
            lotto[i] = randNum;
        }
    }

    printf("Lottorad:\n");
    for(int i=0;i<7;i++)
        printf("%d ", lotto[i]);
    
    return 0;
}
