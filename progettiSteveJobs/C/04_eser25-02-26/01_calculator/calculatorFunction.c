#include <stdio.h>

void printMenu(){
    printf("----MENU----\n");
    printf("\n 1. sum \n");
    printf("\n 2. difference \n");
    printf("\n 3. multiplication \n");
    printf("\n 4. division \n");
    printf("\n 0. exit \n");
}

int readChoice(char prompt[]){
    int choice;
    printf("\n\n %s: ", prompt);
    scanf("%d", &choice);
    return choice;
}


void loopChoice() {

    int choice;
    do {
        choice = readChoice("Enter one choice");
        if(choice < 0 || choice > 4) {
            validateChoice(choice);
        } else {
            validateChoice(choice);
        }
    } while (choice != 0);

}

int sum(int a, int b){
     return a + b;
}

int diff(int a, int b){
    return a - b;
}

int molt(int a, int b){
    return a * b;
}

float div(int a, int b){
    if(b != 0){
        return (float)a / b;
    }
    else{
        printf("Error: the denominator not is 0");
        return 0.0;
    }
}

void validateChoice(int value){

    int value1 = readChoice("Enter a value1");
    int value2 = readChoice("Enter a value2");

    switch(value){

        case 1:
            printf("You have chosen 1. sum \n");
            int sumValue =  sum(value1,value2);
            printf("The sum is %d: ",sumValue);
            break;

        case 2:
            printf("You have chosen 2. difference \n");
            int diffValue =  diff(value1,value2);
            printf("The differenze is %d: ",diffValue);
            break;
            
        case 3:
            printf("You have chosen 3. moltiplication \n");
            int moltValue =  molt(value1,value2);
            printf("The moltiplication is %d: ",moltValue);
            break;

        case 4:
            printf("You have chosen 4. division \n");
            int divValue =  div(value1,value2);
            printf("the division is %d: ", divValue);
            break;

        case 0:
            printf("You have chosen 0. exit \n");
            break;

        default:     
            printf("\nYou have chosen an invalid choice \n");          
    }
}

int main(void){
    printMenu();
    loopChoice();
    return 0;
}