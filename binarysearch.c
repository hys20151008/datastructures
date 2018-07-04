#include<stdio.h>

int binary_search(int a[], int x, int n) {
    int low, mid, high;
    low = 0;
    high = n-1;
    while(low <= high) {
	mid = (low+high)/2;
        if(a[mid] < x)
 	    low = mid + 1;
        else if(a[mid] > x)
	    high = mid -1;
        else
           return mid;
    }
    return -1;
}


int main(){
    int a[] = {1, 2, 3, 5, 6, 9, 10, 40};
    int ret = binary_search(a, 6, 8);
    printf("%d\n", ret);
    ret = binary_search(a, 8, 8);
    printf("%d\n", ret);
}
    
        
