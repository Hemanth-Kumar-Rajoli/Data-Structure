//implementaion of stack using single linked list

#include<stdio.h>
#include<stdlib.h>
#define INVALID -2147483648

void push(int);
int pop();
void traversal();

typedef struct node{
	int value;
	struct node *next;
}Node;
Node *top=NULL;
int main(){
	int choice,pushElement,popElement;
	do{
		printf("\t\t\t\t\tmenu\n");
		printf("\t\t\t\t--------------------\n");
		printf("\t\t\t1.push\n");
		printf("\t\t\t2.pop\n");
		printf("\t\t\t3.traversal\n");
		printf("\t\t\t4.quit/exit\n");
		printf("Enter the choice for operation to work : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("Enter the 'element' to push : ");
				scanf("%d",&pushElement);
				push(pushElement);
				break;
			case 2 :
				popElement = pop();
				if(popElement!=INVALID)
					printf("%d\n",popElement);
				else{
					printf("err : the stack is empty\n");
					printf("suggest : try to push\n");
					break;
				}
				break;
			case 3 :
				traversal();
				break;
			case 4 :
				break;
			default :
				printf("err : INVALID key try another\n");
			
		}
	}
	while(choice!=4);
}

//operataion goes here
//push operation

void push(int pushIt){
	Node *new =(Node *)malloc(sizeof(Node));
	new -> value =pushIt;
	new -> next = top;
	top = new; 
}
//pop operation
int pop(){
	int returnElement;
	Node *temp;
	if(top){
		returnElement=top->value;
		temp = top;
		top=top->next;
		free(temp);
	}
	else
		returnElement=INVALID;
	return returnElement;
}
//traversal operation
void traversal(){
	Node *temp=top;
	while(temp){
		printf("<-%d",temp->value);
		temp=temp->next;
	}	
}


