#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node{
	ElementType data;
	struct Node* next;
	struct Node* previous;
} *List;

typedef struct Node Node;
typedef Node* Position;

int MAKENULL_LIST(List *p_list){
	free(*p_list);
	(*p_list) = (Node*) malloc(sizeof(Node));
	(*p_list)->data = 0;
	(*p_list)->next = NULL;
	(*p_list)->previous = (*p_list);
	return 0;
}

Position FIRST(List list){return list;}

Position ENDLIST(List list){
	Position res = FIRST(list);
	while(res->next) res = res->next;
	return res;
}

Position NEXT(List list, Position pos){
	return pos->next;
}

Position PREVIOUS(List list, Position pos){
	return pos->previous;
}

ElementType RETRIEVE(List list, Position pos){
	return pos->data;
}

ElementType *p_RETRIEVE(List *p_list, Position pos){
	return &pos->data;
}

int INSERT_LIST(List* p_list, ElementType e, Position pos){
	struct Node* tmp = (Node*) malloc(sizeof(Node));
	tmp->data = e;
	
	tmp->next = pos->next;
	tmp->previous = pos;
	
	pos->next = tmp;
	
	return 0;
}

int DELETE_LIST(List* p_list, Position pos){
	pos->previous->next = pos->next;
	if (pos->next) pos->next->previous = pos->previous;
	
	free(pos);
	
	return 0;
}

Position LOCATE(List list, ElementType e){
	Position i = FIRST(list);
	while(i){
		if (RETRIEVE(list, i) == e) return i;
		i = NEXT(list, i);
	}
	
	return ENDLIST(list);
}

int PRINT(List list){
	Position pos = FIRST(list);
	while(pos){
		if (pos != pos->previous) printf("%d\t", RETRIEVE(list, pos));
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
	Position i = NEXT(*p_list, FIRST(*p_list));
	while(i){
		Position j = NEXT(*p_list, i);
		while(j){
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

