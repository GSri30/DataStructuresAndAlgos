#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y){int temp=x;x=y;y=temp;}


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

void minBuildHeap(int*heap,int length){
    for(int i=((length)/2)-1;i>-1;i--){
        minTopDownHeapify(i,heap,length);
    }
}

void HeapSort(int heap[], int length)
{
    minBuildHeap(heap, length);
    for(int i =length-1; i>=0; i--)
    {
        SWAP(heap[0],heap[i]);
        minTopDownHeapify(0,heap,i);
    }
    for(int i =0; i<length/2; i++)
    {
        SWAP(heap[i],heap[length-i-1]);
    }
}

int main(){
    int*input=(int*)calloc(10000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    HeapSort(input,len);
    for(int i=0;i<len;i++){
        printf("%d ",input[i]);
    }
    free(input);
    return 0;
}