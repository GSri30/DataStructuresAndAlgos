#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input[10000];
    char updated[4000];
    gets(input);
    int length=strlen(input);
    int j=0;
    for(int i=0;i<length;i++){
        if(input[i]!=' ' && input[i]!=',' && input[i]!='{' && input[i]!='}'){
            int j;
            for(j=0;j<strlen(updated);j++){
                if(updated[j]==input[i]){
                    break;
                }
            }
            if(j==strlen(updated)){
                updated[j++]=input[i];
            }
        }
    }
    int length1=strlen(updated);
    printf("%d",length1);
    return 0;
}