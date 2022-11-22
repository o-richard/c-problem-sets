#include<stdio.h>

// Function to displays the fibonnacci sequence of a given number
void fibonnacci(int user_input, int term_1, int term_2, int next_term);

void main()
{
    // Store the positive interger input by a user
    int number=0;

    // Display purpose of the program
    printf("The program that calculates the fibonnacci sequence of a given number.\n\n");

    // Ensure input is a positive interger
    do
    {
        printf("Enter a positive number: ");
        scanf("%d", &number);
    } while (number < 0);
    
    // Begin the fibonnacci sequence
    int term_1=0, term_2=1;

    printf("\nThe fibonnacci sequence.\n");

    // Incase the input is 0
    if (number == 0)
    {
        printf("  %d  ", term_1);
    }
    // Incase the input is 1
    else if (number == 1)
    {
        printf("  %d    %d  ", term_1, term_2);
    }
    // Incase other numbers have been input
    else
    {
        printf("  %d    %d  ", term_1, term_2);

        int next_term = term_1 + term_2;

        fibonnacci(number, term_1, term_2, next_term);   
    }
}

// Function to displays the fibonnacci sequence of a given number
void fibonnacci(int user_input, int term_1, int term_2, int next_term)
{
    // Stop when the expected next term exceeds the user input
    if (next_term > user_input)
    {
        return;
    }

    printf("  %d  ", next_term);

    term_1 = term_2;
    term_2 = next_term;

    next_term = term_1 + term_2;

    fibonnacci(user_input, term_1, term_2, next_term);
}