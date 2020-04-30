#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define swap(x,y) {char temp=x;x=y;y=temp;}
#define SWAP(x,y) {int temp=x;x=y;y=temp;}

void reverseString(char*string){
    int len=strlen(string);
    for(int i=0;i<len/2;i++){
        swap(string[i],string[len-i-1]);
    }
}

char*addBinaries(char*num1,char*num2){
    int len1=strlen(num1),len2=strlen(num2);
    if(len2>len1){
        char*temp=num1;
        num1=num2;
        num2=temp;
        SWAP(len1,len2);
    }
    char*answer=(char*)calloc(100000,sizeof(char));
    int carry=0;
    int i;
    for(i=0;i<len2;i++){
        if(num1[len1-1-i]+num2[len2-1-i]-96>1){
            answer[i]=0+carry+'0';
            carry=1;
        }
        else if(num1[len1-1-i]+num2[len2-1-i]-96==1){
            if(carry){
                answer[i]=0+'0';
                carry=1;
            }
            else{
                answer[i]=1+'0';
                carry=0;
            }
        }
        else{
            answer[i]=carry+'0';
            carry=0;
        }
    }
    int j;
    for(j=i;j<i+len1-len2;j++){
        if(num1[len1-1-j]+carry-48>1){
            answer[j]=0+'0';
            carry=1;
        }
        else{
            answer[j]=num1[len1-1-j]+carry;   
            carry=0;
        }
    }
    if(carry){
        answer[j]=1+'0';
    }
    reverseString(answer);
    return answer;
}

//function to add required number of zeros at the end
char*addZeros(char*num,int number,int n){
    for(int i=n;i<n+number;i++){
        num[i]='0';
    }
    return num;
}

char*squareBinary(char*number){
    char*answer=(char*)calloc(100000,sizeof(char));
    int n=strlen(number);
    for(int i=0;i<n;i++){
        if(number[n-i-1]=='1'){
            answer=addBinaries(answer,addZeros(number,i,n));
        }
    }
    return answer;
}

int main(){
    char*input=(char*)calloc(100000,sizeof(char));
    scanf("%s",input);
    printf("%s",squareBinary(input));
    free(input);
    return 0;
}