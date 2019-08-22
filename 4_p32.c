#include "list.h"

int cnt(List list, Element x){
	int res = 0;
	Position pos = begin(list);
	while(pos < end(list)){
		++res;
		pos = next(list, pos);
	}
	return res;
}

int main(){
	int n, i;
	List list;
	Element x;
	
	init(&list);
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		Element tmp;
		scanf("%d", &tmp);
		insert(&list, tmp, end(list));
	}
	scanf("%d", &x);

	printf("%d", cnt(list, x));
	
	return 0;
}
