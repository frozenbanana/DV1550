#include <stdio.h>
#include <string.h>
#include "func.h"

int main(){
    char string[10];
    printf("Type in string: ");
    scanf("%s",string); 
    getchar();
    reverse(string, strlen(string));
    printf("%s \n", string);
    reverse(string, strlen(string));
    printf("%s \n", string);
}
