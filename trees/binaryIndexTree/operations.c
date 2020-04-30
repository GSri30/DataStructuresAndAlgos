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

//O(logN)
int prefixSum(int*bit,int i){
    int sum=0;
    int j=i+1;
    while(j>0){
        sum+=bit[j];
        j=j-(j&(-j)); 
    }
    return sum;
}

//O(logN)
void update(int*array,int*bit,int len,int i,int x){
    array[i]=x;
    int j=i+1;
    int currentValue=bit[j];
    while(j<len+1){
        bit[j]+=(x-currentValue);
        j=j+(j&(-j));
    }
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int*bit=build(input,len);
    printf("%d",prefixSum(bit,4));
    free(input);
    return 0;
}