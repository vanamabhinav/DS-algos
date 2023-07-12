#include<stdio.h>
#include<stdlib.h>
// create a node which contains data and pointer next

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNodeFirst(int data) {
    struct Node* newNode = createNode(data);

    // Assign the next pointer of the newly created node to head

    newNode->next = head;
    
    // Move the head to point to the newly created Node
    head = newNode;
    return head;
}

void addNodeLast(int data) {
    //create another node by newNode 
    //assign the data and next pointer will point to null
    // take another pointer as ptr and by using while loop traversing till the last node
    // last node next pointer should point to newNode adress


    // create..
    // assign..
    // assign the next of last node to the new node - get the last node by traversing the linked list

    struct Node* newNode = createNode(data);

    if (head==NULL){
        newNode->next=head;
    }
    else {
        struct Node* pointer = head;
        while(pointer->next!=NULL){
            pointer=pointer->next;
        }
        pointer->next = newNode;
        return head;  

    }


}

struct Node* printList(head){
    //print the data of each node by traversing through the linked list
    struct Node* pointer = head;
    while(pointer->next != NULL){
        printf(" %d ,",pointer->data);
        pointer = pointer->next;
    }    
}

void addNodeAt(int data,int index){

    struct Node* newNode= createNode(data);
    struct Node* pointer = head;
    int i = 0;
    while(i!= index ){
        pointer=pointer->next;      
        i++;
    }
    pointer->next = newNode->next;
    newNode->next = pointer->next->next;
    return head;   
}

void deleteFirst(){
    struct Node* pointer = head;
    head = head->next;
    free(pointer);
   return head;
}

void deleteLast(){
    struct Node* pointer = head;
    struct Node* previousPointer;
    // if the list as only one node, head will become NULL 
    if (head==NULL){
        printf("\n  Linked list empty , nothing to delete");
    }
    if (pointer->next = NULL){
        head = NULL;
        return;
    }
    else{
        while(pointer->next != NULL){
            previousPointer=pointer;
            pointer = pointer->next;
        }
        previousPointer->next = NULL;
        free(pointer);
        return head;
    }
}

void deleteAt( int index){
    struct Node* pointer = head;
    int i=0;
    while(i!= index-1){
        pointer=pointer->next;
        i++;
    }
    struct Node* pointer2 = pointer->next;
    pointer->next = pointer2->next;
    free(pointer2);
    return head;
}

void updateAt(int data, int index){
    struct Node* pointer = head;
    int i=0;
    while(i!= index){
        pointer = pointer->next;
        i++;
    }
    pointer->data=data;
    return head;
}





// addNodeAt(int pos) 
// print               
// deleteAt()
// updateAt
// deleteFirst
// deleteLast
// Arrays vs Linked List

void main(){
   
   // addNodeFirst(2);
    //addNodeFirst(12);
    
}