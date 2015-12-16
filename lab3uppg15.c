#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int i,j,n=0;
    char string[100];
    char konsonant[] = "bcdfghjklmnpqrstvxz";
    char rovString[300];
    memset(string, '\0',sizeof(string));    
    memset(rovString, '\0',sizeof(rovString));
    printf("Input text to rövarspråket-encryption:\n");
    fgets(string, sizeof(string)-1, stdin);
   
    //printf("stor första bokstav: %c", toupper(konsonat[j]));
    for(i=0;i<=strlen(string)-1;i++){
        for(j=0;j<=strlen(konsonant)-1;j++){
            if(string[i] == konsonant[j] || string[i] == toupper(konsonant[j])){  
                rovString[n] = string[i];
                rovString[n+1] = 'o';
                rovString[n+2] = string[i];
                n+=3;
                break;
            }
            else if (j == strlen(konsonant)-1){
                rovString[n++] = string[i];
            }
        }

    }

    
    printf("Output:\n%s\n", rovString);
    
}
