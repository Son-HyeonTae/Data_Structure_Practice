#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 60

typedef struct {
	int id;
	int arrival_time;
	int service_time;
} element;

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
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	QueueType queue;
	
	init_queue(&queue);
	for (int clock = 0; clock < minutes; clock++) {
		printf("���� �ð� : %d\n", clock);
		if ((rand() % 10) < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("Customer #%d, start service at %dminuits. Process time : %d\n", customer.id, customer.arrival_time, customer.service_time);
		}

		if (service_time > 0) {
			printf("Customer #%d, processing.\n", service_customer);
			service_time--;
		}
		else {
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("Customer #%d, start service at %dminuits. Waiting time was %dminutes.\n", customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("Total waiting time = %dminues\n", total_wait);

	return 0;
}
// output
// ���� �ð� : 0
// Customer #0, start service at 0minuits.Process time : 3
// Customer #0, start service at 0minuits.Waiting time was 0minutes.
// ���� �ð� : 1
// Customer #0, processing.
// ���� �ð� : 2
// Customer #1, start service at 2minuits.Process time : 3
// Customer #0, processing.
// ���� �ð� : 3
// Customer #0, processing.
// ���� �ð� : 4
// Customer #1, start service at 4minuits.Waiting time was 2minutes.
// ���� �ð� : 5
// Customer #1, processing.
// ���� �ð� : 6
// Customer #2, start service at 6minuits.Process time : 3
// Customer #1, processing.
// ���� �ð� : 7
// Customer #1, processing.
// ���� �ð� : 8
// Customer #2, start service at 8minuits.Waiting time was 2minutes.
// ���� �ð� : 9
// Customer #3, start service at 9minuits.Process time : 1
// Customer #2, processing.
// ���� �ð� : 10
// Customer #4, start service at 10minuits.Process time : 3
// Customer #2, processing.
// ���� �ð� : 11
// Customer #2, processing.
// ���� �ð� : 12
// Customer #5, start service at 12minuits.Process time : 1
// Customer #3, start service at 12minuits.Waiting time was 3minutes.
// ���� �ð� : 13
// Customer #3, processing.
// ���� �ð� : 14
// Customer #6, start service at 14minuits.Process time : 1
// Customer #4, start service at 14minuits.Waiting time was 4minutes.
// ���� �ð� : 15
// Customer #7, start service at 15minuits.Process time : 1
// Customer #4, processing.
// ���� �ð� : 16
// Customer #8, start service at 16minuits.Process time : 2
// Customer #4, processing.
// ���� �ð� : 17
// Customer #9, start service at 17minuits.Process time : 3
// Customer #4, processing.
// ���� �ð� : 18
// Customer #5, start service at 18minuits.Waiting time was 6minutes.
// ���� �ð� : 19
// Customer #5, processing.
// ���� �ð� : 20
// Customer #6, start service at 20minuits.Waiting time was 6minutes.
// ���� �ð� : 21
// Customer #6, processing.
// ���� �ð� : 22
// Customer #10, start service at 22minuits.Process time : 1
// Customer #7, start service at 22minuits.Waiting time was 7minutes.
// ���� �ð� : 23
// Customer #7, processing.
// ���� �ð� : 24
// Customer #11, start service at 24minuits.Process time : 3
// Customer #8, start service at 24minuits.Waiting time was 8minutes.
// ���� �ð� : 25
// Customer #8, processing.
// ���� �ð� : 26
// Customer #8, processing.
// ���� �ð� : 27
// Customer #9, start service at 27minuits.Waiting time was 10minutes.
// ���� �ð� : 28
// Customer #9, processing.
// ���� �ð� : 29
// Customer #12, start service at 29minuits.Process time : 3
// Customer #9, processing.
// ���� �ð� : 30
// Customer #9, processing.
// ���� �ð� : 31
// Customer #10, start service at 31minuits.Waiting time was 9minutes.
// ���� �ð� : 32
// Customer #10, processing.
// ���� �ð� : 33
// Customer #13, start service at 33minuits.Process time : 2
// Customer #11, start service at 33minuits.Waiting time was 9minutes.
// ���� �ð� : 34
// Customer #11, processing.
// ���� �ð� : 35
// Customer #11, processing.
// ���� �ð� : 36
// Customer #11, processing.
// ���� �ð� : 37
// Customer #12, start service at 37minuits.Waiting time was 8minutes.
// ���� �ð� : 38
// Customer #14, start service at 38minuits.Process time : 1
// Customer #12, processing.
// ���� �ð� : 39
// Customer #12, processing.
// ���� �ð� : 40
// Customer #12, processing.
// ���� �ð� : 41
// Customer #13, start service at 41minuits.Waiting time was 8minutes.
// ���� �ð� : 42
// Customer #15, start service at 42minuits.Process time : 2
// Customer #13, processing.
// ���� �ð� : 43
// Customer #13, processing.
// ���� �ð� : 44
// Customer #14, start service at 44minuits.Waiting time was 6minutes.
// ���� �ð� : 45
// Customer #14, processing.
// ���� �ð� : 46
// Customer #16, start service at 46minuits.Process time : 1
// Customer #15, start service at 46minuits.Waiting time was 4minutes.
// ���� �ð� : 47
// Customer #15, processing.
// ���� �ð� : 48
// Customer #15, processing.
// ���� �ð� : 49
// Customer #17, start service at 49minuits.Process time : 3
// Customer #16, start service at 49minuits.Waiting time was 3minutes.
// ���� �ð� : 50
// Customer #16, processing.
// ���� �ð� : 51
// Customer #17, start service at 51minuits.Waiting time was 2minutes.
// ���� �ð� : 52
// Customer #17, processing.
// ���� �ð� : 53
// Customer #17, processing.
// ���� �ð� : 54
// Customer #18, start service at 54minuits.Process time : 1
// Customer #17, processing.
// ���� �ð� : 55
// Customer #19, start service at 55minuits.Process time : 3
// Customer #18, start service at 55minuits.Waiting time was 1minutes.
// ���� �ð� : 56
// Customer #18, processing.
// ���� �ð� : 57
// Customer #20, start service at 57minuits.Process time : 1
// Customer #19, start service at 57minuits.Waiting time was 2minutes.
// ���� �ð� : 58
// Customer #19, processing.
// ���� �ð� : 59
// Customer #19, processing.
// Total waiting time = 100minues