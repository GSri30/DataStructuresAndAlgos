//Find if there exists i,j,k such that a[i]<a[k]<a[j]
//Or 132 type sequence problem


#include<stdlib.h>
#include<stdio.h>

int*findNextMaxIndex(int*array,int len){
    int*stack=(int*)calloc(10000,sizeof(int));
    int top=-1;
    int*ans=(int*)calloc(100000,sizeof(int));
    for(int i=0;i<len;i++){
        if(top==-1){
            stack[++top]=i;
        }
        if(array[i]<array[stack[top]]){
            stack[++top]=i;
        }
        else{
            while(top>-1 && array[stack[top]]<=array[i]){
                ans[stack[top--]]=i;
            }
            stack[++top]=i;
        }
    }
    while(top>-1){
        ans[stack[top--]]=-1;
    }
    return ans;
}

int*findNextMinIndex(int*list,int length){
    int*stack=(int*)calloc(10000,sizeof(int));
    int top=-1;
    int*ans=(int*)calloc(100000,sizeof(int));
    for(int i=0;i<length;i++){
        if(top==-1){
            stack[++top]=i;
        }
        if(list[i]>list[stack[top]]){
            stack[++top]=i;
        }
        else{
            while(top>-1 && list[stack[top]]>=list[i]){
                ans[stack[top--]]=i;
            }
            stack[++top]=i;
        }
    }
    while(top>-1){
        ans[stack[top--]]=-1;
    }
    return ans;
}

int findPairs(int*list,int len){
    int*nextMax=findNextMaxIndex(list,len);
    int*nextMin=findNextMinIndex(list,len);
    int i;
    for(i=0;i<len;i++){
        if(nextMax[i]!=-1 && nextMin[nextMax[i]]!=-1){
            if(list[i]<list[nextMin[nextMax[i]]]){
                printf("%d %d %d\n",i,nextMax[i],nextMin[nextMax[i]]);
                break;
            }
        }
    }
    return !(i==len);
}

int main(){
    int*input=(int*)calloc(10000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    printf("%d",findPairs(input,len));
    free(input);
    return 0;
}