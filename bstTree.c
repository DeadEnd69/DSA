#include <stdio.h>
#include <stdlib.h>

struct tree
{
    struct tree *left;
    int info;
    struct tree *right;
};

struct tree *rt = NULL;

void insrt()
{
    int x;
    struct tree *temp, *root;
    root = rt;
    temp = (struct tree *)malloc(sizeof(struct tree));
    printf("Enter data:");
    scanf("%d", &x);
    temp->left = NULL;
    temp->right = NULL;
    temp->info = x;

    if (root == NULL)
    {
        rt = temp; // Update the global root pointer
        return;
    }

    while (1)
    {
        if (temp->info > root->info)
        {
            if (root->right == NULL)
            {
                root->right = temp;
                return;
            }
            else
            {
                root = root->right;
            }
        }
        else
        {
            if (root->left == NULL)
            {
                root->left = temp;
                return;
            }
            else
            {
                root = root->left;
            }
        }
    }
}

void inorder(struct tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("\t%d", root->info);
        inorder(root->right);
    }
}

void preorder(struct tree *root)
{
    if (root != NULL)
    {
        printf("\t%d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct tree *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("\t%d", root->info);
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n\t1.Insert a node\n\t2.Pre-order traversal\n\t3.In-order traversal\n\t4.Post-order traversal\n\t5.Exit\n");
        printf("Enter a choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insrt();
            break;
        case 2:
            preorder(rt);
            break;
        case 3:
            inorder(rt);
            break;
        case 4:
            postorder(rt);
            break;
        case 5:
            exit(0); // Use exit(0) to exit the program gracefully
            break;
        default:
            printf("Invalid choice....");
        }
    }
    return 0;
}
