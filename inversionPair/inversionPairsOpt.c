#include<stdio.h>
#include<stdlib.h>

int merge(int a[],int i,int k,int j){
    int left=i,right=k+1,p=0;
    int*b=(int*)calloc(100000,sizeof(int));
    int count=0;
    while(left<=k && right<=j){
        if(a[left]<a[right]){
            b[p++]=a[left++];
        }
        else
        {
            b[p++]=a[right++];
            count+=(k-left+1);
        }
    }
    while (left<=k)
    {
        b[p++]=a[left++];
    }
    while (right<=j)
    {
        b[p++]=a[right++];
    }
    p=0;left=i;
    while(left<=j){
        a[left++]=b[p++];
    }
    free(b);
    return count; 
}

int mergeSort(int a[],int i,int j){
    if(i<j){
        int k=(i+j)/2;
        return mergeSort(a,i,k)+mergeSort(a,k+1,j)+merge(a,i,k,j);
    }
    return 0;
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    printf("%d",mergeSort(input,0,len-1));
    return 0;
}