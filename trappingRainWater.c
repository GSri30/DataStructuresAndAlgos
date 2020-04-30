//LeetCode 42

#include<stdlib.h>
#include<stdio.h>

int max(int num1,int num2){
    if(num1>num2){
        return num1;
    }
    return num2;
}

int min(int num1,int num2){
    if(num1>num2){
        return num2;
    }
    return num1;
}

int trap(int* height, int heightSize){
    if(heightSize<=2){
        return 0;
    }
    int*maxLeftSide=(int*)calloc(heightSize,sizeof(int));
    maxLeftSide[0]=-1;
    maxLeftSide[1]=height[0];
    for(int i=2;i<heightSize;i++){
        maxLeftSide[i]=max(maxLeftSide[i-1],height[i-1]);
    }
    int*maxRightSide=(int*)calloc(heightSize,sizeof(int));
    maxRightSide[heightSize-1]=-1;
    maxRightSide[heightSize-2]=height[heightSize-1];
    for(int i=heightSize-3;i>-1;i--){
        maxRightSide[i]=max(maxRightSide[i+1],height[i+1]);
    }
    int count=0;
    for(int i=0;i<heightSize;i++){
        if(maxLeftSide[i]==-1 || maxRightSide[i]==-1){
            continue;
        }
        else{
            if(min(maxLeftSide[i],maxRightSide[i])>height[i]){
                count+=(min(maxLeftSide[i],maxRightSide[i])-height[i]);
            }
        }
        
    }
    return count;
}

int main(){
    int*h=(int*)calloc(1000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&h[i]);
    }
    printf("%d",trap(h,len));
    return 0;
}