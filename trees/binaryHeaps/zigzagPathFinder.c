//LeetCode 1104

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SWAP(x,y){int temp=x;x=y;y=temp;}

void reverseStr(char*bin,int len){
    for(int i=0;i<len/2;i++){
        SWAP(bin[i],bin[len-1-i]);
    }
}

char*toBinary(int number){
    char*binary=(char*)calloc(1000,sizeof(char));
    int i=0;
    while(number>0){
        binary[i++]=(number%2)+'0';
        number=number/2;
    }
    reverseStr(binary,strlen(binary));
    return binary;
}

int* pathInZigZagTree(int label, int* returnSize){
    char*binary1=toBinary(label);
    char*binary2=toBinary(label);
    for(int i=1;i<strlen(binary2);i++){
        if(binary2[i]=='0'){
            binary2[i]='1';
        }
        else
        {
            binary2[i]='0';
        }
    }
    int*store1=(int*)calloc(strlen(binary1),sizeof(int));
    int*store2=(int*)calloc(strlen(binary2),sizeof(int));
    store1[0]=binary1[0]-'0';
    store2[0]=binary2[0]-'0';
    int*answer=(int*)calloc(strlen(binary1),sizeof(int));
    for(int i=1;i<strlen(binary1);i++){
        store1[i]=(2*store1[i-1])+binary1[i]-'0';
        store2[i]=(2*store2[i-1])+binary2[i]-'0';
    }
    int i=0;
    if(strlen(binary1)%2==0){
        while(i<strlen(binary1)){
            answer[i]=store2[i];
            i++;
            answer[i]=store1[i];
            i++;
        }
    }
    else
    {
        while(i<strlen(binary1)-1){
            answer[i]=store1[i];
            i++;
            answer[i]=store2[i];
            i++;
        }
        answer[i]=store1[i];
    }
    *returnSize=strlen(binary1);
    return answer;
}


int main(){
    int i;
    scanf("%d",&i);
    int a=0;
    int*ans=pathInZigZagTree(i,&a);
    for(int i=0;i<a;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}