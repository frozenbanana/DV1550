#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myblackjack.h"

#define DECKSIZE 52

struct card;
struct player;
int main(void){
  printf("WELCOME TO HENRYS BLACKJACK\n"); 
  //player1
  struct player player1;
  printf("Type name for player1: ");
  scanf("%s",player1.name);
  getchar();
  player1.playerHand = NULL;
  player1.cardValue = 0;
  player1.startCards = 2;
  //player2
  struct player player2;
  printf("Type name for player2: ");
  scanf("%s",player2.name);
  getchar();
  player2.playerHand = NULL;
  player2.cardValue = 0;
  player2.startCards = 2;
  //computer
  struct player comp;
  strcpy(comp.name, "the dealer");
  comp.playerHand = NULL;
  comp.cardValue = 0;
  comp.startCards = 1;

  struct card *deck = NULL;
  int deckCount = 0;
  //struct card *usedDeck = NULL;
  //usedDeck = (struct card*)calloc(DECKSIZE,sizeof(struct card));
  deck = createDeck(deck);    // deck created
  shuffleDeck(deck);   // deck shuffled
  
  /* Name giving and first cards dealing  */
  printf("\n\nHand of %s:\n", player1.name);
  dealCards(player1.playerHand, deck, &deckCount, &player1.startCards);
  printCards(player1.playerHand, player1.startCards);
  
  printf("\n\nHand of %s: \n", player2.name);
  dealCards(player2.playerHand, deck, &deckCount, &player2.startCards);
  printCards(player2.playerHand, player2.startCards);
  
  printf("\n\nHand of %s: \n", comp.name);
  dealCards(comp.playerHand, deck, &deckCount, &comp.startCards);
  printCards(comp.playerHand, comp.startCards);
 

  /* Hit or stay phase  */
 printf("------------------------------------------------------\n");
 player1.cardValue = actDealer(player1,deck, &deckCount,22);
 printf("------------------------------------------------------\n");
 player2.cardValue = actDealer(player2,deck, &deckCount,22);
 printf("------------------------------------------------------\n");
    if(player1.cardValue  == -1 && player2.cardValue == -1){  // if both loses bank does not have to continue
        printf("Both players lost!\n");
        printf("--------------------Game-finished---------------------\n");
        goto masteJagKompletteraNufragetecken;
    }
 comp.cardValue = actDealer(comp,deck,deckCount,17); 
 printf("------------------------------------------------------\n");
 whoWon(player1, player2, comp);   
 printf("--------------------Game-finished---------------------\n");

masteJagKompletteraNufragetecken:
/* Freeing memory */
free(deck);
free(player1.playerHand);
free(player2.playerHand);
free(comp.playerHand);

}
