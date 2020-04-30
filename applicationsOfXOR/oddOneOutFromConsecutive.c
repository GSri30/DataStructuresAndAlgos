// Given an array(each element repeated twice and are also consecutive except one element).Find that element.

//left+1+(((right-left)/2)-1)/2
//store only odd indices and perform binary search over those and if the element obtained is e, then add it to left+1 and take that element with that index as the middle element in the original binary search.

#include<stdio.h>
#include<stdlib.h>

int findOddInConsecutive(int*list,int length){
    int left=0,right=length-1,middle;
    while(left<=right){
        middle=(((right+3*left)/2)+1)/2;
        if(list[middle-1]!=list[middle] && list[middle]!=list[middle+1]){
            return list[middle];
            break;
        }
        else if(list[middle]==list[middle-1]){
            left=middle+1;
        }
        else{
            right=middle-1;
        }
    }
    return -1;
}

int main(){
    int len;
    scanf("%d",&len);
    int*input=(int*)calloc(100000,sizeof(int));
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int ans=findOddInConsecutive(input,len);
    printf("%d",ans);
    return 0;
}