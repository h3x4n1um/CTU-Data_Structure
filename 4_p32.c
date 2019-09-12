#include "list.h"

int cnt(List list, ElementType x){
	int res = 0;
	Position pos = FIRST(list);
	while(pos < ENDLIST(list)){
		++res;
		pos = NEXT(list, pos);
	}
	return res;
}

int main(){
	int n, i;
	List list;
	ElementType x;
	
	MAKENULL_LIST(&list);
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		ElementType tmp;
		scanf("%d", &tmp);
		INSERT_LIST(&list, tmp, ENDLIST(list));
	}
	scanf("%d", &x);

	printf("%d", cnt(list, x));
	
	return 0;
}
