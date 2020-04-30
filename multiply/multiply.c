#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Not useful

void multiply(char*number1,char*number2);

int main()
{
    char number1[10000];char number2[10000];int carry;
    scanf("%s %s",number1,number2);
    multiply(number1,number2);
    return 0;
}

void multiply(char*number1,char*number2){
    int len1=strlen(number1);int len2=strlen(number2);
    int*answer=(int*)calloc(len1+len2,sizeof(int));
    int temp;int temp1=0;int i;int j;int carry;
    for(int i=0;i<len2;i++)
    {   
        carry=0;
        for(int j=0;j<len1;j++)
        {
            temp=((number1[len1-j-1]-48)*(number2[len2-i-1]-48))+carry;
            if(temp>9){
                answer[i+j]+=temp%10;
                carry=temp/10;
                if(answer[i+j]>9){
                    temp1=answer[i+j];
                    answer[i+j]=temp1%10;
                    answer[i+j+1]+=temp1/10;
                }
            }
            else
            {
                answer[i+j]+=temp;
                temp1=answer[i+j];
                if(temp1>9){
                    answer[i+j]=temp1%10;
                    answer[i+j+1]+=temp1/10;
                }
                carry=0;
            }
        }
        answer[i+len1]+=carry;
    }
    int count=0;
    for(int j=0;j<len1+len2;j++)
    {
        if(answer[len1+len2-1-j]!=0){
            break;
        }
        count++;
    }
    i=count;
    while (i<len1+len2)
    {
        printf("%d",answer[len1+len2-1-i]);
        i++;
    }

}