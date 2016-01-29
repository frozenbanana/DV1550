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
  printf("utan ptr: %d\n", player1.startCards);
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

  int cardCounter = 0;
  struct card *deck = NULL;
  deck = createDeck(deck);    // deck created
  int i;
  for(i=0; i<20; i++)
    shuffleDeck(deck);   // deck shuffled

  /* Name giving and first cards dealing  */
  printf("\n\nHand of %s:\n", player1.name);
  dealCards(&player1, deck, &cardCounter);
  printCards(player1.playerHand, player1.startCards);
  printf("\n\nHand of %s: \n", player2.name);
  dealCards(&player2, deck, &cardCounter);
  printCards(player2.playerHand, player2.startCards);

  printf("\n\nHand of %s: \n", comp.name);
  dealCards(&comp, deck, &cardCounter);
  printCards(comp.playerHand, comp.startCards);


  /* Hit or stay face  */
 printf("------------------------------------------------------\n");
 player1.cardValue = actDealer(player1,deck, &cardCounter,22);
 printf("------------------------------------------------------\n");
 player2.cardValue = actDealer(player2,deck, &cardCounter,22);
 printf("------------------------------------------------------\n");
    if(player1.cardValue  == -1 && player2.cardValue == -1){  // if both loses dealer does not have to continue
        printf("Both players lost!\n");
        printf("--------------------Game-finished---------------------\n");
        goto masteJagKompletteraNufragetecken;
    }
 comp.cardValue = actDealer(comp,deck,&cardCounter,17);
 printf("------------------------------------------------------\n");
 whoWon(player1, player2, comp);
 printf("--------------------Game-finished---------------------\n");

masteJagKompletteraNufragetecken:
/* Freeing memory */
free(deck);
free(player1.playerHand);
free(player2.playerHand);
free(comp.playerHand);
return 0;
}
