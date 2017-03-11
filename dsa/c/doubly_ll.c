#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node node;

node *getnode();
node *insertion_ending(node *r,int x);
node *insertion_starting(node *r,int x);
void print(node *);
int total_nodes(node *);

int main()
{
	node *start = NULL;
	start = insertion_ending(start,10);
	start = insertion_ending(start,15);
	start = insertion_ending(start,20);
	start = insertion_ending(start,25);
	start = insertion_ending(start,30);
	start = insertion_starting(start,5);
	start = insertion_starting(start,6);
	start = insertion_starting(start,7);
        start = insertion_starting(start,8);
        start = insertion_starting(start,9);
	
	int count = 0;
	count = total_nodes(start);
	printf("\ntotal number of nodes is %d\n",count);

	print(start);

	return 0;
}

node *getnode(){
	node *t = (node *)malloc(sizeof(node));
	return t;
}

node *insertion_ending(node *r,int x){
	if (r == NULL){
		node *te = getnode();
		te->next = NULL;
		te->prev = NULL;
		te->data = x;
		r = te;
		return r;
	}
	else {
		node *temp = r;
		while (temp->next!=NULL){
			temp = temp->next;
		}
		node *newnode = getnode();
		newnode->next = temp->next;
		newnode->prev = temp;
		newnode->data = x;
		temp->next = newnode;
		return r;
	}
}

node *insertion_starting(node *r,int x){
	if (r == NULL){
		node *newnode = getnode();
		newnode->next = NULL;
		newnode->prev = NULL;
		newnode->data = x;
		r = newnode;
		return r;
	}
	else{
		node *newnode = getnode();
		r->prev = newnode;
		newnode->next = r;
		newnode->prev = NULL;
		newnode->data = x;
		r = newnode;
		return r;
	}
}

void print(node *t){
	node *temp = NULL;
	temp = t;
	while (temp!=NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

int total_nodes(node *r){
	int temp = 0;
	while(r!=NULL){
	r = r->next;
	temp++;
	}
	return temp;
}
