#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct Stack
{
    int top;
    unsigned capacity;
    int* array;
}Stack;


//in danh sach
void print(Stack * stack);
//khoi tao stack voi so luong phan tu
Stack* createStack(unsigned capacity);
//kiem tra xem co full khong
int Full(Stack* stack);
//kiem tra stack co trong khog
int Empty(Stack* stack);
//push
void push(Stack* stack, int item);
//pop va tra ve gia tri
int pop(Stack* stack);
//peek hien thi phan tu top
int peek(Stack* stack);



void print(Stack * stack){
    printf("in danh sach:\n");
    for(int i=0;i<=stack->top;i++){
        printf("%d ",stack->array[i]);
    }
    printf("\n");
}

Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
 
 
int Full(Stack* stack)
{   return stack->top == stack->capacity - 1; }
 
int Empty(Stack* stack)
{   return stack->top == -1;  }
void push(Stack* stack, int item)
{
    if (Full(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(Stack* stack)
{
    if (Empty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
int peek(Stack* stack)
{
    if (Empty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
// int main()
// {
//     Stack* stack = createStack(100);
 
//     push(stack, 14);
//     push(stack, 25);
//     push(stack, 38);
//     push(stack, 48);
//     print(stack);
//     printf("%d popped from stack\n", pop(stack));
//     print(stack);
//     printf("Top item is %d\n", peek(stack));
//     print(stack);
//     return 0;
// }

 