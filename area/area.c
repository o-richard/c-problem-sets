#include<stdio.h>

void main ()
{
    // Store user's choice
    char choice;

    // Select the shape they want to chose
    printf("Select the shape which you wish to calculate the area (A, B or C).HINT: THE VALUES ARE CHARACTER SENSITIVE :\n A. Triangle \n B. Circle \n C. Rectangle \n");
    
    // Get user input
    choice = getchar();

    // Store the area
    float area;

    // Perform a switch case
    switch (choice)
    {
    case 'A':
        {
            // Store the height and base of the triangle
            float height, base;

            printf("Height of triangle: ");
            scanf("%f", &height);

            printf("Base of triangle: ");
            scanf("%f", &base);

            area = 0.5 * height * base;
            printf("The area of the triangle is %.4f square units.", area);
            break;
        }
    
    case 'B':
        {
            // Store the radius of circle
            float radius;

            printf("Radius of circle: ");
            scanf("%f", &radius);

            area = 3.142 * radius * radius;
            printf("The area of the circle is %.4f square units.", area);
            break;
        }

    case 'C':
        {
            // Store the radius of circle
            float length, width;

            printf("Length of rectangle: ");
            scanf("%f", &length);

            printf("Width of rectangle: ");
            scanf("%f", &width);

            area = length * width;
            printf("The area of the rectangle is %.4f square units.", area);
            break;
        }

    default:
        printf("Your choice is not among the present options.");
        break;
    }
}
