#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define SWAP(x,y) {int temp=x;x=y;y=temp;}
#define swap(x,y) {char temp=x;x=y;y=temp;}
#define MAX 100000

//Not Done!!!!
//Doubt on how to do binary search for 1's

int binToDec(char* binary) 
{
    int n = strlen(binary);
	int decimal = 0; 
	int pow = 1; //Powers of 2 starting from 2^0 = 1
	for(int i =0; i<n; i++)
	{
		decimal += pow*(binary[n-i-1]-'0'); //Converting binary string to decimal value 
		pow = pow*2;
	}
	return decimal; //returns decimal value of the binary string
}

char* divByTwo(char* string)
{
    char* number = (char*)malloc(MAX*sizeof(char));
    char* result = (char*)malloc(MAX*sizeof(char));
    int len = strlen(string);
    int carry;
    int next_carry = 0;
    for(int i = 0; i<len; i++)
    {
        carry = next_carry;
        if(string[i] == '1' || string[i] == '3' || string[i] == '5' || string[i] == '7' || string[i] == '9')
            next_carry = 5;
        else
            next_carry = 0;

        int num = ((string[i]-'0')/2) + carry;
        number[i] = num + '0';
    }

    int i = 0, k = 0;
    if(len!=1)
        while(number[i] == '0')
            i++;

    for(i; i<len; i++)
        result[k++] = number[i]; 

    return result;
}

char* decToBin(char* decimal)
{
    char* result = (char*)malloc(MAX*sizeof(char));
    char* number = (char*)malloc(MAX*sizeof(char));
    int remainder;
    int len = strlen(decimal);
    int i = 0;
    while(len != 1 || decimal[0] != '0')
    {
        remainder = (decimal[len-1]-'0')%2;
        number[i++] = remainder + '0';
        decimal = divByTwo(decimal);
        len = strlen(decimal);
    }

    for(int j =0; j<i; j++)
        result[j] = number[i-j-1];

    return result;
}

char* addBinary(char* num1, char* num2)
{
    int len1 = strlen(num1), len2 = strlen(num2);
    char* add = (char*)malloc(MAX);
    int carry = 0, index = 0;
    for(int i=0; i<len1; i++)
    {
        int sum = 0;
        if(i<len2)
            sum = (num1[len1-i-1]-'0')+(num2[len2-i-1]-'0');
        else
            sum = num1[len1-i-1]-'0';
        add[index++] = ((sum+carry)%2)+'0';
        carry = (sum+carry)/2;
    }

    if(carry!=0)
        add[index++] = (carry)+'0';

    for(int i =0; i<index/2; i++)
        swap(add[i],add[index-i-1]);
    
    return add;
}

char* squareBinary(char* num)
{
    int len = strlen(num);
    char* square = calloc(MAX,sizeof(char));
    char* temp = malloc(MAX);
    for(int i = 0; i<len; i++)
    {
        temp[i] = num[i];
    }

    for(int i = 0; i<len; i++)
    {
        if(num[len-i-1] == '1')
        {
            for(int j =0; j<i; j++)
            {
                temp[len+j] = '0';
            }
        int diff = strlen(temp)-strlen(square);
        if(diff>=0)
            square = addBinary(temp,square);
        else
            square = addBinary(square,temp);
        }
    }
    return square;
}

bool isgreater(char* num1, char* num2)
{   
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int i =0, k= 0;

    if(len1!=1)
    {
        while(num1[i] == '0')
        {
            len1--;
            i++;
        }
    }

    if(len1>len2)
        return true;
    else if(len1<len2)
        return false;

    while(len1>0 && len2>0)
    {
        if(num1[i] == '0' && num2[k] == '1')
        {
            return false;
        }
        else if(num1[i] == '1' && num2[k] == '0')
        {
            return true;
        }
        else
        {
            i++;
            k++;
            len1--;
            len2--;
        }
    }
    return false;
}

char*findSqrt(char*number){
    char*binary=decToBin(number);
    int left=0,right=strlen(binary)-1;
    char*ans=(char*)calloc(strlen(binary),sizeof(char));
    for(int i=0;i<strlen(binary);i++){
        ans[i]='0';
    }
    while(1){
        if(left<=right){
            int middle=(left+right)/2;
            ans[middle]='1';
            printf("%s\n",ans);
            char*square=squareBinary(ans);
            if(isgreater(binary,square)){
                right=middle-1;
            }
            else if(isgreater(square,binary)){
                ans[middle]='0';
                left=middle+1;
            }
            else{
                break;
            }
        }
    }
    return ans;
}

int main(){
    char*input=(char*)calloc(10000,sizeof(char));
    scanf("%s",input);
    printf("%s",findSqrt(input));
    free(input);
    return 0;
}


//square binary    tobin    compare bin     