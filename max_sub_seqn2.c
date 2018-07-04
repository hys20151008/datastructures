#include<stdio.h>


int max_sub_seq(int a[], int n) {
    int tmpsum, maxsum, i, j;
    maxsum = 0;
    for(i=0;i<n;i++) {
            tmpsum = 0;
	for(j=i;j<n;j++) {
    	    tmpsum += a[j];
            if(tmpsum > maxsum)
		maxsum = tmpsum;
        }
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
