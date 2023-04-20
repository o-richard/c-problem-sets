#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A node in the tree
typedef struct node
{
    // Store a unique key of a student
    int key;
    // Store the first name of the student
    char first_name[20];
    // Store the last name of the student
    char last_name[20];
    // A pointer to the left node
    struct node *left;
    // A pointer to the right node
    struct node *right;
}
node;

// A student data type
typedef struct student
{
    // Store a unique key of a student
    int key;
    // Store the first name of the student
    char first_name[20];
    // Store the last name of the student
    char last_name[20];
}
student;

// Display the main menu
int display_menu();
// Display the traversal menu
int traversal_display_menu();
// Check if a key exists (1 - True & 0 - False)
int find_key(int key, node *current);
// Insert a new node.
void insert_node(node *newNode);
// Update the node of a partiular key
void update_node(int key, char fname[], char lname[], node *current);
// Show the data of a particular student key
void search_key(int key, node *current);
// In order traversal
void inorder(node *current);
// Pre order traversal
void preorder(node *current);
// Post order traversal
void postorder(node *current);
// Return the maximum depth
int maxDepth(node *current);
// Show all student keys in a given level from left to right
void currentlevel(node *current, int level);
// Free dynamic memory
void destroy_tree(node *current);

// The root of the tree
node *root = NULL;
// The number of students currently
int studentCount = 0;

// The main function
int main()
{
    // The program runs until a user explicitly exits
    for(;;)
    {
        int user_choice = display_menu();

        switch (user_choice)
        {
        case 1:
            {
                // Insert a new student
                node *newNode = malloc(sizeof(node));
                // Ensure the memory is available
                if (newNode == NULL)
                {
                    printf("There is not enough memory to insert the node");
                    break;
                }

                // The key of the student
                int student_key;
                // The first & last name of the student
                char first_name[20], last_name[20];
                printf("Enter the unique key of the student (An Interger): ");
                scanf("%d", &student_key);
                printf("Enter the first name of the student: ");
                scanf("%s", first_name);
                printf("Enter the last name of the student: ");
                scanf("%s", last_name);

                // Update the node information
                newNode->key = student_key;
                strcpy(newNode->first_name, first_name);
                strcpy(newNode->last_name, last_name);
                newNode->left = NULL;
                newNode->right = NULL;

                // Check if the key already exists (Ask to replace or pass)
                int key_exists = find_key(student_key, root);
                if (key_exists == 1)
                {
                    printf("\n");
                    int user_insertion_choice;
                    printf("The key %d already exists, do you wish to replace the previous data with the current one?\n", student_key);
                    do
                    {
                        printf("Your option (1. Yes. 2. No): ");
                        scanf("%d", &user_insertion_choice);
                    } while ((user_insertion_choice < 1) || (user_insertion_choice > 2));

                    if (user_insertion_choice == 2)
                    {
                        // Free the new node
                        free(newNode);
                        break;
                    }
                    else 
                    {
                        // Free the new node
                        free(newNode);
                        // Perform an update
                        update_node(student_key, first_name, last_name, root);
                        break;
                    }
                }
                // Perfrom the instertion
                insert_node(newNode);
                printf("The insertion was succesful\n");
                // Increment the number of students
                studentCount++;
                break;
            }
        case 2:
            {
                // The key of the student
                int student_key;
                printf("Enter the unique key of the student (An Interger): ");
                scanf("%d", &student_key);

                // Perform a search
                search_key(student_key, root);
                break;
            }
        case 3:
            {
                // Update for a student

                // The key of the student
                int student_key;
                printf("Enter the unique key of the student (An Interger): ");
                scanf("%d", &student_key);

                // Ensure the student key exists
                int key_exists = find_key(student_key, root);
                if (key_exists == 0)
                {
                    printf("Sorry, this student key does not exists.\n");
                    break;
                }

                // The first & last name of the student
                char first_name[20], last_name[20];
                printf("Enter the first name of the student: ");
                scanf("%s", first_name);
                printf("Enter the last name of the student: ");
                scanf("%s", last_name);

                // Perform an update
                update_node(student_key, first_name, last_name, root);
                printf("The update was succesful\n");
                break;
            }
        case 4:
            {
                // Tranverse the whole tree
                int user_tranversal_choice = traversal_display_menu();
                
                if (user_tranversal_choice == 1)
                {
                    inorder(root);
                }
                else if (user_tranversal_choice == 2)
                {
                    preorder(root);
                }
                else
                {
                    postorder(root);
                }

                if (root == NULL)
                {
                    printf("The tree is empty.\n");
                }
                break;
            }
        case 5:
            {
                // Find the depth of the tree
                printf("The depth of the tree is %d.\n", maxDepth(root));
                break;
            }
        case 6:
            {
                // Show the nodes per level of the tree
                int depth = maxDepth(root);
                for (int i = 0; i < depth; i++)
                {
                    printf("Level %d: ", i);
                    currentlevel(root, i);
                    printf("\n");
                }
                
                break;
            }
        case 7:
            {
                if (root == NULL)
                {
                    printf("The tree is empty.\n");
                }
                else
                {
                    printf("The tree is not empty.\n");
                }
                break;
            }
        case 8:
            {
                // Exit out of the program
                
                // Delete the whole tree
                destroy_tree(root);
                return 0;
            }
        }
        int main_menu_choice = 1;
        do
        {
            printf("Do you wish you proceed to the main menu? (1. Yes. 2. No): ");
            scanf("%d", &main_menu_choice);
        } while ((main_menu_choice < 1) || (main_menu_choice > 2));

        if (main_menu_choice == 2)
        {
            // Exit out of the program    
            // Delete the whole tree
            destroy_tree(root);
            return 0;
        }
    }
}

