#include "Linked List.h"

typedef List Stack;

void makenullStack(Stack *pS){
	makenullList(pS);
}

bool emptyStack(Stack S){
	return emptyList(S);
}

ElementType top(Stack S){
	retrieve(first(S), S);
}

void pop(Stack *pS){
	deleteList(first(*pS), pS);
}

void push(ElementType x, Stack *pS){
	insertList(x, first(*pS), pS);
}
