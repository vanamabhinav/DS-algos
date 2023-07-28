#include<stdio.h>
#include<stdio.h>

struct stackNode{
    int data;
    struct stackNode* next;
}; 

typedef struct stackNode stackNode;

stackNode* top = NULL;

stackNode* createNode(int data) {
    stackNode* new_node = (stackNode*) malloc(sizeof(stackNode));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

stackNode* isEmpty(stackNode* top) {    
   if( top ==NULL ) {
    return 1;
   }
   return 0;
}
    

stackNode* push(int data) {
    stackNode* new_node = createNode(data);
    new_node->next = top;
    top = new_node;
    return top;
}

stackNode* pop( stackNode* top) {
    if(isEmpty(top)) {
        printf("\n stack underflow");
        return -1;    //assuming that -1 is not a valid element in stack
    }
    stackNode* node = top;
    top = top->next;
    //int data = node->data;
    //free(node)
    //return data
    return top;
}

stackNode* peek(stackNode* top, int index) {
    if (isEmpty(top)) {
        printf("stack is empty");
        return -1;
    } 
    int i;
    for(i = 0; (i<=index-1 && top!=NULL);i++ ) {
        top = top->next;
    }
    return top->data;  
}

stackNode* display(stackNode* top) {
    if(isEmpty(top)) {
        printf("\n stack is empty,stack underflow");
        return -1; 
    }
    printf("\n the elements are");
    while(top != NULL) {
        printf("\n  %d",top->data);
        top = top->next;
    }
}

int main() {
    push(12);
    push(34);
    push(45);
    push(50);
    push(65);
    printf("the element is %d", peek(top,2));
    display(top);

}
