#include<stdio.h>


int max_sub_seq(int a[], int n) {
    int tmpsum, maxsum, i;
    maxsum = tmpsum = 0;
    for(i=0;i<n;i++) {
    	tmpsum += a[i];
        if(tmpsum > maxsum)
	    maxsum = tmpsum;
        else if(tmpsum < 0) //当tmpsum<0时,将tmpsum置为0,不更新maxsum
	    tmpsum = 0;
    }
    return maxsum;
}


    
int main() {
    int a[] = {4, -3, 5, -2, -1, 2, 6, -2};
    int ret;
    ret =  max_sub_seq(a, 8);
    printf("%d\n", ret);
    return 0;
}
