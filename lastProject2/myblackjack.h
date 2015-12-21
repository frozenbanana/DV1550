#ifndef myblackjack_h
#define myblackjack_h

struct card{
  int value;
  int color;
};

struct card* createDeck();
void shuffleDeck(struct card *anyPtr);
void printCards(struct card *anyPtr, int amount);
void dealCards(struct card *anyCard, struct card *anyDeck, struct card *usedCards,int amount);

#endif
