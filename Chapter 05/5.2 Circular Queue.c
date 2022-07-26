#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
	return (q->front == q->rear);
}

int is_full(QueueType *q) {
	return (((q->rear + 1) % MAX_QUEUE_SIZE) == q->front);
}

void queue_print(QueueType *q) {
	printf("Queue(front=%d, rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType *q, element item) {
	if (is_full(q)) {
		error("Queue Overflow Error\n");
	}
	q->rear = (q->rear + 1) % (MAX_QUEUE_SIZE);
	q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
	if (is_empty(q)) {
		error("Queue Underflow Error\n");
	}
	q->front = (q->front + 1) % (MAX_QUEUE_SIZE);
	return q->data[q->front];
}

element peek(QueueType *q) {
	if (is_empty) {
		error("Queue is empty\n");
	}
	return (q->data[(q->front + 1) % (MAX_QUEUE_SIZE)]);
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);

	printf("-- Stage : Add data --\n");
	while (!is_full(&queue)) {
		printf("input integer : ");
		scanf_s("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("Queue is full\n\n");

	printf("-- Stage : Delete data -- \n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("dequeued integer : %d\n", element);
		queue_print(&queue);
	}
	printf("Queue is empty\n\n");
	
	return 0;
}
// output
// --Stage : Add data --
// input integer : 10
// Queue(front = 0, rear = 1) = 10 |
// input integer : 20
// Queue(front = 0, rear = 2) = 10 | 20 |
// input integer : 30
// Queue(front = 0, rear = 3) = 10 | 20 | 30 |
// input integer : 40
// Queue(front = 0, rear = 4) = 10 | 20 | 30 | 40 |
// Queue is full
// 
// -- Stage : Delete data --
// dequeued integer : 10
// Queue(front = 1, rear = 4) = 20 | 30 | 40 |
// dequeued integer : 20
// Queue(front = 2, rear = 4) = 30 | 40 |
// dequeued integer : 30
// Queue(front = 3, rear = 4) = 40 |
// dequeued integer : 40
// Queue(front = 4, rear = 4) =
// Queue is empty