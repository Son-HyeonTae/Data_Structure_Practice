#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 1
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
	return (top == -1);
}

int is_full() {
	return (top == MAX_STACK_SIZE - 1);
}

void push(element item) {
	if (is_full()) {
		fprintf(stderr, "Stack Overflow Error\n");
		return;
	}
	else {
		stack[++top] = item;
	}
}

element pop() {
	if (is_empty()) {
		fprintf(stderr, "Stack Underflow Error\n");
		exit(1);
	}
	else {
		return stack[top--];
	}
}

element peek() {
	if (is_empty()) {
		fprintf(stderr, "Stack Underflow Error\n");
		exit(1);
	}
	else {
		return stack[top];
	}
}

int main(void) {
	element ie = { 201819543,
						 "Kim",
						 "Suwon" };
	element oe;
	element pe;

	push(ie);
	pe = peek();
	push(ie);
	oe = pop();
	
	printf("\n");
	printf("student_no : %d\n", oe.student_no);
	printf("student_no : %s\n", oe.name);
	printf("student_no : %s\n", oe.address);
	printf("\n");
	printf("student_no : %d\n", pe.student_no);
	printf("student_no : %s\n", pe.name);
	printf("student_no : %s\n", pe.address);
	printf("\n");
	
	pop();

	return 0;
}
// output
// Stack Overflow Error

// student_no : 201819543
// student_no : Kim
// student_no : Suwon

// student_no : 201819543
// student_no : Kim
// student_no : Suwon

// Stack Underflow Error