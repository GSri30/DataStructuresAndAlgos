//In this we will learn how to reuse the same array again and again but do not go through the old values(though they will be present in the same array)
//Also learn how to perform some operation (O(n)) for :
// k then for k/2 , k/4, ....(here k==len(n)) 

#include<stdio.h>
#include<stdlib.h>

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

int*findCummulative(int*list1,int length){
    int*list2=(int*)calloc(length+1,sizeof(int));
    list2[0]=0;
    for(int i=1;i<length;i++){
        list2[i]=list2[i-1]+list1[i-1];
    }
    return list2;
}

int*mergeSeq(int*list,int*n,int lengthl,int lengthn){
    int*cummulativeList=findCummulative(n,lengthl);
    while(1)
    {
        if(lengthn==1){
            break;
        }
        if(lengthn%2==1){
            for(int i=1;i<lengthn;i+=2){
                merge(list,cummulativeList[i-1],cummulativeList[i]-1,cummulativeList[i+1]-1);
            }
        }
        else{
            for(int i=1;i<lengthn+1;i+=2){
                merge(list,cummulativeList[i-1],cummulativeList[i]-1,cummulativeList[i+1]-1);
            }
        } 
        int left=1; 
        int i;
        for(i=2;i<lengthn+1;i+=2){
            cummulativeList[left++]=cummulativeList[i];
        }
        if(lengthn%2==1){
            cummulativeList[left++]=cummulativeList[i-1];
        }
        lengthn=(lengthn+1)/2;
    }
    return list;
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int*n=(int*)calloc(100000,sizeof(int));
    int lenn;
    scanf("%d",&lenn);
    for(int i=0;i<lenn;i++){
        scanf("%d",&n[i]);
    }
    int*ans=mergeSeq(input,n,len,lenn);
    for(int i=0;i<len;i++){
        printf("%d ",ans[i]);
    }
    free(input);free(n);
    return 0;
}