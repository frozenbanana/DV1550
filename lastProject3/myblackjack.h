#ifndef myblackjack_h
#define myblackjack_h

struct card{
  int value;
  int color;
};

struct player{
  char name[30];
  struct card * playerHand;
  int cardValue;
  int startCards;
};

struct card* createDeck();
void shuffleDeck(struct card *anyPtr);
void printCards(struct card *anyPtr, int amount);
void dealCards(struct player *anyone, struct card *anyDeck, int *counter);

void checkHand(struct card *anyPtr, int amount, int *value);
int actDealer(struct player anyone, struct card *aDeck, int *counter, int pullLimit);
void whoWon(struct player anyOne, struct player anyTwo, struct player dealer);
#endif
