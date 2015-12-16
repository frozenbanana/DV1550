/* BLACK JACK */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DECKSIZE 52

struct card{
    int value;
    int color;
};

struct card* createDeck(){
    int i;
    struct card * anyArray;
    anyArray = (struct card *)malloc((sizeof(struct card)*DECKSIZE));
    printf("Inne\n");
    for(i = 0; i < DECKSIZE; i++){
        anyArray[i].value = i % 14; // 1-13 * 4 i en kortlek    
        anyArray[i].color = i / 13; // 13 st kort per färg
    }
    printf("forloop avklarad i createDeck\n");
    return anyArray;
}

void shuffleDeck(struct card * anyDeck){
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

int askAmountPlayers(){
    int amount = 0;
    printf("How many players? (MAX 5)\n");
    scanf("%d",&amount);
    while(amount <= 0 || amount > 5){
        printf("Not correct (MAX 5)\n");
        printf("How many players? (MAX 5)\n");
        scanf("%d",&amount);
    }
    return amount;
}
void showCards(){

}
void createGame(int AmountOfPlayers){
}
int main(){
    struct card *deck;
    int numPlayers;    
    deck = createDeck();
    shuffleDeck(deck);
    printf("____________________________________\n");
    printf("WELCOME TO HENRY'S BLACK JACK GAME\n");     
    numPlayers = askAmountPlayers();
    
    return 0;
}
