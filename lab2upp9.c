#include <stdio.h>

/*
Du ska implementera en växelmaskin som tar in ett antal olika valörer (svenska valutavalörer), därefter beräkna och presentera totalbeloppet.
*/
int main(void){
	char teststring[10];
	int valor[7] = { 0 } ;
	printf("Ange hur många tusen-lappar: ");
	scanf("%d", &valor[0]);
	printf("Ange hur många femhundra-lappar: ");
	scanf("%d", &valor[1]);
	printf("Ange hur många hundra-lappar: ");
	scanf("%d", &valor[2]);
	printf("Ange hur många 50-lappar: ");
	scanf("%d", &valor[3]);
	printf("Ange hur många 20-lappar: ");
	scanf("%d", &valor[4]);
	printf("Ange hur många 10-mynt: ");
	scanf("%d", &valor[5]);
	printf("Ange hur många 5-mynt: ");
	scanf("%d", &valor[6]);
	printf("Ange hur många 1-mynt: ");
	scanf("%d", &valor[7]);

	printf("Totalbelopp: %d\n", valor[0]*1000 + valor[1]*500 + valor[2]*100 + valor[3]*50 + valor[4]*20 + valor[5]*10 + valor[6]*5 + valor[7]);
	
	
	return 0;

}

