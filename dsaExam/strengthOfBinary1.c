#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findMin(int,int);
int findMaxDifference(char*,int*,int);
long long int maximumStrengthSubString(char*);

int main(){
    char*input=(char*)calloc(100000,sizeof(char));
    scanf("%s",input);
    long long int ans=maximumStrengthSubString(input);
    printf("\n%lld",ans);
    free(input);
    return 0;
}

//Gives the minimum of given inputs
int findMin(int x,int y){
    if(x<y){
        return x;
    }
    return y;
}

//Finds the maximum difference between elements that is possible for a given list.(also j>i)
int findMaxDifference(char*binary,int*list,int length){
    int minimum=list[0],max=0;
    int maxIndex=0,minIndex=0;
    int tempMin=0;
    for(int j=1;j<length;j++){
        if((list[j]-findMin(list[j-1],minimum))>max){
            max=list[j]-findMin(list[j-1],minimum);
            maxIndex=j-1;
        }
        tempMin=minimum;
        minimum=findMin(list[j-1],minimum);
        if(tempMin!=minimum){
            minIndex=j-1;
        }
    }
    for(int i=minIndex;i<maxIndex+1;i++){
        printf("%c",binary[i]);
    }
    return max;
}

//Given an binary input, it calculates an prefix sum array using a specific condition.
//It adds 1 if the current binary bit is '1' and adds -1 if the it is '0'
long long int maximumStrengthSubString(char*binary){
    int length=strlen(binary);
    long long int maximum=-1000000;
    long long int minimum=1000000;
    long long int temp=0;
    int indexMin;
    int indexMax;
    for(int i=0;i<length;i++){
        if(binary[i]=='1'){
            temp+=1;
        }
        else{
            temp+=(-1);
        }
        if(temp>maximum){
            if(temp<minimum){
                minimum=temp;
                indexMin=i;
            }
            maximum=temp;
            indexMax=i;
        }
    }
    printf("%d %d ",indexMin+1,indexMax);
    return maximum-minimum;
}