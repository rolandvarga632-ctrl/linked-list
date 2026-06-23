#include "llist.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>



int main() {

	// init lista
	List *lista = malloc(sizeof(List));
	Init_Linked_List(lista);

	// add 3 int and print the list
	list_push(lista,(void *)(intptr_t)30);
	list_push(lista,(void *)(intptr_t)20);
	list_push(lista,(void *)(intptr_t)40);
	print_list(lista);

	// pop an element and add another 2
	int unit = (int)(intptr_t)list_pop(lista,1);
	list_push(lista,(void *)(intptr_t)50);
	list_push(lista,(void *)(intptr_t)60);
	printf("\n");
	printf("removed element= %d\n", unit);
	printf("\n");
	print_list(lista);

	// free all nodes in list and free list
	freenodes(lista);
	free(lista);
		
	return 0;
}
