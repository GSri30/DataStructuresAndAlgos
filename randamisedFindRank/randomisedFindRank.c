//Given an element from a list, find it's rank

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    return j-left+2;    
}

int rankFinder(int*a,int number,int tofind,int i,int j){
    int x;
    for(x=0;x<number;x++){
        if(a[x]==tofind){
            break;
        }
    }
    SWAP(a[x],a[i]);
    int ans=partitionForRank(a,i+1,j,tofind);
    return ans;
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        scanf("%d",&input[i]);
    }
    printf("Enter the number to be found : ");
    int toFind;
    scanf("%d",&toFind);
    int answer=rankFinder(input,number,toFind,0,number-1);
    printf("Rank of %d is %d",toFind,answer);
    free(input);
    return 0;
}