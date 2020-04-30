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

void finder(int*string,int k){
    int length=0;
    for(int i=0;string[i]!='\0';i++){
        length++;
    }
    int d[length];
    for(int i=0;i<length;i++){
        if(i==0){
            d[i]=string[i];
        }
        else
        {
            d[i]=(string[i])+(d[i-1]);   
        }
    }
    int answer;
    for(int i=0;i<length;i++){
        answer=binarySearch(d,i,length-1,(k+d[i]));
        if(answer!=-1){
            printf("Between index %d to %d (both included)\n",i+1,answer);
        }
    }   
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&input[i]);
    }
    int k;
    scanf("%d",&k);
    finder(input,k);
    free(input);
    return 0;
}