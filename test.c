#include "llist.h"
#include <stdlib.h>
#include <stdint.h>




int main() {
	List *lista = malloc(sizeof(List));
	Init_Linked_List(lista);

	list_push(lista,(void *)(intptr_t)20);
	list_push(lista,(void *)(intptr_t)30);
	//print_list(lista);
	freenodes(lista);
	free(lista);
		
	return 0;
}
