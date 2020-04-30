#include<stdlib.h>
#include<stdio.h>

//sort the list

void merge(int a[],int i,int k,int j){
    int left=i,right=k+1,p=0;
    int*b=(int*)calloc(100000,sizeof(int));
    while(left<=k && right<=j){
        if(a[left]<a[right]){
            b[p++]=a[left++];
        }
        else
        {
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
}

void mergeSort(int a[],int i,int j){
    if(i<j){
        int k=(i+j)/2;
        mergeSort(a,i,k);
        mergeSort(a,k+1,j);
        merge(a,i,k,j);
    }
}

void findSumInList(int*list,int length)
{
    for(int i=0;i<length;i++){
        int left=0,right=length-1;
        while(left<=right)
        {
            if(list[left]+list[right]==list[i]){
                printf("Index: p=%d q=%d k=%d after sorting!\n",left,right,i);
                break;
            }
            else if(list[left]+list[right]<list[i]){
                left++;
            }
            else
            {
                right--;
            }
        }
    }
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    mergeSort(input,0,len-1);
    findSumInList(input,len);
    free(input);
    return 0;
}