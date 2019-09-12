#include "list.h"

int main(){
	int n, i;
	List list;
	
	MAKENULL_LIST(&list);
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		ElementType tmp;
		scanf("%d", &tmp);
		INSERT_LIST(&list, tmp, ENDLIST(list));
	}
	
	ElementType _max = RETRIEVE(list, FIRST(list)),
			_min = RETRIEVE(list, FIRST(list));
			
	i = FIRST(list);
	while(i < ENDLIST(list)){
		if (_max < RETRIEVE(list, i)) _max = RETRIEVE(list, i);
		if (_min > RETRIEVE(list, i)) _min = RETRIEVE(list, i);
		i = NEXT(list, i);
	}
	
	printf("%d %d", _max, _min);
	
	return 0;
}
