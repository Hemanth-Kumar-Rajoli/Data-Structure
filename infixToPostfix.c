// converting the infix expression in to the postfix expression
//here postfix stack head is located to the bottom
//here operators(stack) head is located to the top

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define SIZE 100

int isOperator(char);
int operatorValue(char);
void stackPush(char);
void postfixPush(char);
char stackPop();


typedef struct node{
	char value;
	struct node *next;
}Node;
void printer(Node *);

Node *postfix=NULL,*stack=NULL,*prev=NULL;
int main(){
	char expression[SIZE],temp;
	int i=0,operatorRank,length;
	printf("Enter the expression with out the spaces between the operator and operend : \n");
	expression[0]='(';
	scanf("%s",&expression[1]);
	length=strlen(expression);
	expression[length]=')';
	expression[length+1]='\0';
	temp=expression[i];
	while(temp!='\0'){
		if(isOperator(temp)){
			if(temp==')'){
				while(stack->value!='('){
					postfixPush(stackPop());
				}
				stack=stack->next;
			}
			else{
				while(stack && (operatorValue(temp)<=operatorValue(stack->value) && temp!='(')){
					postfixPush(stackPop());
				}
				stackPush(temp);
			}
		}
		else{
			postfixPush(temp);
		}
		temp=expression[++i];
	}
	
	printer(postfix);

}
int isOperator(char c){
	return (c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')');
}
int operatorValue(char c){
	if(c=='(')
		return 1;
	else if(c=='*' || c=='/')
		return 3;
	else if(c=='+' || c=='-')
		return 2;
	else
		return 0;
}

void stackPush(char opr){
	Node *new =(Node *)malloc(sizeof(Node));
	new -> value =opr;
	new -> next =stack;
	stack=new;
}
void postfixPush(char opr){
	Node *new =(Node *)malloc(sizeof(Node));
	new -> value =opr;
	if(prev){
		prev->next=new;
		new->next=NULL;
	}
	else{
		postfix=new;
		new->next=prev;
	}
	prev=new;
}
char stackPop(){
	Node *tracker=stack;
	char returnValue=tracker->value;
	stack=stack->next;
	free(tracker);
	return(returnValue);
}
void printer(Node *runner){
	while(runner){
		printf("%c",runner->value);
		runner = runner -> next;
	}
}