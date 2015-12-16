/* 
Uppgift 10 Lottodragning 2
I denna uppgift ska du skriva ett annat lottodragningsprogram. Detta lottodragningspro- grammet är lite speciellt. Programmet ska skriva ut en lottorad på 70 st heltal i intervallet [1; 2000] . Återigen, inga dubbletter är tillåtna.  */

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
    int lotto[70] = {0};
    for(int i=0;i<70;i++){
        randNum = rand()%2000 + 1;
        lotto[i] = randNum;
        while(isNotUnique(lotto, randNum, i)){ 
            randNum = rand()%2000+ 1;
            lotto[i] = randNum;
        }
    }

    printf("Lottorad:\n");
    for(int i=0;i<70;i++)
        printf("%d ", lotto[i]);
    
    printf("\n"); 
    return 0;
}
