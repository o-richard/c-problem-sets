#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Store the number of integers involved in a given operation
#define MAX_INTEGERS 2

// An array to store the numbers invloved in an operation
int NUMBERS[MAX_INTEGERS];

// A function to generate an array of random numbers
int *random_integers(int the_start_number, int the_range);

void main()
{
    // Display purpose of the program
    printf("The game helps a person practice arithmetic using different operations and different sets of numbers. You will choose how many number of times you want to play at first, and when your trials end, you may choose to add more tries\n\n");

    // Stores the operation choice
    int operation_choice = 1;
    // Ensures the input is in the correct range
    do
    {
        printf("Choose which operation you want to practise with(Enter the number of your option):\n1. Addition(+)\t2. Multiplication(*)\t3. Subtraction(-)\t4. Division(/)\n");
        scanf("%d", &operation_choice);
    } while ((operation_choice < 1) && (operation_choice > 4));

    // Stores the level choice
    int level_choice = 1;
    // Ensures the input is in the correct range
    do
    {
        printf("Choose which level you want to practise with(Enter the number of your option):\n1. Low(Numbers in the range 1 to 10)\t2. Middle(Numbers in the range 11 to 50)\t3. High(Numbers in the range 51 to 100)\n");
        scanf("%d", &level_choice);
    } while ((level_choice < 1) && (level_choice > 3));

    // Store the start numbers and ranges accoding to the level a user has choosen
    int start_number=1, range=10;
    // Define the start numbers and range of numbers according to a user's choice
    switch (level_choice)
    {
    case 1:
        {
            start_number=1;
            range=10;
            break;
        }
    case 2:
        {
            start_number=11;
            range=40;
            break;
        }
    case 3:
        {
            start_number=51;
            range=50;
            break;
        }
    }

    // Store the number of tries a user has
    int max_tries = 1;

    // Allow user to choose number of tries. Input should be a positive interger
    do
    {
        printf("Enter the number of tries you would like: ");
        scanf("%d", &max_tries);
    } while (max_tries < 1);

    // Keep track of the number of tries used
    int trial_counter = 0;

    // Keep track of right answers
    int right_answers = 0;

    printf("\nEnter the answers to the following questions.\n");

    // Ensure the loop runs forever unless I explicity break it
    for (;;)
    {
        // Perform operations depending on user operation
        switch (operation_choice)
        {
        case 1:
            {
                // An array to store the generated numbers
                int *random_numbers = random_integers(start_number, range);
                
                // Store the index of the second last element in the array
                int second_last_index = MAX_INTEGERS - 1;

                // Store the correct answer
                int correct_answer = 0;

                // Display the question
                for (int j = 0; j < MAX_INTEGERS; j++)
                {
                    printf(" %d ", random_numbers[j]);

                    // Check the current index
                    if (j != second_last_index)
                    {
                        // If it is not the last index
                        printf("+");
                    }
                    else
                    {
                        // If it is the last index
                        printf(": ");
                    }

                    // Get the correct answer
                    correct_answer += random_numbers[j];
                }
                // Store the user's answer
                int user_answer = 0;

                scanf("%d", &user_answer);

                // Check if the user answer is wrong or correct
                if (user_answer == correct_answer)
                {
                    printf("Correct!\n");
                    right_answers++;
                }
                else
                {
                    printf("The correct answer is %d.\n", correct_answer);
                }

                break;
            }
        case 2:
            {
                // An array to store the generated numbers
                int *random_numbers = random_integers(start_number, range);
                
                // Store the index of the second last element in the array
                int second_last_index = MAX_INTEGERS - 1;

                // Store the correct answer
                int correct_answer = 1;

                // Display the question
                for (int j = 0; j < MAX_INTEGERS; j++)
                {
                    printf(" %d ", random_numbers[j]);

                    // Check the current index
                    if (j != second_last_index)
                    {
                        // If it is not the last index
                        printf("*");
                    }
                    else
                    {
                        // If it is the last index
                        printf(": ");
                    }

                    // Get the correct answer
                    correct_answer *= random_numbers[j];
                }
                // Store the user's answer
                int user_answer = 0;

                scanf("%d", &user_answer);

                // Check if the user answer is wrong or correct
                if (user_answer == correct_answer)
                {
                    printf("Correct!\n");
                    right_answers++;
                }
                else
                {
                    printf("The correct answer is %d.\n", correct_answer);
                }
                
                break;
            }
        case 3:
            {
                // An array to store the generated numbers
                int *random_numbers = random_integers(start_number, range);
                
                // Store the index of the second last element in the array
                int second_last_index = MAX_INTEGERS - 1;

                // Store the correct answer
                int correct_answer = random_numbers[0];

                // Display the question
                for (int j = 0; j < MAX_INTEGERS; j++)
                {
                    printf(" %d ", random_numbers[j]);

                    // Check the current index
                    if (j != second_last_index)
                    {
                        // If it is not the last index
                        printf("-");
                    }
                    else
                    {
                        // If it is the last index
                        printf(": ");
                    }

                    // Get the correct answer
                    if (j > 0)
                    {
                        correct_answer -= random_numbers[j];
                    }
                }
                // Store the user's answer
                int user_answer = 0;

                scanf("%d", &user_answer);

                // Check if the user answer is wrong or correct
                if (user_answer == correct_answer)
                {
                    printf("Correct!\n");
                    right_answers++;
                }
                else
                {
                    printf("The correct answer is %d.\n", correct_answer);
                }

                break;
            }
        case 4:
            {
                // An array to store the generated numbers
                int *random_numbers = random_integers(start_number, range);
                
                // Store the index of the second last element in the array
                int second_last_index = MAX_INTEGERS - 1;

                // Store the correct answer
                float correct_answer = (float) random_numbers[0] / random_numbers[1];

                // Display the question
                for (int j = 0; j < MAX_INTEGERS; j++)
                {
                    printf(" %d ", random_numbers[j]);

                    // Check the current index
                    if (j != second_last_index)
                    {
                        // If it is not the last index
                        printf("/");
                    }
                    else
                    {
                        // If it is the last index
                        printf(": ");
                    }

                    // Get the correct answer
                    if (j > 1)
                    {
                        correct_answer /= (float) random_numbers[j];
                    }
                }
                // Store the user's answer
                float user_answer = 0;

                scanf("%f", &user_answer);

                // Check if the user answer is wrong or correct
                if (user_answer == correct_answer)
                {
                    printf("Correct!\n");
                    right_answers++;
                }
                else
                {
                    printf("The correct answer is %.4f.\n", correct_answer);
                }
                
                break;
            }
        }

        // Increment the number of tries
        trial_counter++;
        // Check if the trial counter is equal to the specified maxium tries
        
        if (trial_counter == max_tries)
        {
            // Give an option to a user to terminte or proceed
            int should_terminate = 1;
            do
            {
                printf("Your tries have ended. What would you like to do(Enter the number of your option):\n1. Terminate\t2. Continue with the questions\n");
                scanf("%d", &should_terminate);
            } while ((should_terminate < 1) && (should_terminate > 2));
            // If a user terminates, exit the loop
            if (should_terminate == 1)
            {
                break;
            }
            else
            {
                // Store the number of increased tries
                int increment_tries = 1;

                // Allow user to increment their tries. Input should be a positive interger.
                do
                {
                    printf("Enter the number by which you would like to increase your tries: ");
                    scanf("%d", &increment_tries);
                } while (max_tries < 1);

                // Update the value of maximum tries
                max_tries += increment_tries;
            }
        }
        
    }
    
    // Show the results
    printf("\n");
    printf("Total correct answers: %d\nTotal number of tries: %d\n", right_answers, max_tries);
    
}

// A function to generate an array of random numbers
int *random_integers(int the_start_number, int the_range)
{
    // Generate a random number for each index in the array
    srand(time(0));
    for (int i = 0; i < MAX_INTEGERS; i++)
    {
        NUMBERS[i] = (rand()%the_range+the_start_number);
    }
    
    // Return the array
    return NUMBERS;
}