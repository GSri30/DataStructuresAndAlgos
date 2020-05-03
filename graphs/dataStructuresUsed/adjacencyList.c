#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000000

//un-weighted
struct node{
    int data;
    struct node*link;
};

struct node**adjacencyList(){
    struct node**adjacencyList=(struct node**)calloc(SIZE,sizeof(struct node*));
    for(int i=0;i<SIZE;i++){
        adjacencyList[i]=NULL;
    }
    return adjacencyList;
}

void addIntoAL(struct node**adjacencyList,int i,int j){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->data=j;
    struct node*iPointer=adjacencyList[i];
    if(iPointer==NULL){
        adjacencyList[i]=temp;
    }
    else{
        while(iPointer->link){
            iPointer=iPointer->link;
        }
        iPointer->link=temp;
    }
}

//weighted
struct node_w{
    int data;
    int weight;
    struct node_w*link;
};

struct node_w**adjacencyList_W(){
    struct node_w**adjacencyList=(struct node_w**)calloc(SIZE,sizeof(struct node_w*));
    for(int i=0;i<SIZE;i++){
        adjacencyList[i]=NULL;
    }
    return adjacencyList;
}

void addIntoAL_W(struct node_w**adjacencyList,int i,int j,int weight){
    struct node_w*temp=(struct node_w*)calloc(1,sizeof(struct node_w));
    temp->data=j;
    temp->weight=weight;
    struct node_w*iPointer=adjacencyList[i];
    if(iPointer==NULL){
        adjacencyList[i]=temp;
    }
    else{
        while(iPointer->link){
            iPointer=iPointer->link;
        }
        iPointer->link=temp;
    }
}



int main(){
    struct node_w**al=adjacencyList_W();
    addIntoAL_W(al,3,10,50);
    addIntoAL_W(al,3,20,60);
    struct node_w*pointer=al[3];
    printf("%d %d",pointer->link->data,pointer->link->weight);
    free(al);
    return 0;
}