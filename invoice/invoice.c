#include<stdio.h>

// A data type to store the name of the item and it's price
typedef struct invoice_item
{
    char item_name[50];
    float item_price;
}
invoice_item;

void main()
{
    // Display the purpose of the program
    printf("The program creates invoices for hotel customers. The invoices are stored in a file.\n");

    // A file storing the information
    FILE *INVOICE_FILE = fopen("invoice.txt", "w");

    if (INVOICE_FILE == NULL)
    {
        printf("Sorry, could not create or retrieve the file. Please try again.");
        return;
    }
    
    // Keep track of the maximum tries
    int max_tries = 1;
    // Keep track of number of entered inputs
    int trial_counter = 0;

    // Loop forever until the user chooses to terminate
    for(;;)
    {
        printf("\nCustomer number %d\n", trial_counter + 1);

        // Store the name of the customer
        int customer_name[50];

        printf("Enter the customer name: ");
        getchar();
        scanf("%[^\n]s", customer_name);

        // Store the date of the invoice
        int dd, mm, yyyy;

        printf("Enter the date of the invoice in the format (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &dd, &mm, &yyyy);

        // Store the number of items in the list
        int number_of_items = 1;

        do
        {
            printf("How many items do you want to include in the invoice: ");
            scanf("%d", &number_of_items);
        } while (number_of_items < 1);
        
        // An array to store the names of the items and prices
        invoice_item items[number_of_items];

        // Store the total cost of items, discount offered, amount payable
        float total_cost=0, discount_offered=0, amount_payable;

        for (int i = 0; i < number_of_items; i++)
        {
            // Enter details for each item
            printf("Enter item name: ");
            scanf("%s", items[i].item_name);

            printf("Enter item price: ");
            scanf("%f", &items[i].item_price);

            total_cost += items[i].item_price;
        }

        // Calculate discount and amount payable
        if (total_cost > 5000)
        {
            discount_offered = (5 / 100.0) * total_cost;
        }
        amount_payable = total_cost - discount_offered;

        // Print the values to a file
        fprintf(INVOICE_FILE, "\n");
        fprintf(INVOICE_FILE, "Customer name: %s\n", customer_name);
        fprintf(INVOICE_FILE, "Date of invoice: %02d/%02d/%04d\n", dd,mm,yyyy);
        fprintf(INVOICE_FILE, "List of items: %s\n", customer_name);

        for (int j = 0; j < number_of_items; j++)
        {
            fprintf(INVOICE_FILE, "\t\tName: %s\tPrice: Kshs %.2f\n", items[j].item_name, items[j].item_price);
        }

        fprintf(INVOICE_FILE, "Total cost of items: %.2f\n", total_cost);
        fprintf(INVOICE_FILE, "Discount offered: %.2f\n", discount_offered);
        fprintf(INVOICE_FILE, "Total amount paid by customer: %.2f\n", amount_payable);
        fprintf(INVOICE_FILE, "\n");
       
        // Increment the number of tries
        trial_counter++;
        
        // Check if the trial counter is equal to the specified maxium tries
        if (trial_counter == max_tries)
        {
            // Give an option to a user to terminte or proceed
            int should_terminate = 1;
            do
            {
                printf("What would you like to do?(Enter the number of your option):\n1. Terminate\t2. Add more entries\n");
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
                    printf("Enter the number of customers you would like to add their entries: ");
                    scanf("%d", &increment_tries);
                } while (max_tries < 1);

                // Update the value of maximum tries
                max_tries += increment_tries;
            }    
        }
        
    }

    // Close the file
    fclose(INVOICE_FILE);

    // Inform user what to do
    printf("\nPlease open the file 'invoice.txt' to see the details of your invoices.\n");
}