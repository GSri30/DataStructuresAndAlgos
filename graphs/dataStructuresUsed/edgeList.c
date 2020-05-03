#include<stdio.h>
#include<stdlib.h>

//un-weighted

struct node{
    int i;
    int j;
    struct node*link;
};

void addToEL(struct node**root,int i,int j){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->i=i;temp->j=j;
    if(*root==NULL){
        *root=temp;
    }
    else{
        struct node*pointer=*root;
        while(pointer->link){
            pointer=pointer->link;
        }
        pointer->link=temp;
    }
}

//weighted

struct node_w{
    int i;
    int j;
    int weight;
    struct node_w*link;
};

void addToEL_W(struct node_w**root,int i,int j,int weight){
    struct node_w*temp=(struct node_w*)calloc(1,sizeof(struct node_w));
    temp->i=i;temp->j=j;temp->weight=weight;
    if(*root==NULL){
        *root=temp;
    }
    else{
        struct node_w*pointer=*root;
        while(pointer->link){
            pointer=pointer->link;
        }
        pointer->link=temp;
    }
}

int main(){
    struct node_w*root=NULL;
    addToEL_W(&root,2,3,5);
    printf("%d %d %d",root->i,root->j,root->weight);
    return 0;
}