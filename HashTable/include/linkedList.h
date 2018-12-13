/* Harriet Odiete
*  Linked List Struture for student
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct studentInfo{
   int id;
   char * name;
   struct studentInfo * prev;
   struct studentInfo * next;
}Student;

Student * createList();

Student * createStudent(int id, char * name);

void destroyList(Student ** list);

void destroyStudent(Student * info);

bool isEmpty(Student * list);

int length(Student * list);

void addToFront(Student ** list, int id, char * name);

void addToBack(Student ** list, int id, char * name);

Student * removeFromFront(Student ** list);

Student * removeFromBack(Student ** list);

Student * getHead(Student ** list);

void printList(Student ** list);

