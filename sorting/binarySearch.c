#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binarySearch(int*a,int leftIndex,int rightIndex,int required){
    int middleIndex;
    if(leftIndex<=rightIndex){   
        middleIndex=(leftIndex+rightIndex)/2;
        if(required==a[middleIndex]){
            return middleIndex;
        }
        if(a[middleIndex]>required){
            return binarySearch(a,leftIndex,middleIndex-1,required);
        }
        return binarySearch(a,middleIndex+1,rightIndex,required);
    }
    return -1;
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        scanf("%d",&input[i]);
    }
    int req;
    scanf("%d",&req);
    int answer=binarySearch(input,0,number-1,req);
    printf("%d",answer);
    free(input);
    return 0;
}