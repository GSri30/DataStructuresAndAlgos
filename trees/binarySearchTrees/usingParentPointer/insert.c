#include<stdlib.h>
#include<stdio.h>

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

void insert(struct node*root,int value){
    struct node*ptr=root;
    while(1){
        if(value<ptr->data){
            if(ptr->left!=NULL){
                ptr=ptr->left;
            }
            else{
                ptr->left=node(value,ptr);
                break;
            }
        } 
        else{
            if(ptr->right!=NULL){
                ptr=ptr->right;
            }
            else{
                ptr->right=node(value,ptr);
                break;
            }
        }
    }
}