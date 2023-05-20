/*
Author: Abhinav Sushil Pawar
Date: 20/05/2023
*/
//FIFO
//O(1)
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
struct Queue        //skeleton
{
    int front,rear,size;
    unsigned capacity;
    int* array;
};
typedef struct Queue QUEUE;

QUEUE* create(unsigned capacity)
{
    QUEUE* queue=(QUEUE*)malloc(sizeof(QUEUE));
    if(queue==NULL)
    {
        printf("Queue creation error...\n");
        return;
    }
    queue->capacity=capacity;
    queue->front=queue->size=0;
    queue->rear=capacity-1;
    queue->array=(int*)malloc(queue->capacity*sizeof(int));
    return queue;
}

int isFull(QUEUE* queue)    //overflow
{
    if(queue->size==queue->capacity)
    {
        printf("Queue is full\n");
        return 1;
    }
    else
        return 0;
}

int isEmpty(QUEUE* queue)
{
    if(queue->size==0)
    {
        printf("Stack is empty\n");
        return 1;
    }
    else
        return 0;
}
void enqueue(QUEUE* queue,int item) //add element to queue
{
    if(isFull(queue))
        return;
    queue->rear=(queue->rear+1)%queue->capacity;        //helps to assign elements to empty locations before front
    queue->array[queue->rear]=item;
    queue->size=queue->size+1;
    printf("%d enqueued; front=%d, rear=%d, size=%d\n",item,queue->front,queue->rear,queue->size);
}

int dequeue(QUEUE* queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    int buffer=queue->array[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->size=queue->size-1;
    printf("%d dequeued; front=%d, rear=%d, size=%d\n",buffer,queue->front,queue->rear,queue->size);
    return buffer;
}

int getfront(QUEUE* queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
int getrear(QUEUE* queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

void main()
{
    QUEUE* queue=create(MAX);
    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);

    dequeue(queue);
    printf("front item=%d \n rear item=%d\n",getfront(queue),getrear(queue));
}
