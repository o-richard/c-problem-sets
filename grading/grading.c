#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Store the maximum number of courses of a given student
#define MAX_COURSES 5

// A custom datatype to store student details
typedef struct student
{
    // Store the unique index of a given student
    int student_index;
    // Registration number of a student
    char registration_number[20];
    // Full name of a student
    char full_name[50];
    // Admission number of a student
    char admission_number[20];
    // The marks of a given student
    int marks[MAX_COURSES];
    // The grades of a given student
    char grades[MAX_COURSES];
    // The codes of the units the student is doing.Each string has a maximum of 10 characters.
    char codes[MAX_COURSES][10];
    // A pointer to the next student
    struct student* next;
}
student;

// A function to display the main menu
int display_menu();

// A function to grade marks
char grade(int course_mark);

// Create a linked list
student *all_students = NULL;

void main()
{
    // Keep track of current number of students
    int number_of_students = 0;

    // Perfom calculations until the user exits
    for(;;)
    {
        // Display the main menu to the user and get their option
        int user_option = display_menu();

        switch (user_option)
        {
        case 1:
            {
                // Increment the number of students
                number_of_students += 1;

                // Create a new student
                student *new_student = malloc(sizeof(student));

                // Check if any memory is available
                if (new_student == NULL)
                {
                    // Free memory
                    student *temp = all_students->next;

                    while (temp != NULL)
                    {
                        free(all_students);
                        all_students = temp;
                        temp = temp->next;
                    }
                    printf("Sorry, please try again later. Enough memory is not available at the moment");
                    return;
                }

                // Enter the student details

                // Generate a unique student entry index
                new_student->student_index = number_of_students;

                // Enter the registration number
                printf("\nEnter the registration number of the student(Max 19 characters): ");
                getchar();
                fgets(new_student->registration_number, 19, stdin);
                
                // Enter the full name
                printf("Enter the full name of the students(Max 49 characters): ");
                fgets(new_student->full_name, 49, stdin);

                // Enter the admission number
                printf("Enter the admission number of the student(Max 19 characters): ");
                fgets(new_student->admission_number, 19, stdin);

                // Enter the course codes and marks for each course
                printf("Enter the course codes and marks for your courses\n");
                for (int k = 0; k < MAX_COURSES; k++)
                {
                    // Store the mark of a given course
                    int course_mark=0;
                    // Show the number of current course
                    printf("\tCourse number %d\n", k + 1);

                    // Enter the code of the course
                    printf("\tCourse code: ");
                    fgets(new_student->codes[k], 19, stdin);

                    // Enter the mark of the course
                    printf("\tCourse mark: ");
                    scanf("%d", &course_mark);

                    new_student->marks[k] = course_mark;

                    // Assign a grade to the mark
                    new_student->grades[k] = grade(course_mark);

                    getchar();
                }
                
                // Update the linked list. Insertion at the beginning
                new_student->next = all_students;

                all_students = new_student;

                printf("Student added successfully!\n");

                break;
            }
        case 2:
            {
                // Check if there are any students available
                if (number_of_students == 0)
                {
                    printf("\nSorry, currently there are no students available.\n");
                }
                else
                {
                    // Display details of all students
                    student *temp = all_students;

                    while (temp != NULL)
                    {
                        printf("Entry number/index %d\n", temp->student_index);
                        printf("Registration number %s", temp->registration_number);
                        printf("Full name %s", temp->full_name);
                        printf("Admission number %s", temp->admission_number);
                        printf("Courses\n");
                        for (int j = 0; j < MAX_COURSES; j++)
                        {
                            printf("\tCourse code %s\t\tMarks %d\tGrade %c\n", temp->codes[j], temp->marks[j], temp->grades[j]);    
                        }

                        temp = temp->next;
                    }
                }
                
                // Terminate the switch case
                break;
            }
        case 3:
            {
                // Check if there are any students available
                if (number_of_students == 0)
                {
                    printf("\nSorry, currently there are no students available.\n");
                }
                else
                {
                    // Store the index of a student asked by a user
                    int user_student_index = 1;
                    do
                    {
                        printf("Enter the valid entry number/index: ");
                        scanf("%d", &user_student_index);
                    } while ((user_student_index < 1) && (user_student_index > number_of_students));

                    student *temp = all_students;

                    while (temp != NULL)
                    {
                        // Display the information of a particular student index
                        if (temp->student_index == user_student_index)
                        {
                            printf("Entry number/index %d\n", temp->student_index);
                            printf("Registration number %s", temp->registration_number);
                            printf("Full name %s", temp->full_name);
                            printf("Admission number %s", temp->admission_number);
                            printf("Courses\n");

                            // Store the total marks of a student
                            int student_total_marks = 0;

                            for (int j = 0; j < MAX_COURSES; j++)
                            {
                                printf("\tCourse code %s\t\tMarks %d\tGrade %c\n", temp->codes[j], temp->marks[j], temp->grades[j]);    

                                // Calculate total student marks
                                student_total_marks += temp->marks[j];
                            }

                            printf("Total marks: %d\n", student_total_marks);
                        }

                        temp = temp->next;
                    }

                }

                // Terminate the switch case
                break;
            }
        case 4:
            {
                // Check if there are any students available
                if (number_of_students == 0)
                {
                    printf("\nSorry, currently there are no students available.\n");
                }
                else
                {
                    // Store the index of a student asked by a user
                    int user_student_index = 1;
                    do
                    {
                        printf("Enter the valid entry number/index: ");
                        scanf("%d", &user_student_index);
                    } while ((user_student_index < 1) && (user_student_index > number_of_students));

                    student *temp = all_students;

                    while (temp != NULL)
                    {
                        // Display the information of a particular student index
                        if (temp->student_index == user_student_index)
                        {
                            printf("Entry number/index %d\n", temp->student_index);
                            printf("Registration number %s", temp->registration_number);
                            printf("Full name %s", temp->full_name);
                            printf("Admission number %s", temp->admission_number);
                            printf("Courses\n");

                            // Store the total marks of a student
                            int student_total_marks = 0;

                            for (int j = 0; j < MAX_COURSES; j++)
                            {
                                printf("\tCourse code %s\t\tMarks %d\tGrade %c\n", temp->codes[j], temp->marks[j], temp->grades[j]);    

                                // Calculate total student marks
                                student_total_marks += temp->marks[j];
                            }

                            // Calculate average of student marks
                            float student_average_marks = (float) student_total_marks / MAX_COURSES;

                            printf("Average marks: %.3f\n", student_average_marks);
                        }

                        temp = temp->next;
                    }
                }

                // Terminate the switch case
                break;
            }
        case 5:
            {
                // Check if there are any students available
                if (number_of_students == 0)
                {
                    printf("\nSorry, currently there are no students available.\n");
                }
                else
                {
                    // Store the index of a student
                    int user_student_index = 1;
                    do
                    {
                        printf("Enter the valid entry number/index ");
                        scanf("%d", &user_student_index);
                    } while ((user_student_index < 1) && (user_student_index > number_of_students));

                    student *temp = all_students;

                    while (temp != NULL)
                    {
                        // Display the information of a particular student index
                        if (temp->student_index == user_student_index)
                        {
                            printf("Entry number/index %d\n", temp->student_index);
                            printf("Registration number %s", temp->registration_number);
                            printf("Full name %s", temp->full_name);
                            printf("Admission number %s", temp->admission_number);
                            
                            // Store the unit with the highest mark of a student
                            char student_highest_mark[10];

                            // Update the value of maximum mark to first unit
                            int max = temp->marks[0];

                            for (int j = 0; j < MAX_COURSES; j++)
                            {
                                // Check the value of maximum mark
                                if (temp->marks[j] > max)
                                {
                                    strcpy(student_highest_mark, temp->codes[j]);
                                }
                            }

                            printf("Course code of the unit with the highest mark: %s\n", student_highest_mark);

                        }
                    }

                }

                // Terminate the switch case
                break;
            }
        case 6:
            {
                // Check if there are any students available
                if (number_of_students == 0)
                {
                    printf("\nSorry, currently there are no students available.\n");
                }
                else
                {
                    // Store the index of a student
                    int user_student_index = 1;
                    do
                    {
                        printf("Enter the valid entry number/index ");
                        scanf("%d", &user_student_index);
                    } while ((user_student_index < 1) && (user_student_index > number_of_students));

                    student *temp = all_students;

                    while (temp != NULL)
                    {
                        // Display the information of a particular student index
                        if (temp->student_index == user_student_index)
                        {
                            printf("Entry number/index %d\n", temp->student_index);
                            printf("Registration number %s", temp->registration_number);
                            printf("Full name %s", temp->full_name);
                            printf("Admission number %s", temp->admission_number);
                            
                            // Store the unit with the highest mark of a student
                            char student_lowest_mark[10];

                            // Update the value of maximum mark to first unit
                            int max = temp->marks[0];

                            for (int j = 0; j < MAX_COURSES; j++)
                            {
                                // Check the value of maximum mark
                                if (temp->marks[j] < max)
                                {
                                    strcpy(student_lowest_mark, temp->codes[j]);
                                }
                            }

                            printf("Course code of the unit with the lowest mark: %s\n", student_lowest_mark);

                        }
                    }
                }

                // Terminate the switch case
                break;
            }
        case 7:
            {
                // Free memory
                student *temp = all_students->next;

                while (temp != NULL)
                {
                    free(all_students);
                    all_students = temp;
                    temp = temp->next;
                }

                // Exit out of the program
                printf("\nYou have terminated the program.\n");
                return;
            }
        }
    }
}

// A function to display the main menu
int display_menu()
{
    // Store the choice of a given user
    int user_choice = 1;

    do
    {
        printf("What would you like to do?(Enter the number of your option)\n");
        // Display the available options
        printf("1. Add student details\t2. View student details\t3. Calculate the total student marks\n4. Calculate the average marks of a student\t5. Display the unit with the highest mark of a particular student\t6. Display the unit with the lowest mark\t7. Exit\n");
        scanf("%d", &user_choice);
    } while ((user_choice < 1) && (user_choice > 7));
    
    return user_choice;
}

// A function to grade marks
char grade(int course_mark)
{
    if (course_mark >= 70)
    {
        return 'A';
    }
    else if (course_mark >= 60)
    {
        return 'B';
    }
    else if (course_mark >= 50 )
    {
        return 'C';
    }
    else if (course_mark >= 40)
    {
        return 'D';
    }
    else 
    {
        return 'F';
    }
}