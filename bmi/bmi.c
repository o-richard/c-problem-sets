#include<stdio.h>

// The program calculates a person's BMI
void main ()
{
    // Store a person's height in metres
    float height;
    // Store a person's weight in Kilograms
    float weight;
    // Store calculated height
    float calculated_height;
    // Store calculated BMI
    float bmi;

    printf("To calculate your BMI, input your weight and height\n");

    // Enter a person's weight
    printf("Weight (In kilograms): ");
    scanf("%f", &weight);
    // Enter a person's height
    printf("Height (In metres): ");
    scanf("%f", &height);

    // Square a person's height
    calculated_height = height * height;
    // Calculate BMI
    bmi = weight / calculated_height;

    // Output a person's weight and height
    printf("Your weight is %.2f kilograms.\nYour height is %.2f metres.\nYour BMI is %.1f\n", weight, height, bmi);
}