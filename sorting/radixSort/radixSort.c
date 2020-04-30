#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int findLenOfNum(int number){
    int len=0;
    while(number){
        len++;
        number=number/10;
    }
    return len;
}

int findLenOfLongestNum(int*list,int length){
    int longest=0;
    for(int i=0;i<length;i++){
        if(findLenOfNum(list[i])>longest){
            longest=findLenOfNum(list[i]);
        }
    }
    return longest;
}

void radixSort(int*list,int length,int lengthOfLargest){
    int tens=1;
    int*hashSimilarTable,*answer;
    while(lengthOfLargest){
        //reset the lookup table
        hashSimilarTable=(int*)calloc(10,sizeof(int));
        answer=(int*)calloc(length,sizeof(int));
        //store the count of each unit digit in the list
        for(int i=0;i<length;i++){
            hashSimilarTable[(list[i]/tens)%10]++;    
        }
        //store the cummulative sum of these counts
        for(int j=1;j<10;j++){
            hashSimilarTable[j]=hashSimilarTable[j-1]+hashSimilarTable[j];
        }
        //arrange according to the digits place at that particular instance by decreasing the count
        for(int i=length-1;i>-1;i--){
            answer[--hashSimilarTable[(list[i]/tens)%10]]=list[i];
        }
        tens=tens*10;
        for(int i=0;i<length;i++){
            list[i]=answer[i];
        }
        lengthOfLargest--;
    }
    free(hashSimilarTable);
    free(answer);
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    //here we even need to specify the length of the longest number in the list
    //write a code for that
    radixSort(input,len,findLenOfLongestNum(input,len));
    for(int j=0;j<len;j++){
        printf("%d ",input[j]);
    }
    return 0;
}