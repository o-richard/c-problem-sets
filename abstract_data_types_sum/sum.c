#include<stdio.h>
#include<stdlib.h>

// Handle array data type
void arrays();
// Handle matrices data type
void matrices();
// Handle polynomials data type
void polynomials();

// Custom datatype for polynomials
typedef struct poly
{
    // Store the co-efficient of polynomial term
    int coefficient;
    // Store the power of polynomial term
    int power;
    // Pointer to the next poly
    struct poly* next;
}
poly;


void main()
{
    // Store the choice of a user
    int user_choice=1;

    // Show the main menu of the program
    printf("\t1. Arrays");
    printf("\t2. Matrices");
    printf("\t3. Polynomials\n");
    // Ensure the value is in the range of 1-3
    do
    {
        printf("Choose which abstract data type do you want to perform the addition of (Enter the option of your answer): ");
        scanf("%d", &user_choice);
    } while ((user_choice < 1) || (user_choice > 3));

    // Show the appropriate function depending on user input
    switch (user_choice)
    {
        case 1:
            {
                // In the case of arrays
                arrays();
                break;
            }
        case 2:
            {
                // In the case of matrices
                matrices();
                break;
            }
        case 3:
            {
                // In the case of polynomials
                polynomials();
                break;
            }
        default:
            break;
    }
}

// Handle array data type
void arrays()
{
    // Ask user for the number of elements
    int element_number = 1;
    // Ensure the value is greater than 0
    do
    {
        printf("Enter the number of elements to have in your array(Minimum is 1): ");
        scanf("%d", &element_number);
    } while (element_number < 1);
    // Ask user for the number of arrays to add
    int array_number = 1;
    // Ensure the value is atleast 2
    do
    {
        printf("Enter the number of arrays you wish to add (Minimum is 2): ");
        scanf("%d", &array_number);
    } while (array_number < 2);
    // Create an array to hold the arrays input by user and the answer (Hence +1)
    int array[array_number+1][element_number];
    // Allow user to input the arrays "array_number" of times for "element_number" of times
    for (int i = 0; i < array_number; i++)
    {
        printf("Enter the elements for array number %d\n", i+1);
        for (int j = 0; j < element_number; j++)
        {
            printf("\tElement %d: ", j + 1);
            scanf("%d", &array[i][j]);
        }   
    }
    // Perform addition and save the result for "element_number" of times for "array_number" of times, storing at array[array_number]
    for (int k = 0; k < element_number; k++)
    {
        int current_sum = 0;
        for (int l = 0; l < array_number; l++)
        {
            current_sum += array[l][k];
        }
        // Store the result corrctly
        array[array_number][k] = current_sum;
    }
    // Display the result
    printf("The resultant sum of all arrays is:\n");
    // Show each element at array[array_number]
    for (int m = 0; m < element_number; m++)
    {
        printf("%d\t", array[array_number][m]);
    }
    
}
// Handle matrices data type
void matrices()
{
    // Ask user for the order of the matrices (Row, Columns)
    // Ensure the value is greater than 0
    int row_number=1;
    do
    {
        printf("Enter the number of rows to have in your matrix(Minimum is 1): ");
        scanf("%d", &row_number);
    } while (row_number < 1);
    // Ensure the value is greater than 0
    int col_number=1;
    do
    {
        printf("Enter the number of columns to have in your matrix(Minimum is 1): ");
        scanf("%d", &col_number);
    } while (col_number < 1);
    // Ask user for the number of matrices to add
    int matrices_number = 1;
    // Ensure the value is atleast 2
    do
    {
        printf("Enter the number of matrices you wish to add (Minimum is 2): ");
        scanf("%d", &matrices_number);
    } while (matrices_number < 2);   
    // Create an array to hold the matrices input by user and the answer (Hence +1)
    int matrix[matrices_number+1][row_number][col_number];
    // Allow user to input the matrices "matrices_number" of times for "row_number" of times for "col_number" of times
    for (int i = 0; i < matrices_number; i++)
    {
        printf("Enter the elements for matrix number %d\n", i+1);
        for (int j = 0; j < row_number; j++)
        {
            printf("\tRow number %d\n", j+1);
            for (int k = 0; k < col_number; k++)
            {
                printf("\t\tColumn number %d: ", k+1);
                scanf("%d", &matrix[i][j][k]);
            }
            
        }   
    }
    // Perform addition and save the result for "row_number" of times for "col_number" of times "matrices_number" of times, storing at matrix[matrices_number]
    for (int l = 0; l < row_number; l++)
    {
        for (int m = 0; m < col_number; m++)
        {
            int current_sum = 0;
            for (int n = 0; n < matrices_number; n++)
            {
                current_sum += matrix[n][l][m];
            }
            // Store the result corrctly
            matrix[matrices_number][l][m] = current_sum;
        }
    }
    // Display the result
    printf("The resultant sum of all matrices is:\n");
    // Show each element at matrix[matrices_number], for "row_number" of times for "col_number" of times
    for (int p = 0; p < row_number; p++)
    {
        printf("\t");
        for (int q = 0; q < col_number; q++)
        {
            printf("%d\t", matrix[matrices_number][p][q]);   
        }
        printf("\n");
    }
}

