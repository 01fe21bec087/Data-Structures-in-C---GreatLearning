/*
Author: Abhinav Sushil Pawar
Date: 20/05/2023
*/
//stack ==> LIFO
//O(1)
//create(),push(),pop(),peek()
#include<stdio.h>
#include<stdlib.h>      //for INT_MIN
#define MAX 100         //array size
struct Stack
{
    int top;
    unsigned size;
    int* arr;
};
typedef struct Stack STACK;

STACK* create(unsigned size)
{
    STACK* stack=(STACK*)malloc(sizeof(STACK));
    if(stack==NULL)
    {
        printf("Stack creation error...\n");
        return;
    }
    printf("Stack created successfully...\n");
    stack->size=size;
    stack->top=-1;
    stack->arr=(int*)malloc(stack->size*sizeof(int));   //allocate memory for array => sizeof array * sizeof data element in array
    return stack;
}

int isFull(STACK* stack)        //overflow condition
{
    if(stack->top == stack->size-1) //1 ==> overflow
    {
        printf("Stack is full\n");
        return 1;
    }
    else
        return 0;
}

int isEmpty(STACK* stack)       //Underflow
{
    if(stack->top == -1)
    {
        printf("Stack is empty\n");
        return 1;
    }
    else
        return 0;
    //return (stack->top == -1);   //1 ==> underflow
}

void push(STACK* stack,int item)    //add an element to stack
{
    if(isFull(stack))      //check overflow condition
        return;
    stack->arr[++stack->top]=item;
    printf("%d pushed; top=%d\n",stack->arr[stack->top],stack->top);
}

int pop(STACK* stack)       //remove the top element
{
    if(isEmpty(stack))     //check underflow condition
        return -1;
    int buffer=stack->arr[stack->top];
    stack->top--;
    printf("%d popped; top=%d\n",buffer,stack->top);
    return buffer;
}

int peek(STACK* stack)      //get the top element
{
    if(isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top];
}

void main()
{
    STACK* stack=create(MAX);
    push(stack,10);
    push(stack,20);
    push(stack,50);
    printf("top ==> %d\n",stack->top);
    pop(stack);
    pop(stack);
    //(isEmpty(stack)==-1)? printf("Empty\n") : printf("Not empty\n");
}
