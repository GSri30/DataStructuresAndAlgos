// floyd's cycle finding algorithm

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*link;
};

struct node*root=NULL;
struct node*root1=NULL;
struct node*p;

void addNode(struct node**head,int num){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->data=num;
    temp->link=NULL;

    if(*head==NULL){
        p=*head=temp;
    }
    else
    {
        p->link=temp;
        p=p->link;
    }
}

bool Distinguisher(struct node**head){
    struct node*p1=*head,*p2=*head;
    while(p2!=NULL){
        p1=p1->link;
        p2=p2->link;
        if(p2!=NULL){
            p2=p2->link;
        }
        else{
            return false;
        }
        if(p1==p2){
            return true;
        }
    }
    return false;
}

int main(){
    struct node*tempPointer;
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        addNode(&root,i+1);
    }
    int number1;
    scanf("%d",&number1);
    for(int j=0;j<number1;j++){
        addNode(&root1,j+2);
        if(j==number1/3){
            tempPointer=p;
        }
    }
    p->link=tempPointer;
    if(Distinguisher(&root)){
        printf("First is cycle\nSecond is linear");
    }
    if(Distinguisher(&root1)){
        printf("First is linear\nSecond is cycle");
    }
    return 0;
}

