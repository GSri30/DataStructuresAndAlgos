//Given an array of numbers, find the first index of the element which is lesser that the current element.Find for all elements of the array

#include<stdio.h>
#include<stdlib.h>

//Iterative method

// int*giveResult(int*list,int length){
//     int*result=(int*)calloc(10000,sizeof(int));
//     for(int i=0;i<length;i++){
//         for(int j=i;j<length;j++){
//             if(list[j]<list[i]){
//                 result[i]=j;
//                 break;
//             }
//             else{
//                 result[i]=-1;
//             }
//         }
//     }
//     return result;
// }

// int main(){
//     int*input=(int*)calloc(100000,sizeof(int));
//     int len;
//     scanf("%d",&len);
//     for(int i=0;i<len;i++){
//         scanf("%d",&input[i]);
//     }
//     int*ans=giveResult(input,len);
//     for(int i=0;i<len;i++){
//         printf("%d ",ans[i]);
//     }
//     free(input);
//     return 0;
// }

//Optimised method

int*giveResult(int*list,int length){
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

int main(){
    int*input=(int*)calloc(10000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int*ans=giveResult(input,len);
    for(int i=0;i<len;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}