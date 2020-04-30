//Search for a key

#include<stdlib.h>
#include<stdio.h>

//returns 0 if not found else 1 if found

struct node{
    int data;
    struct node*left;
    struct node*right;
    struct node*parent;
};

struct node*node(int value,struct node*currentNodeParent){
    struct node*temp=(struct node*)calloc(1,sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=currentNodeParent;
}

void buildBST(struct node**root,int*array,int length){
    *root=node(array[0],NULL);
    struct node*pointer=NULL;
    for(int i=1;i<length;i++){
        pointer=*root;
        while(1){
            if(array[i]<pointer->data){
                if(pointer->left!=NULL){
                    pointer=pointer->left;
                }
                else{
                    pointer->left=node(array[i],pointer);
                    break;
                }
            } 
            else{
                if(pointer->right!=NULL){
                    pointer=pointer->right;
                }
                else{
                    pointer->right=node(array[i],pointer);
                    break;
                }
            }
        }
    }
}

int find(struct node*root,int value){
    struct node*ptr=root;
    while(ptr!=NULL){
        if(value==ptr->data){
            return 1;
        }
        else if(value<ptr->data){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    return 0;
}

int main(){
    int*input=(int*)calloc(100000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    int tofind;
    scanf("%d",&tofind);
    struct node*root=NULL;
    buildBST(&root,input,len);
    printf("%d",find(root,tofind));
    free(input);
    return 0;
}