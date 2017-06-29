#include <stdio.h>
#include <stdlib.h>

struct queue{
    int *a;
    int queuesize;
    int head;
    int tail;
};
typedef struct queue *Q;

void init(Q q, int n){
    q->head = q->tail = 0;
    q->queuesize = n;
    q->a = (int*)malloc(sizeof(int)*q->queuesize);
}

void enqueue(Q q,int x){
    if(((q->tail + 1) % q->queuesize) == q->head){
	printf("queue is full\n");
    }
    else{
	q->a[q->tail] = x;
	q->tail = (q->tail + 1) % q->queuesize;
    }
}
int dequeue(Q q){
    if(q->tail == q->head)
	return -1;
    else{
        q->head = ((++q->head)%q->queuesize);
    }
}

int main(){
    Q q;
    q = (Q)malloc(sizeof(struct queue));
    init(q,10);
    int i=0;
    for(i=0;i<9;i++){
	enqueue(q,i);
    }

    for(i=q->head;i<9;i++){
	printf("%d\t",q->a[i]);
    }
    printf("\n");
    printf("%d\n",q->head);
    dequeue(q);
    
    printf("%d\n",q->head);
    for(i=q->head;i<9;i++){
	printf("%d\t",q->a[i]);
    }

    return 0;
}




















