//If list is already sorted

#include<stdio.h>
#include<stdlib.h>

void findAddition(int*list,int length,int x){
    int leftPointer=0,rightPointer=length-1;
    while(leftPointer<=rightPointer){                                                                                                          
        if((list[rightPointer]+list[leftPointer])==x){
            printf("Index: p=%d q=%d",leftPointer,rightPointer);
            break;
        }
        else if((list[rightPointer]+list[leftPointer])<x){
            leftPointer++;
        }
        else{
            rightPointer--;
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
    int number;
    scanf("%d",&number);
    findAddition(input,len,number);
    free(input);
    return 0;
}