#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
	struct listNode *prev;
	struct listNode *next;
	void *value;
} listNode;

typedef struct list {
	listNode *head;
	listNode *tail;
	unsigned long len;
} list;


typedef struct listIter {
	listNode *next;
	int direction;
} listIter;


list *listCreate(void){
	struct list *list;
	if ((list = malloc(sizeof(*list))) == NULL)
		return NULL;

	list->head = list->tail = NULL;
	list->len = 0;
	return list;
}

list *listAddNodeHead(list *list, void *value) {
	listNode *node;
	if ((node = malloc(sizeof(*node))) == NULL)
		return NULL;
	node->value = value;
	if (list->len == 0) {
		list->head = list->tail = node;
		node->prev = node->next = NULL;
	} else {
		node->prev = NULL;
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	list->len++;
	return list;
}


list *listAddNodeTail(list *list, void *value) {
	listNode *node;
	if ((node = malloc(sizeof(*node))) == NULL)
		return NULL;
	node->value = value;
	if (list->len == 0) {
		list->head = list->tail = node;
		node->prev = node->next = NULL;
	} else {
		node->prev = list->tail;
		node->next = NULL;
		list->tail->next = node;
		list->tail = node;
	}
}

listIter *listGetIterator(list *list, int direction) {
	listIter *iter;
	if ((iter = malloc(sizeof(*iter))) == NULL)
		return NULL;
	if (direction == 0)
		iter->next = list->head;
	else
		iter->next = list->tail;
	iter->direction = direction;
	return iter;
}

listNode *listNext(listIter *iter) {
	listNode *current = iter->next;
	if (current != NULL) {
		if (iter->direction == 0)
			iter->next = current->next;
		else
			iter->next = current->prev;
	}
	return current;
}


listNode *listSearchKey(list *list, void *key) {
	listIter *iter;
	listNode *node;
	iter = listGetIterator(list, 0);
	while((node = listNext(iter)) != NULL) {
		if (key == node->value) {
			return node;
		}
	}
	return NULL;
}


int main() {
	char *s = "hello";
	char *w = "world";
	struct list *list;
	list = listCreate();
	list = listAddNodeHead(list, s);
	list = listAddNodeTail(list, w);
	listNode *p;
	p = list->head;
	//printf("%s\n",list->head->value);
	while(p != NULL) {
		printf("%s\n", (char*)p->value);
		p = p->next;
	}
	p = listSearchKey(list, s);
	printf("%s\n", (char*)p->value);
	return 0;
}

