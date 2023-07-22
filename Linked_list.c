#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
// create a node which contains data and pointer next

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc( sizeof(struct Node) );
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

    if(head == NULL) {
        newNode->next=head;
    } else {
        struct Node* pointer = head;
        while(pointer->next != NULL) {
            pointer=pointer->next;
        }
        pointer->next = newNode;
        return head;  
    }
}

struct Node* printList(struct Node* head) {
    //print the data of each node by traversing through the linked list
    struct Node* pointer = head;
    while(pointer->next != NULL){
        printf(" %d ,",pointer->data);
        pointer = pointer->next;
    }    
}

void addNodeAt(int data,int index) {

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

void deleteFirst(struct Node* head) {
    struct Node* pointer = head;
    head = head->next;
    free(pointer);
   return head;
}

void deleteLast(struct Node* head) {
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

void deleteAt( int index) {
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

void updateAt(int data, int index) {
    struct Node* pointer = head;
    int i=0;
    while(i!= index){
        pointer = pointer->next;
        i++;
    }
    pointer->data=data;
    return head;
}

struct Node* detectCycle(struct Node* head) {
    struct Node* fastPointer = head;
    struct Node* slowPointer = head;
    while(slowPointer && fastPointer && fastPointer->next) {
        fastPointer = fastPointer->next->next;
        slowPointer = slowPointer->next;
        if (slowPointer == fastPointer) {
            //printf("\n There is cycle detected in the list");
            return slowPointer;
        }
    }
    return NULL;
}

struct Node* getCycleStartNode(struct Node* head ) {
    if( detectCycle( head)) { 
        struct Node* entryPointer = head;
        struct Node* meetingPointer = detectCycle(head);
        while(entryPointer && meetingPointer) {
            entryPointer = entryPointer->next;
            meetingPointer = meetingPointer->next;
            if (entryPointer == meetingPointer) {
                printf("the entry node is %d",entryPointer->data);
                return 0;
            } 
        }
    }
     else {  
        printf("there is no cycle");
        //return NULL;
    }
}

struct Node* reverseList(struct Node* head) {
    struct Node* firstPointer = NULL;
    struct Node* secondPointer;
    if (head = NULL) {
        return NULL;
    }
    else {
        while(head != NULL)  {
            secondPointer = head->next; 
            head->next = firstPointer; // accessing the first node next to NULL
            firstPointer = head; //assigning the address of next node in current next
            head = secondPointer;//the head should traverse to the next node 
        }
        head = firstPointer;
        return head;

    }

}

struct Node* sortingList(struct Node* head) {
    struct Node* firstPointer = head;
    struct Node* secondPointer;
    int temporary_Variable;
    while(firstPointer->next != NULL) {
        secondPointer = firstPointer->next;
        while(secondPointer != NULL) {
            if ( firstPointer->data > secondPointer->data ) {
                temporary_Variable = secondPointer->data;
                secondPointer->data = firstPointer->data;
                firstPointer->data = temporary_Variable;
            }
            secondPointer = secondPointer->next;
        }
        firstPointer = firstPointer->next;
    }
    return head;
}

struct Node* mergeTwo_sortedlist(struct Node* head1,struct Node* head2) { // head1 and head2 are two sorted linked list
    struct Node* sortingPointer;
    if (head1 == NULL) {
        return head2;             
    }
    if (head2 == NULL) {
        return head1;
    }
    if ( head1->data <= head2->data) {
        sortingPointer = head1;
        head1 = sortingPointer->next;
    }
    else {
        sortingPointer = head2;
        head2 = sortingPointer->next;{
    }
    struct Node* new_head = sortingPointer;
    while(head1 && head2){
        if (head2->data <= head1->data){
            sortingPointer->next = head2;
            sortingPointer = head2;
            head2 = sortingPointer->next;
        }
        else {
            sortingPointer->next = head1;
            sortingPointer = head1;
            head1 = sortingPointer->next;
        }
    }
    if (head1 == NULL) {
        sortingPointer->next = head2;
    }
    if (head2 == NULL) {
        sortingPointer->next = head1;
    }
    return new_head;
}

struct Node* mergeK_Sortedlist(int numberof_lists, ...) {
    if (numberof_lists == 0) {
        return NULL;
    }
    va_list args;
    va_start ( args, numberof_lists );
    struct Node* new_head = va_arg(args, struct Node*); //the new_head heads to one of the list
    for (int i = 1; i < numberof_lists; i++) {          // the loop is iterated for the remaining no of lists
        struct Node* current_head = va_arg(args, struct Node*); // current_head heads to a remaining list and change the list for each iteratiom 
        new_head = mergeTwo_sortedlist(newhead, current_head);  // new_head is been merged with all the remaining lists 
    }
    va_end(args);
    return newhead;
}



    


// addNodeAt(int pos) 
// print               
// deleteAt()
// updateAt
// deleteFirst
// deleteLast
// Arrays vs Linked List

