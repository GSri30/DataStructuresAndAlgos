#include<stdio.h>
#include<stdlib.h>

int*build(int*array,int length){
    int*bit=(int*)calloc(length+1,sizeof(int));
    bit[0]=0;
    for(int i=0;i<length;i++){
        int j=i+1;
        while(j<length+1){
            bit[j]+=array[i];
            j=j+(j&(-j));
        }
    }
    return bit;
}

int main(){
    int*input=(int*)calloc(10000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int*ans=build(input,len);
    for(int i=0;i<len+1;i++){
        printf("%d ",ans[i]);
    }
    free(input);
    return 0;
}