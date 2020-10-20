#include<stdio.h>
#include<stdlib.h>
#define INVALID -2147483648

typedef struct node{
	int value;
	struct node *next;
}Node;

void insertRight(int);
void insertLeft(int);
void traversal();
int deleteRight();
int deleteLeft();

Node *left=NULL,*right=NULL;

int main(){
	int insertElement,deleteElement,choice;
	do{
		printf("\t\t\t\tmenu\n");
		printf("\t\t\t--------------------\n");
		printf("\t\t1.insertRight\n");
		printf("\t\t2.insertLeft\n");
		printf("\t\t3.deleteRight\n");
		printf("\t\t4.deleteLeft\n");
		printf("\t\t5.traversal\n");
		printf("\t\t6.exit/quit\n");
		printf("Select the operation : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("enter the element to insert to right : ");
				scanf("%d",&insertElement);
				insertRight(insertElement);
				break;
			case 2 :
				printf("enter the element to insert to left : ");
				scanf("%d",&insertElement);
				insertLeft(insertElement);
				break;
			case 3 :
				deleteElement=deleteRight();
				if(deleteElement==INVALID)
					printf("Err : deque is empty\n");
				else
					printf("Delete : %d",deleteElement);
				break;
			case 4 :
				deleteElement=deleteLeft();
				if(deleteElement==INVALID)
					printf("Err : deque is empty\n");
				else
					printf("Delete : %d",deleteElement);
				break;
			case 5 :
				traversal();
				break;
			case 6 :
				break;
			case 7 :
				printf("right : %d\nleft : %d\n",right,left);
			default:
				printf("Invalid selected choice pls sellect other\n");
		}
	}while(choice!=6);
}
void insertRight(int pushIt){
	Node *new = (Node *)malloc(sizeof(Node));
	new->value=pushIt;
	new->next=NULL;
	if(right)
		right->next=new;
	else
		left=new;
	right=new;
}
void insertLeft(int pushIt){
	Node *new =(Node *)malloc(sizeof(Node));
	new->value=pushIt;
	new->next=left;
	if(!left)
		right=new;
	left=new;

}
int deleteLeft(){
	int returnElement=INVALID;
	Node *copyLefttt=left;
	if(left || right){
		returnElement=left->value;
		left=left->next;
		if(!left){
			right=NULL;
		}
		free(copyLefttt);
	}
	return returnElement;
}
int deleteRight(){
	int returnElement=INVALID;
	Node *copyRight=right,*copyLeft=left;
	if(left || right){
		returnElement=right->value;
		free(copyRight);
		if(left==right)
			left=right=NULL;
		else{
			while(copyLeft->next!=right)
				copyLeft=copyLeft->next;
			right=copyLeft;
			right->next=NULL;
			
		}
			
	}
	return returnElement;
}
void traversal(){
	Node *copyLeft=left;
	if(left || right){
		do{
			printf("%d\t",copyLeft->value);
			copyLeft=copyLeft->next;
		}while(copyLeft!=NULL);
		printf("\n");
	}
}