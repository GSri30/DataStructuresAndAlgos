#include<stdio.h>
#include<stdlib.h>

int*countSort(int*list,int length){
    int*lookup=(int*)calloc(100000,sizeof(int));
    int*ans=(int*)calloc(length,sizeof(int));
    int max=0;
    for(int i=0;i<length;i++){
        lookup[list[i]]+=1;
        if(list[i]>max){
            max=list[i];
        }
    }
    for(int i=1;i<max+1;i++){
        lookup[i]+=lookup[i-1];
    }
    for(int i=length-1;i>-1;i--){
        ans[--lookup[list[i]]]=list[i];
    }    
    for(int i=0;i<length;i++){
        list[i]=ans[i];
    }
    free(ans);
    return list;
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int*ans=countSort(input,len);
    for(int i=0;i<len;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}