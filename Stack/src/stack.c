/* Harriet Odiete
*  Linked List Struture for student
*/
#include "stack.h"

Stack * createStack(){
    Stack * newStack = NULL;
    length = 0;
    return newStack;
}

Stack * initNode(int num){
    Stack * newNode = malloc(sizeof(Stack));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
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

void push(Stack ** myStack, int element){
    Stack * newNode = initNode(element);
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

int pop(Stack ** myStack){
    int num;
    Stack * removeNode = *myStack;
    if(isEmpty(*myStack) == true){
        printf("The stack is empty, nothing to pop.\n");
        return -1;
    }
    else{
        num = removeNode->num;
        *myStack = (*myStack)->next;
        free(removeNode);
    }
    length--;
    return num;
}

int peek(Stack * myStack){
    Stack * top;
    if(isEmpty(myStack) == true)
    {
        printf("The stack is empty, nothing at top.\n");
        return -1;
    }
    else{
        top  = myStack;
    }
    return top->num;
}



