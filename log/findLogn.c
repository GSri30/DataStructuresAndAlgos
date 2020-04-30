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

int findLogN(char*number){
    int len=strlen(number);
    int i=0;
    while(strlen(number)){
        len=strlen(number);
        number=divide(number);
        i++;
    }
    return i-1;
}

int main(){
    char*input=(char*)calloc(100000,sizeof(char));
    char*ans=(char*)calloc(100000,sizeof(char));
    scanf("%s",input);
    printf("%d",findLogN(input));
    return 0;
}