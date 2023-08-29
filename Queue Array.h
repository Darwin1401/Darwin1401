#define MaxLength 50
typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];
	int Front, Rear;
}Queue;

void makenullQueue(Queue *pQ){
	pQ->Front=pQ->Rear=-1;
}

bool emptyQueue(Queue Q){
	return Q.Front==-1;
}

int numberofElements(Queue Q){
	if(emptyQueue(Q)){
		return 0;
	}
	return Q.Rear-Q.Front+1;
}

bool fullQueue(Queue Q){
	return numberofElements(Q)==MaxLength;
}

ElementType front(Queue Q){
	if(emptyQueue(Q)){
		return -1;
	}
	return Q.Elements[Q.Front];
}

void deQueue(Queue *pQ){
	if(!emptyQueue(*pQ)){
		pQ->Front++;
		if(pQ->Front>pQ->Rear){
			makenullQueue(pQ);
		}
	}
}

void pushQueue(Queue *pQ){
	if(!emptyQueue(*pQ)&&!fullQueue(*pQ)&&pQ->Front>0){
		int i, j=0;
		for(i=pQ->Front; i<=pQ->Rear; i++){
			pQ->Elements[j]=pQ->Elements[i];
			j++;
		}
		pQ->Rear=numberofElements(*pQ)-1;
		pQ->Front=0;
	}
}

void enQueue(ElementType x, Queue *pQ){
	if(!fullQueue(*pQ)){
		if(emptyQueue(*pQ)){
			pQ->Front=0;
		}
		else{
			pushQueue(pQ);
		}
		pQ->Rear++;
		pQ->Elements[pQ->Rear]=x;	
	}
}