/*Skriv ett program som skriver ut alla heltalssidor (a,b,c) för alla rätvinkliga trianglar där omkretsen är ett heltal samt mindre än 1000.*/

#include <stdio.h>
#include <math.h>

int main(){
    int a=1,b=2;
    float c=3; 
    
    printf("Alla rätvinkliga heltalstrianglar med omkretsen < 1000:\n");
    for(; a <= 1000; a++){                  // omkretsen är 1000 så en katet måste vara under 1000
        c = sqrt(pow(a,2)+pow(b,2));        // c är hypotenusa, beräknad från pythagoras sats
        b = 1000-a-c;                       // b kommer alltid vara differensen av en 1000-(b+c)
        if(b < 1)                           // b måste större än 0
            break;
        if(c-(int)c)                        // Om c är ett hel tal är det en rätvinklig triangel av heltal.
            printf("a: %4d, b: %4d, c: %4d\n",a,b,(int)c);
        }   
    }


