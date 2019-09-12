#include "list.h"

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
	
	SORT_LIST(&list);
	PRINTLN(list);
	
	scanf("%d", &x);
	INSERT_LIST(&list, x, ENDLIST(list));

	SORT_LIST(&list);
	PRINTLN(list);
	
	return 0;
}
