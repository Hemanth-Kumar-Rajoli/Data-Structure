#include<stdio.h>
#include<stdlib.h>
// double linked list creation
typedef struct bnode{
    struct bnode *lptr;
    int value;
    struct bnode *rptr;
}Bnode;
Bnode *root=NULL;

void insert(int);
void delete(int);
void TraversalPostOrder(Bnode *);
void TraversalPreOrder(Bnode *);
void TraversalInOrder(Bnode *);



void main(){
    int choice,item;
    do{
        printf("\n\t\t\tMenu");
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.traversal - postOrder");
        printf("\n4.traversal - preOrder");
        printf("\n5.traversal - inOrder");
        printf("\nExit");
        printf("\nenter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                printf("\nenter the element to enter : ");
                scanf("%d",&item);
                insert(item); 
                break;
            case 2 :
                printf("\nenter the element to delete : ");
                scanf("%d",&item);
                delete(item); 
                break;
            case 3 :
                printf("\n traversal in post-order\n");
                TraversalPostOrder(root);
                break;
            case 4 :
                printf("\n traversal in pre-order\n");
                TraversalPreOrder(root); 
                break;
            case 5 : 
                printf("\n traversal in in-order\n");
                TraversalInOrder(root);
                break;
            case 6 : break;
        }
    }while(choice!=6);
}
void insert(int insertIt){
    Bnode *new=(Bnode *)malloc(sizeof(Bnode));
    new->value=insertIt;
    new->lptr=NULL;
    new->rptr=NULL;
    if(root){
        Bnode *copy=root;
        while(!((copy->value>insertIt && !copy->lptr) || (copy->value<=insertIt && !copy->rptr))){
            if(copy->value>insertIt)
                copy=copy->lptr;
            else
                copy= copy->rptr;
        }
        if(copy->value>insertIt)
            copy->lptr=new;
        else
            copy->rptr=new;
    }
    else{
        root=new;
    }
}
void delete(int value){
    Bnode *curr = root,*prev=root;
    while(curr!=NULL && curr->value!=value){
        prev = curr;
        if(value>curr->value)
            curr=curr->rptr;
        else
            curr=curr->lptr;
    }
    if(curr!=NULL){
        if(curr->lptr==NULL && curr->rptr==NULL){
            if(curr==root)
                root=NULL;
            else if(value>prev->value)
                prev->rptr=NULL;
            else
                prev->lptr=NULL;
        }
        else if(curr->lptr!=NULL && curr->rptr!=NULL){
            if(curr==root)
                root=curr->rptr;
            else if(value>prev->value)
                prev->rptr=curr->rptr;
            Bnode *copy=curr->rptr;
            while(copy->lptr!=NULL)
                copy=copy->lptr; 
            copy->lptr=curr->lptr;
        }
        else{
            if(curr->value>value){
                if(curr==root)
                    root=curr->rptr;
                else
                    prev->rptr=curr->rptr;
            }
            else{
                if(curr==root)
                    root=curr->lptr;
                else
                    prev->lptr=curr->lptr;
            }
        }
        free(curr);
    }
    else
        printf("\nthe value did not found\n");
}
void TraversalPostOrder(Bnode *takenRoot){
    Bnode *copy=takenRoot;
    if(copy){
        TraversalPostOrder(copy->lptr);
        TraversalPostOrder(copy->rptr);
        printf("%d->",copy->value);
    }
}
void TraversalPreOrder(Bnode *takenRoot){
    Bnode *copy=takenRoot;
    if(copy){
        printf("%d->",copy->value);
        TraversalPreOrder(copy->lptr);
        TraversalPreOrder(copy->rptr);
    }
}
void TraversalInOrder(Bnode *takenRoot){
    Bnode *copy=takenRoot;
    if(copy){
        TraversalInOrder(copy->lptr);
        printf("%d->",copy->value);
        TraversalInOrder(copy->rptr);
    }

}