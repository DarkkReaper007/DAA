#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key; 
    int height;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int key){
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(Node* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

int getBalance(Node* node){
    if(node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

void updateHeight(Node* node){
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if(leftHeight > rightHeight){
        node->height = leftHeight + 1;
    }else{
        node->height = rightHeight + 1;
    }
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* balanceNode(Node* node){
    updateHeight(node);
    int balance = getBalance(node);

    if(balance > 1){
        if(getBalance(node->left) < 0){
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    }

    if(balance < -1){
        if(getBalance(node->right) > 0){
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    return node;
}

Node* insertIterative(Node* root, int key){
    if(root == NULL){
        return createNode(key);
    }

    Node* stack[100];
    int top = -1;

    Node* current = root;
    Node* parent = NULL;

    while(current != NULL){
        parent = current;
        stack[++top] = current;

        if(key < current->key){
            current = current->left;
        }else if(key > current->key){
            current = current->right;
        }else{
            return root;
        }
    }

    Node* newNode =createNode(key);
    if(key < parent->key){
        parent->left = newNode;
    }else{
        parent->right = newNode; 
    }

    while(top >= 0){
        stack[top] = balanceNode(stack[top]);

        if(top > 0){
            if(stack[top - 1]->left == stack[top]){
                stack[top - 1]->left = stack[top];
            }else{
                stack[top - 1]->right = stack[top];
            }
        }
        top--;
    }
    return stack[0];
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
int main(){
    Node* root = NULL;
    int keys[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    for(int i=0; i<n; i++){
        root = insertIterative(root, keys[i]);
    }

    printf("Inorder traversal of AVL tree: \n");
    inorder(root);
    printf("\n");
    return 0;
}