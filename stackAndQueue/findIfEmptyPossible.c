//Leetcode 946

//Given a pushed and popped stack find whether it is possible to start with an empty stack and end with an empty stack after performming the operations

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int*stack=(int*)calloc(1000,sizeof(int));
    int*ptrPushed=pushed,*ptrPopped=popped;
    int top=-1;
    int iPushed=-1,iPopped=0;
    int i=0;
    while(1){
        stack[++top]=ptrPushed[++iPushed];
        if(stack[top]==ptrPopped[iPopped])
        {
            while(top>-1 && ptrPopped[iPopped]==stack[top]){
                top--;
                iPopped++;
            }
        }
        if(iPushed==pushedSize-1){
            if(top==-1){
                return true;
            }
            if(top>-1){
                return false;
            }
        }
    }   

}

int main(){
    int*input1=(int*)calloc(1000,sizeof(int));
    int*input2=(int*)calloc(1000,sizeof(int));
    int pushed,popped;
    scanf("%d",&pushed);
    for(int i=0;i<pushed;i++){
        scanf("%d",&input1[i]);
    }
    scanf("%d",&popped);
    for(int i=0;i<popped;i++){
        scanf("%d",&input2[i]);
    }
    printf("%d",validateStackSequences(input1,pushed,input2,popped));
    free(input1);free(input2);
    return 0;
}