#include<stdio.h>

void main ()
{
    // Store exhange rate of KES to USD
    const float KES_TO_USD = 0.0083;
    float amount, calculated;

    // Enter the amount
    printf("Amount (In Kenyan Shilling): ");
    scanf("%f", &amount);

    // Store amount in USD
    calculated = amount * KES_TO_USD;

    printf("Amount in US dollars: %.2f\n", calculated);
}