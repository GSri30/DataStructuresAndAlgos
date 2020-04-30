#include<stdio.h>
#include<stdlib.h>

int multiply(int a,int n){
    int ans=1;
    for(int i=0;i<n;i++){
        ans*=a;
    }
    return ans;
}

void findKthRoot(int n,int k,int left,int right){
    int middle=(left+right)/2;
    if(middle==left || middle==right){
        printf("%d",middle);
        return;
    }
    if(left<=right){
        if(multiply(middle,k)>n){
            findKthRoot(n,k,left,middle);
        }
        if(multiply(middle,k)<n){
            findKthRoot(n,k,middle,right);
        }
        if(multiply(middle,k)==n){
            printf("%d",middle);
            return;
        }
    }
}

int main(){
    int number,k;
    scanf("%d %d",&number,&k);
    findKthRoot(number,k,0,number);
    return 0;
}