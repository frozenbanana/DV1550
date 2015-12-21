#include <stdio.h>
#include <stdlib.h> // rand och srand
#include <time.h> // time

void genRand(int* y,long x){
   int randomNumber = 0;
   srand(time(NULL)); // Skapar (seed) baserat pa nu (tid i sekunder);
   int i = 0;
   for(;i<x;i++){
   randomNumber = rand()%10 + 1; // Likformigt slumptal i intervallet [1;10]
    y[i] = randomNumber;
   }
   i == x ? printf("Array fylld med slumpade heltal!\n"): printf("Något gick fel!\n");
}

void getAvr(int* y, long x){
    int tot = 0;
   for(int i=0;i<x;i++){
    tot += y[i];
   }
    int medelV = tot/x;
    printf("Medelvärde: %d\n", medelV);
}

void minMax(int* y, long x){
        int min = y[0];
        int max = y[0];
    for(int i=1;i<x;i++){
        max <= y[i] ? max = y[i] : max; 
        min >= y[i] ? min = y[i] : min; 
    }
    printf("Minsta: %d, Högsta: %d \n",min,max);
}

int main(void) {
        int numbers[1000] = {0};
        
        genRand(numbers, sizeof(numbers)/4);
        getAvr(numbers, sizeof(numbers)/4);
        minMax(numbers, sizeof(numbers)/4);

        return 0;
}
