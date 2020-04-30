//Given bars,we need to find the max area rectangle that is possible.The rectangle shouldn't contain any of the top points of the histograms.
#include<stdio.h>
#include<stdlib.h>

void print(int*list,int length){
    for(int i=0;i<length;i++){
        printf("%d ",list[i]);
    }
}

int*giveResult(int*list,int length){
    int*stack=(int*)calloc(10000,sizeof(int));
    int top=-1;
    int*ans=(int*)calloc(100000,sizeof(int));
    for(int i=0;i<length;i++){
        if(top==-1){
            stack[++top]=i;
        }
        if(list[i]>list[stack[top]]){
            stack[++top]=i;
        }
        else{
            while(top>-1 && list[stack[top]]>list[i]){
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

int maxArea(int*list,int length){
    int*rightMins=giveResult(list,length);
    int*reverseList=(int*)calloc(10000,sizeof(int));
    for(int i=0;i<length;i++){
        reverseList[i]=list[length-1-i];
    }
    int*leftMins=giveResult(reverseList,length);
    int maxArea=0;
    int leftIndex,rightIndex;
    for(int i=0;i<length;i++){
        if(leftMins[i]==-1 && rightMins[i]==-1){
            rightIndex=-1;
            leftIndex=-1; 
        }
        else if(leftMins[i]==-1){
            leftIndex=-1;
            rightIndex=rightMins[i];
        }
        else if(rightMins[i]==-1){
            rightIndex=-1;
            leftIndex=leftMins[i];
        }
        else{
            rightIndex=rightMins[i];
            leftIndex=leftMins[i];
        }
        if((rightIndex-leftIndex-2)*list[i]>maxArea){
            maxArea=(rightIndex-leftIndex-2)*list[i];
        }
    }
    return maxArea;
}

int main(){
    int*input=(int*)calloc(10000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int answer=maxArea(input,len);
    printf("%d",answer);
    free(input);
    return 0;
}