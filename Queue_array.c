#include<stdio.h>
#include<stdlib.h>

struct queue {
    int* array;
    int size;
    int frontIndex;
    int backIndex;
};

int isEmpty(struct queue* queue) {
    if(queue->backIndex == queue->frontIndex) {
        return -1;
    }
    return 0;
}

int isFull(struct queue* queue) {
    if(queue->backIndex == queue->size - 1) {
        return 1;
    }
    return 0;
}

void enqueue(struct queue* queue, int data) {
    if(isFull(queue)) {
        printf("\n queue overflow ");
    }
    queue->backIndex++;
    queue->array[queue->backIndex] = data;
}

int dequeue(struct queue* queue) {

    if(isEmpty(queue)) {
        printf("\n queue is empty, we can't delete an element \n");
        return -1;
    }
    queue->frontIndex++;
    int data = queue->array[queue->frontIndex];
    return data;
}

int main() {
    struct queue* queue = (struct queue*) malloc(sizeof(struct queue));
    queue->backIndex = -1;
    queue->frontIndex = -1;
    queue->size = 20;
    queue->array = (int*) malloc(queue->size*sizeof(int));

    enqueue(queue,24);
    enqueue(queue,45);
    printf("%d", dequeue(queue));

}