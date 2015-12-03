#include "func.h"
#include <string.h>
/* Changes places on the first and last, second and second last..etc of any string */
void reverse(char * array, int numberOfChars){

int i = 0;
int j = strlen(array) - 1;

    while(i < j)
    {
        char c = array[i];              //temp char to keep old value
        array[i++] = array[j];          // first change with last
        array[j--] = c;                 // last change with first
    }                                   // and so on until i<j
}
/* returns the average of positive numbers in an array els return 0  */
double meanOfPositives(double * array, int length){

    int i;
    double sum = 0, average;

    for(i = 0; i < length; i++){
        if(array[i] < 0)
            return 0;
        sum += array[i];
    }
    average = sum / length;

    return average;
}                    