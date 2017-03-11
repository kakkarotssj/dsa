#include <stdio.h>
#include <stdlib.h>

int stack[10];
int top = -1;
void push(int num);
void  pop();
void peek();
void print();
void update(int pos, int num);

int main(){
	push(5); push(6); push(7); push(8);
	pop();
	push(9); push(10);
	printf("\n"); print(); printf("\n");
	update(3,50);
	printf("\n"); print(); printf("\n");

	return 0;
}

void update(int pos, int num){
	if (pos < 0 || pos > top){
		printf("CAN'T UPDATE\n");
	}
	else {
		stack[pos-1] = num;
	}
}

void print(){
	if (top < 0){
		printf("STACK IS EMPTY!\n");
	}
	else {
		int i = 0;
		printf("WHOLE STACK IS : \n");
		for (;i<=top;i++){
			printf("%d\n",stack[i]);
		}
	}
}

void push(int num){
	if (top > 9){
		printf("LIMIT EXCEEDED! STACK IS FULL!!\n");
	}
	else {
		top++;
		stack[top] = num;
	}
}

void pop(){
	if (top < 0 || top >9){
		printf("NOTHING TO POP!!!\n");
	} 
	else {
		top--;
	}
}

void peek(){
	printf("PEEK element IS : %d \n",stack[top]);
}