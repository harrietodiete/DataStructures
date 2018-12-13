/* Harriet Odiete
*  Linked List Struture for student
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node
{
	char ch;
    int x;
    int y;
    bool visited;
    
}Node;

typedef struct StackNode{
   Node * block;
   struct StackNode * next;
}Stack;

int length;

Stack * createStack();

Node * initNode(char ch, int x, int y);

Stack * createStackNode(Node * node);

void destroyStack(Stack ** myStack);

bool isEmpty(Stack * myStack);

int getLength(Stack * myStack);

void push(Stack ** myStack, Node * node);

Node * pop(Stack ** myStack);

Node * peek(Stack * myStack);



