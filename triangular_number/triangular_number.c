#include<stdio.h>

void main ()
{
    int number, sum = 0;

    printf("The program displays the sum of all numbers till the entered number\n\n");

    // Ensure the number is positive
    do
    {
        printf("Enter the number HINT: Should be a positive value: ");
        scanf("%d", &number);
    } while (number < 0);

    for (int i = 0 ; i <= number; i++)
    {
        sum += i;
    }
    
    printf("The total sum is %d", sum);
}