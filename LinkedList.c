//single linked list 

#include<stdio.h>
#include<stdlib.h>
#define Null 0

int length=0;
void push(int);
void pop();
void traversal();
void insert(int,int);
void add(int);

typedef struct node{
	int i;
	struct node *next;
}Node;

Node *head = Null;

int main(){
	int choice,pushingElement,insertElement,index;
	//menu driven program
	do{
		printf("\n\n\t\t\t\t  menu\n");
		printf("\t\t\t========================\n");
		printf("\t\t\t\t1.push\n");
		printf("\t\t\t\t2.add\n");
		printf("\t\t\t\t3.insert\n");
		printf("\t\t\t\t4.pop\n");
		printf("\t\t\t\t5.traversal\n");
		printf("\t\t\t\t6.exit/quit\n");
		printf("\t\t\t========================\n");
		printf("select the operation need to go : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("enter the number to push : ");
				scanf("%d",&pushingElement);
				push(pushingElement);
				length++;
				break;
			case 2 :
				printf("enter the number to add : ");
				scanf("%d",&pushingElement);
				add(pushingElement);
				length++;
				break;
			case 3 :
				printf("enter the 'INDEX' to insert : ");
				scanf("%d",&index);
				printf("enter the 'ELEMENT' to insert : ");
				scanf("%d",&insertElement);
				insert(index,insertElement);
				break;
			case 4 :
				pop();
				break;
			case 5 :
				traversal();
				break;
		}
		

	}
	while(choice!=6);
}

//push function

void push(int pushIt){
	Node *new =(Node *)malloc(sizeof(Node));
	new -> i =pushIt;
	new -> next = head;
	head = new;	
}
//adding the element at starting index;

void add(int pushIt){
	Node *jumper=head;
	Node *adder =(Node *)malloc(sizeof(Node));
	adder -> i=pushIt;
	if(jumper==Null){
		
		adder -> next =Null;
		head = adder;
	}
	else{
		while(jumper -> next){
			jumper = jumper->next;
		}
		adder -> next = Null;
		jumper -> next =adder;
	}
}

//inserting the element at given index;
void insert(int indexTo,int pushIt){
	indexTo++;
	Node *inserter =(Node *)malloc(sizeof(Node));
	inserter -> i =pushIt;
	if(indexTo<=length){
		Node *jumper=head;
		for(int j=0;j<length-indexTo;j++){
			jumper = jumper->next;
		}
		inserter->next=jumper->next;
		jumper -> next = inserter;
		length++;
	}
	else{
		printf("error : taken length is out of range\nsuggest : try 'push' or 'add' methods\n");
	}
}
// pop function

void pop(){
	if(head != Null){
		printf("%d",head -> i);
		head = head -> next;
		length--;
	}
	else{
		printf("The link is empty");	
	}
}
// diaplaying the content

void traversal(){
	Node *pointer=head;
	while(pointer){
	printf("<-%d",pointer->i);
	pointer = pointer->next;
	}
}

