//Breadth First search
//We use a queue and adjacency list here
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

void bfs(struct node**al,int n,int source){
    int*queue=(int*)calloc(1000000,sizeof(int));
    int bottom=-1,top=-1;
    int*phi=(int*)calloc(n,sizeof(int));
    int*flag=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        phi[i]=-2;flag[i]=0;
    }
    queue[++top]=source;phi[source]=-1;flag[source]=1;
    while(bottom<top){
        int u=queue[++bottom];
        printf("%d ",u);
        struct node*ptr=al[u];
        while(ptr){
            if(!flag[ptr->data]){
                queue[++top]=ptr->data;flag[ptr->data]=1;phi[ptr->data]=u;
            }
            ptr=ptr->link;
        }
    }
}

int main(){
    struct node**al=adjacencyList();
    addIntoAL(al,1,2);addIntoAL(al,2,3);addIntoAL(al,3,4);
    bfs(al,3,1);
    return 0;
}

