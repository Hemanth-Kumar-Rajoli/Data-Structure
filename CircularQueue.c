#include<stdio.h>
#define size 6
#define INVALID -2147483648

void insert(int);
void traversal();
int delete();

//global variables and arrays
int queue[size];
int rare=-1,front=-1;

int main(){
	int insertElement,deleteElement,choice;
	do{
		printf("\t\t\t\tmenu\n");
		printf("\t\t\t--------------------\n");
		printf("\t\t1.insert\n");
		printf("\t\t2.delete\n");
		printf("\t\t3.traversal\n");
		printf("\t\t4.exit/quit\n");
		printf("Select the operation : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 :
				printf("enter the element to insert : ");
				scanf("%d",&insertElement);
				insert(insertElement);
				break;
			case 2 :
				deleteElement=delete();
				if(deleteElement==INVALID)
					printf("The array is empty \n");
				else
					printf("Deleted %d\n",deleteElement);
				break;
			case 3 :
				traversal();
				break;
			case 4 :
				break;
			default:
				printf("Invalid selected choice pls sellect other\n");
		}
	}while(choice!=4);
}
/*
	step1:
		check if front is besides the rare or not
		1.1:
			if yes then array is full so we come out of the function
		1.2:
			if not then move the element to next index(between 0 and size)
	step2:
		2.1:
			if front is -1 make change to 0
*/
void insert(int insertIt){
	if(front==(rare+1)%size){
		printf("Err : queue is out of boundary \n");
		return;
	}
	queue[(++rare)%size]=insertIt;
	rare=rare%size;
	if(front==-1)
		front=0;
	printf("inserted the element\n");
}
/*
	step3:
		3.1:
			check if array is empty or not by condition front or rare =-1
			3.1.1:
				if Not we loop throught the queue until front(coped value) and rare values are equal
*/
void traversal(){
	if(front!=-1){
		int count=0;
		int copyFront=front;
		while(copyFront==rare || count!=1){
			printf("%d\t",queue[copyFront]);
			if(copyFront==rare)
				count=1;
			copyFront=(++copyFront)%size;
		}
	}
}
/*
	step4:
		4.1:
			check queue is empty or not if empty return invalid number
		4.2:
			then check if the queue has only one element then make the front and rare to -1(original position)
		4.3:
			if the queue has more than one element then move the front to next index 
		4.4:
			before checking the queue elements copy the deleting element and return it at last
*/
int delete(){
	int copyElement;
	if(front==-1){
		return INVALID;
	}
	copyElement=queue[front];
	if(front==rare){
		rare=-1;
		front=-1;
	}
	else
		front=(++front)%size;
	return copyElement;
}