#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CARDSIZE 52
/*
 *Skriver ut alla de 52 korten.
 •
 Slumpar ordningen i kortleken.
 * */
enum suit{
    CLUB, SPADES, DIAMOND, HEARTS
};
typedef enum suit Suit;

enum value{
    ACE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,
    JACK, QUEEN, KING
};
typedef enum value Value;


struct card{
    Suit cardSuit;
    Value cardValue;
};

void addCardInDeck(struct card* anyDeck){
    int i=0;
    int j=0;
    Suit tempSuit = -1;    // + 1 = CLUBS
    Value tempValue = 0;  // ACE
    for(i;i<CARDSIZE;i++){
            anyDeck[i].cardValue  = tempValue % 13; // ace - king for each
            if(tempValue%13 == 0)                 //change suit after ace-king
                 tempSuit++;
            anyDeck[i].cardSuit = tempSuit;     //  suit of card get assigned 
            tempValue++;                        // increment the value
    }
}

void printDeck(struct card* anyDeck){
    int i;
    for(i=0;i<CARDSIZE;i++){
        printf("Card number %d: ",i+1);
       switch(anyDeck[i].cardValue){
           case 0:
                printf("ACE OF ");
            break;
           case 1:
                printf("TWO OF ");
            break;
           case 2:
                printf("THREE OF ");
            break;
           case 3:
                printf("FOUR OF ");
            break;
           case 4:
                printf("FIVE OF ");
            break;
           case 5:
                printf("SIX OF ");
            break;
           case 6:
                printf("SEVEN OF ");
            break;
           case 7:
                printf("EIGHT OF ");
            break;
           case 8:
                printf("NINE OF ");
            break;
           case 9:
                printf("TEN OF ");
            break;
           case 10:
                printf("JACK OF ");
            break;
           case 11:
                printf("QUEEN OF ");
            break;
           case 12:
                printf("KING OF ");
            break;
           default:
                printf("ERROR");
            break;
       }
       switch(anyDeck[i].cardSuit){
           case 0:
                printf("CLUBS\n");
            break;
           case 1:
                printf("SPADES\n");
            break;
           case 2:
                printf("DIAMONDS\n");
            break;
           case 3:
                printf("HEARTS\n");
            break;
           default: 
                printf("SUIT ERROR\n");
            break;
       }
    }        
        // printf("Card %d: %s of %s\n", i, anyDeck[i].cardValue, anyDeck[i].cardSuit);
}
void shuffleDeck(struct card * anyDeck){
    srand(time(NULL));          //sätter frö
    int r,i;
    struct card temp;           //temp struct för swap med a,b
    struct card *a,*b;          // poniters för att byta värde
    for(i=0;i<CARDSIZE;i++){    // loopa igenom kortlek
    a = &anyDeck[i];            // a pekar på 0-51 korten
    r = rand() % 52;            // r är slumpat mellan 0-51
    b = &anyDeck[r];            // b pekar på ett slumpat tal 0-51 (r)
    printf("Card number %d is swtiching with Card number %d\n",i,r);
    temp = *a;                  // temp håller värdet i a 
    *a = *b;                    // a bytar med b, som är slumpat från r
    *b = temp;                  // b tar a's gamla värde
    }
}
int main(){
int choice = 0;
struct card *deck;

deck = (struct card*)malloc((sizeof(struct card) * CARDSIZE));

addCardInDeck(deck);
printf("Cards added into deck.\n\n");
while(1){
    printf("Press 1 to print cards.\n");
    printf("Press 2 to shuffle cards.\n");
    scanf("%d",&choice);

    if(choice == 1)
        printDeck(deck);
    else if(choice == 2)
        shuffleDeck(deck);
    else
        break;
    }


}

