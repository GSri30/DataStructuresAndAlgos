#include<stdio.h>
#include<stdlib.h>

// Or make duplicates and increment and decrement values of duplicates even.Now increase count only basing upon the condition applied upon the duplicates.

int merge(int a[],int i,int k,int j,int pk){
    int left=i,right=k+1,p=0;
    int*b=(int*)calloc(100000,sizeof(int));
    int count=0;
    while(left<=k && right<=j){
        if(a[left]<a[right]){
            b[p++]=a[left++];
        }
        else
        {
            for(int i=left;i<=k;i++){
                if(a[i]>a[right]+pk){
                    count+=(k-i+1);
                    break;
                }
            }
            b[p++]=a[right++];
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

int mergeSort(int a[],int i,int j,int pk){
    if(i<j){
        int k=(i+j)/2;
        return mergeSort(a,i,k,pk)+mergeSort(a,k+1,j,pk)+merge(a,i,k,j,pk);
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
    int p;
    scanf("%d",&p);
    printf("%d",mergeSort(input,0,len-1,p));
    return 0;
}