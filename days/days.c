#include<stdio.h>

void main ()
{
    // Store the number of the day
    int day_number;

    // Input the day
    printf("Enter the any value from 1 to 7 to get the name of the day: ");
    scanf("%i", &day_number);

    // Show the name of the day
    // ASSUMPTION: First day of the week is on Sunday
    switch (day_number)
    {
    case 1:
        printf("Sunday\n");
        break;
    case 2:
        printf("Monday\n");
        break;
    case 3:
        printf("Tuesday\n");
        break;
    case 4:
        printf("Wednesday\n");
        break;
    case 5:
        printf("Thursday\n");
        break;
    case 6:
        printf("Friday\n");
        break;
    case 7:
        printf("Saturday\n");
        break;
    default:
        printf("\nYour value was not in the specified range( 1 to 7).\n");
        break;
    }
}