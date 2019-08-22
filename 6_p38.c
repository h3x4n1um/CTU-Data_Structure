#include "list.h"

List merge(List list1, List list2){
	Position pos = begin(list2);
	while(pos < end(list2)){
		insert(&list1, locate(list2, pos), end(list1));
		pos = next(list2, pos);
	}
	sort(&list1);
	return list1;
}

int main(){
	int n, i;
	List first, second;
	
	init(&first);
	init(&second);
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		int tmp;
		scanf("%d", &tmp);
		insert(&first, tmp, end(first));
	}
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		int tmp;
		scanf("%d", &tmp);
		insert(&second, tmp, end(second));
	}
	
	println(merge(first, second));
	
	return 0;
}
