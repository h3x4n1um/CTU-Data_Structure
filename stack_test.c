#include "stack.h"

int main(){
	stack s;
	MAKENULL_STACK(&s);
	PUSH(&s, 1);
	PUSH(&s, 2);
	PUSH(&s, 3);
	PUSH(&s, 4);
	PUSH(&s, 5);
	while(!EMPTY_STACK(s)){
		printf("%d\n", TOP(s));
		POP(&s);
	}
	return 0;
}
