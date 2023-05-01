#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode
{
    int key;
    char fname_initial, lname_initial;
    struct treenode *left;
    struct treenode *right;
} treenode;

int display_menu();
int traversal_display_menu();

treenode *createnode(int key, char fname_initial, char lname_initial);
bool insertnode(treenode **rootptr, int key, char fname_initial, char lname_initial, bool is_update);
bool findnode(treenode *root, int key);

// Print the tabs for each tree level
void printtabs_per_level(int numtabs);
// Print the tree without tabs per level
void inorder_notabs(treenode *root);
void preorder_notabs(treenode *root);
void postorder_notabs(treenode *root);
// Print the tree with tabs per level
void inorder_tabs(treenode *root, int level);
void preorder_tabs(treenode *root, int level);
void postorder_tabs(treenode *root, int level);

int maxDepth(treenode *root);
void destroy_tree(treenode *root);

int main ()
{
    treenode *root = NULL;

    for(;;)
    {
        int user_choice = display_menu();

        switch (user_choice)
        {
            case 1:
            {
                int key;
                char fname_initial, lname_initial;
                printf("Enter the unique key of the student (An Interger): ");
                scanf("%d", &key);

                while ((getchar()) != '\n' );
                printf("Enter the first name initial of the student (A character): ");
                fname_initial = getchar();

                while ((getchar()) != '\n' );
                printf("Enter the last name of the student (A character): ");
                lname_initial = getchar();

                bool result = insertnode(&root, key, fname_initial, lname_initial, false);
                if (result == true)
                {
                    printf("The insertion was succesful.\n");
                }
                else
                {
                    printf("The insertion was not succesful. Key %d already exists.\n", key);
                }

                break;
            }
            case 2:
            {
                int key;
                printf("Enter the unique key of the student (An Interger): ");
                scanf("%d", &key);

                bool result = findnode(root, key);
                if (result == true)
                {
                    printf("The student with the key %d was found.\n", key);
                }
                else
                {
                    printf("The student with the key %d was not found.\n", key);
                }

                break;
            }
            case 3:
            {
                int key;
                char fname_initial, lname_initial;
                printf("Enter an existing unique key of the student (An Interger): ");
                scanf("%d", &key);

                while ((getchar()) != '\n' );
                printf("Enter the first name initial of the student (A character): ");
                fname_initial = getchar();

                while ((getchar()) != '\n' );
                printf("Enter the last name initial of the student (A character): ");
                lname_initial = getchar();

                bool result = insertnode(&root, key, fname_initial, lname_initial, true);
                if (result == true)
                {
                    printf("The update was succesful.\n");
                }
                else
                {
                    printf("The update was not succesful. Ensure key %d exists.\n", key);
                }

                break;
            }
            case 4:
            {
                // Tranverse the whole tree
                int user_tranversal_choice = traversal_display_menu();
                
                if (user_tranversal_choice == 1)
                {
                    inorder_notabs(root);
                }
                else if (user_tranversal_choice == 2)
                {
                    preorder_notabs(root);
                }
                else if (user_tranversal_choice == 3)
                {
                    postorder_notabs(root);
                }
                else if (user_tranversal_choice == 4)
                {
                    inorder_tabs(root, 0);
                }
                else if (user_tranversal_choice == 5)
                {
                    preorder_tabs(root, 0);
                }
                else
                {
                    postorder_tabs(root, 0);
                }
            
                break;
            }
            case 5:
            {
                printf("The depth of the tree is %d.\n", maxDepth(root));
                break;
            }
            case 6:
            {
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
            destroy_tree(root);
            return 0;
        }
    }
}

int display_menu()
{
    int user_choice;
    printf("\n");
    printf("1. Insert a new student\n");
    printf("2. Search for a student\n");
    printf("3. Update for a student\n");
    printf("4. Tranverse the whole tree - Display the student keys only\n");
    printf("5. Find the depth of the tree\n");
    printf("6. Exit\n");

    do
    {
        printf("Enter the number of your option: ");
        scanf("%d", &user_choice);
    } while ((user_choice < 1) || (user_choice > 6));
    
    return user_choice;
}

int traversal_display_menu()
{
    int user_choice;
    printf("\n");
    printf("1. In Order - Without tabs\n");
    printf("2. Pre Order - Without tabs\n");
    printf("3. Post Order - Without tabs\n");
    printf("4. In Order - With tabs\n");
    printf("5. Pre Order - With tabs\n");
    printf("6. Post Order - With tabs\n");

    do
    {
        printf("Enter the number of your option: ");
        scanf("%d", &user_choice);
    } while ((user_choice < 1) || (user_choice > 6));
    return user_choice;
}

treenode *createnode(int key, char fname_initial, char lname_initial)
{
    treenode *new = malloc(sizeof(treenode));

    if (new == NULL) return NULL;

    new->key = key;
    new->fname_initial = fname_initial;
    new->lname_initial = lname_initial;
    new->left = NULL;
    new->right = NULL;

    return new;
}

bool insertnode(treenode **rootptr, int key, char fname_initial, char lname_initial, bool is_update)
{
    treenode *root = *rootptr;

    // Empty tree
    if (root == NULL)
    {
        // Incase an update is occurring
        if (is_update == true)
        {
            return false;
        }
        else
        {
            (*rootptr) = createnode(key, fname_initial, lname_initial);
            return true;
        }
    }

    // Key Exists
    if (root->key == key) 
    {
        // Incase an update is occuring
        if (is_update == true)
        {
            root->fname_initial = fname_initial;
            root->lname_initial = lname_initial;
            return true;
        }
        else
        {
            return false;
        }
    }

    if (key < (root->key))
    {
        insertnode(&(root->left), key, fname_initial, lname_initial, is_update);
    }
    else
    {
        insertnode(&(root->right), key, fname_initial, lname_initial, is_update);
    }
}

bool findnode(treenode *root, int key)
{
    if (root == NULL) return false;

    if (root->key == key) 
    {
        printf("\tFirst Name Initial: %c\n", root->fname_initial);
        printf("\tLast Name Initial: %c\n", root->lname_initial);
        return true;
    }

    if (key < (root->key))
    {
        findnode((root->left), key);
    }
    else
    {
        findnode((root->right), key);
    }
}

void printtabs_per_level(int numtabs)
{
    for (int i = 0; i < numtabs; i++)
    {
        printf("\t");
    }
}

// In order traversal (Visit the root as the middle one)
void inorder_notabs(treenode *root)
{
    if (root != NULL)
    {
        printf("Left\n");
        inorder_notabs(root->left);
        printf("Key: %d\n\tFirst Name Initial: %c\n\tLast Name Initial: %c\n", root->key, root->fname_initial, root->lname_initial);
        printf("Right\n");
        inorder_notabs(root->right);
    }
    else
    {
        printf("----- <empty> ----\n");
        return;
    }
}
// Pre order traversal (Visit the root as the first one)
void preorder_notabs(treenode *root)
{
    if (root != NULL)
    {
        printf("Key: %d\n\tFirst Name Initial: %c\n\tLast Name Initial: %c\n", root->key, root->fname_initial, root->lname_initial);
        printf("Left\n");
        preorder_notabs(root->left);
        printf("Right\n");
        preorder_notabs(root->right);
        return;
    }
    else
    {
        printf("----- <empty> ----\n");
        return;
    }
}
// Post order traversal (Visit the root as the last one)
void postorder_notabs(treenode *root)
{
    if (root != NULL)
    {
        printf("Left\n");
        postorder_notabs(root->left);
        printf("Right\n");
        postorder_notabs(root->right);
        printf("Key: %d\n\tFirst Name Initial: %c\n\tLast Name Initial: %c\n", root->key, root->fname_initial, root->lname_initial);
    }
    else
    {
        printf("----- <empty> ----\n");
        return;
    }
}

// In order traversal (Visit the root as the middle one)
void inorder_tabs(treenode *root, int level)
{
    if (root != NULL)
    {
        printtabs_per_level(level);
        printf("Left\n");
        inorder_tabs(root->left, level + 1);

        printtabs_per_level(level);
        printf("Key: %d\n\tFirst Name Initial: %c\n\tLast Name Initial: %c\n", root->key, root->fname_initial, root->lname_initial);
        
        printtabs_per_level(level);
        printf("Right\n");
        inorder_tabs(root->right, level + 1);
    }
    else
    {
        printf("----- <empty> ----\n");
        return;
    }
}
// Pre order traversal (Visit the root as the first one)
void preorder_tabs(treenode *root, int level)
{
    if (root != NULL)
    {
        printtabs_per_level(level);
        printf("Key: %d\n\tFirst Name Initial: %c\n\tLast Name Initial: %c\n", root->key, root->fname_initial, root->lname_initial);
        
        printtabs_per_level(level);
        printf("Left\n");
        preorder_tabs(root->left, level + 1);
        
        printtabs_per_level(level);
        printf("Right\n");
        preorder_tabs(root->right, level + 1);
        return;
    }
    else
    {
        printf("----- <empty> ----\n");
        return;
    }
}
// Post order traversal (Visit the root as the last one)
void postorder_tabs(treenode *root, int level)
{
    if (root != NULL)
    {
        printtabs_per_level(level);
        printf("Left\n");
        postorder_tabs(root->left, level + 1);
        
        printtabs_per_level(level);
        printf("Right\n");
        postorder_tabs(root->right, level + 1);
        
        printtabs_per_level(level);
        printf("Key: %d\n\tFirst Name Initial: %c\n\tLast Name Initial: %c\n", root->key, root->fname_initial, root->lname_initial);
    }
    else
    {
        printf("----- <empty> ----\n");
        return;
    }
}

int maxDepth(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else 
    {
        // compute the depth of each subtree
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
 
        //  use the larger one 
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

void destroy_tree(treenode *root)
{
  if(root != NULL)
  {
      destroy_tree(root->left);
      destroy_tree(root->right);
      free(root);
  }
}  