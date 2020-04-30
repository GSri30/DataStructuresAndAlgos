#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int powerFinder(int x,int n){
    int y=1;
    while(n>0){
        if(n%2==1){
            y*=x;
            if(n==1){
                break;
            }
        }
        x=x*x;
        n=n/2;
    }
    return y;
}

int main(){
    int x;int n;
    scanf("%d %d",&x,&n);
    int answer=powerFinder(x,n);
    printf("%d",answer);
    return 0;
}