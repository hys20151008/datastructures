#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

typedef struct node* List;

List CreateList(List L){
       int i=0;
       List p,prev,head;
       head=p=L;//=(List)malloc(sizeof(struct node));
       
       for(i=0;i<9;i++){
           prev=p;
           p = (List)malloc(sizeof(struct node));
	   p->val = i;
	   prev->next = p;
       }
       return head;
}
List InsertHead(List L,int x){
	List head,p;
	head = L;
	p = (List)malloc(sizeof(struct node));
	p->next = head->next;
	p->val = x;
	head->next = p;
	return head;
}

List InsertTail(List L){
        int x;
	List p,head,r;
	head = L = r = (List)malloc(sizeof(struct node));
     while(x!=-1){
        scanf("%d",&x);
	p = (List)malloc(sizeof(struct node));
	p->val = x;
	r->next= p;
	r = p;}
        r->next=NULL;
	return head;
}

int Isempty(List L){
	return L->next==NULL;
}

List Find(List L,int x){
	List p;
	p = L->next;
	while(p!=NULL && p->val!=x){
		p = p->next;
	}
	return p;
}

List reverse(List L){
	List current,pnext,prev;
	if(L == NULL || L->next == NULL){
		return L;
	}
	current = L->next;
	pnext = current->next;
	current->next=NULL;
	while(pnext){
		prev = pnext->next;
		pnext->next=current;
		current=pnext;
		pnext=prev;
	}
	L->next = current;
	
	return L;

}

void deleteList(List L){
	List tmp;
	p = L->next;
	L->next=NULL;
	while(p!=NULL){
		tmp = p->next;
		free(p);
		p=tmp;
	}
}


	   

int main(){
	List L,head,p,new,h;
        h = (List)malloc(sizeof(struct node));
        head=L= (List)malloc(sizeof(struct node));
	int i;
        head =  InsertHead(L,1);	
        head =  InsertHead(L,2);	
        head =  InsertHead(L,3);	
//	p = head->next;
//        while(p!=NULL){
//           new = (List)malloc(sizeof(struct node));
//           head = InsertHead(h,p->val);
//           p = p->next;
//        }
    //p = head->next;    
 //    printf("%d\n",Isempty(L));
	// printf("%p\n",&p);

	// while(p!=NULL){
	// 	printf("%d\n",p->val);
	// 	printf("%p\n",&p);
	// 	p=p->next;}
    // head = Find(L,3);
    // printf("%d\n", head->val);
        printf("%p\n",head);

        head = reverse(L);
        printf("%p\n", head);
        p = head->next;
         while(p!=NULL){
		printf("%d\n",p->val);
		p=p->next;}
	return 0;
}

	

