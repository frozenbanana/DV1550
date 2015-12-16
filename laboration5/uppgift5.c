#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Skapa en catalog av personer med dynamiskt minne */
struct Person{
    char name[64];
    int birthYear;
};

void addInStruct(struct Person *anyCatalogue, int anySize, int startVal){
    int i;
    for(i=startVal;i<anySize;i++){
        printf("Name of person %d: ", i+1);
        fgets(anyCatalogue[startVal].name,64,stdin);
        printf("Birth year of person %d: ", i+1);
        scanf("%d", &anyCatalogue[startVal].birthYear);
        getchar();
    }
}
void printStruct(struct Person *anyCatalogue, int anySize){
    int i;
    printf("\n---------------Printing catalogue-------------\n");
    for(i=0;i<anySize;i++)
        printf("Person nr %d:\nNamn: %sBirth year: %d\n", i+1,anyCatalogue[i].name, anyCatalogue[i].birthYear);
    printf("\n\n\n");
}

int main(){
    int size,i;
    int choice = -1;
    struct Person *aCatalogue;
    printf("How many persons in the catalog?\n");
    scanf("%d", &size);
    getchar();

    aCatalogue = (struct Person*)malloc((sizeof(struct Person) * size));
    addInStruct(aCatalogue,size,0);
    printStruct(aCatalogue,size);
    while(choice != 0){
    printf("Press 1 if you want to add a new person.\nPress 0 to exit\n");
    scanf("%d",&choice);
    getchar();
        if(choice){
        aCatalogue = (struct Person*)realloc(aCatalogue, sizeof(struct Person)*++size);
        addInStruct(aCatalogue,size,size-1);
        printStruct(aCatalogue,size);
        }
    }
    free(aCatalogue);
    return 0;
}
