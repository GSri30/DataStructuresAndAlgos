#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PRIME 100003

int toDec(int n){
    int decimal=0;
    int remainder;int i=1;
    while(n){
        remainder=n%10;
        n=n/10;
        decimal+=remainder*i;
        i*=2;
    }
    return decimal;
}
struct node
{
    int indexOfPattern;
    struct node*next;
};
struct node*pointer;
void insert(char in,struct node**r){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->indexOfPattern=in;
    temp->next=NULL;
    if(*r==NULL){
        pointer=*r=temp;
    }
    else{
        pointer->next=temp;
        pointer=temp;
    }
}


int lcs(char*string1,char*string2,int l){
    int x=2;
    struct node*hashTable[PRIME];
    for(int i=0;i<PRIME;i++){
        hashTable[i]=NULL;
    }
    int length1=strlen(string1);
    int length2=strlen(string2);
    int sub1=string1[0]-48;
    int sub2=string2[0]-48;
    for(int i=1;i<l;i++){
        x=x*2;
        sub1=(2*sub1+string1[i]-48)%PRIME;
        sub2=(2*sub2+string2[i]-48)%PRIME;
    }
    insert(0,&hashTable[sub2]);
    for(int j=0;j<length2-l;j++){
        sub2=(2*sub2+(string2[j+l]-48)-x*(string2[j]-48))%PRIME;
        insert(j+1,&hashTable[sub2]);
    }

    struct node*ptr;

    for(int j=0;j<length1-l;j++){
        if(hashTable[sub1]!=NULL){
            ptr=hashTable[sub1];
            while(ptr!=NULL){
                int k;
                for(k=0;k<l;k++){
                    if(string1[(ptr->indexOfPattern)+k]!=string2[j+k]){
                        break;
                    }
                }
                if(k==l){
                    // printf("Match found for length = %d",l);
                    return 1;
                }
                ptr=ptr->next;
            }
        }
        sub1=(2*sub1+(string1[j+l]-48)-x*(string1[j]-48))%PRIME;
    }
    struct node*cleanerPresent,*cleanerNext;    
    for(int c=0;c<PRIME;c++){
        cleanerPresent=hashTable[c];
        if(cleanerPresent!=NULL){
            while(cleanerPresent!=NULL){
                cleanerNext=cleanerPresent->next;
                cleanerPresent=hashTable[c];
                free(cleanerPresent);
                cleanerPresent=cleanerNext;
            }
        }
        hashTable[c]=NULL;
    }
    return 0;
}
int tempLongest=0;
int binarySearchLen(char*s1,char*s2,int left,int right){
    int middle=left+right/2;
    if(left>right){
        return tempLongest;
    }
    if(lcs(s1,s2,middle)){
        tempLongest+=middle;
        binarySearchLen(s1,s2,middle+1,right);
    }
    else{
        binarySearchLen(s1,s2,left,middle-1);
    }
}

int main(){
    char*s1=(char*)calloc(100000,sizeof(char));
    char*s2=(char*)calloc(100000,sizeof(char));
    scanf("%s",s1);
    scanf("%s",s2);
    int length1=strlen(s1),length2=strlen(s2);
    int longest=1;
    for(int i=2;i<length1;i++){
        if(lcs(s1,s2,i)){
            longest=i;
        }
    }

    printf("%d",longest);
    free(s1);free(s2);
    return 0;
}