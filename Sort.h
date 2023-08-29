#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int max(int A[], int n)
{
	int Max=A[0], i;
	for(i=1; i<n; i++){
		if(Max<A[i]) Max=A[i];
	}
	return Max;
}

int partition(int A[], int start, int end)
{
	int i=start+1, j, piv=A[start];
	for(j=start+1; j<=end; j++){
		if(A[j]<piv){
			swap(&A[i], &A[j]);
			i++;
		}
	}
	swap(&A[start], &A[i-1]);
	return i-1;
}

int randPartition(int A[], int start, int end)
{
	srand((int)time(0));
	int random=start+rand()%(end-start+1);
	swap(&A[random], &A[start]);
	return partition(A, start, end);
}

void quickSort(int A[], int start, int end)
{
	if(start<end){
		int pivPos=partition(A, start, end);
		quickSort(A, start, pivPos-1);
		quickSort(A, pivPos+1, end);
	}
}

void countSort(int A[], int n, int place)
{
	int output[n], i, count[10];
	memset(count, 0, 10*sizeof(int));
	for(i=0; i<n; i++){
		count[(A[i]/place)%10]++;
	}
	for(i=1; i<10; i++){
		count[i]+=count[i-1];
	}
	for(i=n-1; i>=0; i--){
		output[count[(A[i]/place)%10]-1]=A[i];
		count[(A[i]/place)%10]--;
	}
	for(i=0; i<n; i++){
		A[i]=output[i];
	}
}

void radixSort(int A[], int n)
{
	int maxx = max(A, n), mul=1;
	while(maxx){
		countSort(A, n, mul);
		mul*=10;
		maxx/=10;
	}
}
