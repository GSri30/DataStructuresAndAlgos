#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y) {int temp=x;x=y;y=temp;}

int findLenOfNum(int number){
    int len=0;
    while(number){
        len++;
        number=number/10;
    }
    return len;
}

int findLenOfLongestNum(int*list,int length){
    int longest=0;
    for(int i=0;i<length;i++){
        if(findLenOfNum(list[i])>longest){
            longest=findLenOfNum(list[i]);
        }
    }
    return longest;
}

struct node
{
    int data;
    struct node*link;
};

struct node*ptr=NULL;

void insert(struct node**root,int value){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    if(*root==NULL){
        ptr=*root=temp;
    }
    else{
        ptr->link=temp;
        ptr=ptr->link;
    }
}

void bruteForce(struct node**root){
    struct node*outertemp=(*root);
    while(outertemp){
        struct node*temp=outertemp;
        struct node*temp1=outertemp;
        int min=outertemp->data;
        while(temp){
            if((temp->data)<min){
                min=temp->data;
                temp1=temp;
            }
            temp=temp->link;
        }
        SWAP((outertemp->data),(temp1->data));
        outertemp=outertemp->link;
    }
}
// int main(){
//     struct node*p=NULL;
//     insert(&p,351);
//     insert(&p,346);
//     bruteForce(&p);
//     struct node*temp=p;
//     while(temp){
//         printf("%d ",temp->data);
//         temp=temp->link;
//     }
//     return 0;
// }
void bucketSort(int*list,int length,int*answer){
    struct node*bucket[100000];
    int maxlen=findLenOfLongestNum(list,length);
    for(int i=0;i<100000;i++){
        bucket[i]=NULL;
    }
    for(int i=0;i<length;i++){
        int temp=list[i];
        int j=0;
        while(j<maxlen){
            temp=temp/10;
            j++;
        }
        insert(&bucket[temp],list[i]);
    }
    struct node*tempPointer=NULL;
    int a=0;
    for(int j=0;j<100000;j++){
        if(bucket[j]!=NULL){
            tempPointer=bucket[j];
            bruteForce(&tempPointer);
            while(tempPointer)
            {
                answer[a]=tempPointer->data;
                tempPointer=tempPointer->link;
                a++;
            }
        }
    }
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int*answer=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    bucketSort(input,len,answer);
    for(int j=0;j<len;j++){
        printf("%d ",answer[j]);
    }
    free(input);
    free(answer);
    return 0;
}