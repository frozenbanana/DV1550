#include "myblackjack.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define DECKSIZE 52

struct card;

struct card* createDeck(){
    int i;
    struct card * anyArray;
    anyArray = (struct card *)malloc((sizeof(struct card)*DECKSIZE));
    for(i = 0; i < DECKSIZE; i++){
        anyArray[i].value = i % 13; // 1-13 * 4 i en kortlek    
        anyArray[i].color = i / 13; // 13 st kort per färg
    }
    return anyArray;
}

void shuffleDeck(struct card *anyPtr){
    srand(time(NULL));  // sätter frö
    int random,i;         // ska peka på ett random tal mellan 0-51
    struct card *a, *b; // pointers för att byta värde
    struct card temp;   
    for(i = 0; i < DECKSIZE; i++){  //loppar igenom hela kortleken
        a = &anyPtr[i];            //a ref till minnesadressen av anydeck[i]
        random = rand() % 52;       //random är mellan 0-51
        b = &anyPtr[random];   //b deref minneadrees av random i av any deck
        temp = *a;              //temp pekas om till a's adress
        *a = *b;                //a pekar till b
        *b = temp;              //b pekar till temp som är b's gamla adress;
    }
}

void dealCards(struct card* anyCard,struct card *anyDeck,struct card *usedCards, int amount){ // ska ge skapa kort och ge random värde
  srand(time(NULL));
  int i, j, random;
  int used = 0;
  if(anyCard == NULL){
    anyCard = (struct card*)malloc((sizeof(struct card)*amount)); // ge första kortet
  printf("anyCard == NULL\n");
  }
  else{
    anyCard = (struct card*)realloc(anyCard,sizeof(struct card)*++amount);
  printf("anyCard != NULL\n");
  }
  for(i=0;i<amount;i++){
  //printf("i: %d\n", i);
    random = rand() % 51;
    for(j=0;j<DECKSIZE;j++){ // 
     if((anyDeck[random].value == usedCards[j].value) && (anyDeck[random].color == usedCards[j].color)){
          used = 1;
      }
    }
    if(used == 1){
      i--; 
      }
    else{
     anyCard[i] = anyDeck[random];     
      usedCards[i] = anyCard[i]; // make sure that card cannot be taken again
    }
      
      used = 0; 
  }
   
}

void printCards(struct card *anyPtr, int amount){
    int i;
    for(i=0;i<amount;i++){

        printf("Inne i printCards\n");
        printf("Card number %d: ",i+1);

        switch(anyPtr[i].value){
           case 0:
                printf("ACE "); break;
           case 1:
                printf("2 "); break;
           case 2:
                printf("3 "); break;
           case 3:
                printf("4 "); break;
           case 4:
                printf("5 "); break;
           case 5:
                printf("6 "); break;
           case 6:
                printf("7 "); break;
           case 7:
                printf("8 "); break;
           case 8:
                printf("9 "); break;
           case 9:
                printf("10 "); break;
           case 10:
                printf("JACK "); break;
           case 11:
                printf("QUEEN "); break;
           case 12:
                printf("KING "); break;
           default:
                printf("ERROR"); break;
       }
       switch(anyPtr[i].color){
           case 0:
                printf("♧ \n"); break;
           case 1:
                printf("♤ \n"); break;
           case 2:
                printf("♦ \n"); break;
           case 3:
                printf("♥ \n"); break;
           default: 
                printf("SUIT ERROR\n"); break;
       }
    }        
}



