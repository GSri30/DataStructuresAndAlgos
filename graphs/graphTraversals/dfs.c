//Depth first search
//We use a stack and adjacency list

#include<stdlib.h>
#include<stdio.h>

#define SIZE 1000000

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

void dfs(struct node**al,int n,int source){
    int*stack=(int*)calloc(1000000,sizeof(int));
    int top=-1;
    int*phi=(int*)calloc(n,sizeof(int));
    int*flag=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){   
        phi[i]=-2;flag[i]=0;
    }
    stack[++top]=source;phi[source]=-1;
    while(top>=0){
        int u=stack[top--];
        if(!flag[u]){
            printf("%d ",u);flag[u]=1;
            struct node*ptr=al[u];
            while(ptr){
                if(!flag[ptr->data]){
                    stack[++top]=ptr->data;phi[ptr->data]=u;
                }
                ptr=ptr->link;
            }
        }
    }
}

int main(){
    struct node**al=adjacencyList();
    addIntoAL(al,1,2);addIntoAL(al,1,3);addIntoAL(al,2,5);
    dfs(al,4,1);
    return 0;
}