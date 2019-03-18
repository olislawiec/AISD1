
#include "struct.h"

/* licznik porownan */
int counter = 0;



List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->start = NULL;
    return list;
}

/* Tworzenie elementu listy */
Element* createElement(int value) {
    Element* element = (Element*)malloc(sizeof(Element));
    element->value = value;
    element->next = NULL;
    return element;
}

/* Wstawianie elementu do podanej listy o podanej wartosci */
void insert(List* list, int value, int a) {
    Element* elementToInsert = createElement(value);

    if (list->start == NULL) {
        list->start = elementToInsert;
        if (a)counter++;
        return;
    }

    Element* helper = list->start;
    while (helper->next != NULL) {
        helper = helper->next;
        if(a) counter++;
    }

    helper->next = elementToInsert;      
}

/* usuwanie danego elementu z danej listy */
void delete(List* list, int value) {
    if (list->start == NULL) {
        return;
    }

    if (list->start->value == value) {
        Element* helper = list->start->next;
        free(list->start);
        list->start = helper;
        return;
    }
   
    Element* previous = list->start;
    Element* next = previous->next;
    while (next != NULL) {
        if (next->value == value) {
            previous->next = next->next;
            free(next);
        }
        previous = next;
        next = next->next;
    }      
}

int isempty(List* list) {
    return list->start == NULL;
}

/* jesli znajdzie dany element w danej liscie przesuwa go na przod listy */
int findMTF(List* list, int value) {
    if (list->start == NULL) {
        counter++;
        return 0;
    } 

    if (list->start->value == value && list->start->next == NULL) {
        counter++;
        return 1;
    }

    if (list->start->value == value) {
        Element* tmp = list->start;
        list->start = tmp->next;
        
        Element* helper = list->start;
        while(helper->next != NULL) {
            helper = helper->next;
            counter++;
        }
        helper->next = tmp;
        tmp->next = NULL;
        return 1;
    }

    Element* previous = list->start;
    Element* next = previous->next;
    while (next != NULL) {
        counter++;
        if (next->value == value) {
            counter++;
            previous->next = next->next;

            Element* helper = previous;
            while (helper->next != NULL) {
                counter++;
                helper = helper->next;
            }
            helper->next = next;
            next->next = NULL;
            return 1;
        }
        next = next->next;
    }

    return 0;
}

/* jesli znajdzie dany element w danej liscie przesuwa go o jeden do przodu*/
int findTRANS(List* list, int value) {
    if (list->start == NULL) {
        counter++;
        return 0;
    } 

    if (list->start->value == value && list->start->next == NULL) {
        counter++;
        return 1;
    }

    if (list->start->value == value) {
        counter++;
        Element* temp = list->start;
        list->start = temp->next;
        temp->next = list->start->next;
        list->start->next = temp;
        return 1;
    }

    Element* previous = list->start;
    Element* next = previous->next;
    while (next != NULL) {
        counter++;
        if (next->value == value) {
            counter++;
            if (next->next == NULL) {
                counter++;
                previous->next = NULL;
                next->next = list->start;
                list->start = next;
                return 1;
            } else {
                previous->next = next->next;
                next->next = next->next->next;
                previous->next->next = next;
                return 1;
            }
        }
        previous = next;
        next = next->next;
    }
    return 0;
}

void showList(List* list) {
    Element* helper = list->start;
    if (helper == NULL) {
        return;
    }
    printf("%d ", helper->value);
    while (helper->next != NULL) {
        helper = helper->next;
        printf("%d ", helper->value);
    }
    printf("\n");
}

int main() {
     // List* list = createList();
     // showList(list);
	 // if(isempty(list))
		 // printf("jestpusta");
	 
     // insert(list, 5,1);
    //insert(list, 10);
   // insert(list, 15);
   // insert(list, 20);
     // insert(list, 25,1);
     // showList(list);
	 // if(isempty(list))
		 // printf("jestpusta");
	 
    // delete(list, 8);
    // showList(list);
    // delete(list, 5);
    // showList(list);
    // delete(list, 10);
    // showList(list);
    // delete(list, 20);
    // showList(list);
    // insert(list, 30);
    // showList(list);
    // delete(list, 30);
    // showList(list);
    // printf("\n");
    // insert(list, 5);
    // insert(list, 10);
    // showList(list);
    // findTRANS(list, 15);
    // showList(list);
    // findTRANS(list, 15);
    // showList(list);
    // findTRANS(list, 15);
    // showList(list);
    // findTRANS(list, 15);
    // showList(list);
    // insert(list, 50);
    // showList(list);
    // findMTF(list, 15);
    // showList(list);
    // findMTF(list, 5);
    // showList(list);

    List* list2 = createList();
    List* list3 = createList();
    srand(time(0));

    int whatWas[100];
    for (int i = 1; i <= 100; i++) {
        whatWas[i-1] = 0;
    }
    while(1) {
        int random = rand()%100 + 1;
        if (whatWas[random-1] == 0) {
            insert(list2, random, 1);
            insert(list3, random, 0);
            whatWas[random-1] = 1;
        } 
        
        int all = 1;
        for (int i = 0; i < 100; i++) {
            if (whatWas[i] == 0) {
                all = 0;
            }
        }
        if (all) {
            break;
        }
    }

    int c = counter;

    int max = 100;
    while (!isempty(list2)) {
		for(int i=0; i<100; i++){
			findMTF(list2,i+1);
		}
     //   if (findMTF(list2, max)) {
            delete(list2, max);
     //   }
        max--;
    }

     printf("mtf %d\n", counter + c);
     counter = 0;

    max = 100;
    while (!isempty(list3)) {
       for(int i=0; i<100; i++){ 
	findTRANS(list3, max);
	}
            delete(list3, max);
        
        max--;
    }

    printf("trans %d\n", counter + c);

    return 0;
}
