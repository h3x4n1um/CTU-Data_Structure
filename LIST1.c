#include "list.h"

int main(){
	int n, i, cnt;
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
	
	Position pos = begin(list);
	while(pos < end(list)){
		while(locate(list, pos) == x){
			++cnt;
			if (cnt > 1) erase(&list, pos);
		}
		pos = next(list, pos);
	}
	println(list);
	return 0;
}
