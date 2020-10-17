#include<stdio.h>
#include<stdlib.h>
#define INVALID -2147483648

typedef struct node{
	int value;
	struct node *next;
}Node;
Node *front=NULL,*rare=NULL;

void insert(int);
int delete();
void display();

void main(){
	int choice,insertElement,deleteElement;
	do{
		printf("\t\t\t\tMain Menu\n");
		printf("\t\t\t\t---------\n");
		printf("\t\t1.insert\n");
		printf("\t\t2.delete\n");
		printf("\t\t3.display\n");
		printf("\t\t4.exit/quit\n");
		printf("Select the operation need to do : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("Enter the 'element' need to insert : ");
				scanf("%d",&insertElement);
				insert(insertElement);
				break;
			case 2 :
				deleteElement=delete();
				if(deleteElement==INVALID)
					printf("Err : the queue is empty\n");
				else
					printf("Deleted : %d",deleteElement);
				break;
			case 3:
				display();
				break;
			case 4 :
				break;
			default :
				printf("INVALID number select another\n");
		}
	}while(choice!=4);
}
void insert(int pushIt){
	Node *new = (Node *)malloc(sizeof(Node));
	new->value=pushIt;
	new->next=NULL;
	if(rare)
		rare->next=new;
	else
		front = new;
	rare=new;
}
int delete(){
	int returnElement=INVALID;
	if(front){
		Node *copyFront=front;
		returnElement=front->value;
		front=front->next;
		free(copyFront);
	}
	else
		rare=NULL;
	return returnElement;
}
void display(){
	Node *frontCopy=front;
	while(frontCopy){
		printf("%d\t",frontCopy->value);
		frontCopy=frontCopy->next;
	}
}