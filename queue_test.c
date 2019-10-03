#include "queue.h"

int main(){
	queue q;
	MAKENULL_QUEUE(&q);
	ENQUEUE(1, &q);
	ENQUEUE(2, &q);
	ENQUEUE(3, &q);
	ENQUEUE(4, &q);
	ENQUEUE(5, &q);
	while(!EMPTY_QUEUE(q)){
		printf("%d\n", FRONT(q));
		DEQUEUE(&q);
	}
	return 0;
}
