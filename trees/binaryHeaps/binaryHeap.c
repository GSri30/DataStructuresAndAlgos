#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y){int temp=x;x=y;y=temp;}

//Min heap

void minBottomUpHeapify(int i,int*heap){
    int p=(i-1)/2;
    while(p>=0 && (heap[p])>(heap[i])){
        SWAP(heap[p],heap[i]);
        i=p;
        p=(i-1)/2;
    }
}

void minTopDownHeapify(int i,int*heap,int n){
    int child;
    while(2*i+2<n){
        int child=(heap[2*i+1]<heap[2*i+2]) ? 2*i+1 : 2*i+2;
        if(heap[i]>heap[child]){
            SWAP(heap[i],heap[child]);
            i=child;
        }
        else{
            break;
        }
    }
    if(2*i+1<n && heap[i]>heap[2*i+1]){
        SWAP(heap[i],heap[2*i+1]);
    }
}

void minAddNode(int x,int*heap,int*length){
    heap[*length]=x;
    *length=*length+1;
    minBottomUpHeapify(*length-1,heap);
}

void minDeleteMin(int*heap,int*length){
    SWAP(heap[0],heap[*length-1]);
    *length=*length-1;
    minTopDownHeapify(0,heap,*length);
}

void minUpdateNode(int i,int value,int*heap,int length){
    if(heap[i]>value){
        heap[i]=value;
        minBottomUpHeapify(i,heap);
    }
    else if(heap[i]<value){
        heap[i]=value;
        minTopDownHeapify(i,heap,length);
    }
}

void minDeleteGeneralNode(int i,int*heap,int*length){
    minUpdateNode(i,heap[0]-1,heap,*length);
    minDeleteMin(heap,length);
}

void minBuildHeap(int*heap,int length){
    for(int i=((length)/2)-1;i>-1;i--){
        minTopDownHeapify(i,heap,length);
    }
}

//NonOptimised
// void BuildHeap(int heap[], int length)
// {
//     for(int i =0; i<length; i++)
//     {
//         BottomUpHeapify(heap, i);
//     }
// }


//Max heap

void maxBottomUpHeapify(int i,int*heap){
    int p=(i-1)/2;
    while(p>=0 && (heap[p])<(heap[i])){
        SWAP(heap[p],heap[i]);
        i=p;
        p=(i-1)/2;
    }
}

void maxTopDownHeapify(int i,int*heap,int n){
    int child;
    while(2*i+2<n){
        int child=(heap[2*i+1]>heap[2*i+2]) ? 2*i+1 : 2*i+2;
        if(heap[i]<heap[child]){
            SWAP(heap[i],heap[child]);
            i=child;
        }
        else{
            break;
        }
    }
    if(2*i+1<n && heap[i]<heap[2*i+1]){
        SWAP(heap[i],heap[2*i+1]);
    }
}

void maxDeleteMax(int*heap,int*length){
    SWAP(heap[0],heap[*length-1]);
    *length=*length-1;
    maxTopDownHeapify(0,heap,*length);
}

void maxUpdateNode(int i,int value,int*heap,int length){
    if(heap[i]<value){
        heap[i]=value;
        maxBottomUpHeapify(i,heap);
    }
    else if(heap[i]>value){
        heap[i]=value;
        maxTopDownHeapify(i,heap,length);
    }
}

void maxDeleteGeneralNode(int i,int*heap,int*length){
    maxUpdateNode(i,heap[0]+1,heap,*length);
    maxDeleteMax(heap,length);
}

void maxBuildHeap(int*heap,int length){
    for(int i=((length)/2)-1;i>-1;i--){
        maxTopDownHeapify(i,heap,length);
    }
}

int main(){
    int*heap=(int*)calloc(10000,sizeof(int));
    int length;
    scanf("%d",&length);
    int temp;
    for(int i=0;i<length;i++){
        scanf("%d",&heap[i]);
        bottomUpHeapify(i,heap);
    }
    for(int i=0;i<length;i++){
        printf("%d ",heap[i]);
    }
    return 0;
}