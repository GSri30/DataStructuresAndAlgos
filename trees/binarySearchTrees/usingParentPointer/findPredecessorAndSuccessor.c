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

//0 for leftchild 1 for right child
int whichChild(struct node*pointer){
    int data=pointer->data;
    pointer=pointer->parent;
    if(pointer->left->data==data){return 0;}
    return 1;
}

struct node*getPredecessor(struct node*pointer){
    if(pointer->left){
        pointer=pointer->left;
        while(pointer->right){
            pointer=pointer->right;
        }
    }
    else{
        if(pointer->parent){
            while(pointer){
                if(!whichChild(pointer)){
                    pointer=pointer->parent;
                }
                else{
                    pointer=pointer->parent;
                    break;
                }
            }
        }
        else{
            return NULL;
        }
    }
    return pointer;
}

struct node*getSuccessor(struct node*pointer){
    if(pointer->right){
        pointer=pointer->right;
        while(pointer->left){
            pointer=pointer->left;
        }
    }
    else{
        if(pointer->parent){
            while(pointer){
                if(whichChild(pointer)){
                    pointer=pointer->parent;
                }
                else{
                    pointer=pointer->parent;
                    break;
                }
            }
        }
        else{
            return NULL;
        }
    }
}

int main(){
    int*input=(int*)calloc(1000,sizeof(int));
    int len;
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&input[i]);
    }
    struct node*root=NULL;
    buildBST(&root,input,len);
    struct node*ptr=root->left->right->right;
    struct node*ans=getPredecessor(ptr);
    printf("%d",ans->data);
    free(input);
    return 0;
}