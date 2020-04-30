// Given an array, find the xor of the elements present between the given indices

#include<stdio.h>
#include<stdlib.h>

int findXOR(int*list,int length,int left,int right){
    int*anotherList=(int*)calloc(100000,sizeof(int));
    anotherList[0]=list[0];
    for(int i=1;i<length;i++){
        anotherList[i]=list[i]^anotherList[i-1];
    }
    int answer=anotherList[right]^anotherList[left-1];
    return answer;
}

int main(){
    int len;
    scanf("%d",&len);
    int*input=(int*)calloc(len,sizeof(int));
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int left,right;
    scanf("%d %d",&left,&right);
    int ans=findXOR(input,len,left,right);
    printf("%d",ans);
    free(input);
    return 0;
}