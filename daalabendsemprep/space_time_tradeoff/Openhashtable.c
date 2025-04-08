#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

struct Node{
    int key;
    struct Node* next;
};

struct Node* hashtable[TABLE_SIZE];

int hashfunction(int key){
    return key % TABLE_SIZE;
}

void insert(int key){
    int index = hashfunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashtable[index];
    hashtable[index] = newNode;
}
void display(){
    for(int i=0; i<TABLE_SIZE; i++){
        printf("Index %d: ", i);
        struct Node* temp = hashtable[i];
        while(temp){
            printf("%d ->", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int search(int key){
    int index =  hashfunction(key);
    struct Node* temp = hashtable[index];
    while(temp){
        if(temp->key == key){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main(){
    for(int i=0; i<TABLE_SIZE; i++){
        hashtable[i] = NULL;
    }
    insert(15);
    insert(25);
    insert(35);
    insert(5);
    insert(34);

    printf("HASH TABLE");

    display();
}