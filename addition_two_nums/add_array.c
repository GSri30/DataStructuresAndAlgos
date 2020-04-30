#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// void swap(char*n1,char*n2)
// {
//     char*temp;
//     temp=n1;n1=n2;n2=temp;
// }

int main()
{
    char number1[100000];
    char number2[100000];
    char answer[1000000];
    scanf("%s %s",number1,number2);
    int len1=strlen(number1);
    int len2=strlen(number2);
    int i=0;int carry=0;
    if(len2>len1)
    {
        // swap(number1,number2);
        // len1=strlen(number1);
        // len2=strlen(number2);
        int temp;
        while(i<len1){
            temp=(number2[len2-i-1]-48)+(number1[len1-i-1]-48)+carry;
            if(temp>9){
            answer[i]=temp%10+'0';
            carry=temp/10;
            }
            else
            {
                answer[i]=temp+'0';
                carry=0;
            }     
            i++;
        }
        while(i<len2){
            temp=(number2[len2-i-1]-48)+carry;
            if(temp>9){
                answer[i]=temp%10+'0';
                carry=temp/10;
            }
            else{
                answer[i]=temp+'0';
                carry=0;   
            }        
            i++;
        }
    }
    else
    {
        int temp;
        while(i<len2){
            temp=(number1[len1-i-1]-48)+(number2[len2-i-1]-48)+carry;
            if(temp>9){
                answer[i]=temp%10+'0';
                carry=temp/10;
            }
            else
            {
                answer[i]=temp+'0';
                carry=0;
            }     
            i++;
        }
        while(i<len1){
            temp=(number1[len1-i-1]-48)+carry;
            if(temp>9){
                answer[i]=temp%10+'0';
                carry=temp/10;
            }
            else{
                answer[i]=temp+'0';
                carry=0;   
            }        
            i++;
        }   
    }
    if(carry){
        if(len1>len2){
            answer[len1]=carry+'0';
        }
        else
        {
            answer[len2]=carry+'0';
        }        
    }
    // if(carry){
    //     answer[i]=carry;
    // }
    //printf("%s",answer);
    int len=strlen(answer);int j=0;
    while(j<len){
        printf("%c",answer[len-1-j]);
        j++;
    }
    return 0;
}