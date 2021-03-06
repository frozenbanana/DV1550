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
struct card* dealCards(struct card *anyCard, struct card *anyDeck, struct card *usedCards, int *amount);

void checkHand(struct card *anyPtr, int amount, int *value);
int actDealer(struct player anyone, struct card *aDeck, struct card *aUsedDeck, int pullLimit);
void whoWon(struct player anyOne, struct player anyTwo, struct player dealer);
#endif
