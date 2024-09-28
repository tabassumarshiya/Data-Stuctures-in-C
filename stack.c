#include <stdint.h>
#include <stdio.h>

/*
Definition:
  Stack is a linear data structure that holds data of the same type 
  in LIFO(Last-In-First-Out) format
Functions:
  Below are functions to perform operations on the stack such as
  initializing, writing data, reading data, removing data from the stack 
  */
#define MAX_STACK_SIZE 50

/*Create the building block of stack; we need a fixed size array and a 
variable to keep track of the elements in the array */
typedef struct stack
{
  uint8_t data[MAX_STACK_SIZE];
  uint8_t top;
}stack;

/*Initialize the stack*/ 
void initialize(stack* st)
{
  st->top = -1;
}

/*Returns true if the stack is empty*/
bool is_empty(stack* st)
{
  return (st->top == -1);
}

/*Returns true is stack is full*/
bool is_full(stack* st)
{
  return (st->top == MAX_STACK_SIZE);
}

/*Insert data on the stack*/
uint8_t stack_push(stack* st, uint8_t data)
{
  //Check if stack is full, if yes return -1, else push data
  if(is_full(st))
  {
    printf("Cannot push data, stack is full!\n");
    return -1;
  }
  st->data[st->top++] = data;
}

/*Remove data from the stack*/
uint8_t stack_pop(stack* st)
{
  if(is_empty(st))
  {
    printf("Cannot pop stack, stack is empty!\n");
    return -1;
  }
  return st->data[st->top--];
}

/*Read data at the top of stack*/
uint8_t stack_peek(stack *st)
{
  if(is_empty(st))
  {
    printf("Cannot peek data, stack is empty!\n");
    return -1;
  }
  return st->data[st->top];
}




