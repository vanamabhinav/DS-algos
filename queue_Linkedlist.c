#include<stdio.h>
#include<stdlib.h>

struct queueNode {
    int data;
    struct queueNode* next;
};

struct queueNode* frontIndex = NULL;
struct queueNode* rearIndex = NULL;

struct queueNode* createNode(int data) {
    struct queueNode* new_node = (struct queueNode*) malloc(sizeof(struct queueNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct queueNode* isEmpty() {
    if(frontIndex == NULL && rearIndex == NULL) {
        return 1;
    }
    return 0;
}

void enqueue(int data) {
    struct queueNode* new_node = createNode(data);
    if(isEmpty()) {
        frontIndex = rearIndex =new_node;
    }
    rearIndex->next = new_node;
    rearIndex = new_node;
}
struct queueNode* dequeue() {
    struct queueNode* pointer = frontIndex;
    if(frontIndex == NULL) {
        printf("\n queue is empty ");
        return -1;
    }
    frontIndex = frontIndex->next;
    int data = pointer->data;
    //free(pointer)
    return data;
}

void printQueue() {
    if(isEmpty()) {
        printf("\n queue is empty");
    }
    struct queueNode* currentPointer = frontIndex;
    printf("\n the elements are :");
    while(currentPointer != NULL) {
        printf("\n %d",currentPointer->data);
        currentPointer = currentPointer->next;
    }
}

int main() {
    enqueue(34);
    enqueue(12);
    enqueue(2);
    enqueue(1);
    printf("the dequeueing element is %d", dequeue());
    printQueue();

}

