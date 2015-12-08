#include <stdio.h>
#include "func.h"


int main(void){
	int nrA,nrB;
	printf("type on two numbers: \n");
	scanf("%d%d", &nrA, &nrB);
	getchar();

	if (isPermutation(nrA, nrB))
		printf("NrA and nrB are a permutation\n");
	else
		printf("NrA and nrB are not a permutation\n")
	getchar();
		return 0;
}
