#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define SWAP(x,y) {int temp=x;x=y;y=temp;}
#define swap(x,y) {char temp=x;x=y;y=temp;}

bool checkEven(int n){
    if(n%2==0){
        return true;
    }
    return false;
}

void reverseString(char*string){
    int len=strlen(string);
    for(int i=0;i<len/2;i++){
        swap(string[i],string[len-i-1]);
    }
}

char*divide(char*num){
    char*answer=(char*)calloc(100000,sizeof(char));
    int len=strlen(num);
    int carry=0;
    for(int i=0;i<len;i++){
        if(i!=len-1){
            if(checkEven(num[len-2-i])){
            answer[i]='0'+(num[len-1-i]-48)/2;
            }
            else{
                answer[i]='0'+(num[len-1-i]-48)/2+5;
            }
        }
        else{
            if((num[len-1-i]-48)/2!=0){
                answer[i]='0'+(num[len-1-i]-48)/2;
            }
        }
    }
    reverseString(answer);
    return answer;
}

void decToBin(char*number){
    int len=strlen(number);
    char*answer=(char*)calloc(100000,sizeof(char));
    int i=0;
    while(strlen(number)){
        if(checkEven(number[strlen(number)-1])){
            answer[i]='0';
        }
        else{
            answer[i]='1';
        }
        number=divide(number);
        i++;
    }
    reverseString(answer);
    printf("%s",answer);
}

int main(){
    char*input=(char*)calloc(10000,sizeof(char));
    scanf("%s",input);
    decToBin(input);
    free(input);
    return 0;
}

