#include <stdio.h>
#include <string.h>

int main(void){
    char variabel1[3] = {'h','e','j'};
    char variabel2[3] = {'h','e','j'};
    printf("strcmp: %d\n",strcmp("HEJ","HEJ"));
    if(strcmp(variabel1, variabel2) != 0)
        printf("True\n");
}
