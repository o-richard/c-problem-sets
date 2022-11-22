#include<stdio.h>

void main ()
{
    // Store the number of the month
    int month_number;

    // Input the month of birth
    printf("Select your month of birth :\n 1. January\t 2. February\t 3. March\t 4. April\n\n 5. May\t\t 6. June\t 7. July\t 8. August\n\n 9. September\t 10. October\t 11. November\t 12. December\n\n");

    scanf("%d", &month_number);

    // Display pet 'birthstones' accoding to user's birth month
    printf("Your pet \"birthstone\" is ");

    switch (month_number)
    {
    case 1:
        printf("a rabbit.\n");
        break;
    case 2:
        printf("a chameleon.\n");
        break;
    case 3:
        printf("a canary.\n");
        break;
    case 4:
        printf("a cat.\n");
        break;
    case 5:
        printf("a ferret.\n");
        break;
    case 6:
        printf("a turtle.\n");
        break;
    case 7:
        printf("a hamster.\n");
        break;
    case 8:
        printf("a snake.\n");
        break;
    case 9:
        printf("a dog.\n");
        break;
    case 10:
        printf("a tarantula.\n");
        break;
    case 11:
        printf("a iguana.\n");
        break;
    case 12:
        printf("a guinea pig.\n");
        break;
    default:
        printf("unknown. Try to select one of the available options.\n");
        break;
    }
}