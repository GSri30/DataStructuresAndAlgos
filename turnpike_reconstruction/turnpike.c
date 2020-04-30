#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void turnpikerecursion(){
    
}

void turnpike(int*d,int*x,int m,int n){
    
}

int main(){
    int*d=(int*)calloc(100000,sizeof(int));
    int m=1,n;
    int*temp=d;
    while(temp){
        m++;
        temp++;
    }
    n=(1+sqrt(1+(8*m)))/2;
    int*x=(int*)calloc(n,sizeof(int));


    free(d);free(x);
    return 0;
}