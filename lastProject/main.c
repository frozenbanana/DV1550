/* BLACK JACK */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DECKSIZE 52

struct card{
    int value;
    int color; // 0 = spader, 1 = klöver, 2 = ruter, 3 hjärter
};

struct player{
   char name[20];
   int amountCard;  // jag vill sätta = 0
   struct card * playersCards;         // jag vill sätta = NULL
};

struct card* createDeck(){
    int i;
    struct card * anyArray;
    anyArray = (struct card *)malloc((sizeof(struct card)*DECKSIZE));
    for(i = 0; i < DECKSIZE; i++){
        anyArray[i].value = i % 13; // 1-13 * 4 i en kortlek    
        anyArray[i].color = i / 13; // 13 st kort per färg
    }
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

struct player* makePlayers(int amount){
    char choice;
    int i;
    struct player *playerPtr;
 
    playerPtr = (struct player *)malloc((sizeof(struct player)*amount));
    printf("Do you want to name players? (y/n)\n");
    scanf("%c", &choice);
    
    /*if(choice != 'y'){   
      for(i=0;i<amount;i++){
        c = (i + 1) + '0';
        playerPtr[i].name = "player" + c; // funkar detta?     
      }
    }
    else*/
      for(i=0;i<amount;i++){
        printf("Name player %d: ", i+1);
        scanf("%s",playerPtr[i].name);
        getchar();
      }

      return playerPtr;
}

void printCards(struct card* anyCard,int size){
   // printf("size: %d\n", *size);
    int i;
   // printf("i2: %d\n", i);
    for(i=0;i<size;i++){

        printf("Card number %d: ",i+1);
        //printf("anyCard[%d].value. %d\n",i, anyCard[i].value);

        switch(anyCard[i].value){
           case 0:
                printf("ACE ");
            break;
           case 1:
                printf("2 ");
            break;
           case 2:
                printf("3 ");
            break;
           case 3:
                printf("4 ");
            break;
           case 4:
                printf("5 ");
            break;
           case 5:
                printf("6 ");
            break;
           case 6:
                printf("7 ");
            break;
           case 7:
                printf("8 ");
            break;
           case 8:
                printf("9 ");
            break;
           case 9:
                printf("10 ");
            break;
           case 10:
                printf("JACK ");
            break;
           case 11:
                printf("QUEEN ");
            break;
           case 12:
                printf("KING ");
            break;
           default:
                printf("ERROR");
            break;
       }
       switch(anyCard[i].color){
           case 0:
                printf("♧ \n");
            break;
           case 1:
                printf("♤ \n"); 
            break;
           case 2:
                printf("♦ \n");
            break;
           case 3:
                printf("♥ \n");
            break;
           default: 
                printf("SUIT ERROR\n");
            break;
       }
    }        
}

void dealCards(struct card* anyCard,struct card *anyDeck, int size){ // ska ge skapa kort och ge random värde
  srand(time(NULL));
  int i;
  int random;
  if(anyCard == NULL){
    //printf("anyCard == NULL\n");
    anyCard = (struct card*)malloc((sizeof(struct card)*size)); // ge första kortet
  }
  else{
    anyCard = (struct card*)realloc(anyCard,sizeof(struct card)*++size);
  }
  printf("size: %d\n", size); 
  for(i=0;i<size;i++){
    random = rand() % 51;
 //   printf("BEFORE Value %d, color %d\n",anyCard[i].value,anyCard[i].color);
    anyCard[i] = anyDeck[random]; //ger ett random värde
 //   printf("After Value %d, color %d\n",anyCard[i].value,anyCard[i].color);
  }
   
}

  
int main(){
    struct player *players;
    struct card *deck;
    //struct player computer;
    int numPlayers;
    int i;


    deck = createDeck();
    shuffleDeck(deck);
    printf("__WELCOME_TO_HENRY'S_BLACK_JACK_GAME__\n");     
    printf("How many players? (MAX 5)\n");
    scanf("%d", &numPlayers);
     while(numPlayers < 1 || numPlayers > 5){
       printf("Minimum 1, Maximum 5\n");
       scanf("%d", &numPlayers);
     }
    players = makePlayers(numPlayers);
    printf("number of players %d\n", numPlayers);
    printf("_________LETS_PLAY_BLACK_JACK!________\n");
    for(i=0;i<numPlayers;i++){
      players[i].playersCards = NULL;
      players[i].amountCard = 2; //varför fungerar du inte?=
      printf("player: %s\n", players[i].name);
      dealCards(players[i].playersCards,deck,players[i].amountCard);
    }

    free(deck);
    free(players);
    return 0;
}


//TO DO: Korten ska plockas från kortleken. 
