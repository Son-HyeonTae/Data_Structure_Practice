#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack Overflow Error\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Underflow Error\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Underflow Error\n");
		exit(1);
	}
	else {
		return s->data[s->top];
	}
}


int main(void) {
	StackType *s;		// change : s -> *s, because of melloc

	s = (StackType*)malloc(sizeof(StackType));

	init_stack(s);			// change : &s -> s, because of line 52;
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));

	free(s);

	return 0;
}
// output
// 3
// 2
// 1