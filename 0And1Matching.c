#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int searchForEqual(char a[],int l){
    char*pointer1=a,*pointer2=a;
    int count=0;
    for(int i=0;i<l-1;i++){
        pointer2++;
    }  
    int left=1,right=l;
    while(left<right && right-left!=1){
        while(*pointer1!='0' && left!=right && right-left!=1){
            pointer1++;
            left++;
        }
        while(*pointer2!='1' && left!=right && right-left!=1){
            pointer2--;
            right--;
        }
        pointer1++;pointer2--;
        left++;right--;
        count++;
    }    
    if(left==right){
        return left-1;
    }
    if(right-left==1){
        return -1;
    }
    return -1;
}

int main(){
    char*input=(char*)calloc(100000,sizeof(char));
    scanf("%s",input);
    int length=strlen(input);
    int answer;
    answer=searchForEqual(input,length);
    printf("At index %d",answer);
    free(input);
    return 0;
}