// Display the main menu
int display_menu()
{
    // User's choice
    int choice;
    printf("\n");
    printf("1. Insert a new student\n");
    printf("2. Search for a student\n");
    printf("3. Update for a student\n");
    printf("4. Tranverse the whole tree - Display the student keys only\n");
    printf("5. Find the depth of the tree\n");
    printf("6. Find the number of nodes per level of the tree\n");
    printf("7. Check if the tree is empty\n");
    printf("8. Exit\n");

    do
    {
        printf("Enter the number of your option: ");
        scanf("%d", &choice);
    } while ((choice < 1) || (choice > 8));
    
    return choice;
}

// Display the tranversal menu
int traversal_display_menu()
{
    // User's choice
    int choice;
    printf("\n");
    printf("1. In Order\n");
    printf("2. Pre Order\n");
    printf("3. Post Order\n");

    do
    {
        printf("Enter the number of your option: ");
        scanf("%d", &choice);
    } while ((choice < 1) || (choice > 3));

    return choice;
}

// Check if a key exists (1 - True & 0 - False)
int find_key(int key, node *current)
{
    if (current != NULL)
    {
        if (key == (current->key))
        {
            return 1;
        }
        else if (key < (current->key))
        {
            return find_key(key, current->left);
        }
        else
        {
            return find_key(key, current->right);
        }
    }
    else
    {
        return 0;
    }
}

// Inserts a new node
void insert_node(node *newNode)
{
    if (root == NULL)
    {
        // Perform the insertion
        root = newNode;
        return;
    }

    // Traverse the tree to find the appropriate location for the new node
    node *current_node = root;
    while (1) 
    {
        if ((newNode->key) < current_node->key) 
        {
            if (current_node->left == NULL) 
            {
                current_node->left = newNode;
                break;
            }
            current_node = current_node->left;
        } 
        else if ((newNode->key) > current_node->key) 
        {
            if (current_node->right == NULL) 
            {
                current_node->right = newNode;
                break;
            }
            current_node = current_node->right;
        }
    }
    return;
}

// Update the node
void update_node(int key, char fname[], char lname[], node *current)
{
    if (current != NULL)
    {
        if (key == (current->key))
        {
            // Update the information
            strcpy(current->first_name, fname);
            strcpy(current->last_name, lname);
            return;
        }
        else if (key < (current->key))
        {
            return update_node(key, fname, lname, current->left);
        }
        else
        {
            return update_node(key, fname, lname, current->right);
        }
    }
}

// Show the data of a particular student key
void search_key(int key, node *current)
{
    if (current != NULL)
    {
        if (key == (current->key))
        {
            printf("A record of a student with the key %d was found.\n", key);
            printf("The first name of the student: %s\n", current->first_name);
            printf("The last name of the student: %s\n", current->last_name);
            return;
        }
        else if (key < (current->key))
        {
            return search_key(key, current->left);
        }
        else
        {
            return search_key(key, current->right);
        }
    }
    else
    {
        printf("No such record was found.\n");
        return;
    }
}

// In order traversal (Visit the root as the middle value)
void inorder(node *current)
{
    if (current != NULL)
    {
        inorder(current->left);
        printf(" %d ", current->key);
        inorder(current->right);
    }
}

// Pre order traversal (Visit the root as the first value)
void preorder(node *current)
{
    if (current != NULL)
    {
        printf(" %d ", current->key);
        inorder(current->left);
        inorder(current->right);
    }
}

// Post order traversal (Visit the root as the last value)
void postorder(node *current)
{
    if (current != NULL)
    {
        inorder(current->left);
        inorder(current->right);
        printf(" %d ", current->key);
    }
}

// Return the maximum depth
int maxDepth(node *current)
{
    if (current == NULL)
    {
        return 0;
    }
    else 
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(current->left);
        int rDepth = maxDepth(current->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
        {
            return (lDepth + 1);
        }
        else
        {
            return (rDepth + 1);
        }
    }
}

// Show all student keys in a given level from left to right
void currentlevel(node *current, int level)
{
    if (current != NULL) 
    {
        if (level == 0)
        {
            printf("%d ", current->key);
        }
        else if (level > 0) 
        { 
            currentlevel(current->left, level-1); 
            currentlevel(current->right, level-1);
        }			
    }
    else
    {
        return;
    }
}

// Free dynamic memory
void destroy_tree(node *current)
{
  if(current != NULL)
  {
      destroy_tree(current->left);
      destroy_tree(current->right);
      free(current);
  }
}  