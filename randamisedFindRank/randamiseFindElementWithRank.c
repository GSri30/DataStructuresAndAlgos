//Given a rank, find the element from the given list.

#include<stdlib.h>
#include<stdio.h>

#define SWAP(x,y) {int temp=x;x=y;y=temp;}

int partitionForRank(int*array,int i,int j,int pivot){
    int left=i,right=j;
    while(left<=right){
        while(left<=right && array[left]<=pivot)
        {
            left++;
        }
        while(left<=right && array[right]>pivot){
            right--;
        }
        if(left<=right){
            SWAP(array[left],array[right]);
            left++;right--;
        }
    }   
    array[i-1]=array[left-1];array[left-1]=pivot;
    return left-1; 
}

int findElement(int*list,int left,int right,int rank){
    if(left<=right){
        int p=left+(rand()%(right-left+1));
        SWAP(list[left],list[p]);
        int k=partitionForRank(list,left+1,right,list[left]);
        if(rank==right-k+1){
            return list[k];
        }
        else if(rank<right-k+1){
            return findElement(list,k+1,right,rank);
        }
        else{
            return findElement(list,left,k-1,rank-(right-k+1));
        }
    }
    return -1;
}

int main(){
    int len;
    scanf("%d",&len);
    int*input=(int*)calloc(100000,sizeof(int));
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int r;
    scanf("%d",&r);
    printf("Element with rank %d is : %d",r,findElement(input,0,len-1,r));
    free(input);
    return 0;
}