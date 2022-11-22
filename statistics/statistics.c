#include<stdio.h>
#include<math.h>

// Function to sort the numbers in descending order. Returns an array
float *descending_sort(float n[], int size);
// Function to find maximum number
float max_number(float n[], int size);
// Function to find minimum number
float min_number(float n[], int size);
// Function to find average of the numbers
float average(float n[], int size);
// Function to find standard deviation of the numbers
float standard_deviation(float n[], int size);

void main()
{
    // Store user's choice
    int choice;

    // Display the purpose of the program
    printf("What would you like to do?(Input the number of your choice)\n\n1.Sort numbers in a descending order.\n2.Find the minimum number.\n3.Find the maximum number.\n4.Find the average of the numbers.\n5.Find the standard deviation of the nummbers.\n");
    scanf("%d", &choice);

    // Store size of array for the numbers
    int array_size=0;

    // Input the array size
    printf("How many numbers do you want to input? ");
    scanf("%d", &array_size);

    // Allocate the appropriate size for the array
    float numbers[array_size];

    // Input the number
    for (int i = 0; i < array_size; i++)
    {
        // User inputs the number
        printf("Enter number %d: ", i+1);
        scanf("%f", &numbers[i]);
    }

    // Perform a switch case depending on user's choice
    switch (choice)
    {
    case 1:
        {
            // A new array to store output
            float *sorted_numbers = descending_sort(numbers, array_size);
            
            // Print the sotted numbers
            printf("The new output is: ");

            for (int b = 0; b < array_size; b++)
            {
                printf("  %.2f  ", sorted_numbers[b]);
            }
            // Add a new line
            printf("\n");

            // Stop the execution
            break;
        }
    case 2:
        {
            // Store the minimum number   
            float minimum = min_number(numbers, array_size);

            // Show the minimum number
            printf("The minimum number is %.2f\n", minimum);

            // Stop the execution
            break;
        }
    case 3:
        {
            // Store the maximum number   
            float maximum = max_number(numbers, array_size);

            // Show the maximum number
            printf("The maximum number is %.2f\n", maximum);

            // Stop the execution
            break;
        }
    case 4:
        {
            // Store the average number   
            float mean = average(numbers, array_size);

            // Show the average of the numbers
            printf("The mean is %.2f\n", mean);

            // Stop the execution
            break;
        }
    case 5:
        {
            // Store the std deviation
            float std_dev = standard_deviation(numbers, array_size);

            // Show the stndard deviation of the numbers
            printf("The standard deviation is %.2f\n", std_dev);

            // Stop the execution
            break;
        }
    default:
        // Stop the program incase the choice is invalid
        break;
    }   
}

// Function to sort the numbers in descending order
float *descending_sort(float n[], int size)
{
    // Store the array_size
    int arr_size = size;
    
    // Keep track of the array indices
    int current_index = 0;

    // Loop until all indexes have been sorted
    while (current_index < arr_size)
    {
        // Assign the number in current index as the maximum
        float max = n[current_index];

        // Store the position of the maximum number in the unsorted part of the array
        int position = current_index;

        // Loop through all numbers of the unsorted list of array
        for (int a = current_index; a < arr_size; a++)
        {
            // Look for the maximum value 
            // Compare the numbers.
            if (n[a] > max)
            {
                // Update position of the maximum number
                position = a;

                // Update the current value of max
                max = n[a];
            }
        }

        // Perform a sort

        // Store the number in current index temporarily
        int temp_number = n[position];
        // Store the lesser number
        n[position] = n[current_index];
        // Store the bigger number
        n[current_index] = temp_number;
        
        // Update the current index
        current_index++;
    }

    // Return the sorted array
    return n;
}

// Function to find maximum number
float max_number(float n[], int size)
{
    // Store the array_size
    int arr_size = size;
    // Assign the first number as the maximum
    float max = n[0];

    for (int j = 0; j < arr_size; j++)
    {
        // Compare the numbers. Assign the maximum correctly.
        if (n[j] > max)
        {
            max = n[j];
        }
    }

    // Return the maximum number
    return max;
}

// Function to find minimum number
float min_number(float n[], int size)
{
    // Store the array_size
    int arr_size = size;
    // Assign the first number. Assume it as the minimum
    float min = n[0];

    for (int k = 0; k < arr_size; k++)
    {
        // Compare the numbers. Assign the maximum correctly.
        if (n[k] < min)
        {
            min = n[k];
        }
    }

    // Return the maximum number
    return min;
}

// Function to find average of the numbers
float average(float n[], int size)
{
    // Store the array_size
    int arr_size = size;
    // Initialize sum
    float sum = 0;

    // Calculate the sum of the numbers
    for (int l = 0; l < arr_size; l++)
    {
        sum += n[l];
    }
    
    // Calculate average
    float average = sum / arr_size;

    // Return average
    return average;
}

// Function to find standard deviation of the numbers
float standard_deviation(float n[], int size)
{
    // Calculate the mean
    float mean = average(n, size);

    // Store the array_size
    int arr_size = size;

    // Initialize sum as zero
    float sum = 0;

    // Loop through all numbers
    for (int c = 0; c < arr_size; c++)
    {
        // Find square of distance from the mean for each data point
        float distance = mean - n[c];
        float distance_square = distance * distance;

        // Sum the values
        sum += distance_square;
    }

    // Divide the sum of the values above by number of data points
    float value = sum / arr_size;

    // Find the square root
    float std_deviation = sqrt(value);

    // Return std deviation
    return std_deviation;
}