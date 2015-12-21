#include <stdio.h>
/*
I programmeringsspråket C så kan man använda sig av char-arrayer för att lagra text och ord.
Exempel: Deklarationen char sentence[256]; skapar en enhet av en datatyp som är kapabel att lagra 256 char (tecken).
I denna övning ska vi låta användaren mata in ett valfritt ord (dock inte längre än längden på arrayen). Därefter ska vi

1. med hjälp av en loop kontrollera hur många tecken som användaren matade in.
2. skriva ut ordet baklänges.
3. lägga på ett utropstecken i slutet.
4. låta användaren mata in ytterligare ett ord som vi lägger i en annan array. Därefter (med hjälp av en loop) ska vi avgöra om de två strängarna är lika.
Vad gör nolltecknet ’\0’ för nytta? Vad händer om det inte finns med?
 **/
int main(){

char sentence[256];
char sentence2[256];

printf("Type in a string: ");
fgets(sentence, sizeof(sentence), stdin);

int i = 0;     
while(sentence[i] != '\n')
    i++;

printf("Size of sentence: %d", i);

int enterTecken = i;

for(;i>=0; i--)
    printf("%c", sentence[i]);

printf("\n");

sentence[enterTecken] = '!';
sentence[enterTecken+1] = '\0';

printf("%s \n", sentence);

printf("Mata in ett till ord: ");
fgets(sentence2, sizeof(sentence2), stdin);

i = 0;
while(sentence2[i] != '\n')
    i++;

int enterTecken2 = i;

enterTecken == enterTecken2 ? printf("strängarna är lika stora \n"):sprintf("Strängarna är inte lika stora\n");


return 0;
}

