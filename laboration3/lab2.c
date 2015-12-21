#include <stdio.h>



int main(){

	char from[32],to[32], date[32], where[32];
	

	float time = 0;
	float  duration = 0;
	printf("Who is this invitation from:");
	scanf("%[^\n]s",from);
	getchar();
	printf("Who is this invitation to:");
	scanf("%[^\n]s",to);
	getchar();
	printf("Date:");
	scanf("%[^\n]s",date);
	getchar();
	printf("Start time:");
	scanf("%f",&time);
	printf("Duration (h):");
	scanf("%f",&duration);
	getchar();
	printf("Where:");
	scanf("%[^\n]s",where);
	getchar();
	printf("Hello %s!\n", to);
	printf("You are invited to a party the %s at %05.2f in %s.\n",date, time, where);
	float until = (int)(time + duration) % 24;
	printf("The party last until %05.2f!", until);
	printf("\nSee you there\n%s\n", from);
return 0;
}
