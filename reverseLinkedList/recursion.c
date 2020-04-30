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

void deleteFirst(struct node**head){
    struct node*pointer;
    pointer=*head;
    *head=pointer->link;
    pointer->link=NULL;
}

void addAtEnd(struct node**head,int val){
    struct node*temp1=(struct node*)calloc(1,sizeof(struct node));
    temp1->data=val;
    temp1->link=NULL;
    struct node*p=*head;
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=temp1;
}

void reverse(struct node**head,int n){
    if(n==1){
        return;
    }
    int value=(*head)->data;
    deleteFirst(head);
    reverse(head,n-1);
    addAtEnd(head,value);
}

int main(){
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        addNode();
    }

    reverse(&root,number);
    struct node*ptr=root;
    for(int j=0;j<number;j++){
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    printf("NULL");
    return 0;
}