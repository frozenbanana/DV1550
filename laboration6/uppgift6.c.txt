/*Skriven av: Henry Bergström
 *Datum: 2015-12-15
 *Kurs: DV1550: Inledande programmering i C
*/
#include <stdio.h>
#include <stdlib.h>

struct stock{       // struct för hantera formateringen av varje rad
    float value;
    int year;
    int month;
    int day;
};

void highLowVal(char * filename){                   // hittar högsta och minsta värdet för varje aktie
    FILE *filePointer = fopen(filename,"rt");
    char line[50];
    struct stock temp,highest,lowest;
    
    fgets(line,sizeof(line), filePointer);          // skippa första eftersom den har ett annat format.
    fgets(line,sizeof(line), filePointer);
    sscanf(line, "%d-%d-%d, %f", &highest.year, &highest.month, &highest.day, &highest.value);
    lowest = highest;     
    while(fgets(line,sizeof(line), filePointer) != NULL){       //scannar in alla rader i en temporär struct
        sscanf(line, "%d-%d-%d, %f", &temp.year, &temp.month, &temp.day, &temp.value);
            
            if(highest.value < temp.value){                     // Denna if-satsen hittar den struct med högst värde
            highest.value = temp.value;
            highest.year = temp.year;
            highest.month = temp.month;
            highest.day = temp.day;
            }
            if(lowest.value > temp.value){                      // denna if-satsen hittar den struct med lägst värde
            lowest.value = temp.value;
            lowest.year = temp.year;
            lowest.month = temp.month;
            lowest.day = temp.day;
            }
        }

    printf("Highest value is: %f at date: %d-%d-%d\n",highest.value,highest.year,highest.month,highest.day);    // skriv ut svar
    printf("Lowest value is: %f at date: %d-%d-%d\n",lowest.value,lowest.year,lowest.month,lowest.day);

fclose(filePointer);
}

void bestBuySell(char * filename){                  // ansvarig för att hitta bästa datum för att köpa/sälja
    printf("filename: %s\n", filename);
    FILE *filePointer = fopen(filename,"rt");
    char line[50];
    struct stock bestBuy,bestSell;
    struct stock *stocks;
    float tempProfit = 0.00;
    float profit = 0.00;
    int size,j;
    int i = 0;
    fgets(line,sizeof(line), filePointer);  // skippa första
    sscanf(line,"%d",&size);
    printf("%d\n", size);
    
    stocks = (struct stock*) malloc((sizeof(struct stock)*size-1));
    while(fgets(line,sizeof(line), filePointer) != NULL){ // fyller raderna i structs
        sscanf(line,"%d-%d-%d, %f",&stocks[i].year,&stocks[i].month,&stocks[i].day,&stocks[i].value);
        ++i;
    }    
    for(i=0;i<size-1;i++){
        for(j=i;j<size-1;j++){
            if(stocks[i].value < stocks[j].value){    // kollar största profit för stocks[i].
                tempProfit = (stocks[j].value - stocks[i].value);
                if(tempProfit > profit){              // tempProfit testas om den har större vinst
                profit = tempProfit;                  // spara den då i riktiga profit
                bestBuy = stocks[i];                  // och kom ihåg vilket element det var 
                bestSell = stocks[j];
                }
            }
        }
    }
        free(stocks);
        printf("Best date to buy was: %d-%d-%d at %f\n", bestBuy.year,bestBuy.month,bestBuy.day,bestBuy.value);
        printf("Best date to sell was: %d-%d-%d at %f\nTotal loss: %f\n",bestSell.year,bestSell.month,bestSell.day,bestSell.value,profit);
    fclose(filePointer); 
}

