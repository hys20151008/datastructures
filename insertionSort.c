#include <stdio.h>
void insertSort(int a[], int n){
	int j ,p,tmp;
	for(p=0;p<n;p++){
		tmp=a[p];
		for(j=p;j>0&&a[j-1]>tmp;j--){
			a[j]=a[j-1];
		}
		a[j]=tmp;
	}
}

int main(){
	int a[] ={4,5,6,3,1,2,9,0};
	int i=0;
	int N = sizeof(a)/sizeof(a[0]);
	insertSort(a,N);
	for(i=0;i<N;i++){
		printf("%d\n", a[i]);
	}
	return 0;

}
