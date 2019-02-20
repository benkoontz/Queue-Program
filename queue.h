#ifndef QUEUE_HEADER
#define QUEUE_HEADER
#include <stdlib.h>

typedef struct q {
	struct q * prev; // points to the previous element
	struct q * next; // points to the next element
	int position; // represents each position in the queue
} q;

// This function initializes the head element to NULL
void InitializeQueue(q ** head) {
	*head = NULL;
}

// This function is used to create a new queue item
q * NewItem() {
	return (q*)malloc(sizeof(q)); // use memory to create a new queue element
}

// This function adds an element to the queue, it adds elements to the end of the queue
void AddItem(q ** head, q * item) { // the head has ** because it points to the address of item, item is just an address
	q * temp = *head;
	if (temp == NULL) {
		*head = item;
		(*head)->next = *head;
		(*head)->prev = *head;
	} else if (temp->next == temp) {
		temp->next = item;
		temp->prev = item;
		item->next = temp;
		item->prev = temp;
	} else {
		while (temp->next != *head)
			temp = temp->next;
		item->next = temp->next;
		item->prev = temp;
		temp->next = item;
		(*head)->prev = item;
	}
}

// This function deletes an element in the queue
q * DeleteItem(q ** head) {
	q* del = *head;
	if (del->next == del) {
		*head = NULL;
	} else {
		while (del->next != *head) {
			del = del->next;
		}
		del->prev->next = del->next;
		del->next->prev = del->prev;
	}
	return del;
}

// This function frees memory that is being used
void FreeItem(q ** item) {
	free(*item); // deallocates the memory previously allocated by a call to malloc
	*item = NULL;
}

// This function gets the first element and moves it to the back of the queue
void RotateQueue(q ** head) {
	if (head != NULL) {
		q* temp = *head;
		*head = temp->next;
	}
}

// This function prints the queue
void PrintQueue(q * head) {
	if (head == NULL) {
		printf("\nThe Queue is Empty");
		return;
	}

	printf("queue:");
	if ((head)->next == head) {
		printf("\t%p : %d\n", head, head->position);
	} else {
		q* last = head;
		do {
			printf("\t%p : %d\n", last, last->position);
			last = last->next;
		} while (last != head);
	}
}

#endif
