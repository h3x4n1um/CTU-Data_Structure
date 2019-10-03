#include <limits.h>

#define MAX_SIZE 105

typedef int ElementType;

typedef struct stack{
	ElementType arr[MAX_SIZE];
	int size;
} stack;

void MAKENULL_STACK(stack *s){
	s->size = 0;
}

int EMPTY_STACK(stack s){
	return s.size == 0;
}

ElementType TOP(stack s){
	if (EMPTY_STACK(s)) return INT_MIN;
	return s.arr[s.size-1];
}

void POP(stack *s){
	if (!EMPTY_STACK(*s)) --s->size;
}

int FULL_STACK(stack s){
	return s.size == MAX_SIZE;
}

void PUSH(stack *s, ElementType x){
	if (!FULL_STACK(*s)){
		s->arr[s->size] = x;
		++s->size;
	}
}
