#define MaxLength 100
typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Top_idx;
}Stack;

void makenullStack(Stack *pS){
	pS->Top_idx=MaxLength;
}

bool emptyStack(Stack S){
	return S.Top_idx==MaxLength;
}

bool full(Stack S){
	return S.Top_idx==0;
}

ElementType top(Stack S){
	if(!emptyStack(S)) return S.Elements[S.Top_idx];
	else return -1;
}

void pop(Stack *pS){
	if(!emptyStack(*pS)) pS->Top_idx++;
}

void push(ElementType x, Stack *pS){
	if(!full(*pS)){
		pS->Top_idx--;
		pS->Elements[pS->Top_idx]=x;
	}
}

bool on_Stack(ElementType x, Stack S){
	int i;
	for(i=S.Top_idx; i<MaxLength; i++){
		if(S.Elements[i]==x){
			return 1;
		}
	}
	return 0;
}