#include<stdio.h>

int gcd (int m, int n) {
    int r;
    while(n>0){
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}


int main(){
    int ret;
    ret = gcd(3,6);
    printf("%d\n", ret);
    return 0;
}
