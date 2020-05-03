#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y){int temp=x;x=y;y=temp;}
#define SIZE 1000000
#define MAX 1000000

struct node{
    int weight;
    int j;
};

void minBottomUpHeapify(int i,struct node*heap,int*converter){
    int p=(i-1)/2;
    while(p>=0 && (heap[p].weight)>(heap[i].weight)){
        SWAP(heap[p].weight,heap[i].weight);
        SWAP(heap[p].j,heap[i].j);
        converter[heap[p].j]=p;converter[heap[i].j]=i;
        i=p;
        p=(i-1)/2;
    }
}

void minTopDownHeapify(int i,struct node*heap,int n,int*converter){
    int child;
    while(2*i+2<n){
        int child=(heap[2*i+1].weight<heap[2*i+2].weight) ? 2*i+1 : 2*i+2;
        if(heap[i].weight>heap[child].weight){
            SWAP(heap[i].weight,heap[child].weight);
            SWAP(heap[i].j,heap[child].j);
            converter[heap[i].j]=i;converter[heap[child].j]=child;
            i=child;
        }
        else{
            break;
        }
    }
    if(2*i+1<n && heap[i].weight>heap[2*i+1].weight){
        SWAP(heap[i].weight,heap[2*i+1].weight);
        SWAP(heap[i].j,heap[2*i+1].j);
        converter[heap[i].j]=i;converter[heap[2*i+1].j]=2*i+1;
    }
}

void minDeleteMin(struct node*heap,int*length,int*converter){
    SWAP(heap[0].weight,heap[*length-1].weight);
    SWAP(heap[0].j,heap[*length-1].j);
    converter[heap[0].j]=0;converter[heap[(*length)-1].j]=(*length)-1;
    *length=*length-1;
    minTopDownHeapify(0,heap,*length,converter);
}

void minUpdateNode(int i,int value,struct node*heap,int length,int*converter){
    if(heap[i].weight>value){
        heap[i].weight=value;
        minBottomUpHeapify(i,heap,converter);
    }
    else if(heap[i].weight<value){
        heap[i].weight=value;
        minTopDownHeapify(i,heap,length,converter);
    }
}


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




int*dijkstra(struct node_w**al,int source,int n){
    int*flag=(int*)calloc(n,sizeof(int));
    int*phi=(int*)calloc(n,sizeof(int));
    int*sd=(int*)calloc(n,sizeof(int));
    int*converter=(int*)calloc(n,sizeof(int));
    struct node*heap=(struct node*)calloc(n,sizeof(struct node));

    for(int i=0;i<n;i++){
        flag[i]=0;phi[i]=-2;sd[i]=MAX;heap[i].weight=MAX;heap[i].j=i;converter[heap[i].j]=i;
    }

    sd[source]=0;minUpdateNode(source,0,heap,n,converter);phi[source]=-1;int len=n;

    while(len>0){
        int u=heap[0].j;minDeleteMin(heap,&len,converter);flag[u]=1;
        struct node_w*pointer=al[u];
        while(pointer){
            if(!flag[pointer->data] && sd[pointer->data]>sd[u]+pointer->weight){
                sd[pointer->data]=sd[u]+pointer->weight;
                minUpdateNode(converter[pointer->data],sd[u]+pointer->weight,heap,len,converter);
                phi[pointer->data]=u;
            }
            pointer=pointer->link;
        }   
    }
    return sd;
}

int main(){
    struct node_w**al=adjacencyList_W();
    addIntoAL_W(al,0,1,5);addIntoAL_W(al,0,2,10);addIntoAL_W(al,2,3,20);addIntoAL_W(al,0,2,10);
    int*sd=dijkstra(al,0,4);
    for(int i=0;i<4;i++){
        printf("%d ",sd[i]);
    }
    return 0;
}