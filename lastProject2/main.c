#include <stdio.h>
#include <stdlib.h>

#include "myblackjack.h"

#define DECKSIZE 52

struct card;

int main(void){
  //player1
  char player1[] = "Player1";
  struct card *cardsPlayer1 = NULL;
  //player2
  char player2[] = "Player2";
  struct card *cardsPlayer2 = NULL;
  //computer
  char comp[] = "The Dealer";
  struct card *cardsComputer = NULL;

  struct card *deck = NULL;
  struct card *usedDeck = NULL;
  usedDeck = (struct card*)calloc(DECKSIZE,sizeof(struct card));
  deck = createDeck(deck);
  printf("Deck är klar!\n");
  printf("deck[43].value = %d\ndeck[43].color = %d\n", deck[43].value, deck[43].color);
  dealCards(cardsPlayer1, deck, usedDeck, 2);
  dealCards(cardsPlayer2, deck, usedDeck, 2);
  dealCards(cardsComputer, deck, usedDeck, 1);
  printf("cardsComputer[i].value: %d\n", cardsComputer.value);
  printf("dealCards är klar!\n");

  printCards(cardsComputer, 1);
  

  return 0;
}
