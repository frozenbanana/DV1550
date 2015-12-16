#include <stdio.h>


int main(){
    char choice = -1;
    float num1 = 0;
    float num2 = 0;
    float sum = 0;
    float diff = 0;
    float prod = 0;
    float div = 0; 

    printf("Enter two numbers: \n");
    scanf("%f %f", &num1,&num2);
    getchar();  
    while(choice != '5')
    {
        printf("----------------------\n");
        printf("0: Enter two integers.\n");
        printf("1: Add\n");
        printf("2: Subtract\n");
        printf("3: Multiply\n");
        printf("4: Divide\n");
        printf("5: Exit\n");
        printf("---------------------\n");
        printf("Your choice:");
        scanf("%c", &choice);
        getchar();
       switch (choice){
        case '0':
           printf("Enter two numbers:");
           scanf("%f %f", &num1,&num2);
           printf("\nOK!\n");
           break;
        case '1':
           sum = num1 + num2;
           printf("%.2f + %.2f = %.2f\n\n",num1,num2,sum);
           break;
        case '2':
           diff = num1 - num2;
           printf("%.2f - %.2f = %.2f\n\n",num1,num2,diff);           
           break;
        case '3':
           prod = num1 * num2;
           printf("%.2f * %.2f = %.2f\n\n",num1,num2,prod);
           break;
        case '4':
           div = num1 / num2;
           printf("%.2f / %.2f = %.2f\n\n",num1,num2,div);
           break;
        case '5':
           printf("Exiting!\n");
           choice = '5';

           break;
        default:
           printf("Your input must be 1,2,3,4 or 5\n");
           choice = -1;
           break;
       }
           
    }

}
