#include <stdio.h>

int partition(int a[],int lo,int hi){
	int pivot = a[lo];
	int i = lo;
	int j = hi;
	int tmp;
	while(i < j) {
		while(a[i] < pivot){
			i++;}
		while(a[j] > pivot){
			j--;}
		if(i >= j)
			return j;
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

void quicksort(int a[],int lo,int hi){
	if(lo < hi){
		int p = partition(a,lo,hi);
    printf("%d\n",p);
		quicksort(a,lo,p);
		quicksort(a,p+1,hi);
	}
}

int main(){
	int a[] ={2,4,5,3,1};
	quicksort(a,0,4);
	int i=0;
	for(i=0;i<5;i++){
		printf("%d\t",a[i]);
	}
	return 0;
}

