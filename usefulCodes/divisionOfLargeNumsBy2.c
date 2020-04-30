#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define swap(x,y) {char temp=x;x=y;y=temp;}

void reverseString(char*string){
    int len=strlen(string);
    for(int i=0;i<len/2;i++){
        swap(string[i],string[len-i-1]);
    }
}

bool checkEven(int n){
    if(n%2==0){
        return true;
    }
    return false;
}
//from left
void divide(char*num1,char*answer){
    int len1=strlen(num1);
    int carry=0;
    for(int i=0;i<len1;i++){
        answer[i]=(answer[i])+((num1[i]-48)/2)+carry+'0';
        if(!checkEven(num1[i])){
            carry=5;
        }
        else
        {
            carry=0;
        }
    }
}

//from right
char*divide1(char*num){
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

int main(){
    char*input=(char*)calloc(100000,sizeof(char));
    char*ans=(char*)calloc(100000,sizeof(char));
    scanf("%s",input);
    ans=divide1(input);
    printf("%s",ans);
    return 0;
}