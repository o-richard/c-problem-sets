#include<stdio.h>
#include<math.h>

void main ()
{
    // Store the number input by a user
    int number;

    // Input the number
    printf("Input the number: ");
    scanf(" %d", &number);

    // Determine if a number is prime

    // Determine if number is 2 or 3.
    if (number == 2 || number == 3)
    {
        printf("%d is a prime number\n", number);
    }
    // Determine if number is negative/zero/one or if divisible by 2 or if divisible by 3
    else if (number <= 1 || number % 2 == 0 || number % 3 == 0)
    {
        printf("%d is not a prime number\n", number);
    }
    else
    {
        int square_root = sqrt(number);

        // Loop from 5 till the squareroot of the number
        for (int k=5; k <= square_root; k +=6 )
        {
            /*
            Check if the number is divisible by k
            OR
            Check if the numeber is divisible by the next odd number after k
            */
            if (number % k == 0 || number % (k + 2) == 0) 
            {
                printf("%d is not a prime number\n", number);
                // Stop executing the loop
                return;
            }
        }

        // In case the program did not stop. 'number' is a prime number
        printf("%d is a prime number\n", number);
    }

}