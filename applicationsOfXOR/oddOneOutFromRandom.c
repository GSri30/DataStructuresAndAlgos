// Given an array(each element is repeated twice),find the odd element.(there is no need for the same elements to be consecutive)
//O(n)

#include<stdio.h>
#include<stdlib.h>

int findOdd(int*list,int length){
    int answer=0;
    for(int i=0;i<length;i++){
        answer=answer^list[i];
    }
    return answer;
}

int main(){
    int len;
    scanf("%d",&len);
    int*input=(int*)calloc(100000,sizeof(int));
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int ans=findOdd(input,len);
    printf("%d",ans);
    return 0;
}

