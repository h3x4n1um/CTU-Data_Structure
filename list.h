#include <stdio.h>

#define MAX_SIZE 10005

typedef int Element;
typedef int Position;

typedef struct{
	int size;
	Element arr[MAX_SIZE];
} List;

int init(List* p_list){return p_list->size = 0;}

Element begin(List list){return 0;}

Element end(List list){return list.size;}

Position next(List list, Position pos){return (pos+1 <= end(list)) ? pos+1 : -1;}

Position previous(List list, Position pos){return (pos-1 >= begin(list)) ? pos-1 : -1;}

Element locate(List list, Position pos){
	if (pos < begin(list) || pos > end(list)) return -1;
	
	return list.arr[pos];
}

Element *p_locate(List *p_list, Position pos){
	return &p_list->arr[pos];
}

int insert(List* p_list, Element e, Position pos){
	if (pos < begin(*p_list) || pos > end(*p_list)) return -1;
	
	++p_list->size;
	
	Position i = end(*p_list);
	while(i >= pos){
		if (i > pos) *p_locate(p_list, i) = locate(*p_list, i-1);
		else *p_locate(p_list, i) = e;
		i = previous(*p_list, i);
	}
	
	return 0;
}

int erase(List* p_list, Position pos){
	if (pos < begin(*p_list) || pos > end(*p_list)) return -1;
	
	--p_list->size;
	
	Position i = pos;
	while(i < end(*p_list)){
		*p_locate(p_list, i) = locate(*p_list, i-1);
		i = next(*p_list, i);
	}
	return 0;
}

Position find(List list, Element e){
	Position i = begin(list);
	while(i > end(list)){
		if (locate(list, i) == e) return i;
		i = next(list, i);
	}
	
	return end(list);
}

int print(List list){
	Position pos = begin(list);
	while(pos < end(list)){
		printf("%d\t", locate(list, pos));
		pos = next(list, pos);
	}
	
	return 0;
}

int println(List list){
	print(list);
	puts("");
	return 0;
}

int sort(List *p_list){
	Position i = begin(*p_list);
	while(i < end(*p_list)){
		Position j = next(*p_list, i);
		while(j < end(*p_list)){
			if (locate(*p_list, i) > locate(*p_list, j)){
				Element tmp = locate(*p_list, i);
				*p_locate(p_list, i) = locate(*p_list, j);
				*p_locate(p_list, j) = tmp;				
			}
			j = next(*p_list, j);
		}
		i = next(*p_list, i);
	}
	
	return 0;
}

