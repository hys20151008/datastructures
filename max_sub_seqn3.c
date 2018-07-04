#include<stdio.h>

int max_sub_seq(int a[], int n) {
    int maxsum, tmpsum, i, j, k;
    maxsum = 0;
    
    for(i=0; i<n; i++) {
        for(j=i; j<n; j++) {
            tmpsum = 0;
            for(k=i;k<=j;k++)
		tmpsum += a[k];
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
    
