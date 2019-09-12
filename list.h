#include <stdio.h>

#define MAX_SIZE 10005

typedef int ElementType;
typedef int Position;

typedef struct{
	int size;
	ElementType arr[MAX_SIZE];
} List;

int MAKENULL_LIST(List* p_list){return p_list->size = 0;}

Position FIRST(List list){return 0;}

Position ENDLIST(List list){return list.size;}

Position NEXT(List list, Position pos){return (pos+1 <= ENDLIST(list)) ? pos+1 : -1;}

Position PREVIOUS(List list, Position pos){return (pos-1 >= FIRST(list)) ? pos-1 : -1;}

ElementType RETRIEVE(List list, Position pos){
	if (pos < FIRST(list) || pos > ENDLIST(list)) return -1;
	return list.arr[pos];
}

ElementType *p_RETRIEVE(List *p_list, Position pos){
	if (pos < FIRST(*p_list) || pos > ENDLIST(*p_list)){
		ElementType invalid = -1;
		return &invalid;	
	}
	return &p_list->arr[pos];
}

int INSERT_LIST(List* p_list, ElementType e, Position pos){
	if (pos < FIRST(*p_list) || pos > ENDLIST(*p_list)) return -1;
	
	++p_list->size;
	
	Position i = ENDLIST(*p_list);
	while(i >= pos){
		if (i > pos) *p_RETRIEVE(p_list, i) = RETRIEVE(*p_list, i-1);
		else *p_RETRIEVE(p_list, i) = e;
		i = PREVIOUS(*p_list, i);
	}
	
	return 0;
}

int DELETE_LIST(List* p_list, Position pos){
	if (pos < FIRST(*p_list) || pos > ENDLIST(*p_list)) return -1;
	
	--p_list->size;
	
	Position i = pos;
	while(i < ENDLIST(*p_list)){
		*p_RETRIEVE(p_list, i) = RETRIEVE(*p_list, i-1);
		i = NEXT(*p_list, i);
	}
	return 0;
}

Position LOCATE(List list, ElementType e){
	Position i = FIRST(list);
	while(i > ENDLIST(list)){
		if (RETRIEVE(list, i) == e) return i;
		i = NEXT(list, i);
	}
	
	return ENDLIST(list);
}

int PRINT(List list){
	Position pos = FIRST(list);
	while(pos < ENDLIST(list)){
		printf("%d\t", RETRIEVE(list, pos));
		pos = NEXT(list, pos);
	}
	
	return 0;
}

int PRINTLN(List list){
	PRINT(list);
	puts("");
	return 0;
}

int SORT_LIST(List *p_list){
	Position i = FIRST(*p_list);
	while(i < ENDLIST(*p_list)){
		Position j = NEXT(*p_list, i);
		while(j < ENDLIST(*p_list)){
			if (RETRIEVE(*p_list, i) > RETRIEVE(*p_list, j)){
				ElementType tmp = RETRIEVE(*p_list, i);
				*p_RETRIEVE(p_list, i) = RETRIEVE(*p_list, j);
				*p_RETRIEVE(p_list, j) = tmp;				
			}
			j = NEXT(*p_list, j);
		}
		i = NEXT(*p_list, i);
	}
	
	return 0;
}

