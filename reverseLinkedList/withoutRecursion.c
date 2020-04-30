#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node*link;
};

struct node*root=NULL;
struct node*p;

void addNode(){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    scanf("%d",&(temp->data));
    temp->link=NULL;

    if(root==NULL){
        p=root=temp;
    }
    else
    {
        p->link=temp;
        p=p->link;
    }
}

void reverse(struct node**head,int num){
    struct node*previous=NULL,*current=*head,*next;
    for(int i=0;i<num;i++){
        next=current->link;
        current->link=previous;
        previous=current;
        current=next;
    }
    root=previous;
}

int main(){
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        addNode();
    }
    reverse(&root,number);
    struct node*ptr=root;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    printf("NULL");
    return 0;
}