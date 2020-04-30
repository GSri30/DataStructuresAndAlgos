#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PRIME 100003

int toDec(char*n){
    int decimal=n[0]-48;
    for(int i=1;i<strlen(n);i++){
        decimal=decimal*2+(n[i]-48);
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
struct node*p;
int main(){
    int check;
    char*number=(char*)calloc(100000,sizeof(char));int num;
    scanf("%s %d",number,&num);
    char*patterns[num];
    for(int i=0;i<num;i++){
        patterns[i]=(char*)calloc(10000,sizeof(char));
        scanf("%s",patterns[i]);
    }

    int lengthPattern=strlen(patterns[0]);
    int lengthnumber=strlen(number);

    struct node*hashTable[PRIME];

    for(int i=0;i<PRIME;i++){
        hashTable[i]=NULL;
    }
    char temp;
    for(int i=0;i<num;i++){
        insert(i,&hashTable[toDec(patterns[i])%PRIME]);        
    }
    int sub_number=number[0]-48;
    int x=2;
    for(int i=1;i<lengthPattern;i++){
        x=x*2;
        sub_number=(2*(sub_number)+number[i]-48)%PRIME;
    }
    for(int i=0;i<lengthnumber-lengthPattern;i++){
        if(hashTable[sub_number]!=NULL){
            p=hashTable[sub_number];
            while(p!=NULL){
                int j;
                for(j=0;j<lengthPattern;j++){
                    if(patterns[p->indexOfPattern][j]!=number[i+j]){
                        break;
                    }
                }
                if(j==lengthPattern){
                    check++;
                    printf("Found match! %d pattern at %d index\n",(p->indexOfPattern)+1,i);
                }
                p=p->next;                
            }
        }
        sub_number=(2*sub_number+number[i+lengthPattern]-48-x*(number[i]-48))%PRIME;
        if(sub_number<0){
            sub_number+=PRIME;
        }
    }
    if(check==0){
        printf("No matches found!");
    }
    return 0;
}