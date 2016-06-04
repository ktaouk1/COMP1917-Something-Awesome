#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main (void) {
    int n;                  //Current number in the sequence. Initially set to 1 (first nonzero).
    int prevNum;            //Number before n.
    int nextNum;            //Number after n.
    int w;                  //Used to calculate the next number in the sequence.
    int i;                  //Counter to keep track of the position a number is in the sequence.
    int input;              //Value set by the user.
    int cut = 0;            //Used to terminate the main while loop when necessary.
    char answer = 'y'       //Initial value for parameter.
    char condition = '.';   //Initial value for parameter.
  
    while (cut == 0) {
        n = 1;
        prevNum = 0;
        i = 1;
        w = 0;
        if (condition != '*' && answer != '*') {
            printf("Do you want to find a Fibonacci number or do you want to test if a number is one?\nEnter 'f' for find and 't' for test: ");
            scanf(" %c", &condition);
            if (condition == 't' || condition == 'T') {
                printf("Enter a number to see if it is in the Fibonacci Sequence: ");
                scanf("%d", &input);
                //if statement for a specific case, then a generic formula for all other cases.
                if (input == 1) {
                    printf("%d is number 1 and 2 in the Fibonacci Sequence!\n", input);
                } else {
                    while (w < input) {
                        w = n + prevNum;
                        prevNum = n;
                        n = w;
                        i++;        
            
                    } if (w == input) {
                        nextNum = prevNum + w;                    
                        printf("%d is number %d in the Fibonacci sequence!\n", input, i);
                        printf("Fun Fact: %d is the previous fibonacci number while %d is the one that follows.\n", prevNum, nextNum);
                    } else if (w > input) {
                        printf ("%d is not in the Fibonacci sequence.\n", input);
                        printf ("Fun Fact: %d and %d are the closest numbers of the Fibonacci Sequence to %d.\n", prevNum, w, input);
                    }
                } condition = '*';
            } else if (condition == 'f' || condition == 'F') {
                printf("Which Fibonacci number do you wish to find?: ");
                scanf("%d", &input);
                if (input == 1 || input == 2) {
                    printf("Fibonacci numbers 1 and 2 are both 1.\n");
                } else {
                    while (i < input) {
                        w = n + prevNum;
                        prevNum = n;
                        n = w;
                        i++;
                    } printf ("Fibonacci number %d is %d.\n", input, w);
                } condition = '*';
            } else if (condition != 'f' || condition != 'F' || condition != 'T' || condition != 't') {
                printf ("Please try again.\n");
                condition = '.';
            } 
        }        
        if (condition == '*') {
            answer = '*';       
            if (answer == '*') {
                printf("Do you wish to run the test again?(Y or N): ");
                scanf(" %c", &answer);
            } if (answer == 'Y' || answer == 'y') {
                condition = '.';
            } else if (answer == 'N' || answer == 'n') { 
                cut = 1;
                printf("FIBONACCI!!!");
                Sleep(2000);
            } else if (answer != 'Y' || answer != 'y' || answer != 'N' || answer != 'n') {
                answer = '*';
                printf("Sorry I don't understand.\nPlease enter 'Y' for yes and 'N' for no.\n");
                condition = '*';
            }
        }
    }
    return EXIT_SUCCESS;
}
        
  
