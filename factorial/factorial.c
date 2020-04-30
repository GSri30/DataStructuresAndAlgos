#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SWAP(x,y) {char temp=x;x=y;y=temp;}

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
    // int count=0;
    // for(int j=0;j<len1+len2;j++)
    // {
    //     if(answer[len1+len2-1-j]!=0){
    //         break;
    //     }
    //     count++;
    // }
    // j--;
    //answer[len1+len2-1-j]='\0';
    // i=count;
    i=0;
    while(i<len1+len2)
    {
        answer[i]+='0';
        i++;
    }
    //int a=count;
    int a=0;
    while (a<(len1+len2)/2)
    {
        SWAP(answer[len1+len2-a-1],answer[a]);
        a++;
    }
    return answer;
}

int main()
{
    int number;char*refresh=(char*)calloc(10000000,sizeof(char));
    scanf("%d",&number);
    refresh[0]=number+'0'; char*next=(char*)calloc(1,sizeof(char)); 
    for(int i=number-1;i>0;i--){
        *next=i+'0';
        refresh=multiply(refresh,next);
    }
    printf("%s",refresh);
    free(refresh);
    return 0;
}