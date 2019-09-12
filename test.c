#include "linked_list.h"

int main(){
	List head;
	MAKENULL_LIST(&head);
	printf("%p %p\n", head, ENDLIST(head));
	
	INSERT_LIST(&head, 4, ENDLIST(head));
	INSERT_LIST(&head, 3, ENDLIST(head));
	INSERT_LIST(&head, 2, ENDLIST(head));
	INSERT_LIST(&head, 1, ENDLIST(head));
	INSERT_LIST(&head, 0, ENDLIST(head));
	PRINTLN(head);
	
	DELETE_LIST(&head, NEXT(head, NEXT(head, FIRST(head))));
	PRINTLN(head);
	DELETE_LIST(&head, NEXT(head, NEXT(head, FIRST(head))));
	PRINTLN(head);
	
	DELETE_LIST(&head, LOCATE(head, 4));
	PRINTLN(head);
	
	SORT_LIST(head);
	PRINTLN(head);
	
	return 0;
}
