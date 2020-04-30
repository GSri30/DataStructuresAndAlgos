#include<stdio.h>
#include<stdlib.h>

int findSqrt(int n,int left,int right){
    int middle=(left+right)/2;
    if(middle==left || middle==right){
        return middle;
    }
    if(left<=right){
        if(middle*middle==n){
            return middle;
        }
        if(middle*middle < n){
            return findSqrt(n,middle,right);   
        }
        if(middle*middle > n){
            return findSqrt(n,left,middle);
        }
    }
}

int main(){
    int number;
    scanf("%d",&number);
    int k=findSqrt(number,0,number);
    printf("%d",k);
    return 0;
}