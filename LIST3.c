#include "list.h"

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
	
	sort(&list);
	println(list);
	
	scanf("%d", &x);
	insert(&list, x, end(list));

	sort(&list);
	println(list);
	
	return 0;
}
