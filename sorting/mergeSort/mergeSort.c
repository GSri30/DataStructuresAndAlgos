#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(char a[],int i,int k,int j){
    int left=i,right=k+1,p=0;
    char*b=(char*)calloc(100000,sizeof(char));
    while(left<=k && right<=j){
        if(a[left]-48<a[right]-48){
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

void mergeSort(char a[],int i,int j){
    if(i<j){
        int k=(i+j)/2;
        mergeSort(a,i,k);
        mergeSort(a,k+1,j);
        merge(a,i,k,j);
    }
}

int main(){
    char*a=(char*)calloc(100000,sizeof(char));
    scanf("%s",a);
    int length=strlen(a);
    mergeSort(a,0,length-1);
    printf("%s",a);
    free(a);
    return 0;
}
