//Given a sequence of numbers, find the longest increasing sequence

#include<stdlib.h>
#include<stdio.h>

int*findNextMaxIndex(int*array,int len){
    int*stack=(int*)calloc(10000,sizeof(int));
    int top=-1;
    int*ans=(int*)calloc(100000,sizeof(int));
    for(int i=0;i<len;i++){
        if(top==-1){
            stack[++top]=i;
        }
        if(array[i]<array[stack[top]]){
            stack[++top]=i;
        }
        else{
            while(top>-1 && array[stack[top]]<=array[i]){
                ans[stack[top--]]=i;
            }
            stack[++top]=i;
        }
    }
    while(top>-1){
        ans[stack[top--]]=-1;
    }
    return ans;
}

