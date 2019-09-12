#include "list.h"

List merge(List list1, List list2){
	Position pos = FIRST(list2);
	while(pos < ENDLIST(list2)){
		INSERT_LIST(&list1, RETRIEVE(list2, pos), ENDLIST(list1));
		pos = NEXT(list2, pos);
	}
	SORT_LIST(&list1);
	return list1;
}

int main(){
	int n, i;
	List first, second;
	
	MAKENULL_LIST(&first);
	MAKENULL_LIST(&second);
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		int tmp;
		scanf("%d", &tmp);
		INSERT_LIST(&first, tmp, ENDLIST(first));
	}
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		int tmp;
		scanf("%d", &tmp);
		INSERT_LIST(&second, tmp, ENDLIST(second));
	}
	
	PRINTLN(merge(first, second));
	
	return 0;
}
