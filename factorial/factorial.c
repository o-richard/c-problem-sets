#include <stdio.h>

void main ()
{
    // Store the input. Set answer to 1 since multiplication is going to be done
    int number, answer = 1;

    // Ensure the number is positive
    do
    {
        printf("To display the factorial, enter the number: ");
        scanf("%d", &number);
    } while (number < 0);

    // Perform multiplcation until i=1
    for (int i = number; i > 0; i--)
    {
        answer *= i;
    }

    printf("The answer is %d", answer);
}