void worstBuySell(char * filename){                     // ansvarig för att hitta sämsta datum för att köpa/sälja
    printf("filename: %s\n", filename);
    FILE *filePointer = fopen(filename,"rt");
    char line[50];
    struct stock worstBuy,worstSell;
    struct stock *stocks;                               // struct array pekar till minneutrymme
    float tempLoss = 0.00;
    float loss = 0.00;
    int size,j;
    int i = 0;
    fgets(line,sizeof(line), filePointer);              // skippa första eftersom den har inte samma förmat som de andra
    sscanf(line,"%d",&size);
    printf("%d\n", size);
    
    stocks = (struct stock*) malloc((sizeof(struct stock)*size-1));  // skapa minnesutrymme för stocks. size-1 eftersom första raden inte räknas
    while(fgets(line,sizeof(line), filePointer) != NULL){// fyller raderna  i struct array
    
        sscanf(line,"%d-%d-%d, %f",&stocks[i].year,&stocks[i].month,&stocks[i].day,&stocks[i].value);
        ++i;
    }    
    for(i=0;i<size-1;i++){
        for(j=i;j<size-1;j++){
            if(stocks[i].value > stocks[j].value){      // kollar största loss för stocks[i].
                tempLoss = (stocks[j].value - stocks[i].value); // sparar en temportär variabel för att räkna ut vinst/förlust
                if(tempLoss < loss){                    // om temp variabel har större vinst/förlust så spara över det till den riktiga vinst/förlust variabeln.
                loss = tempLoss;
                worstBuy = stocks[i];                   // ge över datumen till ny variabel
                worstSell = stocks[j];
                }
            }
        }
    }
        free(stocks);
        printf("Worst date to buy was: %d-%d-%d at %f\n", worstBuy.year,worstBuy.month,worstBuy.day,worstBuy.value);
        printf("Worst date to sell was: %d-%d-%d at %f\nTotal loss: %f\n",worstSell.year,worstSell.month,worstSell.day,worstSell.value,loss);
    fclose(filePointer); 
    
}    

int readFile(char * filename){                          // Ansvarig visa användaren vilka funktioner hen kan kalla på.
    printf("File name: %s\n", filename);
    int choice = -1;
    char row[256]={0};
    FILE *filePointer = fopen(filename,"rt");           // öppnar filens från som användaren har skrivit in  
    if(filePointer == NULL)
        printf("The file does not exist or cannot be opened\n");
    while(filePointer != NULL){                         // visar meny om det finns innehåll
        printf("-----------------------------------------\n");
        printf("Choose option about this file\n");
        printf("See highest and lowest value   - Press 1\n");
        printf("The best dates to buy or sell  - Press 2\n");
        printf("The worst dates to buy or sell - Press 3\n");
        printf("Print file                     - Press 4\n"); 
        printf("Exit                           - Press 0\n");
        printf("-----------------------------------------\n");
        scanf("%d", &choice);
        switch(choice){                                 // beroende på val angropas olika funktioner.
            case 1:
                highLowVal(filename);
            break;
            case 2:
                bestBuySell(filename);
            break;
            case 3:
                worstBuySell(filename);
            break;
            case 4:
             while(fgets(row, sizeof(row), filePointer)){   // fgets hämtar varje rad 
                    printf("%s",row);                       // printf skriver ut raden
                    }
            break;
            default:
                printf("Exiting %s\n", filename);
                return 0;
            break;
        
        }
    }
    

    fclose(filePointer);                                    // stänger filen
    return 0;
}


int main(){
int choice = -1;                                            // main ansvarar bara för att skicka in rätt filnamn till readFile
        while(choice != 0){
        printf("*******************************************\n");
        printf("What file do you want to read from?\n");
        printf("apple_USD.txt                     - Press 1\n");
        printf("tesla_USD.txt                     - Press 2\n");
        printf("telia_SEK.txt                     - Press 3\n");
        printf("volvoB_SEK.txt                    - Press 4\n");
        printf("Quit                              - Press 0\n");
        printf("*******************************************\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                readFile("apple_USD.txt");
            break;
            case 2:
                readFile("tesla_USD.txt");
            break;
            case 3:
                readFile("telia_SEK.txt");
            break;
            case 4:
                readFile("volvoB_SEK.txt");
            break;
            default:
                printf("Shutting down program..\n");
            break;
        }
    }

    return 0;
}
