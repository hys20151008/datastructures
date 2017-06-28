#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack {
    char a[100];
    int len;
};

typedef struct stack* stk;

void stackInit(stk s){
    int i=0;
    for(i=0;i<sizeof(s->a)/sizeof(s->a[0]);i++){
        s->a[i]= 'd';
    }
    s->len=-1;
}
bool stackIsFull(stk s){
    return s->len>=100;
}

bool stackIsEmpty(stk s){
    return s->len == -1;
}   
    

void stackPush(stk s,int i){
    if(stackIsFull(s)){
        printf("stack is full\n");
        return;
    }
    s->a[s->len+1] = i;
    s->len++;

}

int stackPop(stk s){
    if(stackIsEmpty(s)){
        printf("stack is Empty\n");
        return -1;
    }
    int ret = s->a[s->len];
    s->a[s->len] = 'd';
    s->len--;
    return ret;
}

void ztobo(stk s,char *array){
    int i=0,N=strlen(array);
    printf("%d\t",N);
    for(i=0;i<N;i++){
        if(array[i] == ')')
            printf("%c ",stackPop(s));
        if((array[i] == '+') || ( array[i] == '*'))
            stackPush(s,array[i]);
        if((array[i] >= '0') && (array[i] <= '9')){
            printf("%c ", array[i]);
        }
    }
    printf("%c ",stackPop(s));
        printf("\n");
}
    
    




int main(){
    stk s = (stk)malloc(sizeof(struct stack)); 
    stackInit(s);
//    stackPush(s,10);
//    printf("%d\n",s->a[0]);
//    printf("%d\n",s->len);
//
//    int a = stackPop(s);
//    printf("%d\n",a);
    
    char a[] = {'5','*','(','(','(','9','+','8',')','*','(','4','*','6',')',')','+','7',')'};
    ztobo(s,a);
    return 0;
} 
     
    
