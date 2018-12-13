/* Harriet Odiete
*  Linked List Struture for student
*/
#include "queue.h"

Queue * createQueue(){
    Queue * newQueue = NULL;
    length = 0;
    return newQueue;
}

Queue * initNode(int num){
    Queue * newNode = malloc(sizeof(Queue));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void destroyQueue(Queue ** que){
    if(isEmpty(*que) == true){
        printf("The queue is empty, nothing to destroy.\n");
    }
    else{
        while(*que != NULL){
            Queue * temp = *que;
            dequeue(&temp);
            *que = (*que)->next;
        }
    }
}

bool isEmpty(Queue * que){
    if(que == NULL){
        return true;
    }
    return false;
}

int getLength(Queue * que){
    return length;
}

void enqueue(Queue ** que, int num){
    Queue * newNode = initNode(num);
    if(isEmpty(*que) == true){
        *que = newNode;
    }
    else{
        Queue * temp = *que;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    length++;
}

int dequeue(Queue ** que){
    int num;
    Queue * removeNode = *que;
    if(isEmpty(*que) == true){
        printf("The queue is empty, nothing to dequeue.\n");
        return -1;
    }
    else{
        num = removeNode->num;
        *que = (*que)->next;
        free(removeNode);
    }
    length--;
    return num;
}

int front(Queue * que){
    Queue * top;
    if(isEmpty(que) == true)
    {
        printf("The queue is empty, nothing at the front.\n");
        return -1;
    }
    else{
        top  = que;
    }
    return top->num;
}


