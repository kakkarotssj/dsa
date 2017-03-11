#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *next;
	int data;
};
typedef struct node node;

node *getnode();
node *insert_starting(node *a,int x);
node *insert_ending(node*b,int x);
void print(node *c);
int total_nodes(node *d);
node *deletion_using_position(node *e,int pos);
node *deletion_using_value(node *f,int value);
node *insertion_user(node *g,int pos,int x);

int main(){	

	node *start = NULL;
	start = insert_starting(start,50);
	start = insert_starting(start,40);
	start = insert_starting(start,30);
	start = insert_starting(start,20);
	start = insert_starting(start,10);
	start = insert_ending(start,60);
	start = insert_ending(start,70);
	start = insert_ending(start,80);
	start = insert_ending(start,90);
	start = insert_ending(start,100);

	int count = total_nodes(start);
	printf("\n Total number of nodes :%d\n\n\n",count);
	print(start);
	printf("\n\n\n");

        start = deletion_using_position(start,5);
        printf("\n\n\n");
        print(start);
	printf("\n\n\n");

	start = deletion_using_value(start,100);
	printf("\n\n\n");
	print(start);
	printf("\n\n\n");
	
	start = insertion_user(start,5,50);
	start = insertion_user(start,10,100);
	print(start);
	
return 0;
}

node *getnode(){
	node *temp = (node *)malloc(sizeof(node));
	return temp;
}

node *insert_starting(node *a,int x){
	node *random = a;
	if (random == NULL){
		node *newnode = getnode();
		newnode->next = a;
		a = newnode;
		newnode->data = x;
		return a;
	}
	else {
		node *newnode = getnode();
		newnode->next = a;
		a = newnode;
		newnode->data = x;
		return a;
	}
}

node *insert_ending(node*b,int x){
	node *random = b;
	if (random == NULL){
		node *newnode = getnode();
		newnode->next = b;
		b = newnode;
		newnode->data = x;
		return b;
	}
	else {
		while(random->next!=NULL){
			random = random->next;
		}
		node *newnode = getnode();
		newnode->next = random->next;
		random->next = newnode;
		newnode->data = x;
		return b;
	}
}
void print(node *c){
	node *temp = c;
	while(c!=NULL){
		printf("%d\n",c->data);
		c = c->next;
	}
}
int total_nodes(node *d){
	int count = 0;
	node *temp = d;
	while (temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

node *deletion_using_position(node *e,int pos){ 
	node *temp = e;
        int count = 2;
        while (count!=pos){
                        count++;
                        temp = temp->next;
                }
        count =1;
        node *another_temp = e;
        //now obtaining next node using ...
        while (temp->next!=another_temp){
                        another_temp = another_temp->next;
                }
        temp->next = another_temp->next;
        return e;
}

node *deletion_using_value(node *f,int value){
	node *temp = f;
	while (temp->data!=value){
		temp = temp->next;
	}
	node *extra = f;
	while(extra->next!=temp){
		extra = extra->next;
		}
	extra->next = temp->next;
	return f;
}

node *insertion_user(node *g,int pos,int x){
	node *temp = g;
	int i = 1;
	while (i!=(pos-1)){
		i++;
		temp = temp->next;
	}
	node *newnode = getnode();
	newnode->next = temp->next;
	newnode->data = x;
	temp->next = newnode;
	return g;
}
