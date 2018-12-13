#include "linkedList.h"

int main(int argc, char * argv[])
{
    /* code */
    Student * list = NULL;
    Student * head;
    Student * getBack;
    Student * getFront;
    int ids[7] =  {84, 96, 12, 33, 91, 57, 28};
    char * names[7] = {"Mary", "John", "Kate", "Thomas", "Paul", "Sandra", "Louis"};
    int i=0;
    int size = sizeof(ids)/sizeof(ids[0]);
    printf("Testing create list function...\n");
    list = createList();
    if(list == NULL){
        printf("\033[0;32m createList() Test successful \033[0m \n");
    }
    else{
        printf("\033[0;31m createList() Test failed \033[0m \n");
    }

    printf("Adding %d items to the list \n", size);
    for(i=0; i<size; i++){
        addToFront(&list, ids[i], names[i]);
    }
    printf("Checking to see if items were added to list\n");
    if(length(list) == 7){
        printf("\033[0;32m length() Test successful \033[0m \n");
    }
    else{
        printf("\033[0;31m length() Test failed \033[0m \n");
    }
    
    printf("Testing remove from back function\n");
    getBack = removeFromBack(&list);
    if(getBack->id == 84 && strcmp(getBack->name, "Mary") == 0){
        printf("\033[0;32m removeFromBack() Test successful \033[0m \n");
    }
    else{
        printf("\033[0;31m removeFromBack() Test failed \033[0m \n");
    }

    printf("Checking to see if length of list is 6\n");
    if(length(list) == 6){
        printf("\033[0;32m length() Test successful \033[0m \n");
    }
    else{
        printf("\033[0;31m length() Test failed \033[0m \n");
    }

    printf("Testing remove from front function\n");
    getFront = removeFromFront(&list);
    if(getFront->id == 28 && strcmp(getFront->name, "Louis") == 0){
        printf("\033[0;32m removeFromFront() Test successful \033[0m \n");
    }
    else{
        printf("\033[0;31m removeFromFront() Test failed \033[0m \n");
    }

    printf("Checking to see if length of list is 5\n");
    if(length(list) == 5){
        printf("\033[0;32m length() Test successful \033[0m \n");
    }
    else{
        printf("\033[0;31m length() Test failed \033[0m \n");
    }

    printf("Getting the current head of the list\n");
    head = getHead(&list);
    if(head->id == 57 && strcmp(head->name, "Sandra") == 0){
        printf("\033[0;32m getHead() Test successful \033[0m \n");
    }
    else{
        printf("\033[0;31m getHead() Test failed \033[0m \n");
    }
    printf("Testing add to back of list function\n");
    addToBack(&list, 25, "Francis");

    printf("Checking to see if length of list is 6\n");
    if(length(list) == 6){
        printf("\033[0;32m Test successful \033[0m \n");
    }
    else{
        printf("\033[0;31m Test failed \033[0m \n");
    }
    printf("Printing list\n");
    printList(&list);

    printf("Destroying list\n");
    destroyList(&list);
    if(list == NULL){
        printf("\033[0;32m destroyList() Test successful \033[0m \n");
    }
    else{
        printf("\033[0;31m destroyList() Test failed \033[0m \n");
    }
    return 0;
}
