#include<stdio.h>
#include<stdlib.h>

void findDifference(int*list,int length,int x)
{
    for(int i=0;i<length-1;i++){
        for(int j=1;j<length;j++){
            if((*(list+j)-*(list+i))==x){
                printf("p=%d,q=%d\n",i,j);
            }
        }
    }
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    int x;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    scanf("%d",&x);
    findDifference(input,len,x);
    free(input);
    return 0;
}