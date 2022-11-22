#include<stdio.h>

// Store details of a sales person
typedef struct sales
{
    // Store name of the salesperson. Assumed maximum length is 50 characters
    char full_name[50];
    // Store payroll number of salesperson. Assumed maximum length is 10 characters
    char payroll_number[10];
    // Store amount of sales the sales person has sold.
    int sales_amount;
    // Store the commission 
    float commission;
    // Store the total salary
    float total_salary;
}
sales_person;

void main ()
{
    // Store the retainer amount
    const int RETAINER_AMOUNT = 25000;

    // Store number of salesperson
    int number_of_salesperson;

    // Get number of sales person
    printf("How many salesperson do you want to capture their data? ");
    scanf("%d", &number_of_salesperson);

    // Exlude added '\n'
    getchar();

    // An array to store details of all sales persons
    sales_person all[number_of_salesperson];

    // Loop through all entries
    for (int i = 0; i < number_of_salesperson; i++)
    {
        // Store entry number
        int entry_number = i + 1;
        printf("Entry Number %d \n", entry_number);

        // Get salespersons name
        printf("Enter sales persons name: ");
        fgets(all[i].full_name, 50, stdin);

        // Get salesperson payroll number
        printf("Enter sales persons payroll number: ");
        fgets(all[i].payroll_number, 50, stdin);

        // Get salesperson sales amount. Ensure value is positive
        do 
        {
            printf("Enter sales persons amount of sales: ");
            scanf("%d", &all[i].sales_amount);
        }
        while(all[i].sales_amount < 0);

        // Exlude added '\n'
        getchar();

        // Store percentage of commission
        int commission_percent;

        // Assign commission percentage
        if (all[i].sales_amount <= 1000)
        {
            commission_percent = 1;
        }
        else if (all[i].sales_amount <= 5000)
        {
            commission_percent = 3;
        }
        else if (all[i].sales_amount <= 10000)
        {
            commission_percent = 5;
        }
        else
        {
            commission_percent = 10;
        }

        // Calculate the commission 
        all[i].commission = (commission_percent / 100.0) * all[i].sales_amount;
        
        // Calculate total salary
        all[i].total_salary = RETAINER_AMOUNT + all[i].commission;

    }
    
    // Display all entries
    for (int j = 0; j < number_of_salesperson; j++)
    {
        // Store entry number
        int entry_number = j + 1;
        printf("Entry Number %d \n", entry_number);

        printf("Sales person name: %s \n", all[j].full_name);
        printf("Sales person payroll number: %s \n", all[j].payroll_number);
        printf("Sales person amount of sales: %d \n\n", all[j].sales_amount);
        printf("Sales person commission: %.2f \n\n", all[j].commission);
        printf("Sales person total salary: %.2f \n\n", all[j].total_salary);
    }

}