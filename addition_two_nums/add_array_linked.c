#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node*link;    
};

struct node*pointer;
struct node*root=NULL;
struct node*root1=NULL;
struct node*rootans=NULL;

void insert(char in,struct node**r){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->data=in;
    temp->link=NULL;
    if(*r==NULL){
        pointer=*r=temp;
    }
    else{
        pointer->link=temp;
        pointer=temp;
    }
}

void reverse(struct node**r){
    struct node*prev=NULL,*next=NULL,*curr=*r;
    while (curr!=NULL)
    {
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;    
    }
    *r=prev;
}

int main(){
    char*input1=(char*)calloc(10000,sizeof(char));
    char*input2=(char*)calloc(10000,sizeof(char));
    scanf("%s %s",input1,input2);
    int length1=strlen(input1),length2=strlen(input2);
    for(int i=0;i<length1;i++){
        insert(input1[length1-i-1],&root);
    }
    for(int j=0;j<length2;j++){
        insert(input2[length2-j-1],&root1);
    }
    struct node*p1=root;
    struct node*p2=root1;
    int carry=0;
    int a=0;
    int temp;
    if(length1>length2){
        while(a<length2){
            temp=(((p1->data)-48)+((p2->data)-48)+carry);
            if(temp>9){
                carry=temp/10;
                insert(temp%10+'0',&rootans);
            }
            else
            {
                insert((((p1->data)-48)+((p2->data)-48)+carry)+'0',&rootans);
                carry=0;
            }
            p1=p1->link;p2=p2->link;
            a++;
        }
        while (a<length1)
        {   
            temp=(p1->data)-48+carry;
            if(temp>9){
                carry=temp/10;
                insert(temp%10+'0',&rootans);
            }
            else
            {
                insert(temp+'0',&rootans);
                carry=0;
            }
            p1=p1->link;
            a++;
        }
    }
    else
    {
        while(a<length1){
        temp=(((p2->data)-48)+((p1->data)-48)+carry);
        if(temp>9){
            carry=temp/10;
            insert(temp%10+'0',&rootans);
        }
        else
        {
            insert((((p2->data)-48)+((p1->data)-48)+carry)+'0',&rootans);
            carry=0;
        }
        p1=p1->link;p2=p2->link;
        a++;
        }
        while (a<length2)
        {   
            temp=(p2->data)-48+carry;
            if(temp>9){
                carry=temp/10;
                insert(temp%10+'0',&rootans);
            }
            else
            {
                insert(temp+'0',&rootans);
                carry=0;
            }
            p2=p2->link;
            a++;
        }
    }
    if(length1==length2){
        if(carry){
            insert(carry+'0',&rootans);
        }
    }
    reverse(&rootans);
    struct node*p=rootans;
    while(p!=NULL){
        printf("%c",p->data);
        p=p->link;
    }
    return 0;
}