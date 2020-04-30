//Delete element with maximum frequency
//Code where we take in integers
//NOT SUITABLE IF ALPHABETS ARE USED

//Input: First enter number of queries, then enter 0 to add an element followed by that element,  else enter 1 to delete max frequencied element(s)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define PRIME 100003

#define SWAP(x,y){int temp=x;x=y;y=temp;}
#define SWAPpointers(p1,p2){struct node*temp=p1;p1=p2;p2=temp;}

struct node{
    int x;
    int count;
    int i;
    struct node*link;
};
struct heapNode{
    int count;
    struct node*next;
};

struct node*pointer=NULL;

struct node* insert(int x,struct node**r,int*heapLen){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->x=x;
    temp->count=1;
    temp->i=*heapLen;
    temp->link=NULL;
    if(*r==NULL){
        pointer=*r=temp;
    }
    else{
        pointer->link=temp;
        pointer=temp;
    }
    return pointer;
}

void maxTopDownHeapify(int i,struct heapNode*heap,int n,struct node**hashTable){
    int child;
    while(2*i+2<n){
        int child=(heap[2*i+1].count>heap[2*i+2].count) ? 2*i+1 : 2*i+2;
        if(heap[i].count<heap[child].count){
            SWAP(heap[i].count,heap[child].count);
            SWAPpointers(heap[i].next,heap[child].next);
            heap[i].next->i=i;
            heap[child].next->i=child;
            i=child;
        }
        else{
            break;
        }
    }
    if(2*i+1<n && heap[i].count<heap[2*i+1].count){
        SWAP(heap[i].count,heap[2*i+1].count);
        SWAPpointers(heap[i].next,heap[2*i+1].next);
        heap[i].next->i=i;
        heap[2*i+1].next->i=2*i+1;
    }
}

void maxBottomUpHeapify(int i,struct heapNode*heap,int n,struct node**hashTable){
    int p=(i-1)/2;
    while(p>=0 && (heap[p].count)<(heap[i].count)){
        SWAP(heap[p].count,heap[i].count);
        SWAPpointers(heap[p].next,heap[i].next);
        heap[i].next->i=i;
        heap[p].next->i=p;
        i=p;
        p=(i-1)/2;
    }
}


void updatePtrToHash(int originalValue,struct node*ptr,struct node**hashTable,struct heapNode*heap){
    int hashValue=originalValue%PRIME;
    struct node*mainPtr=hashTable[hashValue];
    heap[ptr->i].next=mainPtr;
    heap[ptr->i].count=ptr->count;
}

void addElement(struct node*hashTable[],struct heapNode*heap,int value,int*heapLen){
    int original=value;
    value=(value)%PRIME;
    struct node*ptr=hashTable[value];
    while(ptr){
        if(ptr->x==original){
            ptr->count++;
            heap[ptr->i].count=ptr->count;
            maxBottomUpHeapify(ptr->i,heap,*heapLen,hashTable);
            break;
        }
        else{
            ptr=ptr->link;
        }
    }
    if(ptr==NULL){
        struct node*p=insert(original,&hashTable[value],heapLen);
        updatePtrToHash(original,p,hashTable,heap);
        maxBottomUpHeapify(p->i,heap,*heapLen,hashTable);
        (*heapLen)++;
    }
}

void deleteNode(struct node**head, int count) 
{ 
    struct node*temp = *head, *prev;  
    if (temp != NULL && temp->count == count){ 
        *head = temp->link;
        temp->link=NULL;
        free(temp);               
        return; 
    }
    while (temp != NULL && temp->count!= count){ 
        prev = temp; 
        temp = temp->link; 
    }
    if(temp == NULL){
        return;
    }
    prev->link=temp->link; 
    free(temp);  
}

void maxDeleteMax(struct heapNode*heap,int*length,struct node**hashTable){
    if(*length==0){
        return;
    }
    SWAP(heap[0].count,heap[*length-1].count);
    SWAPpointers(heap[0].next,heap[*length-1].next);
    heap[0].next->i=0;
    //Here delete the node(we are following an alternative here)
    // heap[*length-1].next->x=-1;
    // heap[*length-1].next->count=-1;
    // heap[*length-1].next->i=-1;
    deleteNode(&(heap[*length-1].next),heap[*length-1].count);
    *length=*length-1;
    maxTopDownHeapify(0,heap,*length,hashTable);
}

int main(){
    int queries=0,operation=-1,element=-1;
    struct heapNode*heap=(struct heapNode*)calloc(1000000,sizeof(struct heapNode));
    struct node*hashTable[PRIME];
    for(int i=0;i<PRIME;i++){
        hashTable[i]=NULL;
    }
    int heapLen=0;
    
    scanf("%d",&queries);

    for(int i=0;i<queries;i++){
        scanf("%d",&operation);
        if(!operation){
            scanf("%d",&element);
            addElement(hashTable,heap,element,&heapLen);
        }
        else if(operation==1){
            int max=heap[0].count;
            while(heap[0].count==max && heapLen!=0){
                maxDeleteMax(heap,&heapLen,hashTable);
            }
        }
    }
    for(int i=0;i<heapLen;i++){
        struct node*p=heap[i].next;
        while(p){
            if(p->count==heap[i].count){
                printf("x:%d count:%d\n",p->x,p->count);
                break;
            }
            p=p->link;
        }
    }
    return 0;
}