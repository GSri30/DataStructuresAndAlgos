#include<stdio.h>
#include<string.h>

int toDec(char*n){
    int decimal=n[0]-48;
    for(int i=1;i<strlen(n);i++){
        decimal=decimal*2+(n[i]-48);
    }
    return decimal;
}

int main(){
    char number[100000];char pattern[100000];int x=2;
    scanf("%s %s",number,pattern);
    int pattern_dec=toDec(pattern);int pattern_len=strlen(pattern);int number_len=strlen(number);int sub_pattern_dec=number[0]-48;
    for(int j=1;j<pattern_len;j++){
        x=x*2;
        sub_pattern_dec=2*(sub_pattern_dec)+number[j]-48;
    }
    for(int i=0;i<number_len-pattern_len+1;i++){
        if(sub_pattern_dec==pattern_dec){
            printf("found a match at %d\n",i);
        }
        sub_pattern_dec=sub_pattern_dec*2+number[i+pattern_len]-48-x*(number[i]-48);
    }
    return 0;
}