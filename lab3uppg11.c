/*
Uppgift 11 Lottodragning 3
Skriv ett program som löser både Lottodragning 1 och Lottodragning 2 i samma program.  Dvs gör ditt program generellt. Detta gör du med hjälp av att låta användaren mata in värden på de variabler som behövs (lägsta intervall-värde och högsta intervall-värde) för lottodragningsprogrammet. Antalet tal i raden ska vara definierad som en global konstant.  Återigen, inga dubbletter är tillåtna.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int isNotUnique(int* y, int x, int currentSize){
   //printf("I am in inside function\n"); 
    for(int i = 0; i<currentSize; i++){
        if(y[i] == x)
            return 1;
    }
    return 0;
}

const int SIZE = 20;

int main(){
    int interV = 0;
    int interV2 = 0;
    printf("What is the intervall for your lottery row?\n");
    scanf("%d", &interV);
    while(interV < 1){
        printf("Please type in an integer larger then 1");
        scanf("%d",&interV);
        getchar();
    }
    printf("to ");
    scanf("%d", &interV2);
    while(interV2 <= interV + SIZE){
        printf("Please type in an integer larger then the first number + %d\n", SIZE);
        scanf("%d",&interV2);
        getchar();
    }
    
    int randNum = 0;
    srand(time(NULL));
    int lotto[SIZE];
    for(int i=0;i<SIZE;i++){
        randNum = rand()%(interV2-interV+1) + interV;
        lotto[i] = randNum;
        while(isNotUnique(lotto, randNum, i)){ 
            randNum = rand()%(interV2-interV+1) + interV;
            lotto[i] = randNum;
        }
    }

    printf("Lottorad:\n");
    for(int i=0;i<SIZE;i++)
        printf("%d ", lotto[i]);
    
    printf("\n"); 
    return 0;
}
