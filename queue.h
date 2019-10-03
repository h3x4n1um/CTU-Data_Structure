#include <limits.h>

#define MAX_SIZE 105

typedef int ElementType;

typedef int Position;

typedef struct queue{
	ElementType arr[MAX_SIZE];
	Position front, rear;
} queue;

void MAKENULL_QUEUE(queue *q){
	q->front = q->rear = -1;
}

int EMPTY_QUEUE(queue q){
	return q.front == -1;	
}

ElementType FRONT(queue q){
	if (EMPTY_QUEUE(q)) return INT_MIN;
	return q.arr[q.front];
}

int FULL_QUEUE(queue q){
	return (q.rear+1) % MAX_SIZE == q.front;
}

void ENQUEUE(ElementType x, queue *q){
	if (!FULL_QUEUE(*q)){
		if (EMPTY_QUEUE(*q)) q->front = (q->front+1) % MAX_SIZE;
		q->rear = (q->rear+1) % MAX_SIZE;
		q->arr[q->rear] = x;
	}
}

void DEQUEUE(queue *q){
	if (!EMPTY_QUEUE(*q)){
		if (q->front == q->rear) MAKENULL_QUEUE(q);
		else q->front = (q->front+1) % MAX_SIZE;
	}
}
