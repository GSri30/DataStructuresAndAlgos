#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SWAP(x,y) {int temp=x;x=y;y=temp;}

int partition(int*a,int i,int j,int pivot){
    int left=i,right=j;
    while(left<=right){
        while(left<=right && a[left]<=pivot)
        {
            left++;
        }
        while(left<=right && a[right]>pivot)
        {
            right--;
        }
        if(left<=right){
            SWAP(a[left],a[right]);
            left++;right--;
        }
    }
    a[i-1]=a[left-1];a[left-1]=pivot;
    return left-1;
}

void rqs(int*a,int i,int j){
    if(i>j){
        return ;
    }
    int p=i+(rand()%(j-i+1));
    SWAP(a[i],a[p]);
    int k=partition(a,i+1,j,a[i]);
    rqs(a,i,k-1);
    rqs(a,k+1,j);
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        scanf("%d",&input[i]);
    }
    rqs(input,0,number-1);
    for(int j=0;j<number;j++){
        printf("%d",input[j]);
    }
    return 0;
}

