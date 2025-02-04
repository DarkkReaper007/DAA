#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find the Closest Common Ancestor (CCA)
struct Node* findCCA(struct Node* root, int n1, int n2) {
    if (root == NULL) 
        return NULL;

    // If either n1 or n2 matches with root's data, return root
    if (root->data == n1 || root->data == n2) 
        return root;

    // Look for n1 and n2 in left and right subtrees
    struct Node* leftCCA = findCCA(root->left, n1, n2);
    struct Node* rightCCA = findCCA(root->right, n1, n2);

    // If both left and right subtrees return non-null, root is the CCA
    if (leftCCA != NULL && rightCCA != NULL) 
        return root;

    // Otherwise, return the non-null subtree
    return (leftCCA != NULL) ? leftCCA : rightCCA;
}

// Driver code
int main() {
    // Creating the example binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    int n1 = 4, n2 = 5;
    struct Node* cca = findCCA(root, n1, n2);

    if (cca != NULL)
        printf("The Closest Common Ancestor of %d and %d is: %d\n", n1, n2, cca->data);
    else
        printf("No Common Ancestor found.\n");

    return 0;
}
