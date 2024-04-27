#include <stdio.h>
#include <stdlib.h>

// TODO: structs, global variables, etc.


struct listelement{
	int value;
	struct listelement *next;
}typedef element;
//typedef struct listelement element;

element *list_head = NULL;

static int insertElement(int value) {
	// TODO: implement me!

	if (value < 0){
		return -1;
	}

	element *node;
	node = malloc(sizeof(struct listelement));
	if(node == NULL){
		return EXIT_FAILURE;
	}

	element *current = list_head;

	while(current != NULL){
		if(current->value == value){
			return -1;
		}else{
			current = current->next;
		}
	}

	node->value = value;
	node->next = list_head;
	list_head = node;

	return node->value;
}

static int removeElement(void) {
	// TODO: implement me!

	if(list_head == NULL){
		return -1;
	}

	element *current = list_head;
	current = current->next;
	int removedValue = list_head->value;
	free(list_head);
	list_head = current;

	return removedValue;
}

int main (int argc, char* argv[]) {
	printf("insert 47: %d\n", insertElement(47));
	printf("insert 11: %d\n", insertElement(11));
	printf("insert 23: %d\n", insertElement(23));
	printf("insert 11: %d\n", insertElement(11));

	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());

	// TODO: add more tests

	for (int i = 0; i < 100; i += 5){
		printf("insert %d: %d\n", i, insertElement(i));
	}
	for (int i = 0; i < 23; i++){
		printf("remove: %d\n", removeElement());
	}

	for (int i = -10; i < 10; i++){
		printf("insert %d: %d\n", i, insertElement(i));
	}

	for (int i = 0; i < 11; i++){
		printf("remove: %d\n", removeElement());
	}
	
	for (int i = 1; i < 11; i++){
		printf("insert %d: %d\n", 4, insertElement(4));
	}
	for (int i = 0; i < 11; i++){
		printf("remove: %d\n", removeElement());
	}

	exit(EXIT_SUCCESS);
}
