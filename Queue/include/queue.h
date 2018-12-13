/* Harriet Odiete
*  Queue Data Struture
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queueNode{
   int num;
   struct queueNode * next;
}Queue;

int length;

Queue * createQueue();

Queue * initNode(int num);

void destroyQueue(Queue ** que);

bool isEmpty(Queue * que);

int getLength(Queue * que);

void enqueue(Queue ** que, int num);

int dequeue(Queue ** que);

int front(Queue * que);


