#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct dlnode{
	int data;
	struct dlnode *next;
	struct dlnode *prev;
}dlnode;

typedef struct ndlst{
	dlnode *head;	//points to the first element otherwise NULL
	dlnode *tail;	//points to the last element otherwise NULL
	int len;	// number of elements
}ndlst;

//Pre: None
//Post: Creates a null list
ndlst *dlistCreate(void){
	ndlst *ret = malloc(sizeof(ndlst));
	ret->head = NULL;
	ret->tail = NULL;
	ret->len = 0;
	return ret;
}

//Pre: lst is a valid list ( even null )
//Post: Destroys the list
void dlistDestroy(ndlst *lst){
	dlnode *current = lst->head;

	while (current != NULL){
		dlnode *next = current->next;
		free(current);
		current = next;
	}
	free(lst);
}

//Pre: lst is valid
//Post: returns the number of elements in the list
int dlistLength(ndlst *lst){
	return lst->len;
}

//Pre: lst is a valid list with length of at least n
//Post: nth item removed
void dlistRemoveElem(ndlst *lst, int n){
	//three different cases, one where n is head, n is tail, and n is in the middle
    dlnode *current = lst->head;

    for (int i = 1; i < n; i++) {
        current = current->next;
    }

    if (current->prev == NULL) {
        lst->head = current->next;
    } else {
        current->prev->next = current->next;
    }

    if (current->next == NULL) {
        lst->tail = current->prev;
    } else {
        current->next->prev = current->prev;
    }

    free(current);
    lst->len--;
}

// lst is a valid list
void dlistAddToFront(ndlst *lst, int elem){
    dlnode *newNode = malloc(sizeof(dlnode));
    newNode->data = elem;
    newNode->prev = NULL;
    newNode->next = lst->head;

    if (lst->head == NULL) {
        lst->tail = newNode;
    } else {
        lst->head->prev = newNode;
    }

    lst->head = newNode;
    lst->len++;	
}

// lst is a valid list
void dlistAddToEnd(ndlst *lst, int elem){
    dlnode *newNode = malloc(sizeof(dlnode));
    newNode->data = elem;
    newNode->next = NULL;
    newNode->prev = lst->tail;

    if (lst->tail == NULL) {
        lst->head = newNode;
    } else {
        lst->tail->next = newNode;
    }

    lst->tail = newNode;
    lst->len++;	
}

// //Pre: lst is valid
// //prints the items in the list from start to end.
// void dlistPrint(ndlst *lst){
// 	dlnode *node = lst->head;
// 	// iterate over the nodes (items) until node is NULL 
// 	// and print the data
// 	for (; node; node = node->next)
// 		printf("%d  ", node->data);
// 	printf("\n");
// }

// void dlistPrintReverse(ndlst *lst){
// 	dlnode *node = lst->tail;
// 	// iterate over the nodes (items) until node is NULL 
// 	// and print the data
// 	for (; node; node = node->prev)
// 		printf("%d  ", node->data);
// 	printf("\n");
// }

void dlistSort(ndlst *lst){
    if (lst->len > 1) {
        int swapped;
        do {
            swapped = 0;
            dlnode *current = lst->head;
            while (current->next != NULL) {
                if (current->data > current->next->data) {
                    // Swap data
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = 1;
                }
                current = current->next;
            }
        } while (swapped);
    }

}

// rotate the list n times to the left, assume, list not empty
void dlistRotateLeft(ndlst *lst, int n){
    dlnode *current = NULL;

    for(int i=0 ; i<n ; i++){
        current = lst->head;
        lst->head = current->next;
        lst->head->prev = NULL;

        lst->tail->next = current;
        current->prev = lst->tail;
        current->next = NULL;

        lst->tail = current;
    }

}

// rotate the list n times to the right, assume, lst not empty
void dlistRotateRight(ndlst *lst, int n){
    dlnode *current = NULL;

    for(int j=0 ; j<n ; j++){
        current = lst->tail;
        lst->tail = current->prev;
        lst->tail->next = NULL;

        current->next = lst->head;
        lst->head->prev = current;
        lst->head = current;
        current->prev = NULL;
    }
    
}

// int main(void){
// 	ndlst *lst1 = dlistCreate();
// 	assert(dlistLength(lst1) == lst1->len);
// 	assert(dlistLength(lst1) == 0);
// 	dlistAddToEnd(lst1, 10);
// 	dlistAddToFront(lst1, -20);
// 	dlistAddToFront(lst1, 0);
// 	dlistAddToEnd(lst1, 9);
// 	dlistAddToFront(lst1, -9);
// 	dlistAddToFront(lst1, 7);
// 	dlistAddToEnd(lst1, 40);
// 	assert(dlistLength(lst1) == lst1->len);
// 	assert(dlistLength(lst1) == 7);
// 	dlistPrint(lst1);
// 	dlistPrintReverse(lst1);
// 	dlistRemoveElem(lst1, 5);
// 	dlistRemoveElem(lst1, 1);
// 	dlistRemoveElem(lst1, 5);
// 	dlistAddToEnd(lst1, 100);
// 	assert(dlistLength(lst1) == lst1->len);
// 	assert(dlistLength(lst1) == 5);
// 	dlistPrint(lst1);
// 	dlistPrintReverse(lst1);
// 	dlistSort(lst1);
// 	dlistPrint(lst1);
// 	dlistRotateLeft(lst1, 2);
// 	dlistPrint(lst1);         
// 	dlistRotateRight(lst1, 3);
// 	dlistPrint(lst1);         
// 	dlistDestroy(lst1);

//     // should add more tests
// 	return 0;
// }
