#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char number1[100000];char number2[100000];
    int intnumber1[10000],intnumber2[10000];
    int answer[10000];
    scanf("%s %s",number1,number2);
    int a=0;int i;int l=0;
    int len1=strlen(number1),len2=strlen(number2);
    if(len1>len2){
        for(i=0;i<len1;i+=4){
            intnumber1[i/4]=number1[len1-i-4]-48;
            for(int j=1;j<4;j++){
                intnumber1[i/4]=intnumber1[i/4]*10+(number1[len1-i-4+j]-48);
            }
            if(i<len2){
                intnumber2[i/4]=number2[len2-i-4]-48;
                for(int k=1;k<4;k++){
                    intnumber2[i/4]=intnumber2[i/4]*10+(number2[len2-i-4+k]-48);
                }
                l++;
            }
        }
    }
    else
    {
        for(i=0;i<len2;i+=4){
            intnumber2[i/4]=number2[len2-i-4]-48;
            for(int k=1;k<4;k++){
                intnumber2[i/4]=intnumber2[i/4]*10+(number2[len2-i-4+k]-48);
            }
            if(i<len1){
                intnumber1[i/4]=number1[len1-i-4]-48;
                for(int j=1;j<4;j++){
                    intnumber1[i/4]=intnumber1[i/4]*10+(number1[len1-i-4+j]-48);
                }
                l++;
            }
        }
    }
    if(len1%4!=0){
        intnumber1[(i-4)/4]=number1[0]-48;
        for(int a=1;a<len1%4;a++){
            intnumber1[(i-4)/4]=intnumber1[(i-4)/4]*10+(number1[a]-48);
        }
    }
    if(len2%4!=0){
        intnumber2[l-1]=number2[0]-48;
        for(int b=1;b<len2%4;b++){
            intnumber2[l-1]=intnumber2[l-1]*10+(number2[b]-48);
        }
    }
    int carry=0;
    if(len1>len2){
        int iterate;
        for(iterate=0;intnumber2[iterate];iterate++){
            answer[iterate]=intnumber1[iterate]+intnumber2[iterate]+carry;
            if(answer[iterate]>9999){
                carry=answer[iterate]/10000;
                answer[iterate]=answer[iterate]%10000;
            }
            else{
                carry=0;
            }
        }
        while (intnumber1[iterate])
        {
            answer[iterate]=intnumber1[iterate]+carry;
            if(answer[iterate]>9999){
                carry=answer[iterate]/10000;
                answer[iterate]=answer[iterate]%10000;
            }
            else
            {
                carry=0;
            }
            iterate++;
        }
        // if(carry){
        //     answer[iterate]=carry;
        // }        
    }
    else{
        int iterate;
        for(iterate=0;intnumber1[iterate];iterate++){
            answer[iterate]=intnumber2[iterate]+intnumber1[iterate]+carry;
            if(answer[iterate]>9999){
                carry=answer[iterate]/10000;
                answer[iterate]=answer[iterate]%10000;
            }
            else
            {
                carry=0;
            }
        }
        while (intnumber2[iterate])
        {
            answer[iterate]=intnumber2[iterate]+carry;
            if(answer[iterate]>9999){
                carry=answer[iterate]/10000;
                answer[iterate]=answer[iterate]%10000;
            }
            else
            {
                carry=0;
            }
            iterate++;
        }
        // if(carry){
        //     answer[iterate]=carry;
        // }        
    }
    int g,length;
    for(g=0;answer[g];g++){
        length++;
    }
    int it;
    for(it=0;it<length;it++){
        printf("%d",answer[length-it-1]);
    }
    return 0;
}
