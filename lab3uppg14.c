/*
 *Skriv ett program som skriver ut summan av alla palindromtal under
 10000.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPal(char * str){
    int strLen,i;
    strLen = strlen(str)-1;
    for(i=0;i<=strLen/2;i++)
        if(str[i] != str[strLen-i])
            return 0;
    return 1;
}

int main(){
   int limit = 10000;    // begränsningen på tal vi ska undersöka
   char test[15];        // test
  
    for(int i = 0; i < limit; i++){      
    sprintf(test, "%d", i);             // omvandla i till sträng
     if(isPal(test))                     // om test är palidrom, skriv ut  
        printf("%d\n", i);  
    }

}
