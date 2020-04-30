#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char*x,char*y){
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void recursion(char*num,int lindex,int rindex){
    if(lindex==rindex){
        printf("%s\n",num);
        return;
    }
    for(int i=lindex;i<=rindex;i++){
        swap(num+lindex,num+i);
        recursion(num,lindex+1,rindex);
        swap(num+lindex,num+i);
    }
}

int main(){
    char*string=(char*)calloc(1000,sizeof(char));
    int lefti,righti;
    scanf("%s",string);
    recursion(string,0,strlen(string)-1);
    return 0;
}