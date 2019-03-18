
#ifndef STRUCT_H
#define STRUCT_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* element listy */
typedef struct Element {
   int value;
   struct Element* next;
 } Element;

typedef struct List {
    Element* start;
} List;

/* Tworzenie elementu listy */
Element* createElement(int value);
int findTRANS(List* list, int value);
int findMTF(List* list, int value);
void delete(List* list, int value);
void insert(List* list, int value, int a);
List* createList();

#endif
