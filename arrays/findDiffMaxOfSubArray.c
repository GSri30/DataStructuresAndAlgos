// Given sequence a0,a1,a2.. first find p0,p1,..such that p's are cummulaitve sums.
// Find i and j such that pj-pi is max
// or
// Find sub array such that the sum of those elements is maximum

#include<stdio.h>
#include<stdlib.h>

void makePs(int*a,int length,int*p){
    p[0]=0;
    for(int i=1;i<length;i++){
        p[i]=p[i-1]+a[i-1];
        // printf("%d ",p[i]);
    }
}

int findMin(int x,int y){
    if(x<y){
        return x;
    }
    return y;
}

void findDiffMax(int*list,int length){
    int min=list[0],max=-99999;
    int iindex,jindex;
    for(int i=1;i<length;i++){
        if((list[i]-findMin(min,list[i-1]))>max){
            max=list[i]-findMin(min,list[i-1]);
            min=findMin(min,list[i-1]);
            if(findMin(min,list[i-1])==list[i-1]){
                iindex=i-1;
            }   
            jindex=i;  
        }
    }
    printf("Index: i=%d j=%d",iindex-1,jindex-1);
}

int main(){
    int*a=(int*)calloc(100000,sizeof(int));
    int*p=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&a[i]);
    }
    makePs(a,len,p);
    findDiffMax(p,len);
    return 0;
}