// Handle polynomials data type
void polynomials()
{
    // Ask user for the number of polynomials to add
    int polynomials_number = 1;
    // Ensure the value is atleast 2
    do
    {
        printf("Enter the number of polynomials you wish to add (Minimum is 2): ");
        scanf("%d", &polynomials_number);
    } while (polynomials_number < 2);

    // Create an array to hold the polynomials input by user and the answer (Hence +1)
    poly *polys[polynomials_number+1];

    // Initialize the array so that each element points to NULL initially
    for (int u = 0; u <= polynomials_number; u++) {
        polys[u] = NULL;
    }

    // Allow user to input the polynomials "polynomials_number" of times
    for (int i = 0; i < polynomials_number; i++)
    {
        printf("You are inputting terms for polynomial number %d:\n", i+1);
        // Keep track of the number of terms a user has input
        int term_input = 0;
        // Allow user to input any number of terms of the polynomial (Until they wish to stop). Allows at least one value to be input.
        for(;;)
        {
            printf("\tTerm %d: \n", term_input+1);
            // Store the co-efficent and power
            int co_ef = 1, power = 0;

            // Get the co-efficient from the user
            printf("\t\tCo-effienct: ");
            scanf("%d", &co_ef);
            // Get the power from the user
            printf("\t\tPower: ");
            scanf("%d", &power);

            // Create the new node
            poly *new_poly = malloc(sizeof(poly));
            
            // Check if any memory is available
            if (new_poly == NULL)
            {
                // Free memory in case there is none. Run till the current polynomial number i.e until where we have used dynamic memory
                for (int t = 0; t <= i; t++)
                {
                    poly *current_one = polys[t];
                    while (current_one != NULL)
                    {
                        // Store the current element temorarily
                        poly* temp = current_one; 
                        // Move tp the next element
                        current_one = current_one->next;
                        // Free the memory at the current element
                        free(temp);
                    }
                }
                printf("Sorry, please try again later. Enough memory is not available at the moment");
                return;
            }

            new_poly->coefficient = co_ef;
            new_poly->power = power;
            new_poly->next = NULL;

            // Access the head of the linked list. 
            poly *terms = polys[i];
            // The list is empty. Simply add the new node
            if (terms == NULL)
            {
                polys[i] = new_poly;
            }
            else
            {
                // Insert in such a way that the powers of the nodes are from the largest to the smallest
                poly *curr = terms;
                // Keep track of previous polynomial term
                poly *prev = terms;
                while (curr != NULL)
                {
                    // Get the current power
                    int current_power = curr->power;
                    // If the entered power is greater than the current power. Insert here. Break
                    if (power > current_power)
                    {
                        new_poly->next = curr;
                        prev = new_poly;
                        // Update the head
                        polys[i] = prev;
                        // Stop the loop
                        break;
                    }
                    else if (current_power == power)
                    {
                        // Add the co-efficients
                        int current_coef = curr->coefficient;
                        curr->coefficient = current_coef + co_ef;
                        // Delete the new node. Break
                        free(new_poly);
                        break;
                    }
                    prev = curr;
                    curr = curr->next;

                    // If curr == NULL. Means end of linked list, add the node here
                    if (curr == NULL)
                    {
                        prev->next = new_poly;
                        break;
                    }
                }
            }
            
            // Increment the number of terms
            term_input += 1;

            // Ask user if they wish to continue
            int user_choice = 2;
            // Ensure the value is in the range of 1-2
            do
            {
                printf("Do you wish to continue? 1. Yes 2. No (Enter the option of your answer): ");
                scanf("%d", &user_choice);
            } while ((user_choice < 1) || (user_choice > 2));
            // If the value is No i.e 2: Break
            if (user_choice == 2)
            {
                break;
            }
        }
    }
    
    // Perform addition

    // 1. Get the largest power of a term at the start of each linked list since the data was sorted
    // 2. For each polynomial (non-empty), where such a term occurs, perform the addtion of co-eeficients and remove that term, save it in the last array (Powers in ascending order).
    // 3. Repeat 1 & 2 till there are no largest powers i.e all linked lists are NULL
    for(;;)
    {    
        // Keep track if the maximum number is set. 0 - False. 1 - True
        int is_max_number_set = 0;
        // Store the max number
        int max_number=0;
        for (int a = 0; a < polynomials_number; a++)
        {
            poly *currnet = polys[a];
            // Check if the list is empty. Perform only for non-empty ones
            if (currnet != NULL)
            {
                // Set the max_number to the first value that has occurred
                if(is_max_number_set == 0)
                {
                    max_number = currnet->power;
                    // Update a number was found
                    is_max_number_set = 1;
                }
                else
                {
                    // Update the value is there is an occurrence of a greater power
                    int current_power = currnet->power;
                    if (current_power > max_number)
                    {
                        max_number = current_power;
                    }
                    
                }
            }
        }

        // In case there was no term present
        if (is_max_number_set == 0)
        {
            // Quit the loop
            break;
        }
        else
        {
            // Step 2
            int total_cooeficient = 0;
            for (int b = 0; b < polynomials_number; b++)
            {
                poly *curremt = polys[b];
                // Check if the list is empty. Perform only for non-empty ones
                if (curremt != NULL)
                {
                    // Check if the first term matches the maximum value
                    int curr_power = curremt->power;
                    if (max_number == curr_power)
                    {
                        poly *temp_node = polys[b];
                        // Add up the cooefficients
                        total_cooeficient += (curremt->coefficient);
                        // Update the list
                        curremt = curremt->next;
                        polys[b] = curremt;
                        // Free the memory to reduce look up size.
                        free(temp_node);
                    }
                    
                }
            }
            // Create the new node
            poly *new_answer = malloc(sizeof(poly));
            // Check if any memory is available
            if (new_answer == NULL)
            {
                // Free memory in case there is none. Run till the current polynomial number i.e until where we have used dynamic memory
                for (int t = 0; t <= polynomials_number; t++)
                {
                    poly *curr_polynomial = polys[t];
                    while (curr_polynomial != NULL)
                    {
                        // Store the current element temorarily
                        poly* temp_poly = curr_polynomial; 
                        // Move tp the next element
                        curr_polynomial = curr_polynomial->next;
                        // Free the memory at the current element
                        free(temp_poly);
                    }
                }
                printf("Sorry, please try again later. Enough memory is not available at the moment");
                return;
            }

            new_answer->coefficient = total_cooeficient;
            new_answer->power = max_number;
            // Insert as the first item
            poly *head = polys[polynomials_number];
            new_answer->next = head;
            polys[polynomials_number] = new_answer;
        }
    }
    // Print the polynomials
    printf("The resultant sum of all polynomials is:\n");
    // Show each element at polys[polynomials_number], for elements
    for (poly *a = polys[polynomials_number]; a != NULL; a=a->next)
    {
        int the_power = a->power;
        // Incase it is power of zero. Jst display the coeeficient
        if (the_power == 0)
        {
            printf(" (%d) ", a->coefficient);
        }
        else
        {
            printf(" (%dx^%d) ", a->coefficient, the_power);
        }
        if (a->next != NULL)
        {
            printf("+");
        }
    }
    // Free memory   
    poly *ans = polys[polynomials_number];
    while (ans != NULL)
    {
        // Store the current element temorarily
        poly* temp = ans; 
        // Move tp the next element
        ans = ans->next;
        // Free the memory at the current element
        free(temp);
    }
}