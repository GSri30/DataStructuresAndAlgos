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

struct node*lca(struct node*l,struct node*r,struct node*root){
    struct node*pointer=root;
    while(1 && pointer){
        if(pointer->data>r->data && pointer->left){
            pointer=pointer->left;
        }
        else if(pointer->data<l->data && pointer->right){
            pointer=pointer->right;
        }
        else{
            break;
        }
    }
    return pointer;
}

int main(){
    int*input=(int*)calloc(100,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    struct node*root;
    buildBST(&root,input,len);
    struct node*l=root->right->left->left->left;
    struct node*r=root->right->left->right->right->right->right;
    struct node*ptr=lca(l,r,root);
    printf("%d",ptr->data);
    free(input);
    return 0;
}