/*
 *Skriv ett program som skriver ut summan av alla palindromtal under
 10000.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Reverse string forwards and save it in backwards. backwards has to be at least as big as forwards!*/
void reverse(char*forwards, char*backwards){
  int i=0;  // in the old C-Standard you have to declare all used variables at the beginning of a block, which means e.g. for(int i...) was not allowed.
  for(i=0; i < strlen(forwards); i++) {// for every char in forwards
    backwards[strlen(forwards)-i-1] = forwards[i]; // take that char and put it at the reversed position in backwards
  }
  backwards[strlen(forwards)] = 0; // zero termination of string, so that printf knows when to stop printing bytes from the memory
}

int main(){
  int i=0;
  int limit = 100;            // begränsningen på tal vi ska undersöka
  char test[15], rTest[15];   // test för talet, rTest för reverse-talet
  
  for(i = 0; i < limit; i++){      
    sprintf(test, "%d", i);   // omvandla i till limit till sträng
    
    reverse(test, rTest);     // sätt in omvända test i rTest
    
    printf("%s %s %s\n", test, rTest, !strcmp(test,rTest)?"Palindrome":"-"); // skriv ut!
  }
}
