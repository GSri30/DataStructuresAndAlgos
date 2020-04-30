//Given a a string and k, return the length of the largest subString which repeats atleast k times.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define PRIME 100003

struct node{
    int index;
    int count;
    struct node*link;
};
struct node*pointer=NULL;
void insert(int index,struct node**r){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->index=index;
    temp->count=1;
    temp->link=NULL;
    if(*r==NULL){
        pointer=*r=temp;
    }
    else{
        pointer->link=temp;
        pointer=temp;
    }
}

bool check(char*string,int len,int k){
    //Use RabinKarp
    int x=2;
    struct node*hashTable[PRIME];
    for(int i=0;i<PRIME;i++){
        hashTable[i]=NULL;
    }
    int length=strlen(string);
    int sub=string[0]-48;
    for(int i=1;i<len;i++){
        x=x*2;
        sub=(2*sub+string[i]-48)%PRIME;
    }
    insert(0,&hashTable[sub]);
    for(int j=0;j<length-len;j++){
        sub=(2*sub+(string[j+len]-48)-x*(string[j]-48))%PRIME;
        struct node*ptr=hashTable[sub];
        while(ptr){
            int i;
            int k=j+1;
            for(i=ptr->index;i<ptr->index+len;i++){
                if(string[i]!=string[k]){
                    break;
                }
                k++;
            }
            if(i==ptr->index+len){
                ptr->count++;
                break;
            }
            else{
                ptr=ptr->link;
            }
        }
        if(ptr==NULL){
            insert(j+1,&hashTable[sub]);
        }
    }
    for(int i=0;i<PRIME;i++){
        struct node*ptr=hashTable[i];
        while(ptr){
            if(ptr->count>=k){
                break;
            }
            else{
                ptr=ptr->link;
            }
        }
        if(ptr){
            return true;
        }
    }
    struct node*cleanerPresent,*cleanerNext;    
    for(int c=0;c<PRIME;c++){
        if(hashTable[c]){
            cleanerPresent=hashTable[c];
            while(cleanerPresent->link){
                cleanerNext=cleanerPresent->link;
                hashTable[c]=cleanerNext;
                free(cleanerPresent);
                cleanerPresent=cleanerNext;
            }
            hashTable[c]=NULL;
            free(cleanerPresent);
        }
    }
    return false;
}

int findStringForGivenLen(char*string,int k,int l,int r){
    int len=(l+r)/2;
    if(l==len && l!=r){
        if(check(string,r,k)){
            return r;
        }
        else{
            return l;
        }
    }
    if(l==r && check(string,len,k)){
        return l;
    }
    if(l<r){
        if(check(string,len,k)){
            return findStringForGivenLen(string,k,len,r);
        }
        else{
            return findStringForGivenLen(string,k,l,len-1);
        }
    }
    return -1;
}


int main(){
    char*input=(char*)calloc(1000000,sizeof(char));
    scanf("%s",input);
    int k;
    scanf("%d",&k);
    int len=strlen(input);
    printf("%d",findStringForGivenLen(input,k,0,len-1));
    free(input);
    return 0;
}