//Leetcode 1046

//Given an array find the max and next max elements and if they are equal, remove both of them; else replace the largest with the difference between those two and remove the other

#include<stdlib.h>
#include<stdio.h>

#define SWAP(x,y) {int temp=x;x=y;y=temp;}

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

void maxBuildHeap(int*heap,int length){
    for(int i=((length)/2)-1;i>-1;i--){
        maxTopDownHeapify(i,heap,length);
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

int lastStoneWeight(int* stones, int stonesSize){
    maxBuildHeap(stones,stonesSize);
    while(stonesSize>1){
        int child;
        if(stonesSize>2){
            child=(stones[1]>stones[2]) ? 1 : 2;
        }
        else{
            child=1;
        }
        
        if(stones[0]==stones[child]){
            maxDeleteMax(stones,&stonesSize);
            maxDeleteMax(stones,&stonesSize);
        }
        else{
            int deletedvalue=stones[child];
            maxDeleteGeneralNode(child,stones,&stonesSize);
            maxUpdateNode(0,stones[0]-deletedvalue,stones,stonesSize);
        }
    }
    if(stonesSize>0){
        return stones[0];
    }
    return 0;
}

int main(){
    int*input=(int*)calloc(1000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    printf("%d",lastStoneWeight(input,len));
    free(input);
    return 0;
}