#include <stdio.h>

/*
 *Uppgift 4 Delbarhet 1
 Skriv ett program som summerar alla heltal under
 2000 som är jämt delbara med 3.
 */

int divAbleX(int tal, int div){
    int tot = 0;
    for(int i=1;i<=tal;i++)
        !(i % div) ? tot += i: tot;

    return tot;
}

int main(){
    int tal = 0;
    int div = 0;
    printf("Vilket tal:");
    scanf("%d",&tal);
    printf("Vilken delare:");
    scanf("%d",&div);
    printf("Totalt: %d \n", divAbleX(tal, div));

    return 0;
}
