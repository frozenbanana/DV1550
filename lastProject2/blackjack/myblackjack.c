#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "myblackjack.h"
#define DECKSIZE 52
#define MAXCARDS 11

struct card;
struct player;

struct card* createDeck(){
  int i;
  struct card *aDeck;
  aDeck = (struct card *)malloc((sizeof(struct card)* DECKSIZE));
  for(i=0;i<DECKSIZE;i++){
    aDeck[i].value = i%13;
    aDeck[i].color = i/13;
  }

  return aDeck;
}

void shuffleDeck(struct card *anyDeck){
    srand(time(NULL));  // sätter frö
    int random,i;         // ska peka på ett random tal mellan 0-51
    struct card *a, *b; // pointers för att byta värde
    struct card temp;
    for(i = 0; i < DECKSIZE; i++){  //loppar igenom hela kortleken
        a = &anyDeck[i];            //a ref till minnesadressen av anydeck[i]
        random = rand() % 52;       //random är mellan 0-51
        b = &anyDeck[random];   //b deref minneadrees av random i av any deck
        temp = *a;              //temp pekas om till a's adress
        *a = *b;                //a pekar till b
        *b = temp;              //b pekar till temp som är b's gamla adress;
    }
}

void printCards(struct card *anyCard, int amount){
  printf("INSIDE PRINTCARDS amount: %d\n", amount);
 int i;
 for(i=0;i<amount;i++){
     printf("Card number %d: ",i+1);
        switch(anyCard[i].value){
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
       switch(anyCard[i].color){
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
 printf("done printing\n");
}
void dealCards(struct player *anyone, struct card *anyDeck, int *counter){
  printf("INSIDE dealCards\n");
  int i;
  printf("name: %s\n", anyone->name);
  printf("startCards:: %d\n", anyone->startCards);
  int amountOfCards =  anyone->startCards;
  if(anyone->playerHand == NULL){
  printf("NULL\n");
      anyone->playerHand = (struct card *)malloc(sizeof(struct card)*MAXCARDS);
    for(i=0;i<amountOfCards;i++)                        // dealing cards 1st time
       anyone->playerHand[i] = anyDeck[*counter++];
  }
  else{                                             // hit or stay phase
  printf("else\n");
    for(i=amountOfCards;i<=amountOfCards+1;i++)
       anyone->playerHand[i] = anyDeck[*counter++];
  }
     printf("done dealing\n");
}

void checkHand(struct card *anyCard, int amount, int *value){
 int i;
 int oldValue = *value;
  for(i=0;i<amount;i++){
        switch(anyCard[i].value){
           case 0:
                if(*value <= 10)    //Ace is 11 if cardValue is > 10
                  *value += 11;
                else
                  *value +=1;  break;
           case 1:
                  *value += 2; break;
           case 2:
                  *value += 3; break;
           case 3:
                  *value += 4; break;
           case 4:
                  *value += 5; break;
           case 5:
                  *value += 6; break;
           case 6:
                  *value += 7; break;
           case 7:
                  *value += 8; break;
           case 8:
                  *value += 9; break;
           case 9:
                  *value += 10; break;
           case 10:
                  *value += 10; break;
           case 11:
                  *value += 10; break;
           case 12:
                  *value += 10; break;
           default:
                printf("ERROR"); break;
       }
    }
 *value -= oldValue;
  printf("Value: %d\n", *value);
  if(*value > 21){
     printf("BUSTED!\n");
     *value = -1;           // to mark player is busted
  }
}

int actDealer(struct player anyone, struct card *aDeck, int *counter, int pullLimit){
  char choice = 'h';
  //int stay = 1;
  printf("%s turn\n", anyone.name);
  printCards(anyone.playerHand, anyone.startCards);
  if(pullLimit == 21){
  while(choice == 'h'){
      printf("Hit or stay?\n");
      scanf("%c",&choice);
      dealCards(&anyone, aDeck, counter);
      printCards(anyone.playerHand, anyone.startCards);
      checkHand(anyone.playerHand, anyone.startCards, &anyone.cardValue);
    }
  }
  while(pullLimit < 18 ){
      dealCards(&anyone, aDeck, counter);
      printCards(anyone.playerHand, anyone.startCards);
      checkHand(anyone.playerHand, anyone.startCards, &anyone.cardValue);
   }




  return anyone.cardValue;
}


void whoWon(struct player anyone, struct player anytwo, struct player dealer){
  printf("%s got: %d\n", anyone.name, anyone.cardValue);
  printf("%s got: %d\n", anytwo.name, anytwo.cardValue);
  printf("%s got: %d\n", dealer.name, dealer.cardValue);
  printf("This means:");

  if(anyone.cardValue == dealer.cardValue && (anyone.cardValue>=17 && anyone.cardValue <= 19))
    printf("The dealer won over %s because of special rule\n", anyone.name);
  else if(anytwo.cardValue == dealer.cardValue && (anytwo.cardValue>=17 && anytwo.cardValue <= 19))
    printf("The dealer won over %s because of special rule\n", anytwo.name);

  if(anyone.cardValue > dealer.cardValue)
    printf("%s won!\n",anyone.name);
  else if(anyone.cardValue == dealer.cardValue)
    printf("%s is equal with the dealer\n",anyone.name);
  if(anyone.cardValue < dealer.cardValue)
    printf("%s lost!\n",anyone.name);
  if(anytwo.cardValue > dealer.cardValue)
    printf("%s won!\n",anytwo.name);
  else if(anytwo.cardValue == dealer.cardValue)
    printf("%s is equal with the dealer\n",anytwo.name);
  if(anytwo.cardValue < dealer.cardValue)
    printf("%s lost!\n",anytwo.name);

}
