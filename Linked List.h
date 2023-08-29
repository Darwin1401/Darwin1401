#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int ElementType; //setup kieu du lieu
struct Node{
	ElementType Element; //noi dung cua phan tu
	struct Node *Next; // con tro chi den phan tu ke tiep
};
typedef struct Node *Position; //kieu vi tri
typedef Position List; //kieu danh sach

void makenullList(List *pL){
	(*pL)=(struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next=NULL;
}

int emptyList(List L){
	return L->Next==NULL;
}

ElementType retrieve(Position P, List L){
	if(P->Next!=NULL) return P->Next->Element;
}

void insertList(ElementType x, Position P, List *pL){
	Position T;
	T=(struct Node*)malloc(sizeof(struct Node));
	T->Element=x;
	T->Next=P->Next;
	P->Next=T;
}

void deleteList(Position P, List *pL){
	Position Temp;
	if(P->Next!=NULL){
		Temp=P->Next;
		P->Next=Temp->Next;
		free(Temp);
	}
}

Position first(List L){
	return L;
}

Position endList(List L){
	Position P;
	P=L;
	while(P->Next!=NULL){
		P=P->Next;
	}
	return P;
}

Position next(Position P, List L){
	return P->Next;
}

Position previous(Position P, List L){
	Position Q=L;
	while(Q->Next!=P){
		Q=Q->Next;
	}
	return Q;
}

Position locate(ElementType x, List L){
	Position P=first(L), E=endList(L);
	while(P!=E){
		if(retrieve(P, L)==x) return P;
		else P=next(P, L);
	}
	return P;
}

Position myLocate(ElementType x, int i, List L){
	Position P=first(L), E=endList(L);
	int count=0;
	while(P!=E && count<i){
		if(retrieve(P, L)==x) count++;
		if(count<i) P=next(P, L);
	}
	return P;
}

void printList(List L){
	Position P=first(L), E=endList(L);
	while(P!=E){
		printf("%d ", retrieve(P, L));
		P=next(P, L);
	}
	printf("\n");
}

void readList(List *pL){
	int i, n;
	ElementType x;
	makenullList(pL);
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &x);
		insertList(x, first(*pL), pL);
	}
}