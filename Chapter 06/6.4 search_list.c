#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

ListNode* insert_first(ListNode *head, element value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
  }

void print_list(ListNode *head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}

	return NULL;
}

int main(void) {
	ListNode *head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);

	printf("\n");

	if (search_list(head, 20) != NULL)
		printf("No.20 is found in the list.\n");
	else
		printf("No.20 isn't found in the list.\n");

	if (search_list(head, 25) != NULL)
		printf("No.25 is found in the list.\n");
	else
		printf("No.25 isn't found in the list.\n");

	return 0;
}
// output
// 10->NULL
// 20->10->NULL
// 30->20->10->NULL
// 
// No.20 is found in the list.
// No.25 isn't found in the list.