#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//we dont need any algo to convert an bin to dec, as an int can store upto 10^9!!!!

//Therefore we can follow:
// int binToDec(char* binary) 
// {
//     int n = strlen(binary);
// 	int decimal = 0; 
// 	int pow = 1; //Powers of 2 starting from 2^0 = 1
// 	for(int i =0; i<n; i++)
// 	{
// 		decimal += pow*(binary[n-i-1]-'0'); //Converting binary string to decimal value 
// 		pow = pow*2;
// 	}
// 	return decimal; //returns decimal value of the binary string
// }

#define SWAP(x,y) {int temp=x;x=y;y=temp;}
char*multiply(char*number1,char*number2);

char*reverseString(char*string){
for(int i=0;i<strlen(string)/2;i++){
    SWAP(string[i],string[strlen(string)-i-1]);
}
return string;
}

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

char*binToDec(char*binary){
    char*answer=(char*)calloc(100000,sizeof(char));
    answer[0]=binary[0];
    char*two=(char*)calloc(1,sizeof(char));
    two[0]='2';
    char*temp=(char*)calloc(1,sizeof(char));
    for(int i=1;i<strlen(binary);i++){
        temp[0]=binary[i];
        answer=addLarge(multiply(two,answer),temp);
    }
    return answer;
}

int main(){
    char*input=(char*)calloc(100000,sizeof(char));
    scanf("%s",input);
    char*ans=binToDec(input);
    printf("%s",ans);
    free(input);
    return 0;
}