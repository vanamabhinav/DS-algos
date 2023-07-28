#include<stdio.h>
#include<stdlib.h>
struct stack{
int* array;
int top;
int size;
};

int isFull(struct stack* pointer) {
    if(pointer->top == pointer->size-1){
        return 1; 
    }
    return 0;
}

int isEmpty(struct stack* pointer) {
    if(pointer->top == -1){
        return -1;//assuming that -1 is not a valid element in stack
    }
    return 0;
}

void push(struct stack* pointer, int data) {
    if (isFull(pointer)) {
        printf("stack overflow");
        return;
    } 
    pointer->top++;
    pointer->array[pointer->top] = data; 
}

int pop(struct stack* pointer) {
    int data;
    if (isEmpty(pointer)) {
        printf("\n stack underflow");
        return -1;
    }
    int data = pointer->array[pointer->top];
    pointer->top--;
    return data;
    
}

int peek(struct stack* pointer,int i) {
    if (isEmpty(pointer)) {
        printf("stack is empty");
        return -1;
    } 
    return pointer->array[pointer->top -i+1];
}

void display(struct stack* pointer) {
    int i;
    for(i = pointer->top;i<=0;i--) {
        printf("\n Element at index %d is %d",i,pointer->array[i]);
    }
}
int main() {
    struct stack* stack = (struct stack*) malloc(sizeof(struct stack));
    stack->size = 8;
    stack->top = -1;
    stack->array = (int*) malloc(stack->size*(sizeof(int)));
    push(stack,12);
    push(stack,23);
    push(stack,24);
    push(stack,43);
    push(stack,65);
    push(stack,67);
    push(stack,01);
    push(stack,80);
    
}

