// Use this to add two large numbers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char*addLarge(char* lnum, char* snum) 
{
    char* add;
    char*sum=(char*)calloc(100000,sizeof(char));
    add = (char*)malloc(100000*sizeof(char));
    int carry = 0;
    int llen = strlen(lnum); 
    int slen = strlen(snum); 
    for(int i = 1; i<=slen; i++){
        int dig1 = lnum[llen-i] - '0'; 
        int dig2 = snum[slen-i] - '0'; 
        int sum_dig = dig1 + dig2 + carry; 
        add[i-1] = (sum_dig%10) + '0'; 
        carry = sum_dig/10; 
    }
    for(int i = slen+1; i<=llen ;i++) {
        int dig1 = lnum[llen-i] - '0';
        int sum_dig = dig1 + carry;
        add[i-1] = (sum_dig%10) + '0'; 
        carry = sum_dig/10;
    }
    if(carry!=0){
        add[llen] = carry + '0';
    }
    int flen = strlen(add); 
    for(int i=1;i<=flen;i++){
        sum[i-1] = add[flen-i];
    }    
    return sum;
}

int main(){
    char*num1=(char*)calloc(100000,sizeof(char));
    char*num2=(char*)calloc(100000,sizeof(char));
    scanf("%s %s",num1,num2);
    char*addition=addLarge(num1,num2);
    printf("%s",addition);
    return 0;
}