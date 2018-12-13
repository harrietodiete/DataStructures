/* Harriet Odiete
*  Linked List Struture for student
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode{
   int num;
   struct StackNode * next;
}Stack;

int length;

Stack * createStack();

Stack * initNode(int num);

void destroyStack(Stack ** myStack);

bool isEmpty(Stack * myStack);

int getLength(Stack * myStack);

void push(Stack ** myStack, int element);

int pop(Stack ** myStack);

int peek(Stack * myStack);



