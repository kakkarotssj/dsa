#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *next;
	int data;
};
typedef struct node node;

node *insertion_starting(node *start,int value);
node *insertion_ending(node *start,int value);
void print(node *start);
int total_count(node *start);
node *getnode();
node *deletion_position(node *start,int pos);
node *deletion_value(node *start,int value);

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

	int total = total_count(start);
	printf("\n\n");
	print(start);	
	printf("\n\n");
	printf("total number of nodes is : %d",total);
	printf("\n\n");
	
	start = deletion_position(start,5);
	print(start);
	printf("\n\n");
	start = deletion_value(start,8);
	print(start);
	printf("\n\n");

return 0;
}

node *getnode(){
	node *temp;
	temp = (node *)malloc(sizeof(node));
	return temp;
}

node *deletion_value(node *start,int value){
	node *temp = start;
	if (temp->data == value){
		start = temp->next;
		return start;	
	}
	else {
		temp = temp->next;
		while(temp->data != value){
			temp = temp->next;
		}
		node *extra = start;
		extra = extra->next;
		while(extra->next!=temp){
			extra = extra->next;
		}
		extra->next = temp->next;
		return start;
	}
}

node *deletion_position(node *start,int pos){
	int total_nodes = total_count(start);
	if (pos == 1){
		node *first_node = start;
		start = first_node->next;
		return start;
	}
	else if (pos == total_nodes){
		node *temp = start;
		temp = temp->next;
		while(temp->next!=start){
			temp = temp->next;
		}
		node *extra = start;
		extra = extra->next;
		while(extra->next->next!=start){
			extra = extra->next;
		}
		extra->next = temp->next;
		return start;
	}
	else {
	
        	node *temp = start;
		int count = 1;
       		while(count != pos){
                temp = temp->next;
                count++;
        	}
        	count = 2;
        	node *extra = start;
        	while (count!=pos){
                	count++;
                	extra = extra->next;
        	}
        	extra->next = temp->next;
        	return start;
	}
}

node *insertion_starting(node *start,int value){
	if (start == NULL){
		node *newnode = getnode();
		newnode->next = newnode;
		start = newnode;
		newnode->data = value;
		return start;	
	}
	else {
		node *newnode = getnode();
		node *temp = start;
		newnode->data = value;
		while(temp->next != start){
				temp = temp->next;
			}
		newnode->next = start;
		temp->next = newnode;
		start = newnode;
		return start;
	}

}

node *insertion_ending(node *start, int value){
	if (start == NULL){
		node *newnode = getnode();
		newnode->data = value;
		newnode->next = newnode;
		start = newnode;
		return start;
	}
	else{
		node *newnode = getnode();
		newnode->data = value;
		node *temp = start;
		temp = temp->next;
		while (temp->next!=start){
			temp = temp->next;
		}
		newnode->next = start;
		temp->next = newnode;
		return start;
	}
}

int total_count(node *start){
	int count = 1;
	node *temp = start;
	temp = temp->next;
	while(temp!=start){
		temp = temp->next;
		count++;
	}
	return count;
}

void print(node *start){
	node *temp = start;
	printf("%d",temp->data);
	temp = temp->next;
	while(temp!=start){
		printf("%d",temp->data);
		temp=temp->next;
	}
}
