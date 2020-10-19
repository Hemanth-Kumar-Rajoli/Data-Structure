#include<stdio.h>
#define size 6
#define INVALID -2147483648

void insertRight(int);
void insertLeft(int);
void traversal();
int deleteRight();
int deleteLeft();

int deque[size];
int left=-1,right=-1;

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
	if(right==-1){
		left=0;
	}
	if(right!=size-1){
		deque[++right]=pushIt;
	}
	else{
		printf("Err : deque is full\n");
		printf("sugg : try to insert at left (if exits) \n");
	}
}
void insertLeft(int pushIt){
	if(left==-1){
		right=0;
	}
	if(left>0){
		deque[--left]=pushIt;
	}
	else{
		printf("Err : Invalid there is no space to insert at left\n");
		printf("Sugg : try to delete the the left most value (if exist) \n");
	}
}
int deleteRight(){
	int returnElement=INVALID;
	if(right!=-1 || left !=-1){
		if(right==left){
			returnElement=deque[right];
			left=right=-1;
		}
		else if(right>left){
			returnElement=deque[right--];
		}	
	}
	return returnElement;
}
int deleteLeft(){
	int returnElement=INVALID;
	if(right!=-1 || left !=-1){
		if(right==left){
			returnElement=deque[left];
			left=right=-1;
		}
		else if(left<right){
			returnElement=deque[left++];
		}
		
	}
	return returnElement;
}
void traversal(){
	for(int i=left;i<=right;i++){
		printf("%d\t",deque[i]);
	}
	printf("\n");
 }