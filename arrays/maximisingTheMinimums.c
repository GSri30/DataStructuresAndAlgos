//Given an array and k, find all the possible divisions into k sub arrays.Now find the sub array with minimum length in each case.Now return the divisions which have this as maximums.

#include<stdio.h>
#include<stdlib.h>

void maximiseTheMinimums(int*list,int length,int k){
    int sum=0;
    for(int i=0;i<length;i++){
        sum+=list[i];
    }
    int left=0,right=sum;
    int final,count;
    while(1){
        if(left<=right){
            int middleSum=(left+right)/2;
            count=0;
            int tempSum=0;
            for(int i=0;i<length;i++){
                tempSum+=list[i];
                if(tempSum>=middleSum){
                    count++;
                    if(count>=k){
                        break;
                    }
                    tempSum=0;
                }
            }
            if(count>=k){
                final=middleSum;
                left=middleSum+1;
            }
            else{
                right=middleSum-1;
            }
        }
        else{
            break;
        }        
    }

    int s=0,t=0,i;
    for(i=0;t<count-1;i++){
        s+=list[i];
        printf("%d ",list[i]);
        if(s>=final){
            t++;
            printf("\n");
        }
    }
    for(int j=i;j<length;j++){
        printf("%d ",list[j]);
    }
}

int main(){
    int len;
    scanf("%d",&len);
    int*input=(int*)calloc(100000,sizeof(int));
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int k;
    scanf("%d",&k);
    maximiseTheMinimums(input,len,k);
    free(input);
    return 0;
}