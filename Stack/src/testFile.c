#include "stack.h"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

/*Function prototypes*/
void pop_fullTest(Stack ** list);
void push_basicTest(Stack ** list);
int stackLength_basicTest(Stack * list);

int main(int argc, char * argv[])
{
    /*Structures and Variables declaration*/
    Stack * head;
    int myArray[10] = {9, 13, 28, 56, 80, 5, 8, 14, 67, 87};
    int size = sizeof(myArray)/sizeof(myArray[0]);
    int i = 0;
    int top = 0;
    int length = 0;

    printf("Stack test begins\n");
    printf("Testing create stack function...\n");

    head = createStack();
    if(head == NULL){
        printf("%screateStack() Test successful%s\n", GREEN, RESET);
    }
    else{
        printf("%screateStack() Test failed%s\n", RED, RESET);
        printf("Test cannot be continued. Ending test\n");
        exit(1);
    }
    printf("Adding %d items to the stack\n", size);
    /*Testing the Push function*/
    for(i=0; i<size; i++)
    {
        push(&head, myArray[i]); /*Calling Push function*/
    }
    
    if(isEmpty(head) == false && getLength(head) == 10 && peek(head) == 87){
        printf("%spush() Test successful%s\n", GREEN, RESET);
    }
    else{
        printf("%spush() Test failed%s\n", RED, RESET);
        printf("Test cannot be continued. Ending test\n");
        exit(1);
    }

    printf("Is the top of the stack = 87? ");
    top = peek(head);
    if(top == 87)
    {
        printf("%sYES\n%s", GREEN, RESET);
    }
    else
    {
        printf("%sNO\n%s", RED, RESET);
        printf("%s!ERROR:%s peek() function failed\n", RED, RESET);
        printf("Test cannot be continued. Ending test\n");
        exit(1);
    }
    printf("end of creating and adding elements to the stack test\n");
    pop_fullTest(&head);
    push_basicTest(&head);
    length = stackLength_basicTest(head);

    printf("Testing destroy queue function...\n");
    destroyStack(&head);
    if(head == NULL){
        printf("%sdestroyStack() Test successful%s\n", GREEN, RESET);
    }
    else{
        printf("%sdestroyStack() Test failed%s\n", RED, RESET);
    }
    printf("End of Stack test\n");
    return 0;
}
/*Function definitions*/
/*This test checks to ensure that the Pop function in the stack ADT removes the correct element meaning it removes 
the top element of the stack and returns the removed element thereby decreasing the size of the stack*/
void pop_fullTest(Stack ** list)
{
    int popped;
    printf("pop_fullTest begin\n");
    printf("     Removing elements until the top is at 80...\n");
    printf("     Calling Pop function\n");
    while(peek(*list) != 80)
    {
        popped = pop(list);
        printf("     Popped: %d\n", popped);
    }
    printf("     Is the new top = 80? ");
    if(peek(*list) == 80)
    {
        printf("%sYES\n%s", GREEN, RESET);
    }
    else
    {
        printf("%sNO\n%s", RED, RESET);
        printf("     %s!ERROR:%s pop() function failed\n", RED, RESET);
        printf("Test cannot be continued. Ending test\n");
        exit(1);
    }
    printf("end pop_fullTest\n");
}

/*This test checks to ensure that an element can be added to the top of the stack after one has been removed thereby also increasing the size of elements in the stack*/
void push_basicTest(Stack ** list)
{
    printf("push_basicTest begin\n");
    printf("     Adding the number 23 to the existing stack...\n");
    printf("     Calling Push function\n");
    push(list, 23);
    printf("     Is the new top = 23? ");
    if(peek(*list) == 23)
    {
        printf("%sYES\n%s", GREEN, RESET);
    }
    else
    {
        printf("%sNO\n%s", RED, RESET);
        printf("     %s!ERROR:%s push() failed\n", RED, RESET);
        printf("Test cannot be continued. Ending test\n");
        exit(1);
    }
    printf("end push_basicTest\n");
}

/*This test checks to ensure that the stack ADT counts the number of elements in the stack correctly and returns the 
length of the stack*/
int stackLength_basicTest(Stack * list)
{
    int length = 0;
    printf("stackLength_basicTest begin\n");
    printf("     Counting the number of elements in the stack...\n");
    printf("     Calling stackLength function\n");
    length = getLength(list);
    printf("     Is the number of elements in the stack = 6? ");
    if(length == 6)
    {
        printf("%sYES\n%s", GREEN, RESET);
    }
    else
    {
        printf("%sNO\n%s", RED, RESET);
        printf("     %s!ERROR:%s getLength() function failed\n", RED, RESET);
        printf("Test cannot be continued. Ending test\n");
        exit(1);
    }
    printf("end stackLength_basicTest\n");
    return length;
}
