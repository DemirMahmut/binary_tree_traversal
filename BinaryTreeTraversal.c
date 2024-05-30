#include <stdio.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void postOrder(struct Node *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d\n", node->data);
    }
}

void inOrder(struct Node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d\n", node->data);
        inOrder(node->right);
    }
}

void preOrder(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d\n", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main()
{
    struct Node *root = createNode(1); /*    1    */
    root->left = createNode(2);        /*   / \   */
    root->right = createNode(3);       /*  2   3  */
    root->left->left = createNode(4);  /* / \     */
    root->left->right = createNode(5); /*4   5    */
    printf("Preorder traversal\n");
    preOrder(root);
    printf("Inorder traversal\n");
    inOrder(root);
    printf("Postorder traversal\n");
    postOrder(root);
    return 0; 
}