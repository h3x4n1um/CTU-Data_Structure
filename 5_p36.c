#include "list.h"

int main(){
	int n, i;
	List list, odd, even;
	
	MAKENULL_LIST(&list);
	MAKENULL_LIST(&odd);
	MAKENULL_LIST(&even);
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		ElementType tmp;
		scanf("%d", &tmp);
		INSERT_LIST(&list, tmp, ENDLIST(list));
	}
	
	i = FIRST(list);
	while(i < ENDLIST(list)){
		ElementType tmp = RETRIEVE(list, i);
		if (tmp % 2) INSERT_LIST(&odd, tmp, ENDLIST(odd));
		else INSERT_LIST(&even, tmp, ENDLIST(even));
		i = NEXT(list, i);
	}
	
	PRINTLN(odd);
	PRINTLN(even);
	
	return 0;
}
