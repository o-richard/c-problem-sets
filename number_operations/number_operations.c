#include<stdio.h>

// Function to display menu and allow user to make their choice
int display_menu ();

// Function to get number input by a user
int get_input();

// Function to check if a number is even or odd
int isEven(int n);

// Function to check if a number is positive or negative
int isPos(int n);

// Function to check number of digits in an interger
int NumDigit(int n);

void main()
{

    // Display the menu at the start of the program. Get user input.
    int user_choice = display_menu();

    // Perform a switch case depending on user's choice
    switch (user_choice)
    {
    case 1:
        {
            // Get a number

            int user_input = get_input();

            printf("\nYou have entered the number %d.", user_input);

            break;
        }
    case 2:
        {
            // Determine if a number is odd or even

            int user_input = get_input();

            int even_result = isEven(user_input);

            if (even_result == 0)
            {
                printf("\nThe number is even.\n");
            }
            else
            {
                printf("\nThe number is odd.\n");
            }

            break;
        }
    case 3:
        {
            // Determine if a number is positive or negative

            int user_input = get_input();

            int positive_result = isEven(user_input);

            if (positive_result == 0)
            {
                printf("\nThe number is positive.\n");
            }
            else
            {
                printf("\nThe number is negative.\n");
            }

            break;
        }
    case 4:
        {
            // Determine number of digits of a given number

            int user_input = get_input();

            int no_of_digits = NumDigit(user_input);

            printf("\nThe total number of digits in %d is %d.\n", user_input, no_of_digits);

            break;
        }
    case 5:
        {
            // Exit the program

            printf("\nYou have terminated the program.\n");
            break;
        }
    default:
        {
            printf("\nYou have entered an invalid choice.");
            break;
        }
    }

}

// Function to display menu and allow user to make their choice
int display_menu ()
{
    // Store a user's choice
    int choice;

    // Display 5 options
    printf("Choose one of the options below.(Input the number of your option)\n\n1. Get an interger\n2. Determine if an interger is even or odd\n3. Determine if an interger is positive or negative\n4. Determine how many digits are in an interger\n5. Exit\n");
    // Get a user's choice
    scanf("%d", &choice);

    // Return a user's choice
    return choice;
}

// Function to get number input by a user
int get_input()
{
    // Store user input
    int input;

    printf("\nEnter the number: ");
    scanf("%d", &input);

    // Return an input
    return input;
}

// Function to check if a number is even or odd
int isEven(int n)
{
    // Returns 0 if even. Returns 1 if odd.
    if ((n % 2) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Function to check if a number is positive or negative
int isPos(int n)
{
    // Returns 0 if positive. Returns 1 if negative.
    if (n < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to check number of digits in an interger
int NumDigit(int n)
{
    // Store the input number
    int number = n;

    // Store number of digits
    int number_of_digits;

    // The number 0 should have 1 digit at least.
    if (n == 0)
    {
        // Store number of digits
        number_of_digits = 1;
    }
    else
    {
        // Store number of digits
        number_of_digits = 0;
    }

    while (number != 0)
    {
        // Update the value of the number
        number /= 10;

        // Increment the number of the digits 
        number_of_digits++;
    }
    
    // Return the number of digits
    return number_of_digits;
}