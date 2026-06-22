#include "llist.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>



int main() {
	List *lista = malloc(sizeof(List));
	Init_Linked_List(lista);

	list_push(lista,(void *)(intptr_t)30);
	list_push(lista,(void *)(intptr_t)20);
	list_push(lista,(void *)(intptr_t)40);
	print_list(lista);
	int unit = (int)(intptr_t)list_pop(lista,1);
	list_push(lista,(void *)(intptr_t)50);
	list_push(lista,(void *)(intptr_t)60);

	printf("Elements(selected)\n");
	printf("%d\n",unit);
	printf("----------\n");
	printf("The whole list\n");
	print_list(lista);
	freenodes(lista);
	free(lista);
		
	return 0;
}
