#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	struct node *next;
	int data;
};
typedef struct node node;

node *getnode();
node *insertion_starting(node *start, int value);
node *insertion_ending(node *start, int value);
void print(node *start);
int total_nodes(node *start);
node *deletion_position(node *start, int pos);
node *deletion_value(node *start, int value);
void searching(node *start, int value);
node *insertion_position(node *start, int value, int pos);

int main(){
	node *start = NULL;
	start = insertion_starting(start,5);
	start = insertion_starting(start,4);
	start = insertion_starting(start,3);
	start = insertion_starting(start,2);
	start = insertion_starting(start,1);
	start = insertion_ending(start,6);
	start = insertion_ending(start,7);
	start = insertion_ending(start,8);
	start = insertion_ending(start,9);
	start = insertion_ending(start,10);

	printf("\n");
	printf("%d\n",total_nodes(start));
	printf("\n");

	printf("\n");
	print(start);
	printf("\n");

	start = deletion_position(start, 5);
	start = deletion_value(start, 10);

	printf("\n");
	print(start);
	printf("\n");

	searching(start,8);
	printf("\n");
	searching(start,11);

	start = insertion_position(start,5,5);
	start = insertion_position(start,10,10);

	printf("\n");
	print(start);
	printf("\n");

	return 0;
}

node *insertion_position(node *start, int value, int pos){
	int total = total_nodes(start);
	if (pos < 0 && pos > total+1){
		printf("CAN'T PROCEED\n");
	}
	if (pos == 0){
		node *newnode = getnode();
		newnode->data = value;
		newnode->next = start;
		newnode->prev = NULL;
		start->prev = newnode;
		start = newnode;
		return start;
	}
	else if (pos == total+1){
		node *newnode = getnode();
		newnode->data = value;
		node *last_node = start;
		while(last_node->next!=NULL){
			last_node = last_node->next;
		}
		last_node->next = newnode;
		newnode->prev = last_node;
		newnode->next = NULL;
		return start;
	}
	else {
		node *temp = start;
		int count = 1;
		while (count != pos-1 ){
			temp = temp->next;
			count++;
		}
		node *newnode =getnode();
		newnode->data = value;
		newnode->next = temp->next;
		newnode->prev = (temp->next)->prev;
		temp->next = newnode;
		(temp->next)->prev = newnode;
		return start;
	}
}

void searching(node *start, int value){
	node *temp = start;
	while (temp!=NULL){
		if (temp->data == value){
			printf("NUMBER %d, FOUND\n",value);
			break;
		}
		if (temp->next == NULL && temp->data != value){
			printf("NUMBER %d, NOT FOUND\n",value);
			break;
		}
		temp = temp->next;
	}
}

node *deletion_value(node *start, int value){
	int total = total_nodes(start);
	node *temp = start;
	int count = 0;
	while(temp->data!=value){
		temp = temp->next;
		count++;
	}
	if (temp->prev == NULL){
		start = temp->next;
		(temp->next)->prev = NULL;
	}
	else if (temp->next == NULL){
		(temp->prev)->next = NULL;
	}
	else {
		(temp->prev)->next = temp->next;
		(temp->next)->prev = temp->prev;
	}
	return start;
}

node *deletion_position(node *start, int pos){
	node *temp = start;
	int count = 1;
	if (pos == 1){
		start = temp->next;
		(temp->next)->prev = NULL;
	}
	else if (count == total_nodes(start)){
		(temp->prev)->next = NULL;
	}
	else {
	 while(count != pos){
		temp = temp->next;
		count++;
		}
		(temp->prev)->next = temp->next;
		(temp->next)->prev = temp->prev;
	}
	return start;
}

node *getnode(){
	node *temp = (node *)malloc(sizeof(node));
	return temp;
}

int total_nodes(node *start){
	node *temp = start;
	int count = 0;
	while (temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

node *insertion_starting(node *start, int value){
	if (start == NULL){
		node *newnode = getnode();
		newnode->data = value;
		newnode->next = NULL;
		newnode->prev = NULL;
		start = newnode;
		return start;
	}
	else {
		node *newnode = getnode();
		newnode->data = value;
		newnode->next = start;
		newnode->prev = NULL;
		start->prev = newnode;
		start = newnode;
		return start;
	}
}

node *insertion_ending(node *start, int value){
	if (start == NULL){
		node *newnode = getnode();
		newnode->data = value;
		newnode->prev = NULL;
		newnode->next = NULL;
		start = newnode;
		return start;
	}
	else{
		node *newnode = getnode();
		newnode->data = value;
		node *last_node = start;
		while(last_node->next!=NULL){
			last_node = last_node->next;
		}
		last_node->next = newnode;
		newnode->prev = last_node;
		newnode->next = NULL;
		return start;
	}
}

void print(node *start){
	node *temp = start;
	while(temp != NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}