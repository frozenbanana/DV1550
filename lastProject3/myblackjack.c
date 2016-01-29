#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "myblackjack.h"
#define DECKSIZE 52
#define MAXCARDS 11 // 4 aces, 4 two's, 3 three's = 11 cards the highest amount of cards possible

struct card;
struct player;

struct card* createDeck(){
  int i;
  struct card *aDeck;
  aDeck = (struct card *)malloc((sizeof(struct card)* DECKSIZE)); // creates memoryblock to 52 cards
  for(i=0;i<DECKSIZE;i++){  
    aDeck[i].value = i%13;          // values 0-13 , 4 times ( ace is 0, 2 is 1, 3 is 2...
    aDeck[i].color = i/13;          // color 0-3, 13 times ( clove is 0, spades is 1 ....
  }
  
  return aDeck;
}

void shuffleDeck(struct card *anyDeck){
    srand(time(NULL));    // seading 
    int random,i;         
    struct card *a, *b;   // pointers to change values in deck
    struct card temp;     // temporary struct for swap a and b
    for(i = 0; i < DECKSIZE; i++){  
        a = &anyDeck[i];            //a ref to adress of anydeck[i]
        random = rand() % 52;       //random is 0-51
        b = &anyDeck[random];   //b ref to adress of anyDeck[random] 
        temp = *a;              //temp takes value of inside a
        *a = *b;                // a swap's with b
        *b = temp;              // b swap's with temp (who has same value as a)
    }
}

void printCards(struct card *anyCard, int amount){
 int i;    
 for(i=0;i<amount;i++){               // loops through every card in cardhand
     printf("Card number %d: ",i+1);  
        switch(anyCard[i].value){     // prints out correct number
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
       switch(anyCard[i].color){          // and color
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
void dealCards(struct player *anyone, struct card *anyDeck, int *counter){ // updates card hand
  int i;
  int amountOfCards = anyone->startCards;
  if(anyone->playerHand == NULL){
      anyone->playerHand = (struct card *)malloc(sizeof(struct card)*MAXCARDS);
    for(i=0;i<amountOfCards;i++){                        // dealing cards 1st time
       anyone->playerHand[i] = anyDeck[*counter];        // player gets fist unused card in deck
      *counter += 1;                                     // then that card in used
      }
  }
  else{                                             // hit or stay phase
    for(i=amountOfCards;i<amountOfCards+1;i++){
       anyone->playerHand[i] = anyDeck[*counter];
       *counter += 1;
    }
    anyone->startCards++;                           // updates amount of cards on cardhand.
  }
}
void checkHand(struct card *anyCard, int amount, int *value){ // updates cardvalue of cardhand
 int i;
 int aceHighLow = 0;                  // detemines amount of aces on hand
 *value = 0;                          // cardvalue is reset to recount
  for(i=0;i<amount;i++){              //loops through all cards on hand
        switch(anyCard[i].value){     // and adds correct value to player.cardValue 
           case 0:
                 aceHighLow++; break;
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
  // if any ace on hand
  if(aceHighLow>0){  
    for(i=0; i <aceHighLow;i++){      // for every ace
      if((*value + 11) <= 21)         // decide if high ace is OK
        *value += 11;
      else
        *value += 1;                  // otherwise ace = 1
    }
  }
  printf("Value: %d\n", *value);     
  if(*value > 21){
     printf("BUSTED!\n");
     *value = -1;                     // to mark player is busted
  }
}

int actDealer(struct player anyone, struct card *aDeck, int *counter, int pullLimit){ //
  char choice = 'h';
  int stay = 1;
  printf("%s TURN:\n", anyone.name);
  printCards(anyone.playerHand, anyone.startCards);
  checkHand(anyone.playerHand, anyone.startCards, &anyone.cardValue);
 /* Players  */
  if(pullLimit == 21){          
    if(anyone.cardValue == 21 && anyone.startCards == 2){   // check if Black Jack
      printf("BLACK JACK!\n");
      stay = 0;
    }
    while(choice == 'h' && stay == 1){           // gives,prints and updates card values while player types 'h'
      printf("Hit or stay? (h/s)\n");
      scanf("%c",&choice);
      getchar();
      if(choice == 'h' && anyone.cardValue <= 20){
        dealCards(&anyone, aDeck, counter);
        printCards(anyone.playerHand, anyone.startCards);
        checkHand(anyone.playerHand, anyone.startCards, &anyone.cardValue);
         
        if(anyone.cardValue > 20 || anyone.cardValue == -1)// if player is busted leave loop
            stay = 0;
          
      }
    }
  }

  /* Dealer */
  while(pullLimit < 18 && stay){
    while(anyone.cardValue < 16){                       // dealer has to pull until cardvalue > 16
        printf("Press enter to see next card\n");
        getchar();
        dealCards(&anyone, aDeck, counter);
        printCards(anyone.playerHand, anyone.startCards);
        checkHand(anyone.playerHand, anyone.startCards, &anyone.cardValue);
       }      
         stay = 0;
        
  }
  return anyone.cardValue;                // update cardvalue
}


void whoWon(struct player anyone, struct player anytwo, struct player dealer){
  /* Presenting final card values */
  printf("%s got: %d\n", anyone.name, anyone.cardValue);
  printf("%s got: %d\n", anytwo.name, anytwo.cardValue);
  printf("%s got: %d\n", dealer.name, dealer.cardValue);
  printf("This means:\n");
  
  /* player1 compares with dealer  */
  if(anyone.cardValue > dealer.cardValue)
    printf("%s won!\n",anyone.name);
  else if(anyone.cardValue == dealer.cardValue)
    printf("%s is equal with the dealer\n",anyone.name);
  if(anyone.cardValue < dealer.cardValue)
    printf("%s lost!\n",anyone.name);
  /* player 2 compares with dealer */
  if(anytwo.cardValue > dealer.cardValue)
    printf("%s won!\n",anytwo.name);
  else if(anytwo.cardValue == dealer.cardValue)
    printf("%s is equal with the dealer\n",anytwo.name);
  if(anytwo.cardValue < dealer.cardValue)
    printf("%s lost!\n",anytwo.name);

    /* if dealer and player is equal and between 17-19 then dealer wins  */  
  if(anyone.cardValue == dealer.cardValue && (anyone.cardValue>=17 && anyone.cardValue <= 19))
    printf("But the dealer won over %s because of special rule\n", anyone.name);
  else if(anytwo.cardValue == dealer.cardValue && (anytwo.cardValue>=17 && anytwo.cardValue <= 19))
    printf("But the dealer won over %s because of special rule\n", anytwo.name);
}
