#include "list.h"

int main(){
	int n, i;
	List list, odd, even;
	
	init(&list);
	init(&odd);
	init(&even);
	scanf("%d", &n);
	for (i = 0; i < n; ++i){
		Element tmp;
		scanf("%d", &tmp);
		insert(&list, tmp, end(list));
	}
	
	i = begin(list);
	while(i < end(list)){
		Element tmp = locate(list, i);
		if (tmp % 2) insert(&odd, tmp, end(odd));
		else insert(&even, tmp, end(even));
		i = next(list, i);
	}
	
	println(odd);
	println(even);
	
	return 0;
}
