#include <stdio.h>
#include <stdlib.h>

int parent(int i){
	return i/2;
}

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i + 1;
}

void max_heapify(int a[],int i,int N){
	int l = left(i);
	int r = right(i);
	int largest;
	if(l < N && a[l] > a[i]){
		largest = l;
	}else{
		largest = i;
	}

	if(r < N && a[r] > a[largest]){
		largest = r;
	}
	if(largest != i){
		int tmp;
		tmp = a[i];
		a[i] = a[largest];
		a[largest] = tmp;
		max_heapify(a,largest,N);
	}
}


void build_max_heap(int a[],int N){
	int i;
	for(i=N/2;i>=1;i--){
		max_heapify(a,i,N);
	}
}

void heapsort(int a[],int N){
	build_max_heap(a,N);
	int i;
	for(i = N;i>0;i--){
		int tmp;
		tmp = a[1];
		a[1] = a[i];
		a[i] = tmp;
		N--;
		max_heapify(a,1,N);
	}
}

int main(){
	int a[] = {-1,16,14,10,8,7,9,3,2,4,1};
	int N = sizeof(a)/sizeof(a[0]);
	heapsort(a,N);
	int i;
	for(i=1;i<N;i++){
		printf("%d\t",a[i]);
	}
	return 0;
}

