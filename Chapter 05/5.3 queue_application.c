#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return (((q->rear + 1) % MAX_QUEUE_SIZE) == q->front);
}

void queue_print(QueueType* q) {
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

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("Queue Overflow Error\n");
	}
	q->rear = (q->rear + 1) % (MAX_QUEUE_SIZE);
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("Queue Underflow Error\n");
	}
	q->front = (q->front + 1) % (MAX_QUEUE_SIZE);
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty) {
		error("Queue is empty\n");
	}
	return (q->data[(q->front + 1) % (MAX_QUEUE_SIZE)]);
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) {
			enqueue(&queue, rand() % 100);
		}
		queue_print(&queue);
		if (rand() % 10 == 0) {
			int data = dequeue(&queue);
		}
		queue_print(&queue);
	}

	return 0;
}
// output
// ...
// Queue(front = 2, rear = 0) = 9 | 24 | 46 |
// Queue(front = 2, rear = 0) = 9 | 24 | 46 |
// Queue(front = 2, rear = 1) = 9 | 24 | 46 | 1 |
// Queue(front = 3, rear = 1) = 24 | 46 | 1 |
// Queue(front = 3, rear = 2) = 24 | 46 | 1 | 65 |
// Queue(front = 4, rear = 2) = 46 | 1 | 65 |
// Queue(front = 4, rear = 2) = 46 | 1 | 65 |
// Queue(front = 4, rear = 2) = 46 | 1 | 65 |
// Queue(front = 4, rear = 2) = 46 | 1 | 65 |
// Queue(front = 4, rear = 2) = 46 | 1 | 65 |
// Queue(front = 4, rear = 3) = 46 | 1 | 65 | 94 |
// Queue(front = 0, rear = 3) = 1 | 65 | 94 |
// Queue(front = 0, rear = 3) = 1 | 65 | 94 |
// Queue(front = 0, rear = 3) = 1 | 65 | 94 |
// Queue(front = 0, rear = 4) = 1 | 65 | 94 | 26 |
// Queue(front = 0, rear = 4) = 1 | 65 | 94 | 26 |
// Queue(front = 0, rear = 4) = 1 | 65 | 94 | 26 |
// Queue(front = 0, rear = 4) = 1 | 65 | 94 | 26 |
// Queue Overflow Error