// double linked list

#include<stdio.h>
#include<stdlib.h>
#define INVALID -2147483648
typedef struct node{
	int value;
	struct node *lptr;
	struct node *rptr;
}Node;
Node *right=NULL,*left=NULL;

void pushToLeft(int);
void pushToRight(int);
void insert(int,int);
void traversalRight();
void traversalLeft();
int popRight();
int popLeft();

int main(){
	int choice,pushingElement,insertElement,index,popElement,searchElement;
	//menu driven program
	do{
		printf("\n\n\t\t\t\t  menu\n");
		printf("\t\t\t------------------------\n");
		printf("\t\t\t\t1.pushToRight\n");
		printf("\t\t\t\t2.pushToLeft\n");
		printf("\t\t\t\t3.insert after the node\n");
		printf("\t\t\t\t4.popRight\n");
		printf("\t\t\t\t5.popLeft\n");
		printf("\t\t\t\t6.traversalRight\n");
		printf("\t\t\t\t7.traversalLeft\n");
		printf("\t\t\t\t8.exit/quit\n");
		printf("\t\t\t------------------------\n");
		printf("select the operation need to go : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("Enter the 'Element' to pushRigth : ");
				scanf("%d",&pushingElement);
				pushToRight(pushingElement);
				break;
			case 2 :
				printf("Enter the 'Element' to pushLeft : ");
				scanf("%d",&pushingElement);
				pushToLeft(pushingElement);
				break;
			case 3 :
				printf("Enter the element to search : ");
				scanf("%d",&searchElement);
				printf("Enter the element to push : ");
				scanf("%d",&pushingElement);
				insert(searchElement,pushingElement);
				break;
			case 4 :
				popElement=popRight();
				if(popElement==INVALID){
					printf("Err : list is empty \n");
					printf("sugg : try pushRIght or pushLeft");
				}
				else
					printf("%d",popElement);
				break;
			case 5 :
				popElement=popLeft();
				if(popElement==INVALID){
					printf("Err : list is empty \n");
					printf("sugg : try pushRIght or pushLeft");
				}
				else
					printf("%d",popElement);
				break;
			case 6 :
				traversalRight();
				break;
			case 7 :
				traversalLeft();
				break;
			case 8 :
				break;
			default :
				printf("INVALID select thry another \n");
		}
	}
	while(choice!=8);
}

void pushToRight(int pushIt){
	Node *new = (Node *)malloc(sizeof(Node));
	new -> value =pushIt;
	new -> rptr = NULL;
	if(right){
		right->rptr=new;
		new -> lptr = right;
		
	}
	else{
		new -> lptr = NULL;
		left = new;
	}
	right = new;
}
void pushToLeft(int pushIt){
	Node *new = (Node *)malloc(sizeof(Node));
	new -> value =pushIt;
	new -> lptr = NULL;
	if(left){
		left->lptr=new;
		new -> rptr = left;
		
	}
	else{
		new -> lptr = NULL;
		right = new;
	}
	left = new;
}
void insert(int search,int pushIt){
	Node *copyLeft=left;
	Node *new = (Node *)malloc(sizeof(Node));
	while(copyLeft){
		if(search==copyLeft->value){
			new -> value =pushIt;
			new -> lptr = copyLeft;
			new -> rptr = copyLeft->rptr;
			if(copyLeft->rptr)
				copyLeft->rptr->lptr=new;
			else{
				right=new;
			}
			copyLeft->rptr=new;
			break;
		}
		copyLeft=copyLeft->rptr;
	}
}
int popLeft(){
	int returnElement;
	if(left){
		Node *prev=left;
		returnElement = left->value;
		left=left->rptr;
		free(prev);
		if(left)
			left->lptr=NULL;
		else
			right =NULL;
		return returnElement;
	}
	else
		return INVALID;
}
int popRight(){
	int returnElement;
	if(right){
		Node *prev=right;
		returnElement = right->value;
		right=right->lptr;
		free(prev);
		if(right)
			right->rptr=NULL;
		else
			left =NULL;
		return returnElement;
	}
	else
		return INVALID;
}
void traversalRight(){
	Node *tracker=right;
	while(tracker){
		printf("%d->",tracker->value);
		tracker=tracker->lptr;
	}
}
void traversalLeft(){
	Node *tracker=left;
	while(tracker){
		printf("<-%d",tracker->value);
		tracker=tracker->rptr;
	}
}