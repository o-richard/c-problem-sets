#include<stdio.h>

void main ()
{
    int num1, num2, sum, difference, product;
    float quotient;

    // Enter the two intergers
    printf("First number: ");
    scanf("%d", &num1);
    printf("Second number: ");
    scanf("%d", &num2);

    // Perform arithmetic operations
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = (float) num1 / num2;

    // Output
    printf("Addition: %d + %d =%d\n", num1, num2, sum);
    printf("Subtraction: %d - %d=%d\n", num1, num2, difference);
    printf("Multiplication:  %d * %d=%d\n", num1, num2, product);
    printf("Division: %d / %d=%.5f\n", num1, num2, quotient);
}