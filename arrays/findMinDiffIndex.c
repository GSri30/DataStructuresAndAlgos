#include<stdio.h>
#include<stdlib.h>

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

int absolute(int n){
    if(n<0){
        return -n;
    }
    return n;
}

int findMinDiff(int*list,int length){
    int min=1000000;
    for(int i=1;i<length;i++){
        if(absolute(list[i]-list[i-1])<min){
            min=absolute(list[i]-list[i-1]);
        }
    }
    return min;
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        scanf("%d",&input[i]);
    }
    mergeSort(input,0,number-1);
    printf("Min difference is %d",findMinDiff(input,number));
    free(input);
    return 0;
}