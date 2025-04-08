#include<stdio.h>
#include<stdlib.h>

#define EMPTY -1
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

int hashFunction(int key){
    return key % TABLE_SIZE;
}

void insert(int key){
    int index = hashFunction(key);
    int startindex = index;

    while(hashTable[index] != EMPTY){
        index = (index + 1) % TABLE_SIZE;

        if(index == startindex){
            printf("TABLE FULL");
            return;
        }
    }
    hashTable[index] = key;
}
void display(){
    for(int i=0; i<TABLE_SIZE; i++){
        if(hashTable[i] != EMPTY){
            printf("Index %d: %d\n", i, hashTable[i]);
        }else{
            printf("Index %d: EMPTY\n", i);
        }
    }
}
int search(int key){
    int index = hashFunction(key);
    int startindex = index;

    while(hashTable[index] != EMPTY){
        if(hashTable[index] == key){
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if(index == startindex){
            break;
        }
    }
    return -1;
}
int main(){
    for(int i=0; i<TABLE_SIZE; i++){
        hashTable[i] = EMPTY;
    }
    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);

    printf("Closed Hash Table(Linear Probing)");
    display();

    

}