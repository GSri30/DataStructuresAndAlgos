#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SWAP(x,y) {int temp=x;x=y;y=temp;}
char*multiply(char*number1,char*number2);

char*reverseString(char*string){
for(int i=0;i<strlen(string)/2;i++){
    SWAP(string[i],string[strlen(string)-i-1]);
}
return string;
}

int main()
{
char number1[10000];char number2[10000];int carry;
scanf("%s %s",number1,number2);
char*answer;
answer=multiply(number1,number2);
printf("%s",answer);
return 0;
}

char*multiply(char*number1,char*number2){
    int len1=strlen(number1);int len2=strlen(number2);
    char*answer=(char*)calloc(len1+len2,sizeof(char));
    int temp;int temp1=0;int i;int j;int carry;
    for(int i=0;i<len2;i++)
    {   
        carry=0;
        for(int j=0;j<len1;j++)
        {
            temp=((number1[len1-j-1]-48)*(number2[len2-i-1]-48))+carry;
            if(temp>9){
                carry=temp/10;
                if(answer[i+j]+(temp%10)>9){
                    temp1=answer[i+j]+(temp%10);
                    answer[i+j]=(temp1%10);
                    answer[i+j+1]=(answer[i+j+1]+temp1/10);
                }
                else{
                    answer[i+j]=(answer[i+j]+(temp%10));
                }
            }
            else
            {
                answer[i+j]=(answer[i+j]+temp);
                temp1=answer[i+j];
                if(temp1>9){
                    answer[i+j]=(temp1%10);
                    answer[i+j+1]=(answer[i+j+1]+temp1/10);
                }
                carry=0;
            }
        }
        answer[i+len1]=(answer[i+len1]+carry);
    }
    if(carry){
        i=0;
        while (i<len1+len2)
        {
            answer[i]+='0';
            i++;
        }
    }
    else
    {
        i=0;
        while (i<len1+len2-1)
        {
            answer[i]+='0';
            i++;
        }
    }
    answer=reverseString(answer);    
    return answer;
}