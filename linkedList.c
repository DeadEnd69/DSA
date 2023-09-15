#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node
{
    int data;
    struct Node *next;
};

// Insert at the beginning
void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Insert at the end
void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Delete a node
void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Key not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Print the linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int n, num;

    do
    {
        printf("\nChoose one of the options:\n"
               "1. Insert at Beginning\n"
               "2. Insert at End\n"
               "3. Delete a Number\n"
               "4. Display List\n"
               "5. Exit\n");

        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter a number to add: ");
            scanf("%d", &num);
            insertAtBeginning(&head, num);
            break;
        case 2:
            printf("Enter a number to add: ");
            scanf("%d", &num);
            insertAtEnd(&head, num);
            break;
        case 3:
            printf("Enter a number to delete: ");
            scanf("%d", &num);
            deleteNode(&head, num);
            break;
        case 4:
            printf("List contents:");
            printList(head);
            break;
        case 5:
            exit(0);
        default:
            ` printf("Invalid choice. Exiting.\n");
            exit(1);
        }
    } while (n != 5);

    return 0;
}
