#include "queue.h"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int main(int argc, char * argv[])
{
    /* code */
    int num[10] =  {76, 32, 45, 33, 67, 12, 98, 6, 45, 56};
    int i=0;
    int firstNum = 0;
    int head = 0;
    int size = sizeof(num)/sizeof(num[0]);
    Queue * que = NULL;
    printf("Queue test begins\n");
    printf("Testing create queue function...\n");
    que = createQueue();
    if(que == NULL){
        printf("%screateQueue() Test successful%s\n", GREEN, RESET);
    }
    else{
        printf("%screateQueue() Test successful%s\n", RED, RESET);
        printf("Test cannot be continued. Ending test\n");
        exit(1);
    }

   printf("Adding %d items to the queue\n", size);
    for(i=0; i<size; i++){
        enqueue(&que, num[i]);
    }
    printf("Checking to see if items were added to the queue...\n");
    if(getLength(que) == 10){
        printf("%senqueue() Test successful%s\n", GREEN, RESET);
    }
    else{
        printf("%senqueue() Test failed%s\n", RED, RESET);
    }
    
    printf("Testing dequeue function...\n");
    firstNum = dequeue(&que);
    if(firstNum == 76){
        printf("%sdequeue() Test successful%s\n", GREEN, RESET);
    }
    else{
        printf("%sdequeue() Test failed%s\n", RED, RESET);
    }

    printf("The current length of the queue is 9? ");
    if(getLength(que) == 9){
        printf("%sYES%s\n", GREEN, RESET);
    }
    else{
        printf("%sNO%s\n", RED, RESET);
    }

    printf("The current number in front of the queue is 32? ");
    head = front(que);
    if(head == 32){
        printf("%sYES%s\n", GREEN, RESET);
    }
    else{
        printf("%sNO%s\n", RED, RESET);
    }
    printf("Testing destroy queue function...\n");
    destroyQueue(&que);
    if(que == NULL){
        printf("%sdestroyQueue() Test successful%s\n", GREEN, RESET);
    }
    else{
        printf("%sdestroyQueue() Test failed%s\n", RED, RESET);
    }
    return 0;
}
