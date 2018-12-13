/* Harriet Odiete
*  Stack Data Structure Implementation
*/
#include "stack.h"

Stack * createStack(){
    Stack * newStack = NULL;
    length = 0;
    return newStack;
}

Node * initNode(char ch, int x, int y){

    Node * node = malloc(sizeof(Node));
    node->ch = ch;
    node->x = x;
    node->y = y;
    node->visited = false;
    return node;
}

Stack * createStackNode(Node * node){
    Stack * stackNode = malloc(sizeof(Stack));
    stackNode->block = malloc(sizeof(Node));
    stackNode->block->ch = node->ch;
    stackNode->block->x = node->x;
    stackNode->block->y = node->y;
    stackNode->block->visited = true;
    stackNode->next = NULL;
    return stackNode;
}

void destroyStack(Stack ** myStack){
    if(isEmpty(*myStack) == true){
        printf("The stack is empty, nothing to destroy.\n");
    }
    else{
        while(*myStack != NULL){
            Stack * temp = *myStack;
            pop(&temp);
            *myStack = (*myStack)->next;
        }
    }
}

bool isEmpty(Stack * myStack){
    if(myStack == NULL){
        return true;
    }
    return false;
}

int getLength(Stack * myStack){
    return length;
}

void push(Stack ** myStack, Node * node){
    Stack * newNode = createStackNode(node);
    if(isEmpty(*myStack) == true)
    {
        *myStack = newNode;
    }
    else{
        newNode->next = *myStack;
        *myStack = newNode;
    }
    length++;
}

Node * pop(Stack ** myStack){
    Node * point;
    Stack * removeNode = *myStack;
    if(isEmpty(*myStack) == true){
        printf("The stack is empty, nothing to pop.\n");
        return NULL;
    }
    else{
        point = removeNode->block;
        *myStack = (*myStack)->next;
        free(removeNode);
    }
    length--;
    return point;
}

Node * peek(Stack * myStack){
    Stack * top;
    if(isEmpty(myStack) == true)
    {
        printf("The stack is empty, nothing at top.\n");
        return NULL;
    }
    else{
        top  = myStack;
    }
    return top->block;
}



