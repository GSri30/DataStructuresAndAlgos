#include<stdio.h>
#include<stdlib.h>

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

struct List{
    struct node*data;
    struct List*link;
};

void rangeList(struct node*root,struct List**list,struct node*l,struct node*r){
    if(root){
        if(root->data>r->data){
            rangeList(root->left,&list,l,r);
        }
        else if(root->data<l->data){
            rangeList(root->right,&list,l,r);
        }
        else{
            rangeList(root->right,&list,l,r);
            struct List*temp=(struct List*)calloc(1,sizeof(struct List));
            temp->data=root->data;
            temp->link=*list;
            *list=temp;
            rangeList(root->left,&list,l,r);
        }
    }
}

//Just return the len of the list
int rangeCount(struct node*root,int l,int r){
    if(!node && l>r){return 0;}
    if(root->data>r){
        return rangeCount(root->left,l,r);
    }
    if(root->data<l){
        return rangeCount(root->right,l,r);
    }
    return 1+rangeCount(root->left,l,r)+rangeCount(root->right,l,r);
}