#include <stdio.h>

void selection(int a[],int N){
    int i,j,min,tmp,k;
    for(i=0;i<N;i++) {
	min = i;
	for(j=i+1;j<N;j++){
            if(a[j]<a[min])
	        min = j;
	}
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;

    }	    
}

int main(){
    int a[] = {3,4,1,2,9,0,5};
    int N = sizeof(a)/sizeof(a[0]);
    selection(a,N);
    int i=0;
    for(i=0;i<N;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}

