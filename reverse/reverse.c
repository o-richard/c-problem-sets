#include<stdio.h>

void main ()
{
    // Store the number to input
    int number;

    printf("This program will print in reverse order the numbers preceding the given input number and calculate the product of the numbers.\n\n");
    printf("Enter the number: ");
    scanf("%d", &number);

    // Store the counter
    int counter = number;

    // Store the current value of the loop
    int i = 0;

    // Store the product of the numbers
    int product = 1;

    while (counter > 0)
    {
        // Store the number of the current loop
        int j = i;
        // Display all numbers till counter
        while (j >= 0)
        {
            // Store the current number within the loop
            int current_number = counter + j;
            printf("%d\t", current_number);
            j--;    
        }
        
        // Calculate current product
        product *= counter;
        printf("\nThe current product is %d. \n", product);

        // Deincrement the counter value by 1
        counter--;

        // Increment the current value of the loop
        i++;
    }
}