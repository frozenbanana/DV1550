#include <stdio.h>
#include <math.h>
/*
Skriv ett program som använder en
for -loop för utskrift av:
a) Alla heltalen
0 , 1 , 2 ..., 23 , 24 , 25 .
b) Alla heltalen fast baklänges 
25 , 24 , 23 ..., 2 , 1 , 0 .
c) Alla jämna tal mellan 0 och 30. (Tips! Kan göras med hjälp av % -operatorn.)
d) Summera alla heltal mellan 37 och 149, och presentera resultatet.
e) Summera alla heltal i ett intervall som användaren anger gränserna för

*/
int main(){
int i=0;
int j=0;
int tot=0;
	
printf("Ange i: ");
scanf("%d",&i);
getchar();
printf("Ange j: ");
scanf("%d",&j);
int k = abs(((i+j)/2)-i);	// k är avståndet från mitten till en av nodarna
int b = (i+j)/2;		// b är mittenpunkten 
int g = 1;			// heltalsräknare till noder i tallinje
printf("innan for loop k = %d \nb = %d \n", k, b );
tot += b;
for(g;g<=k;g++){
	tot += b + g;
	tot += b - g;
	printf("i for loop k = %d \n", k );
}
if((b+g) != i ||(b+g)!= j)
	tot += ++g;

printf("tot: %d\n", tot);

}
