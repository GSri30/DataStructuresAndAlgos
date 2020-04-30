// if we use backtracking, time will be reduced
// similar to turnpike

//can even first compute all the sums and store and equate k to differences
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void finder(char*string,int k){
    int length=strlen(string);
    int sum;int j;
    for(int i=0;i<length;i++){
        sum=0;j=0;
        while(sum<k && i+j<length){
            sum+=(string[i+j]-48);
            j++;
        }
        if(sum==k){
            printf("index %d to %d ",i,i+j-1);
        }
    }
}

int main(){
    char*input=(char*)calloc(100000,sizeof(char));
    scanf("%s",input);
    int k;
    scanf("%d",&k);
    finder(input,k);
    free(input);
    return 0;
}
