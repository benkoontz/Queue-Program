#include "queue.h"

int main() {
	printf("begin the queue\n");
	q * head=NULL; // head element
	printf("first, set the head equal to NULL %p\n",head);

	InitializeQueue(&head);
	printf("head element is now initialized %p\n",head);

	//create and add new elements
	printf("\ncreate queue elements");
	q * q1 = NewItem();
	q * q2 = NewItem();
	q * q3 = NewItem();
	q * q4 = NewItem();
	q1->position = 1;
	q2->position = 2;
	q3->position = 3;
	q4->position = 4;

	// print each element in the queue and print the position for each element
	printf("\nq1: %p : %d\n", q1, q1->position);
	printf("q2: %p : %d\n", q2, q2->position);
	printf("q3: %p : %d\n", q3, q3->position);
	printf("q4: %p : %d\n", q4, q4->position);

	// add each element to the queue, each element goes after the element that was just added
	printf("\nadd queue elements\n");
	AddItem(&head, q1);
	PrintQueue(head);
	printf("\n");
	AddItem(&head, q2);
	PrintQueue(head);
	printf("\n");
	AddItem(&head, q3);
	PrintQueue(head);
	printf("\n");
	AddItem(&head, q4);
	PrintQueue(head);

    // rotate each element in the queue, the first element moves to the back of the queue
	printf("\nrotating queue elements\n");
	RotateQueue(&head);
	PrintQueue(head);
	printf("\n");
	RotateQueue(&head);
	PrintQueue(head);
	printf("\n");
	RotateQueue(&head);
	PrintQueue(head);
	printf("\n");
	RotateQueue(&head);
	PrintQueue(head);

	// delete each element from the queue
	printf("\ndelete each element\n");
	q * temp = DeleteItem(&head);
	printf("delete: %p : %d\n", temp, temp->position); // print the item and the position
	FreeItem(&temp);
	PrintQueue(head);
	printf("\n");
	temp = DeleteItem(&head);
	printf("delete: %p : %d\n", temp, temp->position);
	FreeItem(&temp);
	PrintQueue(head);
	printf("\n");
	temp = DeleteItem(&head);
	printf("delete: %p : %d\n", temp, temp->position);
	FreeItem(&temp);
	PrintQueue(head);
	printf("\n");
	temp = DeleteItem(&head);
	printf("delete: %p : %d\n", temp, temp->position);
	FreeItem(&temp);
	PrintQueue(head);

	return 0;
}
