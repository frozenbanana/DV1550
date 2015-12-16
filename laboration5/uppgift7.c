#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{
    char name[64];
    int birthYear;
    int phoneNum;
    int salary;
};

void addInReg(struct employee *anyReg, int * anySize, int startVal){
    int i;
    for(i = startVal; i < *anySize; i++){
        printf("Name of employee %d: ", i+1);
        fgets(anyReg[i].name,64,stdin);
        printf("Birth year of employee %d: ", i+1);
        scanf("%d", &anyReg[i].birthYear);
        printf("Phone number of employee %d: ", i+1);
        scanf("%d", &anyReg[i].phoneNum);
        printf("Salary of employee %d: ", i+1);
        scanf("%d", &anyReg[i].salary);
        printf("\nEmployee registered!\n\n");
    }
}

void printRegByName(struct employee *anyReg, int * anySize){
   int i;
    for(i=0;i<*anySize;i++)
    printf("Employee %d: %s\n", i+1,anyReg[i].name);
}
void printRegBySalary(struct employee *anyReg, int *anySize){
    int i,j, biggest;
    struct employee *salaryReg;
    struct employee temp;
    salaryReg = (struct employee*)malloc((sizeof(struct employee)*(*anySize)));
    for(i=0;i<*anySize;i++){ //memcpy inc
        salaryReg[i] = anyReg[i];
    }
    for(i=0;i<*anySize-1;i++){
        biggest = i;
        for(j=i+1; j<*anySize;j++){
            if(salaryReg[biggest].salary < salaryReg[j].salary)
                biggest = j;
        }
        temp = salaryReg[i];
        salaryReg[i] = salaryReg[biggest];
        salaryReg[biggest] = temp;
    }    
    for(i=0; i<*anySize; i++){
        printf("Name: %sSalary: %d\n\n",salaryReg[i].name,salaryReg[i].salary);
    }
    free(salaryReg);
}

void printTotSalary(struct employee *anyReg, int * anySize){
    int i;
    int sum = 0;

    for(i=0;i<*anySize;i++)
        sum += anyReg[i].salary;
    printf("\nYour %d employees costs you a total of: %d\n\n", *anySize,sum);
}

void printRegByAge(struct employee *anyReg, int * anySize){
     int i,j, oldest;
    struct employee *ageReg;
    struct employee temp;
    ageReg = (struct employee*)malloc((sizeof(struct employee)*(*anySize)));
    for(i=0;i<*anySize;i++){ //memcpy inc
        ageReg[i] = anyReg[i];
    }
    for(i=0;i<*anySize-1;i++){
        oldest = i;
        for(j=i+1; j<*anySize;j++){
            if(ageReg[oldest].birthYear < ageReg[j].birthYear)
                oldest = j;
        }
        temp = ageReg[i];
        ageReg[i] = ageReg[oldest];
        ageReg[oldest] = temp;
    }    
    for(i=0; i<*anySize; i++){
        printf("Name: %sBirth Year: %d\n\n",ageReg[i].name,ageReg[i].birthYear);
    }
    free(ageReg);


}
void removeEmployee(struct employee *anyReg, int anyIndex, int *anySize){
    int i = anyIndex;
    anyReg[i] = anyReg[*anySize-1];
    anyReg = realloc(anyReg, sizeof(struct employee)*--*anySize);
}
int searchEmployee(char *searchString ,struct employee *anyReg,  int *anySize){
    int i;
    int peoplefound = 0;
    for(i=0;i<*anySize;i++){
           if(strcmp(searchString, anyReg[i].name) == 1)
            printf("Employee found\n");
            printf("Employee %d\nName %sBirth Year: %d\nPhone number: %d\nSalary: %d\n", i,anyReg[i].name,anyReg[i].birthYear,anyReg[i].phoneNum,anyReg[i].salary);
    peoplefound++;    
    }
    if(peoplefound == 0)
        printf("No employee found with that name\n");
}

int main(){
    int size = 0;
    int choice = -1;
    int employeeNr = -1;
    struct employee *reg;
    reg = (struct employee*)malloc(sizeof(struct employee));
    char search[64];
    
    while(choice != 0){
    printf("Welcome to your employee register\n");
    printf("Press 1 to add new employee. \n");
    printf("Press 2 to print names of employees. \n");
    printf("Press 3 to print register by salary. \n");
    printf("Press 4 to print total salary cost (per month). \n");
    printf("Press 5 to print register by age. \n");
    printf("Press 6 to remove employee. \n");
    printf("Press 7 to search employee. \n");
    printf("Press 0 to exit.\n");
    
    scanf("%d",&choice);
    getchar();
    
        switch(choice){
            case 1:
                reg = (struct employee*)realloc(reg, sizeof(struct employee)* ++size); 
                addInReg(reg,&size,size-1);
            break;
            case 2:
                printRegByName(reg, &size);
            break;
            case 3:
                printRegBySalary(reg, &size);
            break;
            case 4:
                printTotSalary(reg, &size);
            break;
            case 5:
                printRegByAge(reg, &size);
            break;
            case 6:
                printf("type which employe number to you want to remove:");
                scanf("%d",&employeeNr);
                removeEmployee(reg, employeeNr-1, &size);
            break;
            case 7:
                printf("type in employee name to search:");
                fgets(search,64,stdin);
                searchEmployee(search, reg, &size);
            break;
            default:
                printf("Exiting..\n");
            break;
            }
    }
    free(reg);
    return 0;


}


