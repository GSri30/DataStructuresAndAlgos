//Given a sequence of elements, find number of ai>aj cases where j>i
#include<stdio.h>
#include<stdlib.h>

int findInversionPairs(int*list,int length){
    int count=0;
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(list[j]<list[i]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    printf("Number of inversion pairs: %d",findInversionPairs(input,len));
    return 0;
}