#include <stdio.h>
#include <stdlib.h>

struct btree {
    int data;
    struct btree *left;
    struct btree *right;
};

typedef struct btree *p_tree;


p_tree init(p_tree T){
    if(T != NULL){
        T->left = NULL;
        T->right = NULL;
    }
    return NULL;
}

p_tree insert(p_tree T, int x){
    if(T == NULL){
	T = malloc(sizeof(struct btree));
        if(T == NULL){
	    printf("malloc space error!");
        }
        else {
	    T->data = x;
            T->left = T->right = NULL;
        }
    }
    else {
        if(x < T->data) {
	    T->left = insert(T->left,x);
        } else{
        if(x > T->data) {
	    T->right = insert(T->right,x);
  	}
    }
}


    return T;
}


p_tree findMin(p_tree T) {
    if(T == NULL){
        return NULL;
    }
    else {
        if(T->left == NULL) {
 	    return T;
	} else {
	    return findMin(T->left);
        }
    }
}


p_tree findMax(p_tree T) {
    if(T == NULL) {
        return NULL;
    }
    else {
        if(T->right == NULL){
            return T;
        } else {
            return findMax(T->right);
    }
}
}
/*先序遍历*/
void preorder_visit(p_tree T) {
    if(T != NULL) {
        printf("%d\t",T->data);
        preorder_visit(T->left);
        preorder_visit(T->right);
    }
}
/*中序遍历*/
void inorder_visit(p_tree T) {
    if(T != NULL){
        inorder_visit(T->left);
        printf("%d\t",T->data);
        inorder_visit(T->right);
    }
}
/*后序遍历*/
void postorder_visit(p_tree T) {
    if(T != NULL){
        postorder_visit(T->left);
        postorder_visit(T->right);
        printf("%d\t",T->data);
    }
}

p_tree delete(int x, p_tree T) {
    p_tree tmp;
    if(T == NULL) {
        printf("element not found!");
    } else {
        if(x < T->data) {
	    T->left = delete(x, T->left);
        } else {
        if(x > T->data) {
            T->right =  delete(x, T->right);
        } else {
            if(T->left && T->right){
                tmp = findMin(T->right);
                T->data = tmp->data;
                T->right = delete(T->data,T->right);
            } else {
               tmp = T;
               if(T->left = NULL){
		   T = T->right;
	       } else {
	       if(T->right == NULL){
 		   T = T->left;
               }
           }
        }
    }
}
}
}


int main()
{
    p_tree T = malloc(sizeof(struct btree));
    init(T);
    int i=0;
    for(i=0;i<10;i++) {
        insert(T,i);
    }
    preorder_visit(T);
    printf("****************************\n");
    inorder_visit(T);
    printf("****************************\n");
    postorder_visit(T);
    printf("****************************\n");

    printf("\n\n");
    p_tree ret = NULL;
    ret = findMin(T);
    printf("%d\n",ret->data);
    ret = findMax(T);
    printf("%d\n",ret->data);
    delete(9,T);
    preorder_visit(T);
    return 0;
} 










        
