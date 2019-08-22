#include "list.h"

int main(){
	int n, i;
	List list;
	
	init(&list);
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		Element tmp;
		scanf("%d", &tmp);
		insert(&list, tmp, end(list));
	}
	
	Element _max = locate(list, begin(list)),
			_min = locate(list, begin(list));
			
	i = begin(list);
	while(i < end(list)){
		if (_max < locate(list, i)) _max = locate(list, i);
		if (_min > locate(list, i)) _min = locate(list, i);
		i = next(list, i);
	}
	
	printf("%d %d", _max, _min);
	
	return 0;
}
