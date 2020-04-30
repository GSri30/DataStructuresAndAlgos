#include<stdio.h>
#include<stdlib.h>

// j>i

int findMin(int x,int y){
    if(x<y){
        return x;
    }
    return y;
}

int findDifference(int*list,int length){
    int minimum=list[0],max=0;
    for(int j=1;j<length;j++){
        if((list[j]-findMin(list[j-1],minimum))>max){
            max=list[j]-findMin(list[j-1],minimum);
        }
        minimum=findMin(list[j-1],minimum);
    }
    return max;
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    printf("%d",findDifference(input,len));
    free(input);
    return 0;
}