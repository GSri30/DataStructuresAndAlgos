// Given a string , find substring(max length) containing equal number of 0 and 1

// This question is not done!!

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void findSubString(char*string){
    int length=strlen(string);
    //stores cummulative
    int*storage=(int*)calloc(length+1,sizeof(int));
    //lookup array
    int*counter=(int*)calloc(100000,sizeof(int));
    for(int i=0;i<100000;i++){
        counter[i]=-1;
    }
    int max=0;
    storage[0]=length;
    for(int i=1;i<length+1;i++){
        if(string[i-1]=='0'){
            storage[i]=storage[i-1]+(-1);
        }
        else if(string[i-1]=='1'){
            storage[i]=storage[i-1]+1;
        }
    }
    for(int i=0;i<length+1;i++){
        if(counter[storage[i]]==-1){
            counter[storage[i]]=i;
        }
        else{
            if(i-counter[storage[i]]>max){
                max=i-counter[storage[i]];
            }
        }
    }
    printf("%d",max);
}

int main(){
    char*input=(char*)calloc(100000,sizeof(char));
    scanf("%s",input);
    findSubString(input);
    free(input);
    return 0;
}