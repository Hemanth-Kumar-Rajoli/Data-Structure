// Adding of two polynamials
#include<stdio.h>
#include<stdlib.h>
#define Null 0;
typedef struct node{
	int coeff;
	int exp;
	struct node *next;
}Node;

int main(){
	Node *poly1,*poly2;
	int coeff;
	Node *prev = Null;
	// for poly one;
	printf("enter the polynamial 'one' coefficient(-1 to exit) exp :\n");
	while(1){
		Node *curr = (Node *)malloc(sizeof(Node));
		
		scanf("%d",&coeff);
		if(coeff==-1)
			break;
		curr -> coeff =coeff;
		scanf("%d",&curr -> exp);
		if(prev){
			prev -> next = curr;
			curr -> next = Null;
			
		}
		else{
			curr -> next = prev;
			poly1 = curr;
		}
		prev = curr;
	}
	//for poly two
	prev =Null;
	printf("enter the polynamial 'two' coefficient(-1 to exit) exp :\n");
	while(1){
		Node *curr = (Node *)malloc(sizeof(Node));
		
		scanf("%d",&coeff);
		if(coeff==-1)
			break;
		curr -> coeff =coeff;
		scanf("%d",&curr -> exp);
		if(prev){
			prev -> next = curr;
			curr -> next = Null;
		}
		else{
			curr -> next = prev;
			poly2 = curr;
		}
		prev = curr;
		
	}

	//comparing two polynomails;
	Node *curr1=poly1,*curr2=poly2,*poly3,*newprev=Null;
	while(curr1 && curr2){
		Node *new = (Node *)malloc(sizeof(Node));
		if(curr1->exp > curr2 -> exp){
			new->coeff=curr1->coeff;
			new->exp=curr1->exp;
			curr1=curr1->next;
		}
		else if(curr1->exp < curr2 -> exp){
			new->coeff=curr2->coeff;
			new->exp=curr2->exp;
			curr2=curr2->next;
		}
		else{
			new->coeff=curr1->coeff+curr2->coeff;
			new->exp=curr1->exp;
			curr1=curr1->next;
			curr2 =curr2->next;
		}
		
		if(newprev){
			
			newprev->next=new;
			new->next=Null;
		}
		else{
			new->next=Null
			poly3 = new;
		}
		newprev=new;
	}
	
	while(curr1){
		Node *new = (Node *)malloc(sizeof(Node));
		new->coeff=curr1->coeff;
		new->exp=curr1->exp;
		newprev->next=new;
		newprev=new;
		new -> next =Null;
		curr1= curr1->next;
	}
	while(curr2){
		Node *new = (Node *)malloc(sizeof(Node));
		new->coeff=curr2->coeff;
		new->exp=curr2->exp;
		newprev->next=new;
		newprev=new;
		new -> next =Null;
		curr2= curr2->next;
	}
	//result poly
	while(poly3){
		printf("%d->%d\n",poly3->coeff,poly3->exp);
		poly3=poly3->next;
	}
}