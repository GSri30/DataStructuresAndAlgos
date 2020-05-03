//Single Source shortest Path problem
//Uses edge list

#include<stdio.h>
#include<stdlib.h>

#define MAX 100000

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

int*bellmanFord(struct node_w*el,int n,int source){
    int*sd=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        sd[i]=MAX;
    }
    sd[source]=0;
    for(int a=0;a<n;a++){
        struct node_w*temp=el;
        while(temp){
            if(sd[temp->j]>sd[temp->i]+temp->weight){
                sd[temp->j]=sd[temp->i]+temp->weight;
            }
            temp=temp->link;
        }
    }
    return sd;
}

int main(){
    struct node_w*root=NULL;
    addToEL_W(&root,0,1,5);addToEL_W(&root,0,2,10);addToEL_W(&root,1,2,3);
    int*sd=bellmanFord(root,3,0);
    for(int i=0;i<3;i++){
        printf("%d ",sd[i]);
    }
    return 0;
}