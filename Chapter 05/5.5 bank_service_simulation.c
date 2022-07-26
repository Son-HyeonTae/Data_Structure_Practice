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
		printf("현재 시각 : %d\n", clock);
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
// 현재 시각 : 0
// Customer #0, start service at 0minuits.Process time : 3
// Customer #0, start service at 0minuits.Waiting time was 0minutes.
// 현재 시각 : 1
// Customer #0, processing.
// 현재 시각 : 2
// Customer #1, start service at 2minuits.Process time : 3
// Customer #0, processing.
// 현재 시각 : 3
// Customer #0, processing.
// 현재 시각 : 4
// Customer #1, start service at 4minuits.Waiting time was 2minutes.
// 현재 시각 : 5
// Customer #1, processing.
// 현재 시각 : 6
// Customer #2, start service at 6minuits.Process time : 3
// Customer #1, processing.
// 현재 시각 : 7
// Customer #1, processing.
// 현재 시각 : 8
// Customer #2, start service at 8minuits.Waiting time was 2minutes.
// 현재 시각 : 9
// Customer #3, start service at 9minuits.Process time : 1
// Customer #2, processing.
// 현재 시각 : 10
// Customer #4, start service at 10minuits.Process time : 3
// Customer #2, processing.
// 현재 시각 : 11
// Customer #2, processing.
// 현재 시각 : 12
// Customer #5, start service at 12minuits.Process time : 1
// Customer #3, start service at 12minuits.Waiting time was 3minutes.
// 현재 시각 : 13
// Customer #3, processing.
// 현재 시각 : 14
// Customer #6, start service at 14minuits.Process time : 1
// Customer #4, start service at 14minuits.Waiting time was 4minutes.
// 현재 시각 : 15
// Customer #7, start service at 15minuits.Process time : 1
// Customer #4, processing.
// 현재 시각 : 16
// Customer #8, start service at 16minuits.Process time : 2
// Customer #4, processing.
// 현재 시각 : 17
// Customer #9, start service at 17minuits.Process time : 3
// Customer #4, processing.
// 현재 시각 : 18
// Customer #5, start service at 18minuits.Waiting time was 6minutes.
// 현재 시각 : 19
// Customer #5, processing.
// 현재 시각 : 20
// Customer #6, start service at 20minuits.Waiting time was 6minutes.
// 현재 시각 : 21
// Customer #6, processing.
// 현재 시각 : 22
// Customer #10, start service at 22minuits.Process time : 1
// Customer #7, start service at 22minuits.Waiting time was 7minutes.
// 현재 시각 : 23
// Customer #7, processing.
// 현재 시각 : 24
// Customer #11, start service at 24minuits.Process time : 3
// Customer #8, start service at 24minuits.Waiting time was 8minutes.
// 현재 시각 : 25
// Customer #8, processing.
// 현재 시각 : 26
// Customer #8, processing.
// 현재 시각 : 27
// Customer #9, start service at 27minuits.Waiting time was 10minutes.
// 현재 시각 : 28
// Customer #9, processing.
// 현재 시각 : 29
// Customer #12, start service at 29minuits.Process time : 3
// Customer #9, processing.
// 현재 시각 : 30
// Customer #9, processing.
// 현재 시각 : 31
// Customer #10, start service at 31minuits.Waiting time was 9minutes.
// 현재 시각 : 32
// Customer #10, processing.
// 현재 시각 : 33
// Customer #13, start service at 33minuits.Process time : 2
// Customer #11, start service at 33minuits.Waiting time was 9minutes.
// 현재 시각 : 34
// Customer #11, processing.
// 현재 시각 : 35
// Customer #11, processing.
// 현재 시각 : 36
// Customer #11, processing.
// 현재 시각 : 37
// Customer #12, start service at 37minuits.Waiting time was 8minutes.
// 현재 시각 : 38
// Customer #14, start service at 38minuits.Process time : 1
// Customer #12, processing.
// 현재 시각 : 39
// Customer #12, processing.
// 현재 시각 : 40
// Customer #12, processing.
// 현재 시각 : 41
// Customer #13, start service at 41minuits.Waiting time was 8minutes.
// 현재 시각 : 42
// Customer #15, start service at 42minuits.Process time : 2
// Customer #13, processing.
// 현재 시각 : 43
// Customer #13, processing.
// 현재 시각 : 44
// Customer #14, start service at 44minuits.Waiting time was 6minutes.
// 현재 시각 : 45
// Customer #14, processing.
// 현재 시각 : 46
// Customer #16, start service at 46minuits.Process time : 1
// Customer #15, start service at 46minuits.Waiting time was 4minutes.
// 현재 시각 : 47
// Customer #15, processing.
// 현재 시각 : 48
// Customer #15, processing.
// 현재 시각 : 49
// Customer #17, start service at 49minuits.Process time : 3
// Customer #16, start service at 49minuits.Waiting time was 3minutes.
// 현재 시각 : 50
// Customer #16, processing.
// 현재 시각 : 51
// Customer #17, start service at 51minuits.Waiting time was 2minutes.
// 현재 시각 : 52
// Customer #17, processing.
// 현재 시각 : 53
// Customer #17, processing.
// 현재 시각 : 54
// Customer #18, start service at 54minuits.Process time : 1
// Customer #17, processing.
// 현재 시각 : 55
// Customer #19, start service at 55minuits.Process time : 3
// Customer #18, start service at 55minuits.Waiting time was 1minutes.
// 현재 시각 : 56
// Customer #18, processing.
// 현재 시각 : 57
// Customer #20, start service at 57minuits.Process time : 1
// Customer #19, start service at 57minuits.Waiting time was 2minutes.
// 현재 시각 : 58
// Customer #19, processing.
// 현재 시각 : 59
// Customer #19, processing.
// Total waiting time = 100minues