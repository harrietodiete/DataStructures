/* Harriet Odiete
*  Doubly Linked List Data Struture for Student
*/
#include "linkedList.h"

Student * createList(){
    Student * list = NULL;
    return list;
}

Student * createStudent(int id, char * name){
    Student * newStudent = malloc(sizeof(Student));
    newStudent->name = malloc(sizeof(char)*(strlen(name)+1));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->prev = NULL;
    newStudent->next = NULL;
    return newStudent;
}

void destroyList(Student ** list){
    Student * temp = NULL;
    if(isEmpty(*list) == true){
        printf("The list is empty, nothing to destroy.\n");
    }
    else{
        while(*list != NULL){
            temp = *list;
            *list = (*list)->next;
            destroyStudent(temp);
        }
    }
}

void destroyStudent(Student * info){
    free(info->name);
    free(info);
}

bool isEmpty(Student * list){
    if(list == NULL){
        return true;
    }
    return false;
}

int length(Student * list){
    int length = 0;
    Student * temp = list;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void addToFront(Student ** list, int id, char * name){
    Student * toBeAdded = createStudent(id, name);
    if(isEmpty(*list) == true){
        *list = toBeAdded;
        (*list)->prev = NULL;
        (*list)->next = NULL;
    }
    else{
        (*list)->prev = toBeAdded;
        toBeAdded->next = (*list);
        *list = toBeAdded;
    }
}

void addToBack(Student ** list, int id, char * name){
    Student * toBeAdded = createStudent(id, name);
    Student * temp = *list;
    if(isEmpty(temp) == true){
        temp = toBeAdded;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = toBeAdded;
        toBeAdded->prev = temp;
    }
}
 
Student * removeFromFront(Student ** list){
    Student * removed = *list;
    if(isEmpty(*list) == true){
        printf("The list is empty, no head to remove.\n");
        return NULL;
    }
    else{
        (*list)->next->prev = NULL;
        *list = (*list)->next;
    }
    return removed;
}

Student * removeFromBack(Student ** list){
    Student * temp = *list;
    Student * removed = NULL;
    if(isEmpty(temp) == true){
        printf("The list is empty, no tail to remove.\n");
        return NULL;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        removed = temp;
        temp->prev->next = NULL;
        temp = temp->prev;
    }
    return removed;
}

Student * getHead(Student ** list){
    Student * head = *list;
    if(isEmpty(head) == true){
        printf("The list is empty, no head to return.\n");
        return NULL;
    }
    printf("%s, %d\n", head->name, head->id);
    return head;
}

void printList(Student ** list){
    Student * temp = *list;
    if(isEmpty(temp) == true)
    {
        printf("List is empty\n");
    }
    else{
        while(temp != NULL){
            printf("%s, %d\n", temp->name, temp->id);
            temp = temp->next;
        }
    }
}


