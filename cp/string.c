#include<stdio.h>
#include<string.h>

int main(){
    char input[101];
    scanf("%s",input);
    int length=strlen(input);
    for(int i=0;i<length;i++){
        if(input[i]<90){
            input[i]+=32;
        }
        if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u'){
            continue;
        }
        else
        {
            printf(".%c",input[i]);
        }
    }
    return 0;
}