#include <stdio.h>
#include <stdlib.h> // rand och srand
#include <time.h> // time

void genRand(int* y, long x){
   int randomNumber = 0;
   srand(time(NULL)); // Skapar (seed) baserat pa nu (tid i sekunder);
   int i = 0;
   for(;i<x;i++){
   randomNumber = rand()%100 + 1; // Likformigt slumptal i intervallet [1;100]
    y[i] = randomNumber;
   }
   i == x ? printf("Array fylld med slumpade heltal!\n"): printf("Något gick fel!\n");
}

void getAvr(int* y, long x){
    int tot = 0;
   for(int i=0;i<x;i++)
    tot += y[i];
   
    int medelV = tot/x;
    printf("Average: %d\n", medelV);
}

void minMax(int* y, long x){
        int min = y[0];
        int max = y[0];
    for(int i=1;i<x;i++){
        max <= y[i] ? max = y[i] : max; 
        min >= y[i] ? min = y[i] : min; 
    }
    printf("Minimum: %d, Maximum: %d \n",min,max);
}

void searchNumInArray(int* y,int x){
    int foundIndex[20] ={0};
    int j = 0;
    for(int i=0;i<1000;i++){
        x == y[i] ? foundIndex[j++] = i:i;
    }
    if(foundIndex[0] == 0){
         printf("%d was not found in the array\n", x);
    }
    else{
        printf("%d was found at index: ", x);
        j = 0;
        printf("%d", foundIndex[j++]);
        while(foundIndex[j] != 0)
            printf(", %d", foundIndex[j++]);
    }
    
    printf(".\n");

}
int main(void) {
        int numbers[1000] = {0};
        int searchNumb = 0;
        genRand(numbers, sizeof(numbers)/4);
        getAvr(numbers, sizeof(numbers)/4);
        minMax(numbers, sizeof(numbers)/4);

        printf("Search for a number(1-100): ");
        scanf("%d", &searchNumb);
        while(searchNumb < 1 || searchNumb > 100 )
        {
            printf("Between 1-100 please..\n");
            scanf("%d", &searchNumb);
        }

        searchNumInArray(numbers,searchNumb);

        return 0;
}
