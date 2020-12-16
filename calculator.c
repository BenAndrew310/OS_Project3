#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long addition (int input1, int input2);
long substraction (int input1, int input2);
long multiplication (int input1, int input2);

// StudentID = 616336 // replace with your student ID without leading 0

int main() {
    char operator;
    char *operation;

    int input1=0;
    int input2=0;
    long result = 0;

    while(1)
    {
        input1=0;
        input2=0;
        result = 0;

        printf("=======================\n");
        printf("Enter operation [sum - sub - mul - exit]: ");
        scanf("%s",operation);

        if(strcmp(operation,"exit")==0){
            break;
        }

        printf("Enter two operands (space separated): ");
        scanf("%d %d", &input1, &input2);

        if(strcmp(operation,"sum")==0){
            result = addition (input1, input2);
            printf("Operation: [%s] - Operands [%d %d] - Result:[%ld]\n",operation, input1, input2, result);
        }else if(strcmp(operation,"sub")==0){
            result = substraction (input1, input2);
            printf("Operation: [%s] - Operands [%d %d] - Result:[%ld]\n",operation, input1, input2, result);
        }else if(strcmp(operation,"mul")==0){
            result = multiplication (input1, input2);
            printf("Operation: [%s] - Operands [%d %d] - Result:[%ld]\n",operation, input1, input2, result);
        }else{
            printf("Invalid option\n");
        }
    }

    return 0;
}

long addition (int input1, int input2)
{
    long result = 0;
    char command[150];
    const char *load = "sudo insmod calculatorModule.ko";
    char in1[10],in2[10];
    char c[10];

    sprintf(in1,"%d",input1);
    sprintf(in2,"%d",input2);

    strcpy(command,load);
    strcat(command," firstParam=");
    strcat(command,in1);
    strcat(command," secondParam=");
    strcat(command,in2);
    strcat(command," operationParam=\"sum\"");

    system(command);
    FILE * file;
    file = fopen("/sys/module/calculatorModule/parameters/resultParam","r");
    if (file == NULL){
	printf("An error occured\n");
	system("sudo rmmod calculatorModule");
	exit(1);
    }
    fscanf(file, "%[^\n]", c);
    fclose(file);
    system("sudo rmmod calculatorModule");

    result = atol(c);


    return result;
}

long substraction (int input1, int input2)
{
    long result = 0;
    char command[150];
    const char *load = "sudo insmod calculatorModule.ko";
    char in1[10],in2[10];
    char c[10];

    sprintf(in1,"%d",input1);
    sprintf(in2,"%d",input2);

    strcpy(command,load);
    strcat(command," firstParam=");
    strcat(command,in1);
    strcat(command," secondParam=");
    strcat(command,in2);
    strcat(command," operationParam=\"sub\"");

    system(command);
    FILE * file;
    file = fopen("/sys/module/calculatorModule/parameters/resultParam","r");
    if (file == NULL){
	printf("An error occured\n");
	system("sudo rmmod calculatorModule");
	exit(1);
    }
    fscanf(file, "%[^\n]", c);
    fclose(file);
    system("sudo rmmod calculatorModule");

    result = atol(c);


    return result;
}

long multiplication (int input1, int input2)
{
    long result = 0;
    char command[150];
    const char *load = "sudo insmod calculatorModule.ko";
    char in1[10],in2[10];
    char c[10];

    sprintf(in1,"%d",input1);
    sprintf(in2,"%d",input2);

    strcpy(command,load);
    strcat(command," firstParam=");
    strcat(command,in1);
    strcat(command," secondParam=");
    strcat(command,in2);
    strcat(command," operationParam=\"mul\"");

    system(command);
    FILE * file;
    file = fopen("/sys/module/calculatorModule/parameters/resultParam","r");
    if (file == NULL){
	printf("An error occured\n");
	system("sudo rmmod calculatorModule");
	exit(1);
    }
    fscanf(file, "%[^\n]", c);
    fclose(file);
    system("sudo rmmod calculatorModule");

    result = atol(c);


    return result;
}
