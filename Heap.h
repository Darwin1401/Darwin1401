#include <stdio.h>

#define MAXSIZE 100001

int A[MAXSIZE];
int size;

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

int parent(int i){
	return (i-1)/2;
}

void maxHeapify(int A[], int i){
	int largest=0, l=left(i), r=right(i);
	if(l<size && A[l]>A[i]) largest=l;
	else largest=i;
	if(r<size && A[r]>A[largest]) largest=r;
	if(largest!=i){
		swap(&A[largest], &A[i]);
		maxHeapify(A, largest);
	}
}

void buildMaxHeap(int A[]){
	int i;
	for(i=size/2-1; i>=0; i--){
		maxHeapify(A, i);
	}
}

int getMax(int A[]){
	return A[0];
}

int extractMax(int A[]){
	int m=A[0];
	swap(&A[0], &A[size-1]);
	size--;
	maxHeapify(A, 0);
	return m;
}

void insert(int A[], int x){
	size++;
	int i=size-1;
	A[i]=x;
	while(i>0 && A[i]>A[parent(i)]){
		swap(&A[i], &A[parent(i)]);
		i=parent(i);
	}
}

void heapSort(int A[], int *pSize){
	buildMaxHeap(A);
	*pSize=size;
	int i;
	for(i=0; i<*pSize; i++){
		extractMax(A);
		maxHeapify(A, 0);
	}
	size=*pSize;
}
