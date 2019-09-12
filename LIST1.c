#include "list.h"

int main(){
	int n, i, cnt;
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
	
	Position pos = FIRST(list);
	while(pos < ENDLIST(list)){
		while(RETRIEVE(list, pos) == x){
			++cnt;
			if (cnt > 1) DELETE_LIST(&list, pos);
		}
		pos = NEXT(list, pos);
	}
	PRINTLN(list);
	return 0;
}
